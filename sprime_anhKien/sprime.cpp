#include <bits/stdc++.h>
#define nmax 1007
using namespace std;
int n,ngto[nmax],sngto,x[nmax],sum,kq[nmax];
bool nt[nmax];

void sang()
{
    for (int i=2;i<=nmax;i++) nt[i]=true;
    for (int i=2;i<=sqrt(nmax);i++)
    {
        int j=i*i;
        while (j<nmax) {nt[j]=false;j+=i;}
    }
    for (int i=2;i<=nmax;i++)
    if (nt[i]) {ngto[++sngto]=i;}
}

void try_(int i,bool ok)
{
    int l;
    if (!ok) l=x[i-1]; else  l=x[i-1]+1;

    for (int k=l;k<=sngto;k++)
    {
        sum+=ngto[k];
        if (sum>nmax) {sum-=ngto[k];break;}

        x[i]=k;

        kq[sum]=max(kq[sum],i);

        if ((x[i]==x[i-1]) && (i!=1)) try_(i+1,true);
        else try_(i+1,ok);
        sum-=ngto[k];

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("sprime.inp","r",stdin);
    freopen("sprime.out","w",stdout);
    sang();
    for (int i=1;i<=nmax;i++) kq[i]=0;
    kq[1]=1;x[0]=1;
    sum=0;
    try_(1,false);
    for (int i=500;i<=1000;i++) cout<<i<<" "<<kq[i]<<endl;

    /*while (1<2)
    {
        n=0;
        cin>>n;
        if (n==0) return 0;
        //cout<<kq[n]<<endl;
    }*/


}

