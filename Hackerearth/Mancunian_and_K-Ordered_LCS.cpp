// Problem URL - https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

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
#define MAXN      1000007

const int mod = 1e9 + 7;

vi a, b;

int dp[2002][2002][7];

int solve(int n, int m, int k)
{
   if (n == 0 or m == 0)
      return 0;

   if (dp[n][m][k] != -1)
      return dp[n][m][k];

   if (a[n - 1] == b[m - 1])
   {
      return dp[n][m][k] = max(1 + solve(n - 1, m - 1, k), max(solve(n - 1, m, k), solve(n, m - 1, k)));
   }
   else
   {
      if (k > 0)
         dp[n][m][k] = max(1 + solve(n - 1, m - 1, k - 1), max(solve(n - 1, m, k), solve(n, m - 1, k)));
      else
         dp[n][m][k] = max(solve(n - 1, m, k), solve(n, m - 1, k));

      return dp[n][m][k];
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

   memset(dp, -1, sizeof dp);
   int n, m, k;
   cin >> n >> m >> k;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      a.push_back(x);
   }
   for (int i = 0; i < m; ++i)
   {
      int x;
      cin >> x;
      b.push_back(x);
   }

   cout << solve(n, m, k) << endl;
   return 0;
}