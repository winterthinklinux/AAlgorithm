#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	int m;
    cin>>n>>m;
	while((n!=0)||(m!=0)){//n����m������ 
		int p[n],num[m];
		for(int i=1;i<n;i++)  //��� n���� 
		    p[i]=-1;
		for(int i=0;i<m;i++){ //ÿ������ÿ�������о� 
			int temp2;			//������temp2���� 
			cin>>temp2;
			num[i]=temp2;      
			int a[temp2];          
			
			for(int j=0;j<temp2;j++){
			    cin>>a[j];            //����temp[2]���� 
			    int temp=a[0];			//��һ���� 
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


