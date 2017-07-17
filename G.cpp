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

vector<int> used, color;
vector<vector<int>> g;
void dfs(int u, bool c, int &flag)
{
	if(!flag)
		return;
	used[u] = 1;
	c ^= 1;
	color[u] = c;
	for(int i = 0; i < g[u].size(); i++)
	{
		if(used[g[u][i]] == 0)
		{
			dfs(g[u][i], c, flag);
		}
		if(color[u] == color[g[u][i]])
		{
			flag = 0;
			return;
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

	int t, n, m; cin >> t;
	for(int q = 0; q < t; q++)
	{
		cin >> n >> m;
		g = vector<vector<int>> (n);
		used = vector<int> (n, 0);
		color = vector<int> (n, -1);
		for(int i = 0; i < m; i++)
		{
			int x, y; cin >> x >> y;
			x--, y--;
			g[x].pb(y);
			g[y].pb(x);
		}

		int flag = 1;
		bool c = 0;
		for(int i = 0; i < n; i++)
		{
			if(used[i] == 0)
				dfs(i, c, flag);
		}
			
		
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}