// Problem URL - https://codeforces.com/problemset/problem/1324/E

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
#define MAXN      2007

const int mod = 1e9 + 7;

int n, h, l, r;
int dp[MAXN][MAXN], arr[MAXN];

int solve(int idx, int t)
{
	if (idx == n)
		return 0;
	if (dp[idx][t] != -1)
		return dp[idx][t];

	int t1 = (t + arr[idx]) % h;
	int t2 = (t + arr[idx] - 1) % h;

	int &ans = dp[idx][t];
	ans = max(ans, (t1 >= l and t1 <= r) + solve(idx + 1, t1));
	ans = max(ans, (t2 >= l and t2 <= r) + solve(idx + 1, t2));

	return dp[idx][t];
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

	memset(dp, -1, sizeof dp);
	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << solve(0, 0) << endl;
	return 0;
}