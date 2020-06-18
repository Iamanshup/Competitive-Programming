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
	vector<vi> arr(n, vi(m));

	vi v1(m + n - 1, 0);
	vi v2(m + n - 1, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				v1[i + j]++;
			else
				v2[i + j]++;
		}
	}

	int tmp = (m + n - 2) / 2;
	int t1 = 0;
	int t2 = 0;
	int total = 0;
	for (int i = 0; i <= tmp; i++)
	{
		if (i == tmp && (m + n) % 2 == 0)
			continue;
		t1 = v1[i] + v1[n + m - 2 - i];
		t2 = v2[i] + v2[n + m - 2 - i];
		total += min(t1, t2);
	}
	cout << total << endl;
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