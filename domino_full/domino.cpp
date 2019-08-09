#include<bits/stdc++.h>
#define maxn 55
using namespace std;

int n, a[maxn], b[maxn], hieu(0), dd[905], trc[905], f[905], sl[905], cmin, ss;
void truy()
{
    int x=cmin;
    stack<int> P;
    while(x!=hieu+450)
    {
        P.push(f[x]);
        x=trc[x];
    }
    cout<<P.size()<<endl;
    while(!P.empty())
    {
        cout<<P.top()<<" ";
        P.pop();
    }
}
int main()
{
    freopen("DOMINO.inp","r",stdin);
    freopen("DOMINO.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        hieu+=a[i]-b[i];
    }
    dd[hieu+450]=1;
    trc[hieu+450]=0;
    f[hieu+450]=0;
    sl[hieu+450]=0;
    cmin=hieu+450, ss=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i]) continue;
        int c=-2*(a[i]-b[i]);
        if(c>0)
        {
            for(int j=900-c;j>=0;j--)
            {
                if(dd[j])
                {
                    if(!dd[j+c] || sl[j+c]>sl[j]+1)
                    {
                        dd[j+c]=1;
                        trc[j+c]=j;
                        f[j+c]=i;
                        sl[j+c]=sl[j]+1;

                        if(fabs(j+c-450)<fabs(cmin-450) || (fabs(j+c-450)==fabs(cmin-450) && sl[j+c]<ss))
                        {
                            cmin=j+c;
                            ss=sl[j+c];
                        }
                    }
                }
            }
        }
        else
        {
            for(int j=-c;j<=900;j++)
            {
                if(dd[j])
                {
                    if(!dd[j+c] || sl[j+c]>sl[j]+1)
                    {
                        dd[j+c]=1;
                        trc[j+c]=j;
                        f[j+c]=i;
                        sl[j+c]=sl[j]+1;

                        if(fabs(j+c-450)<fabs(cmin-450) || (fabs(j+c-450)==fabs(cmin-450) && sl[j+c]<ss))
                        {
                            cmin=j+c;
                            ss=sl[j+c];
                        }
                    }
                }
            }
        }
    }
    cout<<fabs(cmin-450)<<" ";
    truy();
}
