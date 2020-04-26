// Problem URL - https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/p2-2-b370c810/

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

vi graph[MAXN];
vi tin(MAXN), low(MAXN), edge(MAXN);
vector<bool> vis(MAXN);
set<pii> bridges;
int timer = 0;

void dfs(int s, int p = -1)
{
   vis[s] = true;
   tin[s] = low[s] = timer++;
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
         if (tin[s] < low[u])
            bridges.insert({min(u, s), max(u, s)});
      }
   }
}

void dfs2(int s)
{
   vis[s] = true;
   for (auto u : graph[s])
   {
      if (vis[u])
         continue;
      pii pp = {min(s, u), max(s, u)};
      edge[u] = edge[s];
      if (bridges.find(pp) != bridges.end())
         ++edge[u];
      dfs2(u);
   }
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
   for (int i = 0; i < m; ++i)
   {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }
   for (int i = 1; i <= n; ++i)
   {
      if (!vis[i])
         dfs(i);
   }
   vis.assign(n + 1, false);
   dfs2(n);

   int q;
   cin >> q;
   while (q--)
   {
      int s;
      cin >> s;
      if (edge[s])
         cout << edge[s] << endl;
      else
         cout << "impossible\n";
   }
   return 0;
}