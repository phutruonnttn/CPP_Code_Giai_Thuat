#include <bits/stdc++.h>
#define nmax 1501

using namespace std;
int n,to[nmax][128],link[nmax],word[nmax],sz=0;
bool leaf[nmax];
string s;

void init()
{
    memset(to,0,sizeof(to));
    memset(link,0,sizeof(link));
    memset(word,0,sizeof(0));
    memset(leaf,false,sizeof(leaf));
}

void add_str(string s,int id)
{
    int u=0;
    for(int i=0;i<s.size();i++)
    {
        int j=s[i];
        if(to[u][j]==0)to[u][j]=++sz;
        u=to[u][j];
    }
    leaf[u]=true;
    word[u]=id;
}
void push_link()
{
    queue <int> q;
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int v=link[u];
        leaf[u]|=leaf[v];
        for(int i=0;i<128;i++)
            if(to[u][i]!=0)
        {
            link[to[u][i]]=(u!=0?to[v][i]:0);
            q.push(to[u][i]);
        }
        else to[u][i]=to[v][i];

    }
}
int search_str(string s)
{
    int cnt=0,u=0;
    for(int i=0;i<s.size();i++)
    {
        u=to[u][s[i]];
        int v=u;
        while(leaf[v])
        {
            if (word[v]!=0)cnt++;
            v=link[v];
        }

    }
    return cnt;
}

int main()
{
    freopen("find_patterns.inp","r",stdin);
    freopen("find_patterns.out","w",stdout);
    init();
    getline(cin,s);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char t[15];
        cin>>t;
        add_str(t,i);
    }
    push_link();
    cout<<search_str(s);
    return 0;
}
