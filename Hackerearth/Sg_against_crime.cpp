// Problem URL - https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/sg-and-graphs/

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

vii graph[MAXN];
vi tin(MAXN), low(MAXN);
vector<bool> vis(MAXN);
set<int> bridges;
int timer = 0;

void dfs(int s, int p = -1)
{
   vis[s] = true;
   tin[s] = low[s] = timer++;
   for (auto node : graph[s])
   {
      int u = node.first;
      int id = node.second;
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
            bridges.insert(id);
      }
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

   int n, m, q;
   cin >> n >> m >> q;
   for (int i = 0; i < m; ++i)
   {
      int u, v, id;
      cin >> u >> v >> id;
      graph[u].push_back({v, id});
      graph[v].push_back({u, id});
   }
   for (int i = 1; i <= n; ++i)
   {
      if (!vis[i])
         dfs(i);
   }

   while (q--)
   {
      int id;
      cin >> id;
      if (bridges.find(id) == bridges.end())
         cout << "no\n";
      else
         cout << "YES\n";
   }
   return 0;
}