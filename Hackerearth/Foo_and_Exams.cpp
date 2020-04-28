// Problem URL - https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/foo-and-exams-4/

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

int a, b, c, d, k;

int foo(int t)
{
    int res = (a * t * t * t) + (b * t * t) + (c * t) + d;
    if (res < 0)
        return k + 1;
    return res;
}

void solve()
{
    cin >> a >> b >> c >> d >> k;
    int l = 0, r = 1e6;
    int ans = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (foo(m) <= k)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
    cerr << foo(ans) << endl;
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