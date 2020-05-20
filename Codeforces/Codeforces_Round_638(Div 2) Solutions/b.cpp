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
	vi arr(n);
	set<int> s;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		s.insert(arr[i]);
	}

	if (s.size() > k)
	{
		cout << "-1\n";
		return;
	}

	cout << k * n << endl;
	for (int i = 0; i < n; ++i)
	{
		for (auto u : s)
			cout << u << ' ';
		for (int i = 0; i < k - s.size(); ++i)
		{
			cout << "1 ";
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

	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; ++i)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}