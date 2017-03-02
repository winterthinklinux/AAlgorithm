#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	int m;
    cin>>n>>m;
	while((n!=0)||(m!=0)){//n个人m个社团 
		int p[n],num[m];
		for(int i=1;i<n;i++)  //标记 n个人 
		    p[i]=-1;
		for(int i=0;i<m;i++){ //每个社团每个社团研究 
			int temp2;			//社团是temp2个人 
			cin>>temp2;
			num[i]=temp2;      
			int a[temp2];          
			
			for(int j=0;j<temp2;j++){
			    cin>>a[j];            //输入temp[2]个人 
			    int temp=a[0];			//第一个人 
			    int temp1=p[a[j]];     //temp  
			    if(p[a[j]]==-1)
			        p[a[j]]=temp;
			    else{
			        for(int k=0;k<n;k++)
			           if(temp1==p[k])
			              p[k]=temp;
			    }
			}
			
		}
		int count=1;
		if(p[0]!=-1){
		
		  for(int i=1;i<n;i++){
			   if(p[0]==p[i])
			        count++;
			
		  }
		
	    }
		cout<<count<<endl;
		cin>>n>>m;
	}
	
}


