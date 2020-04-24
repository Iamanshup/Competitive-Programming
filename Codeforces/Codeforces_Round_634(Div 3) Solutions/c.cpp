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
	vi a(n);
	mii mp;
	int g2 = 0;
	vi v;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		++mp[a[i]];
		g2 = max(g2, mp[a[i]]);
	}

	int g1 = mp.size() - 1;

	if (abs(g2 - g1) <= 1)
	{
		cout << min(g2, g1) << endl;
		return;
	}

	if (g1 < g2)
	{
		cout << g1 + 1 << endl;
	}
	else
	{
		cout << g2 << endl;
	}
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