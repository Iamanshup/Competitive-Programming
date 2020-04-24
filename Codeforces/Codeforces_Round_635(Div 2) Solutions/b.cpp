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
	int x, n, m;
	cin >> x >> n >> m;

	while (true)
	{
		if (x <= 0 or n == 0)
			break;
		if (x / 2 + 10 < x)
		{
			x = x / 2 + 10;
			--n;
		}
		else break;
	}

	while (m--)
	{
		x -= 10;
	}
	// while ((n > 0 or m > 0) and x > 0)
	// {
	// 	int va = x / 2 + 10;
	// 	int ls = x - 10;
	// 	if (va < ls and n > 0)
	// 	{
	// 		x = va;
	// 		--n;
	// 	}
	// 	else if (va >= ls and m > 0)
	// 	{
	// 		x = ls;
	// 		--m;
	// 	}
	// }
	if (x <= 0)
		cout << "YES\n";
	else
		cout << "NO\n";
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