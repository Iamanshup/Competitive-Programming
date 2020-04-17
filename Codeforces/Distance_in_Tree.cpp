// Problem URL - https://codeforces.com/problemset/problem/161/D

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
#define MAXN      50007

const int mod = 1e9 + 7;

vi tree[50005];
int dp[50005][505];
int n, k;
int ans = 0;

void dfs(int node, int par = -1)
{
   dp[node][0] = 1;
   for (auto child : tree[node])
   {
      if (child == par)
         continue;
      dfs(child, node);

      for (int i = 1; i <= k; ++i)
      {
         ans += (dp[node][k - i] * dp[child][i - 1]);
      }
      for (int i = 1; i <= k; ++i)
      {
         dp[node][i] += dp[child][i - 1];
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

   memset(dp, 0, sizeof dp);
   cin >> n >> k;
   for (int i = 0; i < n - 1; ++i)
   {
      int u, v;
      cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
   }
   dfs(1);
   cout << ans << endl;
   return 0;
}