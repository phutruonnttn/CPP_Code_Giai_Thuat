#include <bits/stdc++.h>

using namespace std;

long n,gia[20007],tang[20007],vitri[20007],tiso[20007];
//bool dd[20007];
long long ans=0;

/*void quicksort(long l, long r )
{
    long i=l, j=r;
    long chot=tiso[(l+r) / 2];
    do
    {
         while (tiso[i]<chot) i++;
         while (tiso[j]>chot) j--;
         if (i<=j)
          {
              swap(tiso[i],tiso[j]);
              swap(vitri[i],vitri[j]);
              i++; j--;
          }
    }
    while (i<=j);
    if (l<j) return quicksort(l,j);
    if (i<r) return quicksort(i,r);
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin >> n; //long d=0;
    //memset(dd,false,sizeof(dd));
    for (long i=1; i<=n; i++) {cin >> gia[i]; ans+=gia[i];}
    for (long i=1; i<=n; i++) cin >> tang[i]; //if (tang[i]==0) {ans+=gia[i]; dd[i]=true;}};
    /*for (long i=1; i<=n; i++)
        tiso[i]=gia[i]/tang[i];
    for (long i=1; i<=n; i++) vitri[i]=i;
    quicksort(1,n);*/
    sort(tang+1,tang+n+1);
    //for (long i=1; i<=n; i++) cout << tang[i] <<" ";

    long d=0;
    for (long i=n; i>=1; i--)
        {ans+=tang[i]*d;d++;}
    cout << ans;
}

