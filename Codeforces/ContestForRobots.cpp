// https://codeforces.com/contest/1321/problem/A
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

void solve()
{
  int n;
  cin >> n;
  vector<int> r(n), b(n);
  int l = 0, m = 0;

  for (int i = 0; i < n; ++i)
  {
    cin >> r[i];
  }
  for (int i = 0; i < n; ++i)
  {
    cin >> b[i];
    if (b[i] != r[i] and b[i] == 1)
      ++l;
    else if (b[i] != r[i] and r[i] == 1)
      ++m;
  }

  int ans = 1;
  if (m == 0)
    ans = -1;
  else if (l == 0)
    ans = 1;
  else
    ans = l / m + 1;

  cout << ans << endl;
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

  // int tc;
  // cin >> tc;
  // for (int t = 1; t <= tc; ++tc)
  // {
  solve();
  // }

  return 0;
}