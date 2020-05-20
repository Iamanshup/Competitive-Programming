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
#define MAXN      100007

const int mod = 1e9 + 7;

vi arr(MAXN), tree(4 * MAXN);

void build(int l, int h, int p)
{
	if (l == h)
	{
		tree[p] = l;
		return;
	}

	int m = l + (h - l) / 2;
	build(l, m, p << 1);
	build(m + 1, h, (p << 1) | 1);
	tree[p] = arr[tree[p << 1]] > arr[tree[(p << 1) | 1]] ? tree[p << 1] : tree[(p << 1) | 1];
}

void update(int l, int h, int idx, int val, int p)
{
	if (l == h)
	{
		arr[l] = val;
		return;
	}

	int m = l + (h - l) / 2;
	if (idx <= m)
		update(l, m, idx, val, p << 1);
	else
		update(m + 1, h, idx, val, (p << 1) | 1);
	tree[p] = arr[tree[p << 1]] > arr[tree[(p << 1) | 1]] ? tree[p << 1] : tree[(p << 1) | 1];
}

int query(int l, int h, int ql, int qh, int p)
{
	if (ql > h or qh < l)
		return 0;
	if (ql <= l and qh >= h)
		return tree[p];

	int m = l + (h - l) / 2;
	int left = query(l, m, ql, qh, p << 1);
	int right = query(m + 1, h, ql, qh, (p << 1) | 1);

	return arr[left] > arr[right] ? left : right;
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

	arr[0] = INT_MIN;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	build(1, n, 1);

	int q;
	cin >> q;
	while (q--)
	{
		char type;
		int x, y;
		cin >> type >> x >> y;
		if (type == 'U')
			update(1, n, x, y, 1);
		else
		{
			int id1 = query(1, n, x, y, 1);
			int id2 = query(1, n, x, id1 - 1, 1);
			int id3 = query(1, n, id1 + 1, y, 1);

			cout << arr[id1] + max(arr[id2], arr[id3]) << endl;
		}
	}
	return 0;
}