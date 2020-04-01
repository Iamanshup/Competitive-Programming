#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ull unsigned long long
#define pll pair<int, int>
#define rev(v) reverse(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define PI 3.14159265359
#define MAXN 1007

const int mod = 1e9 + 7;

vector<int> tree[MAXN];
vector<int> level(MAXN);

void preprocess(vector<int>& T, vector<vector<int>>& P, int n)
{
   for (int j = 0; 1 << j < n; ++j)
   {
      for (int i = 1; i <= n; ++i)
      {
         if (j == 0)
         {
            P[i][j] = T[i];
         }
         else
         {
            if (P[i][j - 1] != -1)
               P[i][j] = P[P[i][j - 1]][j - 1];
         }
      }
   }
}

int lca(vector<int>& T, vector<vector<int>>& P, int u, int v)
{
   if (level[u] < level[v])
      swap(u, v);
   int log = log2(u);

   for (int i = log; i >= 0; --i)
   {
      if (level[u] - (1 << i) >= level[v])
      {
         u = P[u][i];
      }
   }

   if (u == v)
      return u;

   for (int i = log; i >= 0; --i)
   {
      if (P[u][i] != -1 && P[u][i] != P[v][i])
      {
         u = P[u][i];
         v = P[v][i];
      }
   }

   return T[u];
}

void dfs(int s, int l = 0)
{
   level[s] = l;
   for (auto u : tree[s])
      dfs(u, l + 1);
}

void solve()
{
   int n;
   cin >> n;
   for (int i = 0; i <= n; ++i)
   {
      tree[i].clear();
      level[i] = 0;
   }
   vector<int> T(n + 1);
   vector<vector<int>> P(n + 1, vector<int>(log2(n) + 1, -1));
   for (int i = 1; i <= n; ++i)
   {
      int m;
      cin >> m;
      for (int j = 0; j < m; ++j)
      {
         int x;
         cin >> x;
         tree[i].push_back(x);
         T[x] = i;
      }
   }
   int root;
   for (int i = 1; i <= n; ++i)
   {
      if (T[i] == 0)
      {
         root = i;
         break;
      }
   }
   dfs(root);  // find level of each node
   preprocess(T, P, n);
   int q;
   cin >> q;
   while (q--)
   {
      int u, v;
      cin >> u >> v;
      cout << lca(T, P, u, v) << endl;
   }
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
      cout << "Case " << i << ":\n";
      solve();
   }
   return 0;
}