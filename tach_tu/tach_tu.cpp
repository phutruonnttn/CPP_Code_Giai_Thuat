#include <bits/stdc++.h>
#define nmax 400007
#define nmod 1337377

using namespace std;

int n,to[nmax][128],link[nmax],word[nmax],sz=0,cnt[300007],length[300007];
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
        if(to[u][s[i]]==0)to[u][s[i]]=++sz;
        u=to[u][s[i]];
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
    memset(cnt,0,sizeof(cnt));
    int u=0;
    for(int i=0;i<s.size();i++)
    {
        u=to[u][s[i]];
        int v=u;
        while(leaf[v])
        {
            if (word[v]!=0)
            {
               if (i-length[word[v]]==-1) cnt[i]=(cnt[i]+1)%nmod;
               else cnt[i]=(cnt[i]+cnt[i-length[word[v]]])%nmod;
            }
            v=link[v];
        }

    }
    return (cnt[s.size()-1])%nmod;
}

int main()
{
    freopen("tach_tu.inp","r",stdin);
    freopen("tach_tu.out","w",stdout);
    init();
    getline(cin,s);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char t[105];
        cin>>t;
        add_str(t,i);
        length[i]=strlen(t);
    }
    push_link();
    cout<<search_str(s);
    return 0;
}
