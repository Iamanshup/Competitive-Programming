// Problem URL - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/shivam-and-expensive-birthday-gift-da58b2f0/description/

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

vi tree(4 * MAXN, 0);

void update(int l, int h, int idx, int type, int p)
{
  if (l == h)
  {
    if (type == 1)
    {
      tree[p]++;
    }
    else
    {
      if (tree[p] == 0)
        return;
      tree[p]--;
    }
    return;
  }

  int m = l + (h - l) / 2;
  if (idx <= m)
    update(l, m, idx, type, 2 * p + 1);
  else
    update(m + 1, h, idx, type, 2 * p + 2);
  tree[p] = tree[2 * p + 1] + tree[2 * p + 2];
}

int query(int l, int h, int ql, int qh, int p)
{
  if (ql > h or qh < l)
    return 0;
  if (ql <= l and qh >= h)
    return tree[p];

  int m = l + (h - l) / 2;
  return query(l, m, ql, qh, 2 * p + 1) + query(m + 1, h, ql, qh, 2 * p + 2);
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

  int n, q;
  cin >> n >> q;
  while (q--)
  {
    int type, x, y;
    cin >> type >> x;
    --x;
    if (type != 3)
      update(0, n - 1, x, type, 0);
    else
    {
      cin >> y;
      --y;
      cout << query(0, n - 1, x, y, 0) << endl;
    }
  }
  return 0;
}