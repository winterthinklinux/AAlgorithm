#include<iostream>
using namespace std;
int main()
{   int n,k;
	static int count=0;
	int a[50];
	int m=0;
	cin>>n>>k;
	for(int i=0;i<=k;i++)
		cin>>a[i];
	for(int i=0;i<=k;i++)
	{
		if(a[i]>n)
		{
			cout<<"No Solution!"<<endl;
			return -1;	
		}
			
	 } 
	 for(int i=0;i<=k;i++)
	 {
	 	m += a[i];
	 	if(m+a[i+1]>n)
	 	{
	 		count++;
	 		m=0;
		 }
	 }
	 cout<<count<<endl;
	return 0;
}
