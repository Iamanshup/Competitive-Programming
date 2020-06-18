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
#define MAXN      10000007

const int mod = 1e9 + 7;

vi spf(MAXN);
void sieve()
{
	iota(all(spf), 0);
	for (int i = 2; i * i <= MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < MAXN; j += i)
			{
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

pii getAns(int n)
{
	vi v;
	while (n != 1)
	{
		int p = spf[n];
		v.pb(p);
		while (spf[n] == p)
		{
			n = n / spf[n];
		}
	}
	if (v.size() < 2) return { -1, -1};
	int p = 1;
	for (int i = 1; i < v.size(); ++i)
		p *= v[i];
	return {v[0], p};
}

void solve()
{
	int n;
	cin >> n;
	vi arr(n);
	vii ans(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		ans[i] = getAns(arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans[i].F << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i].S << ' ';
	}
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

	sieve();
	int tc = 1;
	for (int i = 1; i <= tc; ++i)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}