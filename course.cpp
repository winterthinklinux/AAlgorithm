//匈牙利 
#include<cstring>
#include<iostream>
using namespace std;

#define P 110
#define N 310
int map[P][N];//110,310
int match[N];//310
bool use[N];//310
int p, n; 

bool find(int u) 
{
	for (int i = 1; i <= n; ++i)//n个学生 
	{
		if (!use[i] && map[u][i])//还不是课代表 i和课有关联 
		{
			use[i] = true;	//当我的课代表 
			if (match[i] == -1 || find(match[i]))
			{
				match[i] = u;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int ncase;
	int stunum, temp, sum=0;
	cin >> ncase;
	while (ncase--)//测试次数倒数 
	{
		memset(map, 0, sizeof(map));		//二维数组置0 
		memset(match, -1, sizeof(match));	//mathch置一-1
		cin >> p >> n;	//p门课，n个课 
		for (int i = 1; i <= p; ++i)
		{
			cin >> stunum; 		//x选择课程i的人数 
			for (int j = 1; j <= stunum; ++j)
			{
				cin >> temp;	//和课程i有关联的人置为1 
				map[i][temp] = 1; 
			}
		}
		for (int i = 1; i <= p; ++i) //p门课找课代表 
		{
			memset(use, false, sizeof(use));
			if (find(i))//找到一门加1 
				sum++;
		}
		cout << ((sum == p) ? "YES" : "NO") << endl;;
	}
	return 0;
}

