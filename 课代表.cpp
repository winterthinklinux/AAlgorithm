#include<cstring>
#include<iostream>
using namespace std;

#define P 110
#define N 310
int map[P][N];
int match[N];
bool use[N];
int p, n;

bool find(int u) 
{
	for (int i = 1; i <= n; ++i)
	{
		if (!use[i] && map[u][i])
		{
			use[i] = true;
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
	while (ncase--)
	{
		memset(map, 0, sizeof(map));
		memset(match, -1, sizeof(match));
		cin >> p >> n;
		for (int i = 1; i <= p; ++i)
		{
			cin >> stunum;
			for (int j = 1; j <= stunum; ++j)
			{
				cin >> temp;
				map[i][temp] = 1; 
			}
		}
		for (int i = 1; i <= p; ++i) 
		{
			memset(use, false, sizeof(use));
			if (find(i))
				sum++;
		}
		cout << ((sum == p) ? "YES" : "NO") << endl;;
	}
	return 0;
}

