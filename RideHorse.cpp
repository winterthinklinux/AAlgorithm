#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int dir[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};//8���߷�         
struct node
{int x,y,step;};
queue<node>que;
bool matrix[9][9];// 
int ax,ay,bx,by;
node cur,pre;	//��ǰ��㣬ǰһ���ڵ� 
int bfs()		//��������㷨 
{
    int i;
    if(ax==bx&&ay==by)//0�� 
		return 0;
    cur.x=ax;	//��ǰ��� 
	cur.y=ay;
	cur.step=0;
    memset(matrix,0,sizeof(matrix));
    while(!que.empty())
		que.pop();
    matrix[ax][ay]=1;
    que.push(cur); //���� 
    while(!que.empty())
    {
        cur=que.front(); //��ȡ���� 
		que.pop();		//���� 
        cur.step++;
        
        for(int i = 0;i<8;i++)
        {
        	cout<<dir[i][0]<<" "<<dir[i][1]<<endl;
		}
        for(i=0;i<8;i++)
        {
            ax=cur.x+dir[i][0];//�������� 
            ay=cur.y+dir[i][1];
            if(ax>0&&ax<9&&ay>0&&ay<9&&!matrix[ax][ay])
            {
                matrix[ax][ay]=1;
                if(ax==bx&&ay==by)
					return cur.step;
                pre.x=ax;
				pre.y=ay;
				pre.step=cur.step;
                que.push(pre);//���� 
            }
        }
    }
    return -1;
}
int main()
{
    char t1,t2;
    int temp;
    while(cin>>t1>>ay>>t2>>by)
    {
        temp=ay;
        ax=t1-'a'+1;bx=t2-'a'+1; //ax,bx��t1��t2��ת�� 
        cout<<t1<<ay<<"==>"<<t2<<by<<": "<<bfs()<<" moves"<<endl;
    }
    return 0;
}

