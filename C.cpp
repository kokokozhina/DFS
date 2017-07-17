#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

vector<int> used;
vector<vector<int>> g;
void dfs(int u, int j)
{

	used[u] = 1;

	for(int i = 0; i < g[u].size(); i++)
	{
		if(used[g[u][i]] == 0 && g[u][i] != j)
		{
			dfs(g[u][i], j);
		}
		
	}
	used[u] = 2;
}

int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

	int t, n, m; 
	
	cin >> n >> m;
	g = vector<vector<int>> (n);
	used = vector<int> (n, 0);
	for(int i = 0; i < m; i++)
	{
		int x, y; 
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	vector<int> ans;
	for(int j = 0; j < n; j++)
	{
		used = vector<int> (n, 0);
		int c = 0;
		for(int i = 0; i < n; i++)
		{
			if(i != j)
			{

				if(used[i] == 0)
				{
					if(c > 0)
					{
						ans.push_back(j + 1);
						break;
					}
					dfs(i, j);
					c++;
				}
			}
		}
	}	
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}