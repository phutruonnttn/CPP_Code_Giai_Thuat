#include <bits/stdc++.h>

using namespace std;

struct data
{
    long w,id;
};

long n,p,aa[100007],chiso[100007],d[500007];
data a[100007];

bool comp(data m, data n)
{
    if (m.w!=n.w) return m.w<n.w;
    if (m.id!=n.id) return m.id < n.id;
}

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=chiso[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=min(d[node*2],d[node*2+1]);

}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 10000000000;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("JUMP.inp","r",stdin);
    freopen("JUMP.out","w",stdout);
    cin >> n >> p;
    for (long i=1; i<=n; i++) {cin >> a[i].w; a[i].id=i;}
    sort(a+1,a+n+1,comp);
    for (long i=1; i<=n; i++)
        chiso[i]=a[i].id;
    build(1,1,n);

    /*for (long i=1; i<=n; i++) cout << a[i].w << " "; cout << endl;
    for (long i=1; i<=n; i++) cout << a[i].id << " "; cout << endl;*/

    for (long i=1; i<=n; i++) {long tg=a[i].w; aa[i]=tg;}

    //for (long i=1; i<=n; i++) cout << aa[i] << " "; cout << endl;
    //cout << get(1,1,n,1,upper_bound(aa+1,aa+n+1,3)-aa-1) << endl;

    if (aa[n]-aa[1]<p) cout << 0;
    else
    {
    bool ok=false; long maxx=-1;
    for (long i=n; i>=1; i--)
    {
        long mm=get(1,1,n,1,upper_bound(aa+1,aa+n+1,aa[i]-p)-aa-1);
        /*for (long j=(upper_bound(aa+1,aa+n+1,aa[i]-p)-aa)-1; j>=1; j--)
            if (a[i].id>a[j].id) {maxx=max(maxx,a[i].id-a[j].id); ok=true;};*/
        if (mm<a[i].id) {maxx=max(maxx,a[i].id-mm); ok=true;}
    }
    if (!ok) cout << 0; else cout << maxx;
    }
}
