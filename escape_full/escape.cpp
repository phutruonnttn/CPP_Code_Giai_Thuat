
//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "escape"
#define maxn 105
#define maxm 10005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int n, m, xs, ys, xt = -1, yt, dem = 0;
char a[maxn][maxn];
pii q[maxm];
bool dd[maxn][maxn];
int px[maxm], py[maxm];
int tr[maxn][maxn];

void Read()
{
    cin >> m >> n;
    for (int i = 1; i <= m ; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'E')
                xs = i, ys = j;
        }
}

void BFS()
{
    int l, r;
    l = r = 1;
    q[1] = make_pair(xs,ys);
    while (l <= r)
    {
        int ux = q[l].first;
        int uy = q[l++].second;
        for (int i = 0; i < 4; i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if (vx == 0 || vx > m || vy ==0 || vy > n)
            {
                xt = ux;
                yt = uy;
                return;
            }
            if (a[vx][vy] != '.' || dd[vx][vy]) continue;
            q[++r] = make_pair(vx,vy);
            dd[vx][vy] = 1;
            tr[vx][vy] = i;
        }
    }
}

void Calc()
{
    BFS();
    if (xt == -1)
    {
        cout << "NO";
        return;
    }

    while (xt != xs || yt != ys)
    {
        px[++dem] = xt;
        py[dem] = yt;
        int h = tr[xt][yt];
        xt -= dx[h];
        yt -= dy[h];
    }
}

void Write()
{
    if (xt == -1) return;
    cout << "YES\n";
    cout << xs << " " << ys <<endl;
    for (int i = dem; i >= 1; i--)
        cout << px[i] << " " << py[i] <<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    Read();
    Calc();
    Write();

    return 0;
}



