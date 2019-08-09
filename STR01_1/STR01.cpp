#include <bits/stdc++.h>
#define nmax 1500001

using namespace std;
long tu[nmax];
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

void search_str(string s)
{
    int u=0;
    for(int i=0;i<s.size();i++)
    {
        u=to[u][s[i]];
        int v=u;
        while(leaf[v])
        {
            if (word[v]!=0) tu[word[v]]++;
            v=link[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("STR01.inp","r",stdin);
    freopen("STR01.out","w",stdout);
    init();
    long bo;
    cin >> bo >> n;
    cin >> s;
    for(int i=1;i<=n;i++)
    {
        long bo; cin >> bo;
        char t[15];
        cin>>t;
        tu[i]=0;
        add_str(t,i);
    }
    push_link();
    search_str(s);
    for (long i=1; i<=n; i++)
        cout << tu[i] << endl;
}
