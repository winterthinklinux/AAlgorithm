#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
char a[300][300];
void print(int x, int y, int s)
{
	if (1 == s)
	{
		a[x][y] = 'X';
		return;
	}
	int k = (int)pow(3, s - 2);
	print(x, y, s - 1);
	print(x, y + 2*k, s - 1);
	print(x + k, y + k, s - 1);
	print(x + 2 * k, y, s - 1);
	print(x + 2 * k, y + 2 * k, s - 1);
}


int main() 
{
	int n;
	while(cin>>n)
	{
		if(-1==n)
			break;
		memset(a, ' ', sizeof(a));//memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
		int k = (int)pow(3, n - 1);
		print(0, 0, n);

		for(int i=0;i!=k;i++)
		{
			for(int j=0;j!=k;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
		cout<<"-"<<endl;
	}
	return 0;
}
