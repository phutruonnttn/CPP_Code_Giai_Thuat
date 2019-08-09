#include <bits/stdc++.h>
#define nmax 200007

using namespace std;

long long n,a[nmax],dd[nmax],f[nmax][5];

/*void tinh(long u,long tt)
{
    //cout << u << endl;
    if (!ok) return;
    cout << y << endl;
    if (u<=0 || u>n)
    {
        ok=false;
        return;
    }
    if (dd[u]==1)
    {
        y=-1;
        ok=false;
        return;
    }
    dd[u]=1;
    if (tt==0)
    {
        x+=a[u];
        y+=a[u];
        tt=1-tt;
        tinh(x,tt);
        if (!ok) return;
    }
    else
    {
        x-=a[u];
        y+=a[u];
        tt=1-tt;
        tinh(x,tt);
        if (!ok) return;
    }
    if (!ok) return;
}*/

long long tinh(long x, long tt)
{
    if (f[x][tt]!=-1) return f[x][tt];
    f[x][tt]=-2;
    if (tt==0)
    {
        if (x+a[x]>n) f[x][tt]=a[x];
        else
        {
           long t1=tinh(x+a[x],1-tt);
           if (t1!=-2) f[x][tt]=a[x]+t1;// sau cac buoc no lai quay lai gia tri f[x][tt] nen ko cap nhat de no tra ve gia tri -2
        }
    }
    else
    {
        if (x-a[x]==1) //vi chay vo han no se phai quay ve 1
        {
            f[x][tt]=-2;
            return -2;
        }
        if (x-a[x]<=0) f[x][tt]=a[x]; //dung lai khong tinh nua nen tra ve gia tri luon
        else
        {
           long t1=tinh(x-a[x],1-tt);
           if (t1!=-2) f[x][tt]=a[x]+t1;
        }
    }
    return f[x][tt];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GAMEC.inp","r",stdin);
    freopen("GAMEC.out","w",stdout);
    cin >> n;
    for (long i=2; i<=n; i++) cin >> a[i];
    for (long i=0; i<=n; i++) f[i][0]=f[i][1]=-1;
    for (long i=2; i<=n; i++)
    {
        long long ans=tinh(i,1);// bat dau tu buoc 2, tuc la 1+i(1->n-1)
        if (ans==-2) cout << -1 << '\n';
        else cout << ans+i-1 << '\n';//cong them vao 1 luong tu buoc 1 da bo qua
    }
}
