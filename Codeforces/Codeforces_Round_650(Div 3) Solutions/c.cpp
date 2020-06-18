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
	int n, k;
	cin >> n >> k;
	string arr;
	cin >> arr;

	int ans = 0, tmp = 0;
	if (arr[0] == '0')
		++ans;

	for (int i = 1; i < n; ++i)
	{
		if (arr[i] == '1')
		{
			if (i - tmp <= k)
				--ans;
			tmp = i;
		}
		else
		{
			if (i - tmp > k)
			{
				++ans;
				tmp = i;
			}
		}
	}
	cout << ans << endl;
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
		solve();
	}
	return 0;
}