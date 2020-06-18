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
	vi a(MAXN), pos(MAXN), used(MAXN);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pos[a[i]]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] - 1 >= i)
		{
			cout << "-1\n";
			return;
		}
	}
	int p = 0;
	vi ans;
	queue<int> rem;
	for (int i = 0; i <= n; ++i)
	{
		if (pos[i] == 0) continue;

		while (pos[i])
		{
			if (rem.size())
			{
				pos[i]--;
				ans.pb(rem.front());
				used[rem.front()]++;
				rem.pop();
				continue;
			}
			while (pos[p] or used[p]) p++;
			used[p]++;
			ans.pb(p++);
			pos[i]--;
		}
		rem.push(i);
	}
	for (auto it : ans) cout << it << " ";
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

	int tc = 1;
	// cin >> tc;
	for (int i = 1; i <= tc; ++i)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}