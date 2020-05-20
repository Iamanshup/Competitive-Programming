#include <bits/stdc++.h>
using namespace std;
#define FIO                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define pll pair<ll, ll>
#define MOD 1e9 + 7
#define rev(v) reverse(v.begin(), v.end())
#define mem(v, x) memset(v, x, sizeof(v))
#define all(v) v.begin(), v.end()
#define rep(x, a, n, b) for (x = a; x <= n; x += b)
#define rept(x, a, n, b) for (x = a; x >= n; x -= b)
#define PI 3.14159265359

ll findMedian(vector<ll> &a, vector<ll> &b)
{
  int x = a.size();
  int y = b.size();

  if (x > y)
    return findMedian(b, a);

  int low = 0;
  int high = x;

  while (low <= high)
  {
    int partitionX = (low + high) / 2;
    int partitionY = (x + y + 1) / 2 - partitionX;

    ll maxLeftX = (partitionX == 0) ? INT_MIN : a[partitionX - 1];
    ll minRightX = (partitionX == x) ? INT_MAX : a[partitionX];

    ll maxLeftY = (partitionX == 0) ? INT_MIN : b[partitionY - 1];
    ll minRightY = (partitionX == y) ? INT_MAX : b[partitionY];

    if (maxLeftX <= minRightY and maxLeftY <= minRightX)
    {
      if ((x + y) % 2 == 1)
        return max(maxLeftX, maxLeftY);
      else
        return ((max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2);
    }
    else if (maxLeftX > minRightY)
      high = partitionX - 1;
    else
      low = partitionX + 1;
  }
}

void solve()
{
  ll m, n;
  cin >> m >> n;

  vector<ll> a(m, 0), b(n, 0);
  for (int i = 0; i < m; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  ll ans = findMedian(b, a);

  cout << ans << endl;
}

int main()
{
  // freopen("in", "r", stdin);
  // freopen ("out", "w", stdout);
  FIO;
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++)
  {
    // cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}