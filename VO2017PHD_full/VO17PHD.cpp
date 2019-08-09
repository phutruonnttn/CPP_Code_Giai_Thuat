#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   100100
const long long INF = (long long)1e18 + 7LL;
const string noAnswer = "impossible";

vector<pair<int, int> > adj[MAX];
long long dist[MAX], maxValue[MAX];
int value[MAX];
int n, m;

void loadGraph(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);
    scanf("%d", &m);
    REP(love, m) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
}

void dijkstra(void) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;

    dist[1] = 0; q.push(make_pair(dist[1], 1));
    while (!q.empty()) {
        long long d = q.top().fi;
        int u = q.top().se;
        q.pop();

        if (dist[u] != d) continue;
        FORE(it, adj[u]) {
            int v = it->fi;
            if (dist[v] > dist[u] + it->se) {
                dist[v] = dist[u] + it->se;
                q.push(make_pair(dist[v], v));
            }
        }
    }

    if (dist[n] >= INF) {
        cout << noAnswer << endl;
        exit(0);
    }
}

bool compare(const int &x, const int &y) {
    return dist[x] < dist[y];
}
void optimize(void) {
    vector<int> nodes;
    FOR(i, 1, n) nodes.push_back(i);
    sort(ALL(nodes), compare);

    memset(maxValue, -1, sizeof maxValue);
    maxValue[1] = value[1];
    FORE(it, nodes) {
        int u = *it;
        if (maxValue[u] < 0) continue;
        FORE(jt, adj[u]) {
            int v = jt->fi;
            if (dist[v] == dist[u] + jt->se)
                maximize(maxValue[v], maxValue[u] + value[v]);
        }
    }

    cout << dist[n] << " " << maxValue[n] << endl;
}

int main(void) {
    loadGraph();
    dijkstra();
    optimize();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
