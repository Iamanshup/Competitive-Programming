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

void solve()
{
   int n, k;
   cin >> n >> k;
   vi arr(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
   }

   vii v;
   mii cnt;
   vi pref(2 * k + 10, 0);

   for (int i = 0; i < n / 2; ++i)
   {
      cnt[arr[i] + arr[n - i - 1]]++;

      int l = min(arr[i], arr[n - i - 1]) + 1;
      int r = max(arr[i], arr[n - i - 1]) + k;
      v.push_back({l, r});

      pref[l] += 1;
      pref[r + 1] -= 1;
   }

   for (int i = 1; i < 2 * k + 1; ++i)
   {
      pref[i] += pref[i - 1];
   }

   int ans = n;
   for (int i = 2; i <= 2 * k; ++i)
   {
      int cnt0 = cnt[i];
      int cnt1 = pref[i] - cnt0;
      int cnt2 = n / 2 - pref[i];

      ans = min(ans, cnt1 + (2 * cnt2));
   }

   cout << ans << endl;
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
      // cout << "Case #" << i << ": ";
      solve();
   }
   return 0;
}