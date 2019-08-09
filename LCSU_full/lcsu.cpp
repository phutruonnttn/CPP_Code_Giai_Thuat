using namespace std;
const int maxn=200000;
#include <bits/stdc++.h>
int dd[maxn], b[maxn];
void sinh()
{
    srand(time(0));
    freopen("LCSU.inp", "w", stdout);
    int n = rand() % 100000 + 1;
    int k = rand() % n + 1;
    cout << n <<" " <<k <<endl;
    for (int i = 1; i <= k ; i++)
    {
        int x = rand() % n + 1;
        while (dd[x]) x = rand() % n + 1;
        dd[x]=1;
        b[i] = x;
    }
    int y = rand() % 2;
    if (y)
    {
    int x = rand() % k + 1;
    b[x] = 0;
    }
    for (int i = 1; i <= k ; i++) cout << b[i] <<endl;
}

int main()
{
    sinh();
    freopen("LCSU.INP", "r", stdin);
    freopen("LCSU.OUT", "w", stdout);
    int n,m,h,j=1,k,i,t=0,res=0;
    int a[110000]={0};
    cin>>n>>k;
    m=0;
    for(int i=1;i<=k;i++)
    {
        cin>>h;
        if(h==0) t++;
        else
        {
            m++;a[m]=h;
        }
    }
    a[0]=0;
    sort(a+1,a+m+1);
    for(i=1;i<=m;i++)
    {
        while(a[i]-a[j]+j-i>t) j++;
        res=max(t+i-j+1,res);
    }
    cout<<res<<endl;
}
