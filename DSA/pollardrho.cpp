#include <bits/stdc++.h>
using namespace std;
#define int       long long int
#define vi        vector<int>
#define vii       vector<pii>
#define pii       pair<int, int>
#define rev(v)    reverse(v.begin(), v.end())
#define all(v)    v.begin(), v.end()
#define rall(v)   v.rbegin(), v.rend()
#define PI        3.14159265359
#define MAXN      1000007

const int mod = 1e9 + 7;

vi spf(1000007);

void sieve()
{
	for (int i = 1; i < 1000007; ++i)
	{
		if (i % 2 == 0)
			spf[i] = 2;
		else
			spf[i] = i;
	}
	for (int i = 3; i * i <= 1000007; ++i)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < 1000007; j += i)
			{
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

int mult(int a, int b, int mod) {
	return (__int128)a * b % mod;
}

int f(int x, int c, int mod) {
	return (mult(x, x, mod) + c) % mod;
}

int rho(int n, int c = 1) {
	int x = 2;
	int y = 2;
	int g = 1;
	while (g == 1) {
		x = f(x, c, n);
		y = f(y, c, n);
		y = f(y, c, n);
		g = __gcd(abs(x - y), n);
	}
	if (g == n)
		return rho(n, c + 1);
	return g;
}

void solve()
{
	int n;
	cin >> n;
	while (spf[n] == 2)
	{
		cout << 2 << endl;
		n /= 2;
	}
	while (n > 1)
	{
		if (spf[n] != n)
		{
			int p = rho(n);
			cout << p << endl;
			n /= p;
		}
		else
		{
			cout << n << endl;
			n = 1;
			break;
		}
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
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; ++i)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}