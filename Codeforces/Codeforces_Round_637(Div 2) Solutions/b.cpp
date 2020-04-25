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
	int n, k;
	cin >> n >> k;
	vi arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	vi v(n, 0);
	for (int i = 1; i < n - 1; ++i)
	{
		if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
		{
			v[i] = 1;
		}
	}

	vi pref(n);
	for (int i = 1; i < n; ++i)
	{
		pref[i] = v[i] + pref[i - 1];
	}

	int mx = pref[k - 2];
	int idx = 0;
	for (int i = 1; i <= n - k; ++i)
	{
		int sum = pref[i + k - 2] - pref[i];

		if (sum > mx)
		{
			mx = sum;
			idx = i;
		}
	}

	cout << mx + 1 << ' ' << idx + 1 << endl;
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