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
	vector<string> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	vector<string> s;
	for (int i = 0; i < m; ++i)
	{
		string tmp = arr[0];
		for (int j = 0; j < 26; ++j)
		{
			tmp[i] = 'a' + j;
			s.push_back(tmp);
		}
	}

	string ans = "-1";
	for (auto u : s)
	{
		int c1 = 0;
		for (int i = 0; i < n; ++i)
		{
			int c2 = 0;
			for (int j = 0; j < m; ++j)
			{
				if (u[j] != arr[i][j])
					++c2;
			}
			if (c2 > 1)
				++c1;
		}
		if (c1 == 0)
		{
			ans = u;
			break;
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