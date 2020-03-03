// https://codeforces.com/contest/189/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ull unsigned long long
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define pll pair<int, int>
#define MOD 1e9 + 7
#define rev(v) reverse(v.begin(), v.end())
#define mem(v, x) memset(v, x, sizeof(v))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define PI 3.14159265359
#define MAXN 1000007

vector<int> dp(MAXN, 0);
int n, a, b, c;

int solve(int n)
{
  if (n == 0)
    return 0;
  if (n < 0 or (n < a and n < b and n < c))
    return -1;

  if (dp[n])
    return dp[n];

  if (solve(n - a) == -1 and solve(n - b) == -1 and solve(n - c) == -1)
    return dp[n] = -1;

  if (!dp[n])
    return dp[n] = max(solve(n - a), max(solve(n - b), solve(n - c))) + 1;

  return dp[n];
}

#undef int
int main()
#define int long long int
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> a >> b >> c;
  cout << solve(n) << endl;

  return 0;
}