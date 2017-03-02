#include<iostream>
//#include<math.h>
#include<iomanip>
using namespace std;

typedef int ElemType;
struct point
{
	ElemType x,y;
};
int min(int x, int y)
{
	return x < y ? x : y;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
double direction(point i, point j, point k)//计算向量ki和向量ji的叉积 
{
	return (i.x - k.x)*(i.y - j.y) - (i.y - k.y)*(i.x - j.x);
}
bool segment(point i, point j, point k) // //判断点k是否在线段i j上 
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
bool judge(point p1, point p2, point p3, point p4)//判断线段p1p2和p3p4是否相交 
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

int main()
{
	string s = "NO";
	int n;
	cin>>n;
	while(n--)
	{
		int a[6],b[4];
		for(int i = 0;i!=6;i++)
			cin>>a[i];
		for(int i = 0;i!=4;i++)
			cin>>b[i];
		double area = ((a[1] + a[3])*(a[2] - a[0]) + (a[3] + a[5])*(a[4] - a[2]) - (a[1] + a[5])*(a[4] - a[0])) * 1 / 2;
		if(area<0)
			area =  -area;	
	 	point A, B, C, P, Q;
		A.x = a[0];	A.y = a[1];	
		B.x = a[2];	B.y = a[3];	
		C.x = a[4];	C.y = a[5];	
		P.x = b[0];	P.y = b[1];	
		Q.x = b[2];	Q.y = b[3];	
		if(judge(A, B, P, Q) || judge(B, C, P, Q) || judge(C, A, P, Q))
			s  = "YES";
		cout <<"Case 1:" << endl;
		cout <<fixed<< setprecision(1) << area << " " << s << endl;
				
	}
	return 0;
	
}

