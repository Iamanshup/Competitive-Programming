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
	int a[9][9];
	for (int i = 0; i < 9; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 9; ++j)
		{
			int n = s[j] - '0';
			a[i][j] = n;
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		int id = 3 * (i % 3) + i / 3;
		if (a[i][id] == 9)
			a[i][id] = 1;
		else
			a[i][id]++;
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << a[i][j];
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