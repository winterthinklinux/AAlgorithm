#include<iostream>

struct point
{
	int x,y;
};
using namespace std;
int fabs(int a)
{
	return a>0?a:-a;
}
int gcd(int a,int b)
{
	if(0==b) return a;
	else
	return gcd(b,a%b);
}

int Onsegment(point a,point b)
{
	return gcd(fabs(a.x-b.x),fabs(a.y-b.y))+1;
 } 
int main()
{
	int L;
	int flag = 0;
	point s,p;
	while(cin>>L)
	{
		if(0==L)
			break;
		cin>>s.x>>s.y;
		cin>>p.x>>p.y;
		if(fabs(s.x)>L||fabs(s.y)>L||fabs(p.x)>L||fabs(p.y)>L)
			cout<<"Out of range"<<endl;
		else if(Onsegment(s,p)>2)
			cout<<"NO"<<endl;
		else if(Onsegment(s,p)==2)
			cout<<"Yes"<<endl;			
	}
	return 0;
}
