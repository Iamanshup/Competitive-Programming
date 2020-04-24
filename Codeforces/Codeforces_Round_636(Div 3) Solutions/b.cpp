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
	vi arr(n + 1);
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n / 2; ++i)
	{
		arr[i] = 2 * i;
		s1 += arr[i];
	}

	for (int i = 1; i <= n / 2; ++i)
	{
		arr[i + n / 2] = 2 * i - 1;
		s2 += arr[i + n / 2];
	}

	while (s2 < s1)
	{
		arr[n] += 2;
		s2 += 2;
	}

	if (s2 != s1)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = 1; i <= n; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
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