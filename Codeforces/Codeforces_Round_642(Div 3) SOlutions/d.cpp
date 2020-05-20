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
	vi ans(n + 1, 0);
	priority_queue<pair<int, pii>> q;
	q.push({n, { -1, n}});

	int tmp = 0;
	while (!q.empty())
	{
		++tmp;
		pair<int, pii> p = q.top();
		q.pop();
		int l = -p.S.F;
		int r = p.S.S;
		int sz = p.F;

		if (l > r)
			continue;

		if (sz == 1)
		{
			ans[l] = tmp;
			continue;
		}

		int mid;
		if ((r - l + 1) & 1)
		{
			mid = (l + r) / 2;
			ans[mid] = tmp;
		}
		else
		{
			mid = (l + r - 1) / 2;
			ans[mid] = tmp;
		}
		q.push({mid - l + 1, { -l, (mid - 1)}});
		q.push({r - mid + 1, { -(mid + 1), r}});
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
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