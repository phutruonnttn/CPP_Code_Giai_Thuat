#include <bits/stdc++.h>

using namespace std;

long n,a[100007],f[100007],maxx;
vector <long> v;

struct data
{
    long gt,sl;
}t[100007];

data get(long x)
{
    data res;
    res.gt=0; res.sl=0;
    while (x>0)
    {
       if (res.gt<t[x].gt) res=t[x];
        else if (res.gt==t[x].gt)
            {
                res.sl+=t[x].sl;
                if (res.sl>1000000007) res.sl-=1000000007;
            }
       x-=(x&(-x));
    }
    return res;
}

void update(long x, long gt, long sl)
{
    while (x<=maxx+1)
    {
        if (gt>t[x].gt) {t[x].gt=gt; t[x].sl = sl;}
        else if (gt==t[x].gt)
        {
            t[x].sl+=sl;
            if (t[x].sl>1000000007) t[x].sl-=1000000007;
        }
        x+=(x&(-x));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("subseq.inp","r",stdin);
    freopen("subseq.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];

    v.assign(a + 1, a + n + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for (long i=1;i<=n;i++)
         a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;

    maxx=*max_element(a+1,a+n+1);
    a[n+1]=maxx+1;
    data ans;
    for(long i=1; i<=n+1; i++)
    {
        ans=get(a[i]-1);
        f[i]=ans.gt + 1;
        if (ans.sl==0) ans.sl++;
        update(a[i],f[i],ans.sl);
    }
    cout << ans.sl%1000000007;
}
