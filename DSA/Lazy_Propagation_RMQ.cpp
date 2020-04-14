#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ull unsigned long long
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define pll pair<int, int>
#define MOD 1e9 + 7
#define rev(v) reverse(v.begin(), v.end())
#define mem(v, x) memset(v, x, sizeof(v))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define PI 3.14159265359
#define MAXN 1000007

void buildTree(vector<int> &a, vector<int> &segTree, int low, int high, int pos)
{
	if (low == high)
	{
		segTree[pos] = a[low];
		return;
	}
	int mid = low + (high - low) / 2;
	buildTree(a, segTree, low, mid, 2 * pos + 1);
	buildTree(a, segTree, mid + 1, high, 2 * pos + 2);
	segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

int query(vector<int> &segTree, vector<int> &lazyTree, int qlow, int qhigh, int low, int high, int pos)
{
	if (low > high)
		return LONG_MAX;

	if (lazyTree[pos] != 0)
	{
		segTree[pos] += lazyTree[pos];
		if (low != high)
		{
			lazyTree[2 * pos + 1] += lazyTree[pos];
			lazyTree[2 * pos + 2] += lazyTree[pos];
		}
		lazyTree[pos] = 0;
	}

	if (qlow <= low and qhigh >= high) // total,overlap
		return segTree[pos];
	if (qlow > high or qhigh < low) // no overlap
		return LONG_MAX;

	int mid = low + (high - low) / 2;
	return min(query(segTree, lazyTree, qlow, qhigh, low, mid, 2 * pos + 1), query(segTree, lazyTree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
}

void updateTree(vector<int> &a, vector<int> &segTree, vector<int> &lazyTree, int startRange, int endRange, int delta, int low, int high, int pos)
{
	if (low > high)
		return;

	if (lazyTree[pos] != 0)
	{
		segTree[pos] += lazyTree[pos];
		if (low != high)
		{
			lazyTree[2 * pos + 1] += lazyTree[pos];
			lazyTree[2 * pos + 2] += lazyTree[pos];
		}
		lazyTree[pos] = 0;
	}

	if (endRange < low or startRange > high)
		return;

	if (startRange <= low and endRange >= high)
	{
		segTree[pos] += delta;
		if (low != high)
		{
			lazyTree[2 * pos + 1] += delta;
			lazyTree[2 * pos + 2] += delta;
		}
		return;
	}

	int mid = low + (high - low) / 2;

	updateTree(a, segTree, lazyTree, startRange, endRange, delta, low, mid, 2 * pos + 1);
	updateTree(a, segTree, lazyTree, startRange, endRange, delta, mid + 1, high, 2 * pos + 2);

	segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

#undef int
int main()
#define int long long int
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int k = ceil(log2(n));
	int size = 2 * (1 << k) - 1;
	vector<int> segTree(size, LONG_MAX), lazyTree(size, 0);

	buildTree(a, segTree, 0, n - 1, 0);

	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int l, h;
			cin >> l >> h;
			cout << query(segTree, lazyTree, l, h, 0, n - 1, 0) << endl;
		}
		else
		{
			int start, end, val;
			cin >> start >> end >> val;
			updateTree(a, segTree, lazyTree, start, end, val, 0, n - 1, 0);
		}
	}

	return 0;
}