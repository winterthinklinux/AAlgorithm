#include<iostream>

using namespace std;
int n,m;
int a[201][201]={0};
int r[201][201]={0};
int minlength;
void min()//min用于求最短距离 
{
	for(int i=0;i<201;i++)//不可达 
		for(int j=0;j<201;j++)
		{
			r[i][j]=10000;
		}
	for(int i=0;i<m-1;i++)// 
		for(int j=i+1;j<m;j++)
		{
			r[i][j] = a[i][j];
		}

	for(int i=2;i<m;i++)
		{
		for(int j=0;j<=m-i;j++)
			{
				minlength=a[j][j+i];
			    for(int k=j+1;k<j+i;k++)
				{
					if(minlength>(r[j][k]+r[k][j+i]))
					    minlength=(r[j][k]+r[k][j+i]);
					r[j][j+i]=minlength;
					}
				}
			}
}

int main()
{
	int c1=0,c2=0;
	while(cin>>n&&cin>>m)//n个村庄m条路 
	{
		for(int i=0;i<m;i++)//m条路 
		{
			cin>>c1>>c2;
			cin>>a[c1][c2];
		}
		int s,e;
		cin>>s>>e;
		min();
		if(r[s][e]>=10000)
		{
			cout<<"-1"<<endl;
		 } else
		 {
		 	cout<<r[s][e]<<endl;
		 }
		 
	}
	return 0;
}
