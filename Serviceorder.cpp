#include<iostream>
int result(int a[],int i )
{
	if(i==0)
		return a[0];
	else
		return a[i]+result(a,i-1);
}
using namespace std;
int main()
{
	int n;
	int a[4000];
	while(cin>>n)
	{
		for(int i=0;i!=n;i++)
			cin>>a[i];
		for(int i=0;i!=n;i++)
		{
			int min=i;
			for(int j=i+1;j!=n;j++)
			{
				if(a[min]>a[j])
					min = j;
			}
			if(min!=i)
			{
				int temp = a[i];
				a[i] = a[min];
				a[min] = temp;
			}
		}
		if(n==1)
			cout<<0<<endl;
		else
		{
			int sum = 0;
			for(int i =0;i<n-1;i++)
				sum+=result(a,i);
			cout<<sum<<endl;
		}
	}
	return 0;
 } 
