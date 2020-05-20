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

void solve()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	for (int i = a; i <= b; ++i)
	{
		int x = i;
		int z = d;
		int y = -1;

		int lz = c, rz = d;
		while (lz <= rz)
		{
			int mz = lz + (rz - lz) / 2;
			y = -1;
			int l = b, r = c;
			while (l <= r)
			{
				int m = l + (r - l) / 2;
				if (x + m > mz)
				{
					y = m;
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}

			if (y >= b and y <= c)
			{
				z = mz;
				lz = mz + 1;
			}
			else
			{
				rz = mz - 1;
			}
		}

		int l = b, r = c;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (x + m > z)
			{
				y = m;
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}

		if (y == -1)
			continue;
		ans += ((y - b + 1) * (min(d, z) - c + 1));
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

	int tc = 1;
	// cin >> tc;
	for (int i = 1; i <= tc; ++i)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}