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

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	cin >> n >> s;

	if (n == 1 and s == 1)
	{
		cout << "NO";
		return 0;
	}
	if (n == 1)
	{
		cout << "YES\n" << s << endl << s - 1 << endl;
		return 0;
	}

	unordered_map<int, bool> mp;
	vi arr(n, 1);
	arr[n - 1] = s - (n - 1);
	mp[1] = true;

	for (int i = 1; i < n; ++i)
	{
		mp[i] = true;
		mp[s - i] = true;
		arr[i] += arr[i - 1];
		mp[arr[i]] = true;
		mp[s - arr[i]] = true;
	}

	int temp = 1;
	for (int i = 1; i <= s; ++i)
	{
		if (!mp[i])
		{
			cout << "YES\n";
			for (int i = 0; i < n - 1; ++i)
			{
				cout << "1 ";
			}
			cout << s - (n - 1) << endl;
			cout << i << endl;
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}