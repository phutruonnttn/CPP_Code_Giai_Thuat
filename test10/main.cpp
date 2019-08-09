

long par[100007][20],h[100007];

void dfs(long u)
{
    for (long i=0; i<adj[u].size(); i++)
    {
        long v=a[u][i];
        if (v!=par[u][0])
        {
            par[v][0]=u; h[v]=h[u]+1;
            for (long j=1; j<=17; j++)
               par[v][j]=par[par[v][j-1]][j-1];
            dfs(v);
        }
    }
}
