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

#define pb push_back

vector<int> used;
vector<vector<int>> g;
void dfs(int u, int cnt)
{
	used[u] = cnt;
	for(int i = 0; i < g[u].size(); i++)
	{
		if(used[g[u][i]] == 0)
		dfs(g[u][i], cnt);
	}
}

int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

	int n, m; cin >> n >> m;
	g = vector<vector<int>> (n);
	used = vector<int> (n, 0);
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(used[i] == 0)
		{
			cnt++;
			dfs(i, cnt);
		}
	}

	cout << cnt << endl;
	for(int i = 0; i < n; i++)
		cout << used[i] << " " ;
	return 0;
}