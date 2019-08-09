#include <bits/stdc++.h>
#define nmax 1007

using namespace std;

struct data
{
    long k,l,r,gt;
};

long n,m,w[nmax],d,c;
data a[nmax];

void duyet(long u, long yon,long last,long canh)
{
    if (a[u].k==2)
    {
        duyet(a[u].l,yon,2,a[u].r);
        duyet(a[u].r,yon,2,a[u].l);
    }
    if (a[u].k==1)
    {
        long trai=a[u].l, phai=a[u].r;
        if (a[trai].k==2 && a[phai].k==2)
        {
            duyet(trai,yon+1,1,phai);
            duyet(phai,yon,1,trai);
        }
        else
        {
            duyet(trai,yon+1,1,phai);
            duyet(phai,yon+1,1,trai);
        }
    }
    if (last==-1 && canh==-1 && a[u].k==0)
    {
        a[u].gt=w[c--];
        return;
    }
    if (a[u].k==0)
    {
        if (last==1)
        {
            if (a[canh].k==0)
            {
                if (a[u].gt==-1) a[u].gt=w[d++];
                if (a[canh].gt==-1) a[canh].gt=w[c--];
            }
            else
            if (a[canh].k==1)
            {
                if (a[u].gt==-1) a[u].gt=w[d++];
            }
            else
            {
                if (a[u].gt==-1) a[u].gt=w[c--];
            }
        }
        else
        if (last==2)
        {
            if (a[canh].k==0)
            {
                if (yon>=1)
                {
                    if (a[u].gt==-1) a[u].gt=w[d++];
                    if (a[canh].gt==-1) a[canh].gt=w[d++];
                }
                else
                {
                    if (a[u].gt==-1) a[u].gt=w[c--];
                    if (a[canh].gt==-1) a[canh].gt=w[c--];
                }
            }
            else
            if (a[canh].k==1)
            {
                if (a[u].gt==-1) a[u].gt=w[c--];
            }
            else
            {
                if (yon>=1)
                {
                    if (a[u].gt==-1) a[u].gt=w[d++];
                }
                else
                {
                    if (a[u].gt==-1) a[u].gt=w[c--];
                }
            }
        }
    }
}

long calc(long u)
{
    if (a[u].k==2)
    {
        return min(calc(a[u].l),calc(a[u].r));
    }
    if (a[u].k==1)
    {
        return max(calc(a[u].l),calc(a[u].r));
    }
    if (a[u].k==0) return a[u].gt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++) cin >> w[i];
    sort(w+1,w+m+1);
    d=1;c=m;
    for (long i=1; i<=n; i++)
       { cin >> a[i].k >> a[i].l >> a[i].r; a[i].gt=-1;}
    duyet(1,0,-1,-1);
    cout<< calc(1);
}
