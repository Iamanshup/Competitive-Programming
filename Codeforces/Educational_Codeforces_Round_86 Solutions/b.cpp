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
	string s;
	cin >> s;
	string ans = "";
	int n = s.length();

	string tmp = s;
	sort(all(tmp));
	if (tmp[0] == tmp[n - 1] or n <= 2)
	{
		cout << s << endl;
		return;
	}

	if (s[0] == '0')
		ans = "1";
	for (int i = 0; i < n - 1; ++i)
	{
		ans += s[i];
		if (i < n - 1)
		{
			if (s[i] == s[i + 1])
			{
				if (s[i] == '1')
					ans += '0';
				else
					ans += '1';
			}
		}
	}
	if (ans.size() == 0)
		ans = s;
	else
		ans += s[n - 1];
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
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}