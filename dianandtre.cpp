#include<iostream> 
using namespace std;
int n;
struct point{
	int x,y;
};
int fabs(int a) 
{
	return a>0?a:-a;
}
/** 
* @brief 计算三角形面积 差乘法 
*/  
float GetTriangleSquar(point pt0, point pt1, point pt2)  
{  
    point AB,   BC;      
    AB.x = pt1.x - pt0.x;     
    AB.y = pt1.y - pt0.y;     
    BC.x = pt2.x - pt1.x;     
    BC.y = pt2.y - pt1.y;       
    return fabs((AB.x * BC.y - AB.y * BC.x)) / 2.0;      
}  
//点在线段上
bool iszaixian(point a,point b,point p)
{
	int  s1=p.x-a.x, t1=p.y-a.y;        //Q-P1(s1,t1)  
    int  s2=a.x-b.x,t2=a.y-b.y;       //P1-P2(s2,t2)  
    return (s1*t2-t1*s2)==0?true:false;     
 } 
/** 
* @brief 判断给定一点是否在三角形内或边上 
*/  
void  IsInTriangle(point A, point B, point C, point D)  
{  
    float SABC, SADB, SBDC, SADC;  
    SABC = GetTriangleSquar(A, B, C);  
    SADB = GetTriangleSquar(A, D, B);  
    SBDC = GetTriangleSquar(B, D, C);  
    SADC = GetTriangleSquar(A, D, C);  
  	
    float SumSuqar = SADB + SBDC + SADC;  
    if((SADB==0||SBDC==0||SADC==0)&&iszaixian(A,B,D)&&iszaixian(A,C,D)&&iszaixian(B,C,D))
    {
    	cout<<"case"<<n<<":"<<"On Side"<<endl;
	}else if(SABC==SADB+SBDC+SADC)
	{
		cout<<"case"<<n<<":"<<"In triangle"<<endl;
	}else
	{
		cout<<"case"<<n<<":"<<"Out of triangle"<<endl;
	} 

}  
int main()
{
	
	cin>>n;
	while(n--)
	{
		point A,B,C,P;
		cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>P.x>>P.y;
//		 if (IsInTriangle(A, B, C, P))  
//	    {  
//	        cout<<"case"<<n<<":"<<"In triangle"<<endl;  
//	    }  
//	    else  
//	    {  
//	        cout<<"P is not in ABC!"<<endl;  
//	    }  
//		cout<<"case"<<n<<":"<<"In triangle"<<endl;
//		cout<<"case"<<n<<":"<<"On Side"<<endl;
//		cout<<"case"<<n<<":"<<"Out of triangle"<<endl;
		IsInTriangle(A, B, C, P);
	}
	return 0;
}
