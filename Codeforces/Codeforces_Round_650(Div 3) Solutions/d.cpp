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
	string s;
	cin >> s;
	int n;
	cin >> n;
	vi arr(n);
	string ans(n, '?');
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vi mp(26, 0);
	for (auto u : s)
	{
		mp[u - 'a']++;
	}

	int j = 25;
	while (true)
	{
		vi v;
		for (int i = 0; i < n; ++i)
		{
			if (ans[i] != '?')
				continue;
			if (arr[i] == 0)
			{
				v.push_back(i);
			}
		}
		if (!v.size()) break;
		char ch;
		for (; j >= 0; --j)
		{
			if (mp[j] >= v.size())
			{
				ch = 'a' + j;
				--j;
				break;
			}
		}
		for (auto u : v)
		{
			ans[u] = ch;
		}
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] == 0)
				continue;
			for (auto u : v)
			{
				arr[i] -= abs(i - u);
			}
		}
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