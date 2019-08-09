#include <bits/stdc++.h>

using namespace std;

struct node
{
    long num, index, w_count;
    long child[30];
};

vector <node> tree;
string aa,ss;

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

long count_word(string s) //dem xem trong xau ban dau co bao nhieu xau s
{
    long w;
    long indx = 0;
    for (long i = 0; i < s.size(); i++)
    {
        w = s[i] - 'a';
        if (tree[indx].child[w] == -1) return 0;
        indx = tree[indx].child[w];
    }
    return tree[indx].w_count;
}

void del_word(string s) //xoa xau s khoi cay
{
    if (!count_pref(s)) return;
    long w;
    long indx = 0;
    for (long i = 0; i < s.size(); i++)
    {
        tree[indx].num--;
        w = s[i] - 'a';
        indx = tree[indx].child[w];
    }
    tree[indx].num--;
    tree[indx].w_count--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Trie.inp","r",stdin);
    freopen("Trie.out","w",stdout);
    cin >> aa;
    cin >> ss;
    init();
    add_word(aa);
    cout << count_word(ss);
}
