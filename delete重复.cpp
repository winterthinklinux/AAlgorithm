#include<iostream> 
#include<set> 
using namespace std; 

int main() 
{ 
    
    int n;
    while(cin>>n)
    {
    	set<int> s;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			s.insert(temp);
				
		}
		set<int>::iterator it; //定义前向迭代器 
    //中序遍历集合中的所有元素 
		int  array[n],k=0;
	    for(it=s.begin();it!=s.end();it++) 
	   	{
			array[k++]=(*it);
			cout<<k-1<<"" <<array[k-1]<<endl;
		}	
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<n;j++)
	    	{
	    		if(array[j]>array[j+1])
	    		{
	    			int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;	
				}
	
			}
		for(int i=0;i<n-1;i++)
		{
			if(array[i]!=0)
				cout<<array[i]<<" ";
		}
		cout<<array[n-1]<<endl;
		
	}	


    return 0; 
} 
