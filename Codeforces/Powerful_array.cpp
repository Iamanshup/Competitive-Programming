// Problem URL - https://codeforces.com/problemset/problem/86/D

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
#define MAXN      200007

const int mod = 1e9 + 7;

int blk;
int cur_ans = 0;
int freq[1000007];

pair<pii, int> query[MAXN];

int arr[MAXN];
int answer[MAXN];

bool comp(pair<pii, int>& a, pair<pii, int>& b)
{
    if (a.F.F / blk != b.F.F / blk)
        return a.F.F < b.F.F;
    return a.F.S < b.F.S;
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
    blk = sqrt(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> query[i].F.F >> query[i].F.S;
        query[i].F.F--;
        query[i].F.S--;
        query[i].S = i;
    }

    sort(query, query + q, comp);

    int mo_left = 0, mo_right = -1;
    for (int i = 0; i < q; ++i)
    {
        int left = query[i].F.F;
        int right = query[i].F.S;

        while (mo_right < right)
        {
            ++mo_right;
            cur_ans -= freq[arr[mo_right]] * freq[arr[mo_right]] * arr[mo_right];
            freq[arr[mo_right]]++;
            cur_ans += freq[arr[mo_right]] * freq[arr[mo_right]] * arr[mo_right];
        }
        while (mo_right > right)
        {
            cur_ans -= freq[arr[mo_right]] * freq[arr[mo_right]] * arr[mo_right];
            freq[arr[mo_right]]--;
            cur_ans += freq[arr[mo_right]] * freq[arr[mo_right]] * arr[mo_right];
            --mo_right;
        }

        while (mo_left < left)
        {
            cur_ans -= freq[arr[mo_left]] * freq[arr[mo_left]] * arr[mo_left];
            freq[arr[mo_left]]--;
            cur_ans += freq[arr[mo_left]] * freq[arr[mo_left]] * arr[mo_left];
            ++mo_left;
        }
        while (mo_left > left)
        {
            --mo_left;
            cur_ans -= freq[arr[mo_left]] * freq[arr[mo_left]] * arr[mo_left];
            freq[arr[mo_left]]++;
            cur_ans += freq[arr[mo_left]] * freq[arr[mo_left]] * arr[mo_left];
        }

        answer[query[i].S] = cur_ans;
    }

    for (int i = 0; i < q; ++i)
    {
        cout << answer[i] << endl;
    }

    return 0;
}