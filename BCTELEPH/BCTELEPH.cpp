#include <bits/stdc++.h>

using namespace std;

struct node
{
    long num, index, w_count;
    long child[30];
};

struct data
{
    long dd;
    string w;
};

vector <node> tree;
long t,n;
data s[10007];

void new_node()
{
    node aw;
    aw.num = 0;
    for (long i = 0; i < 30; i++) aw.child[i] = -1;
    aw.index = tree.size();
    tree.push_back(aw);
}

void delstruct()
{
    tree.clear();
}

void init()
{
    new_node();
}

void add_word(string s)
{
    long w;
    long indx = 0;
    for (long i = 0; i < s.size(); i++)
    {
      tree[indx].num++;
      w = s[i] - 'a';
      if (tree[indx].child[w] == -1)
      {
          new_node();
          tree[indx].child[w] = tree.size() - 1;
      }
      indx = tree[indx].child[w];
    }
    tree[indx].num++;
    tree[indx].w_count++;
}

long count_pref(string s)  // dem xem co bao nhieu tu bat dau boi xau s
{
    long w;
    long indx = 0;
    for (long i = 0; i < s.size(); i++)
    {
        w = s[i] - 'a';
        if (tree[indx].child[w] == -1) return 0;
        indx = tree[indx].child[w];
    }
    return tree[indx].num;
}

bool comp(data q, data p)
{
    return q.dd > p.dd;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BCTELEPH.inp","r",stdin);
    freopen("BCTELEPH.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; ++tt)
    {
        cin >> n;
        for (long i=1; i<=n; i++)
        {
            cin >> s[i].w;
            s[i].dd=s[i].w.size();
        }
        sort(s+1,s+n+1,comp);
        init();
        bool ok=true;
        for (long i=1; i<=n; i++)
        {
            cout << count_pref(s[i].w) << endl;
            /*if (count_pref(s[i].w)>0)
            {
                ok=false;
                cout << s[i].w << endl;
                break;
            }
            else*/ add_word(s[i].w);
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        delstruct();
    }
}
