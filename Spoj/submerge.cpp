// Problem URL - https://www.spoj.com/problems/SUBMERGE/

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
#define MAXN      100007

const int mod = 1e9 + 7;

vi graph[MAXN];
int low[MAXN];
int tin[MAXN];
vector<bool> vis(MAXN);
int timer;
set<int> articulation_points;

void initialize(int n)
{
   articulation_points.clear();
   vis.assign(n + 1, false);
   timer = 0;
   for (int i = 0; i <= n; ++i)
   {
      graph[i].clear();
      low[i] = tin[i] = -1;
   }
}

void dfs(int s, int p = -1)
{
   vis[s] = true;
   tin[s] = low[s] = timer++;
   int children = 0;
   for (auto u : graph[s])
   {
      if (u == p)
         continue;
      if (vis[u])
      {
         low[s] = min(low[s], tin[u]);
      }
      else
      {
         dfs(u, s);
         low[s] = min(low[s], low[u]);
         if (low[u] >= tin[s] and p != -1)
            articulation_points.insert(s);
         ++children;
      }
   }
   if (p == -1 and children > 1)
      articulation_points.insert(s);
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


   int n, m;
   cin >> n >> m;
   while (n != 0 and m != 0)
   {
      initialize(n);

      for (int i = 0; i < m; ++i)
      {
         int u, v;
         cin >> u >> v;
         graph[u].push_back(v);
         graph[v].push_back(u);
      }

      dfs(1);
      cout << articulation_points.size() << endl;
      cin >> n >> m;
   }
   return 0;
}