#include<bits/stdc++.h>
#define nmax 500005
#define Task "blo"
#define ll long long

using namespace std;

typedef pair< int, int > ii;

long long sl[nmax], num[nmax], low[nmax], cnt, par[nmax], b[nmax], ss[nmax];
int n, m, sz, sum;
bool mark[nmax], dd[nmax];

vector < int > a[nmax], child[nmax], son[nmax];

void Nhap()
{
     ios_base::sync_with_stdio(0);
     cin.tie(NULL);
     cout.tie(NULL);
     freopen(Task".inp", "r", stdin);
     freopen(Task".out", "w", stdout);

     cin >> n >> m;
     for (int i = 1; i <= m; i++)
     {
         int u, v;
         cin >> u >> v;
         a[u].push_back(v);
         a[v].push_back(u);
     }
}

void DFS(int u, int p)
{
    par[u] = p;
    num[u] = low[u] = ++cnt;
    sl[u] = 1;
    int dem = 0;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if  (v == p) continue;
        if (num[v]==0)
        {
            DFS(v, u);
            son[u].push_back(v);
            dem++;
            sl[u] += sl[v];
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u])
            {
                mark[u] = true;
                child[u].push_back(v);
            }
        }
        else
            low[u] = min(low[u], num[v]);
    }
    if (dem < 2 && p==0) mark[u] = false;
}

int main()
{
    Nhap();

    cnt = 0;

    DFS(1,0);

    for (int i = 1; i <= n; i++)
         if (!mark[i])
    {
        cout << 2*(n-1) << '\n';
    }
    else
    {
        if (par[i] == 0)
        {
            long long ans = 0;
            for (int j = 0; j < son[i].size(); j++)
            {
                int u = sl[son[i][j]];
                ans = (ans + (ll)(n - u)*u);
            }
            ans += n - 1;
            cout << ans << '\n';
            continue;
        }
        long long ans = 0, sum = 0, sz =0;
        for (int j = 0; j < child[i].size(); j++)
        {
            int u = sl[child[i][j]];
            b[++sz] = u;
            sum += u;
        }
        b[++sz] = 1; b[++sz] = n - sum - 1;
        for (int j = 1; j <= sz; j++)
            ans = (ans + (ll)(n - b[j])*b[j]);
        cout << ans << '\n';
    }
}
