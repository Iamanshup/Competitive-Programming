// Problem URL - https://www.spoj.com/problems/EC_P/

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
#define MAXN      1007

const int mod = 1e9 + 7;

vi graph[MAXN];
vi low(MAXN), tin(MAXN);
vector<bool> vis(MAXN);
set<pii> bridges;
int timer;

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

void initialize(int n)
{
   timer = 0;
   vis.assign(n + 1, false);
   low.assign(n + 1, -1);
   tin.assign(n + 1, -1);
   bridges.clear();
   for (int i = 0; i <= n; ++i)
   {
      graph[i].clear();
   }
}

void solve()
{
   int n, m;
   cin >> n >> m;
   initialize(n);

   for (int i = 0; i < m; ++i)
   {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }
   dfs(1);

   if (bridges.size() == 0)
      cout << "Sin bloqueos\n";
   else
      cout << bridges.size() << endl;

   vii ans;
   for (auto u : bridges)
   {
      ans.push_back(u);
   }
   sort(all(ans));
   for (auto u : ans)
   {
      cout << u.F << ' ' << u.S << endl;
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

   int tc;
   cin >> tc;
   for (int i = 1; i <= tc; ++i)
   {
      cout << "Caso #" << i << endl;
      solve();
   }
   return 0;
}