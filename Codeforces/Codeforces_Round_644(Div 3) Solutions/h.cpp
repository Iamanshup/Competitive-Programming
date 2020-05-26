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
	int n, m;
	cin >> n >> m;
	vi arr(n);
	map<int, bool> mp;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		int tmp = 0;
		for (auto u : s)
		{
			tmp = tmp * 2 + (u - '0');
		}
		arr[i] = tmp;
	}

	int ans = ((1ll << m) - 1) / 2;

	int tmp = 1ll << m;
	for (auto u : arr)
	{
		mp[u] = true;
		if (tmp & 1)
		{
			if (u >= ans)
			{
				--ans;
				while (mp[ans])
					--ans;
			}
		}
		else
		{
			if (u <= ans)
			{
				++ans;
				while (mp[ans])
					++ans;
			}
		}
		--tmp;
	}

	string s = "";
	while (ans)
	{
		int r = ans % 2;
		s = to_string(r) + s;
		ans /= 2;
	}
	while (s.length() < m)
		s = "0" + s;
	cout << s << endl;
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