#include<iostream>
#include<cstring>
int pos[9][9] ;
using namespace std;
int main()
{	
	int a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				memset(pos[i], 0, sizeof(pos[i]));
		pos[c][d] = 1;
		for(int j =d-1;j>=b;j--)
		{
			for(int i=1;i<9;i++)
			{
				if (i >= 3 && pos[i - 2][j +1] > 0){
					if (pos[i][j] == 0)
						pos[i][j] = pos[i - 2][j +1] + 1;
					else if (pos[i][j] > pos[i - 2][j +1] + 1)
						pos[i][j] = pos[i -2][j + 1] + 1;
				}
				if (i >= 2 && j < d- 1 && pos[i - 1][j + 2] >0){
					if (pos[i][j] == 0)
						pos[i][j] = pos[i - 1][j + 2] + 1;
					else if (pos[i][j] > pos[i - 1][j + 2] + 1)
						pos[i][j] = pos[i - 1][j + 2] + 1;
				}
				if (i < 8 && j < d - 1 && pos[i + 1][j +2] > 0){
					if (pos[i][j] == 0)
						pos[i][j] = pos[i + 1][j +2]  + 1;
					else if (pos[i][j] > pos[i + 1][j +2]  + 1)
						pos[i][j] = pos[i + 1][j +2]  + 1;
				}
				if (i < 7 && pos[i + 2][j + 1] > 0){
					if (pos[i][j] == 0)
						pos[i][j] = pos[i + 2][j + 1]  + 1;
					else if (pos[i][j] > pos[i + 2][j + 1] +1)
						pos[i][j] = pos[i + 2][j + 1] +1;
				}

			}
		}
		if (pos[a][b] == 0)
				cout << "Impossible" << endl;
			else
				cout << pos[a][b] - 1<< endl;

	}
	return 0;
 } 
