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
	int n;
	cin >> n;
	vi arr(n);
	int o = 0, e = 0;
	map<int, bool> mp;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		mp[arr[i]] = true;
		if (arr[i] & 1)
			++o;
		else
			++e;
	}
	if ((e & 1) != (o & 1))
	{
		cout << "NO\n";
		return;
	}
	if (e % 2 == 0 and o % 2 == 0)
	{
		cout << "YES\n";
		return;
	}

	sort(all(arr));
	for (int i = 0; i < n - 1; ++i)
	{
		if ((arr[i] & 1) != (arr[i + 1] & 1))
		{
			if (arr[i] + 1 == arr[i + 1])
			{
				cout << "YES\n";
				return;
			}
		}
	}
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