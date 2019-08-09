#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long di, ca;
};

long long n,m,k,dinh[nmax],duong[nmax],slt,sd[nmax];
vector <long long> a[nmax];
bool dd[nmax];
data vung[nmax];

void dfs(long long u)
{
    dd[u]=true;
    for (long long i=0; i<a[u].size(); i++)
    {
        long long v=a[u][i];
        duong[slt]++;
        if (!dd[v]) {dinh[slt]++;dfs(v);}
    }
}

bool comp(data q, data p)
{
    if (q.di != p.di) return q.di > p.di;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("REGIONS.inp","r",stdin);
    freopen("REGIONS.out","w",stdout);
    cin >> n >> m >> k;
    for (long long i=1; i<=m; i++)
    {
        long long u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    sd[1]=0;
    for (long long i=2; i<=n; i++)
        sd[i]=sd[i-1]+i-1;
    memset(dd,false,sizeof(dd));
    slt=0;
    for (long long i=1; i<=n; i++)
    if (!dd[i]) {slt++; dfs(i);}

    long long maybe=0;

    for (long long i=1; i<=slt; i++)
    {
        duong[i]/=2;
        dinh[i]++;
        vung[i].di=dinh[i];
        vung[i].ca=duong[i];
        maybe+=sd[dinh[i]]-duong[i];
        //cout << dinh[i] << " " << duong[i] << " " << maybe << endl;
    }

    sort(vung+1,vung+slt+1,comp);

    long long ans1,ans2;
    if (k>=slt) ans1=1;
    else ans1=slt-k;

    //cout << maybe << endl;

    if (k<=maybe) ans2=slt;
    else
    {
        ans2=slt;
        k-=maybe;
        //cout << k <<endl;
        long long dq=vung[1].di;
        for (long long i=2; i<=slt; i++)
        {
            long long noi=dq*vung[i].di;
            if (noi>=k)
            {
                ans2--;
                break;
            }
            else
            {
                ans2--;
                k-=noi;
            }
            dq+=vung[i].di;
        }
    }

    cout << ans1 << " " << ans2;
}
