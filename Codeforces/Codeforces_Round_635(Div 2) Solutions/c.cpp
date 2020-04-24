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
#define PI        3.14159265359
#define MAXN      200007

const int mod = 1e9 + 7;

vi tree[MAXN];
vi sz(MAXN), depth(MAXN);

void dfs(int s, int p = -1, int d = 1)
{
   sz[s] = 1;
   depth[s] = d;
   for (auto u : tree[s])
   {
      if (u == p)
         continue;
      dfs(u, s, d + 1);
      sz[s] += sz[u];
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

   int n, k;
   cin >> n >> k;
   for (int i = 0; i < n - 1; ++i)
   {
      int u, v;
      cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
   }
   dfs(1);

   vi v;
   for (int i = 1; i <= n; ++i)
   {
      v.push_back(sz[i] - depth[i]);
   }
   sort(rall(v));

   int ans = 0;
   for (int i = 0; i < n - k; ++i)
   {
      ans += v[i];
   }
   cout << ans << endl;
   return 0;
}