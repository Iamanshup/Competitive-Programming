// Problem URL - https://codeforces.com/problemset/problem/208/D

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
#define MAXN      1000007

const int mod = 1e9 + 7;

int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vi arr(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }
  vii prize(5);
  vi ans(5);
  for (int i = 0; i < 5; ++i)
  {
    cin >> prize[i].F;
    prize[i].S = i;
  }
  sort(rall(prize));

  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += arr[i];
    for (int j = 0; j < 5; ++j)
    {
      if (sum >= prize[j].F)
      {
        ans[prize[j].S] += sum / prize[j].F;
        sum %= prize[j].F;
      }
    }
  }

  for (int i = 0; i < 5; ++i)
  {
    cout << ans[i] << ' ';
  }
  cout << endl;
  cout << sum << endl;
  return 0;
}