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

int n;
vector<string> arr(100);
int valid[100][100];

bool checkx(int i, int j)
{
	if (i == n - 1)
	{
		return valid[i][j] = (arr[i][j] == '1');
	}

	if (arr[i][j] == '0')
	{
		return valid[i][j] = false;
	}

	if (valid[i][j])
		return true;

	return valid[i][j] = checkx(i + 1, j);
}

bool checky(int i, int j)
{
	if (arr[i][j] == '0')
	{
		return valid[i][j] = false;
	}

	if (j == n - 1)
	{
		return valid[i][j] = (arr[i][j] == '1');
	}

	if (valid[i][j])
		return true;

	return valid[i][j] = checkx(i, j + 1);
}

void solve()
{
	cin >> n;
	memset(valid, false, sizeof valid);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	bool f = false;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (arr[i][j] == '1' and (arr[i + 1][j] != '1' && arr[i][j + 1] != '1'))
				f = true;
		}
	}
	if (f)
		cout << "NO\n";
	else
		cout << "YES\n";
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