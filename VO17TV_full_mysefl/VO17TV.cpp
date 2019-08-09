#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
const long long b=727, m=1000000007, m2=m*m;

struct data
{
    long long w,vt;
};

long long n,k,maxl=-1,h[nmax],hashs[nmax],pos[nmax],vtri[nmax];
data bam[nmax];
string s[60],ss;
bool dd[57];

long long get(long l, long r)
{
    return ((hashs[r]-hashs[l-1]*h[r-l+1]+m2) % m);
}

bool comp(data a, data b)
{
    return a.w < b.w;
}

bool ktra(long d)
{
    long long dem=0;
    for (long i=1; i<=n; i++)
       for (long j=vtri[i-1]; j<=vtri[i]-d; j++)
       {
           bam[++dem].w=get(j,j+d-1);
           bam[dem].vt=i;
       }
    sort(bam,bam+dem+1,comp);
    long long sum=-1,cnt=1,tmp=0;
    memset(dd,true,sizeof(dd));

    for (long j=2; j<=dem; j++)
    {
        if (bam[j].w!=bam[cnt].w)
        {
            cnt=j;
            tmp=0;
            for (long i=1; i<=n; i++) dd[i]=true;
        }
        else
        {
            if (dd[bam[j].vt])
            {
                dd[bam[j].vt]=false;
                tmp++;
            }
            if (dd[bam[cnt].vt])
            {
                dd[bam[cnt].vt]=false;
                tmp++;
            }
        }
        sum=max(sum,tmp);
        if (sum>=k) return true;
    }
    if (sum>=k) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VO17TV.inp","r",stdin);
    freopen("VO17TV.out","w",stdout);
    cin >> n >> k;
    ss=""; vtri[0]=0;
    for (long i=1; i<=n; i++)
    {
        cin >> s[i];
        long long tmp=s[i].size();
        vtri[i]=vtri[i-1]+tmp;
        maxl=max(maxl,tmp);
        ss+=s[i];
    }
    h[0]=1;
    for (long i=1; i<=ss.size(); i++)
      h[i]=(h[i-1]*b) % m;

    hashs[0]=(ss[0]) % m;
    for (long i=1; i<=ss.size()-1; i++)
       hashs[i]=(hashs[i-1]*b+ss[i]) % m;

    long long l=1,r=maxl,ans;
    while (l<r)
    {
        long mid=(l+r)/2;
        if (ktra(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid;
    }
    cout << ans;
}
