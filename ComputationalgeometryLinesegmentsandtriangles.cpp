#include<iostream> 
struct point
{
	int x,y;
 };
 
  int min(int x, int y)
{
	return x < y ? x : y;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
 double direction(point i, point j, point k)
{
	return (i.x - k.x)*(i.y - j.y) - (i.y - k.y)*(i.x - j.x);
}
 bool segment(point i, point j, point k)//如何判断点在直线上 
{
	if (min(i.x, j.x) <= k.x&&max(i.x, j.x) >= k.x)
	{
		if (min(i.y, j.y) <= k.y&&max(i.y, j.y) >= k.y&&!(direction(i, j, k)))
		{
			return true;
		}
	}
	return false;
}





bool Judge(point p1,point p2,point p3,point p4)
{
	double d1 = direction(p3, p4, p1);
	double d2 = direction(p3, p4, p2);
	double d3 = direction(p1, p2, p3);
	double d4 = direction(p1, p2, p4);
	if (d1*d2 < 0 && d3*d4 < 0)
		return true;
	if (segment(p3, p4, p1) || segment(p3, p4, p2) || segment(p1, p2, p3) || segment(p1, p2, p4))
		return true;
	return false;

	
}
using namespace std;
int main()
{
	string s = "NO";
	int n;
	cin>>n;
	while(n--)
	{
		int a[6],b[4];
		for(int i=0;i<6;i++)
		{
			cin>>a[i];
		}
		for(int j=0;j<4;j++)
		{
			cin>>b[j];
		}
		point A,B,C,P,Q;
		A.x=a[0];A.y=a[1];
		B.x=a[2];B.y=a[3];
		C.x=a[4];C.y=a[5];
		P.x=b[0];P.y=b[1];
		Q.x=b[2];Q.y=b[3];
		double area = 0.5*((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
		cout<<"case"<<n<<" "<<area<<endl;
		if(Judge(A,B,P,Q)||Judge(A,C,P,Q)||Judge(B,C,P,Q))
			s = "Yes";
		cout<<s<<endl;
	 } 
	return 0;
}
