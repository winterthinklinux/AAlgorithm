#include<iostream>

using namespace std;
int n,m;
int a[201][201]={0};
int r[201][201]={0};
int minlength;
void min()//min��������̾��� 
{
	for(int i=0;i<201;i++)//���ɴ� 
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
	while(cin>>n&&cin>>m)//n����ׯm��· 
	{
		for(int i=0;i<m;i++)//m��· 
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
