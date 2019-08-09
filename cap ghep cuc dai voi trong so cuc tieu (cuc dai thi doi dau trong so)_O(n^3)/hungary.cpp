#include <bits/stdc++.h>
#define nmax 10007
#define vc 999999999

using namespace std;

long long m,n,k,start,fi,c[nmax][nmax],fx[nmax],fy[nmax],mx[nmax],my[nmax],tr[nmax],d[nmax],ar[nmax];
queue <long long> q;

long long getc_(long i, long j) //tra ve trong so canh (x[i],y[j])
{
    return c[i][j]-fx[i]-fy[j];
}

void ktaoBFS()//goi truoc khi dung 1 cay pha
{
    while (!q.empty()) q.pop();
    q.push(start); fi=0;
    memset(tr,0,sizeof(tr));
    for (long j=1; j<=k; j++)
    {
        d[j]=getc_(start,j); //d[i] la khoang cach gan nhat tu 1 X_dinh trong cay pha den y[j]
        ar[j]=start; //ar[i] la X_dinh noi voi y[j] de tao ra k/c gan nhat do
    }
}

void duong_mo()//tim duong mo xuat phat tu x[start]
{
    while (!q.empty())
    {
         long i=q.front();
         q.pop();
         for (long j=1; j<=k; j++)
            if (tr[j]==0)//neu y[j] chua tham
             {
                 long long w=getc_(i,j);
                 if (w==0) // neu canh (x[i],y[j]) la 0_canh
                 {
                     tr[j]=i;
                     if (my[j]==0)
                     {
                         fi=j;
                         return;
                     }
                     q.push(my[j]);
                 }
                 if (d[j]>w)//cap nhat lai d[j] theo cay pha da noi rong hon dinh x[i]
                 {
                     d[j]=w;
                     ar[j]=i;
                 }
             }
    }
}

void noirong()// noi rong bo ghep boi duong mo ket thuc o y[fi] (fi la finish)
{
    while (fi!=0) //fi=0 <=> i=start
    {
        long i=tr[fi];
        long next=mx[i];
        mx[i]=fi;
        my[fi]=i;
        fi=next;
    }
}

void xoay()
{
    //gan del bang gtnn trong so cac d[j] ma y[j] chua tham
    long long del=vc;
    for (long j=1; j<=k; j++)
       if (tr[j]==0 && d[j]<del) del=d[j];
    //xoay
    fx[start]+=del;
    for (long j=1; j<=k; j++)
      if (tr[j]!=0)
       {
           long i=my[j];
           fy[j]-=del;
           fx[i]+=del;
       }
       else d[j]-=del;
     for (long j=1; j<=k; j++)
       if (tr[j]==0 && d[j]==0) // xet nhung y[j] noi voi cay pha qua 1 0_canh moi phat sinh
        {
           tr[j]=ar[j];
           if (my[j]==0)//y[j] chua ghep <=> tim thay duong mo ket thuc o y[j]
           {
               fi=j;
               return;
           }
           q.push(my[j]);// y[j] da ghep, day my[j] vao Queue cho duyet tiep
        }
}

void solve()//thu ghep lan luot cac dinh tu x[1] toi x[k]
{
    for (long i=1; i<=k; i++)
    {
        start=i;//tim cach ghep x[start]
        ktaoBFS();
        while (fi==0)
        {
            duong_mo();
            if (fi==0) xoay();
        }
        noirong();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("hungary.inp","r",stdin);
    freopen("hungary.out","w",stdout);
    cin >> m >> n;
    k=max(m,n);
    for (long i=1; i<=k; i++)
      for (long j=1; j<=k; j++)
        c[i][j]=vc;
    long i,j;
    while (cin >> i >> j) cin >> c[i][j];
    solve();
    long long w=0;
    for (long i=1; i<=m; i++)
    {
        long j=mx[i];
        if (c[i][j]<vc)
        {
            cout << i << " " << j << " " << c[i][j] << '\n';
            w+=c[i][j];
        }
    }
    cout << w;
}
