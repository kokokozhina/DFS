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

int n, v1, v2; 
vector<int> used;
vector<vector<int>> g;
vector<int> p;
void dfs(int u, int pr)
{
	used[u] = 1;
	p[u] = pr;
	for(int i = 0; i < n; i++)
	{
		if(used[i] == 0 && g[u][i] == 1)
			dfs(i, u);
	}
	used[u] = 2;
}

int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

	cin >> n >> v1 >> v2;
	g = vector<vector<int>> (n, vector<int>(n));
	used = vector<int> (n, 0);
	p = vector<int> (n, -1);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}
	v1--, v2--;
	dfs(v1, v1);
	vector<int> ans;
	while(true)
	{
		ans.pb(v2);
		if(v2 == v1 || v2 == -1)
			break;
		v2 = p[v2];
	}

	if(ans.size() > 0 && ans.back() == -1)
		cout << -1 << endl;
	else
	{
		cout << ans.size() - 1 << endl;
		for(int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] +1 << " ";
	}
	return 0;
}