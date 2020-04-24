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
	int n;
	cin >> n;
	vi arr(n);
	int cnt = 1;
	vi v;
	v.push_back(0);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		if (i > 0)
		{
			if (arr[i] * arr[i - 1] < 0)
			{
				++cnt;
				v.push_back(i);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < v.size() - 1; ++i)
	{
		int mx = INT_MIN, mn = INT_MAX;
		for (int j = v[i]; j < v[i + 1]; ++j)
		{
			mx = max(mx, arr[j]);
		}
		ans += mx;
	}


	int mx = INT_MIN, mn = INT_MAX;
	for (int i = v[v.size() - 1]; i < n; ++i)
	{
		mx = max(mx, arr[i]);
	}

	ans += mx;
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