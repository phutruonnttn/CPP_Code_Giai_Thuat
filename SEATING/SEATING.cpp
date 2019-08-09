#include <bits/stdc++.h>

using namespace std;

struct data
{
    long a,b;
};

long long ans;
long long n,m,k;
data lost[57];

bool comp(data q, data p)
{
    if (q.a!=p.a) return q.a < p.a;
    return q.b < p.b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SEATING.inp","r",stdin);
    freopen("SEATING.out","w",stdout);
    cin >> n >> m >> k;
    ans=(m-1)*n;
    for (long i=1; i<=k; i++) cin >> lost[i].a >> lost[i].b;
    sort(lost+1,lost+k+1,comp);
    long long dem=0,part=lost[1].a,last=lost[1].b,d=0;
    for (long i=1; i<=k; i++)
    {
        if (lost[i].a==part)
        {
            if (lost[i].b-last<=1)
            {
                if (lost[i].b!=1 && lost[i].b!=m)
                {d++;
                last=lost[i].b;}
                if (i==k) ans-=(d+1);
            }
            else
            {
                if (lost[i].b==1 || lost[i].b==m)
                {
                    ans-=(d+1);
                    d=0;
                    last=lost[i].b;
                    if (i==k) ans-=(d+1);
                }
                else
                {
                   ans-=(d+1);
                   d=1;
                   last=lost[i].b;
                   if (i==k) ans-=(d+1);
                }
            }
        }
        else
        {
            part=lost[i].a;
            last=lost[i].b;
            ans-=(d+1);
            if (lost[i].b==1 || lost[i].b==m) d=0;
            else d=1;
            if (i==k) ans-=(d+1);
        }
    }
    cout << max((long long)0,ans);
}
