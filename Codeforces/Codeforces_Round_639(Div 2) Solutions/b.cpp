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

int go(int n)
{
	n *= 2;
	int res = 0;
	int l = 1, r = 1e9;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (m * (3 * m + 1) <= n)
		{
			res = m;
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return res;
}

void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	while (n >= 2)
	{
		int tmp = go(n);
		// cerr << tmp << ' ';
		++ans;
		n -= ((tmp * (3 * tmp + 1)) / 2);
	}
	// cerr << endl;
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