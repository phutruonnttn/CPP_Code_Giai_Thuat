#include <bits/stdc++.h>

using namespace std;

struct node
{
    long num, index, w_count;
    long child[30];
};

vector <node> tree;
string s;
long long n,q;

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

long count_pref(string s)
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TUDIEN.inp","r",stdin);
    freopen("TUDIEN.out","w",stdout);
    cin >> n;
    init();
    for (long i=1; i<=n; i++)
    {
        cin >> s;
        add_word(s);
    }
    cin >> q;
    for (long i=1; i<=q; i++)
    {
        cin >> s;
        cout << count_pref(s) << '\n';
    }
}
