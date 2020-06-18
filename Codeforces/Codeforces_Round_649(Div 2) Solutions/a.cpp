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
	int n, x;
	cin >> n >> x;
	vi arr(n);
	int sum = 0;
	int fac = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] % x == 0)
			++fac;
	}
	if (sum % x != 0)
		cout << n << endl;
	else if (fac == n)
		cout << -1 << endl;
	else
	{
		int l = 0, r = n - 1;
		while (l < n and arr[l] % x == 0)
			++l;
		while (r >= 0 and arr[r] % x == 0)
			--r;
		++l;
		r = n - r;
		cerr << l << ' ' << r << endl;
		cout << n - min(l, r) << endl;
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