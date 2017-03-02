#include<iostream>

using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)//Ã°ÅÝÅÅÐò 
		{
			int flag=0;
			for(int j=0;j<n-1;j++)
			{
				if(a[j]>a[j+1])
				{
					flag = 1;
					int temp =a[j];
					a[j] = a[j+1];
					a[j+1] = temp;	
				}	
			
			}
			if(flag==0)
				break;
		}
		for(int i = 0;i<n-1;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[n-1]<<endl;
	}
	return 0;
}
