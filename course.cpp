//������ 
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
	for (int i = 1; i <= n; ++i)//n��ѧ�� 
	{
		if (!use[i] && map[u][i])//�����ǿδ��� i�Ϳ��й��� 
		{
			use[i] = true;	//���ҵĿδ��� 
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
	while (ncase--)//���Դ������� 
	{
		memset(map, 0, sizeof(map));		//��ά������0 
		memset(match, -1, sizeof(match));	//mathch��һ-1
		cin >> p >> n;	//p�ſΣ�n���� 
		for (int i = 1; i <= p; ++i)
		{
			cin >> stunum; 		//xѡ��γ�i������ 
			for (int j = 1; j <= stunum; ++j)
			{
				cin >> temp;	//�Ϳγ�i�й���������Ϊ1 
				map[i][temp] = 1; 
			}
		}
		for (int i = 1; i <= p; ++i) //p�ſ��ҿδ��� 
		{
			memset(use, false, sizeof(use));
			if (find(i))//�ҵ�һ�ż�1 
				sum++;
		}
		cout << ((sum == p) ? "YES" : "NO") << endl;;
	}
	return 0;
}

