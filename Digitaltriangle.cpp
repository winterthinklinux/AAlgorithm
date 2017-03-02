#include<iostream>
#define Max_num 100
using namespace std;
int main()
{
	int H;
	int data[Max_num + 1][Max_num + 1];
	int maxsum[Max_num + 1][Max_num + 1];
	while(cin>>H&&H!=0)
	{
		for(int i = 1; i <= H; i++)
		{
			for(int j = 1; j <= i; j++)
				cin >> data[i][j];
		}
		for(int j = 1; j <= H; j++)
			maxsum[H][j] = data[H][j];

		for(int i = H; i > 1; i--)
		{
			for(int j = 1; j < i; j++)
			{
				if(maxsum[i][j]>maxsum[i][j + 1])//本一个的老大等于上一个老大+本一个数 
					maxsum[i - 1][j] = maxsum[i][j] + data[i-1][j];
				else
					maxsum[i - 1][j] = maxsum[i][j+1] + data[i-1][j];
				
			}
		}
		cout << maxsum[1][1] << endl;

	}
	return 0;
} 
