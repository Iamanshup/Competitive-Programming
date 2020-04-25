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
#define MAXN      2005

const int mod = 1e9 + 7;

int n, k;
vector<string> arr(MAXN);

int changes[MAXN][10];
int dp[MAXN][MAXN];

int solve(int idx, int steps)
{
	if (idx == n)
	{
		if (steps == 0)
		{
			return dp[idx][steps] = 1;
		}
		return dp[idx][steps] = 0;
	}

	if (dp[idx][steps] != -1)
		return dp[idx][steps];

	int mx = 0;
	for (int i = 9; i >= 0; --i)
	{
		int cnt = changes[idx][i];
		if (cnt >= 0 and cnt <= steps)
			mx = max(mx, solve(idx + 1, steps - cnt));
	}
	return dp[idx][steps] = mx;
}

string getAns(int idx, int steps)
{
	if (idx == n or steps < 0)
		return "";

	for (int i = 9; i >= 0; --i)
	{
		int cnt = changes[idx][i];
		if (cnt >= 0 and cnt <= steps and dp[idx + 1][steps - cnt] == 1)
		{
			return to_string(i) + getAns(idx + 1, steps - cnt);
		}
	}
	return "";
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

	vector<string> digit = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

	cin >> n >> k;

	for (int ind = 0; ind < n; ++ind)
	{
		cin >> arr[ind];
		for (int i = 0; i < 10; ++i)
		{
			int cnt = 0;
			string s1 = digit[i];
			string s2 = arr[ind];
			for (int j = 0; j < 7; ++j)
			{
				if (s2[j] == '0' && s1[j] == '1')
					++cnt;
				else if (s2[j] == '1' && s1[j] == '0')
				{
					cnt = -1;
					break;
				}
			}
			changes[ind][i] = cnt;
		}
	}

	int val = solve(0, k);

	string ans = getAns(0, k);
	if (ans.size() == 0)
		cout << "-1";
	else
		cout << ans;

	return 0;
}