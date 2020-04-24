// Problem URL - https://codeforces.com/problemset/problem/5/C

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

   string s;
   cin >> s;
   int n = s.length();
   stack<int> st;
   st.push(-1);
   int ans1 = 0, ans2 = 1;

   for (int i = 0; i < n; ++i)
   {
      if (s[i] == '(')
      {
         st.push(i);
      }
      else
      {
         st.pop();
         if (!st.empty())
         {
            if (ans1 < i - st.top())
            {
               ans1 = i - st.top();
               ans2 = 1;
            }
            else if (ans1 == i - st.top())
            {
               ++ans2;
            }
         }
         else
         {
            st.push(i);
         }
      }
   }

   cout << ans1 << ' ' << ans2 << endl;
   return 0;
}