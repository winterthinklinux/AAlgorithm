#include<iostream>
using namespace std;
typedef int ElemType ;
struct point{
	ElemType x, y;
};
double direction(point i, point j, point k)//计算向量ki和向量ji的叉积 
{
	return (j.x - i.x)*(k.y - j.y) - (j.y - i.y)*(k.x - j.x);
}
int main()
{
	string s = "concave";
	int n;
	while(cin>>n&&n!=0&&n>=3)
	{
		int a[100];
		point b[50];
		for(int i=0;i<2*n;i++)
			cin>>a[i];
		for (int i = 0; i != n; i++)
		{
			b[i].x = a[2*i];
			b[i].y = a[2*i + 1];
		}
		int flag = 0;
		for(int i=0;i!=n;i++)
		{
			if(direction(b[i], b[i + 1], b[i + 2]) < 0)//计算向量ki和向量ji的叉积 
				flag = 1;
		}	
		if (!flag)
			s = "convex";
		cout << s << endl;
		
	}	
}
