#include<iostream>
using namespace std;
int main()
{
	string s1[30],s2[30],s[60];
	int n1,n2,total;
	cin>>n1;
	cin.ignore();//注释 
	for(int i=0;i!=n1;i++)
	{
		getline(cin,s1[i]);
	}
	cin>>n2;
	cin.ignore();
	for(int i=0;i!=n2;i++)
	{
		getline(cin,s2[i]);
	}
	total = n1+n2;
	int i=0,j=0,k=0;
	while(i!=n1&&j!=n2)
	{
		if(s1[i]<s2[j])
			s[k++] = s1[i++];
		else if(s1[i]>s2[j])
			s[k++] = s2[j++]; 
		else//如果两个人的姓相同，那么先出现的人仍在前。
		{
			s[k++] = s1[i++];
			j++;
		}
	}
	while(i!=n1)
	{
		s[k++]= s1[i++];
	}
	while(j!=n2)
	{
		s[k++] = s2[j++];
	}
	cout<<total<<endl;
	for(int i=0;i!=total;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}
