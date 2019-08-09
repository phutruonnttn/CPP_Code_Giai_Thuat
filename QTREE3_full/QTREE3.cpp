#include <bits/stdc++.h>
#define int long long
#define nmax 100001
#define for(i, a, b) for(int i=(a); i<=(b); i++)
#define get get1

using namespace std;

int n, q, h[nmax], subtree[nmax], chain[nmax], color = 0, cnt = 0, head[nmax], b[nmax] = {0}, pos[nmax], vt[nmax], t[4*nmax];
int parent[nmax];
vector <int> a[nmax];

void dfs(int u, int pivot){
    h[u] = h[pivot] + 1;
    parent[u] = pivot;
    subtree[u] = 1;
    for(i, 0, a[u].size() - 1){
        int v = a[u][i];
        if(v!=pivot){
            dfs(v, u);
            subtree[u]+=subtree[v];
        }
    }
}

void hld(int u, int pivot){
    if(!head[u]){
        head[u] = u;
        chain[u] = ++color;
    }
    pos[u] = cnt;
    vt[cnt] = u;
    int maxtree = 0;
    int special = -1;
    for(i, 0, a[u].size() - 1){
        int v = a[u][i];
        if(v!=pivot){
            if(special==-1 || subtree[v]>maxtree){
                maxtree = subtree[v];
                special = v;
            }
        }
    }
    if(special!=-1){
        ++cnt;
        head[special] = head[u];
        chain[special] = chain[u];
        hld(special, u);
        for(i, 0, a[u].size() - 1){
            int v = a[u][i];
            if(v!=pivot && v!=special){
                ++cnt;
                hld(v, u);
            }
        }
    }
}

void build(int k, int l, int r){
    if(l==r){
        t[k] = l;
        return ;
    }
    int m = (l+r)/2;
    build(k*2, l, m);
    build(k*2+1, m+1, r);
    if(b[t[2*k]]>=b[t[2*k+1]]) t[k] = t[2*k];
    else t[k] = t[2*k+1];
}

void update(int k, int l, int r, int i){
    if(r<i || i<l) return ;
    if(l==r){
        b[l] = abs(b[l] - 1);
        return ;
    }
    int m = (l+r)/2;
    update(k*2, l, m, i);
    update(k*2+1, m+1, r, i);
    if(b[t[2*k]]>=b[t[2*k+1]]) t[k] = t[2*k];
    else t[k] = t[2*k+1];
}

int get(int k, int l, int r, int i, int j){
    if(i>r || j<l) return -1;
    if(l>=i && r<=j) return t[k];
    int m = (l+r)/2;
    int u = get(k*2, l, m, i, j);
    int v = get(k*2+1, m+1, r, i, j);
    if(u==-1) return v;
    if(v==-1) return u;
    if(b[u]>=b[v]) return u;
    return v;
}

int getq(int u){
    int no1 = chain[1];
    int id = -1; int ma = 0;
    while(1){
        int nou = chain[u];
        if(no1==nou){
            int val = get(1, 0, n - 1, pos[1], pos[u]);
            if(b[val]>=ma){
                ma = b[val];
                id = val;
            }
            if(ma==0) return -1;
            return vt[id];
        }
        int val = get(1, 0, n - 1, pos[head[u]], pos[u]);
        if(b[val]>=ma){
            ma = b[val];
            id = val;
        }
        u = parent[head[u]];
    }
}

main(){
    freopen("QTREE3.inp", "r", stdin);
    freopen("QTREE3.out", "w", stdout);

    cin >> n >> q;
    for(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    h[0] = -1;

    dfs(1, 0);
    hld(1, 0);
    build(1, 0, n - 1);

    while(q--){
        int id, i; cin >> id >> i;
        if(!id){
            update(1, 0, n - 1, pos[i]);
        }
        else{
            cout << getq(i) << endl;
        }
    }
}
