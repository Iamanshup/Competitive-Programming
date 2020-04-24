#include <bits/stdc++.h>
using namespace std;
#define int       long long int
#define vi        vector<int>
#define vii       vector<pii>
#define pii       pair<int, int>
#define mii       map<int, int>
#define pb        push_back
#define rev(v)    reverse(v.begin(), v.end())
#define all(v)    v.begin(), v.end()
#define rall(v)   v.rbegin(), v.rend()
#define endl      '\n'
#define F         first
#define S         second
#define PI        3.14159265359
#define MAXN      200007

const int mod = 1e9 + 7;

vector<vi> graph;
vector<vi> dist;

void bfs(int s, int x)
{
	queue<int> q;
	q.push(s);
	dist[x][s] = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto u : graph[node])
		{
			if (dist[x][u] != INT_MAX)
				continue;
			q.push(u);
			dist[x][u] = dist[x][node] + 1;
		}
	}
}

void initialize(int n)
{
	++n;
	graph.clear();
	dist.clear();

	graph.resize(n);
	dist.resize(3, vi(n, INT_MAX));
}

void solve()
{
	int n, m, a, b, c;
	cin >> n >> m >> a >> b >> c;

	initialize(n);
	vi arr(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> arr[i];
	}

	sort(all(arr));

	vi pref(m + 1);
	for (int i = 0; i < m; ++i)
	{
		pref[i + 1] = arr[i] + pref[i];
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs(a, 0);
	bfs(b, 1);
	bfs(c, 2);

	int ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		int pos = dist[0][i] + dist[1][i] + dist[2][i];
		if (pos > m)
			continue;
		ans = min(ans, pref[dist[1][i]] + pref[pos]);
	}

	cout << ans << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; ++i)
	{
		solve();
	}
	return 0;
}