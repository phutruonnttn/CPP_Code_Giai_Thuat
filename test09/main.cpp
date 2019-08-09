

struct data
{
    long u,v,w;
};

data a[nmax];
vector <data> kq;
long root[nmax];

bool comp(data a, data b)
{
    return a.w < b.w;
}

long get_root(long u)
{
    return (root[u]) ? root[u] = get_root(root[u]) : u;
}

void kruskal()
{
    sort(a+1,a+m+1,comp);
    memset(root,0,sizeof(root));
    long ans=0;
    for (long i=1; i<=m; i++)
    {
        long p=get_root(a[i].u);
        long q=get_root(a[i].v);
        if (p==q) continue;
        root[p]=q;
        ans+=a[i].w;
        kq.push_back(a[i]);
    }
}
