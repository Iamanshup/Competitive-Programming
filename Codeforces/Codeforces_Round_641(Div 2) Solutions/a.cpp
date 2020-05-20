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

vi spf(MAXN, 0);

void sieve()
{
	for (int i = 0; i < MAXN; ++i)
	{
		if (i & 1)
			spf[i] = i;
		else
			spf[i] = 2;
	}

	for (int i = 3; i * i <= MAXN; ++i)
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

void solve()
{
	int n, k;
	cin >> n >> k;
	while (k--)
	{
		if (spf[n] == 2)
		{
			n += (2 * (k + 1));
			break;
		}
		n += spf[n];
	}
	cout << n << endl;
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
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; ++i)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}