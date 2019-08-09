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
const char noAns[] = "5 or more";
string change(const string &s,int x, int y, int z) {
    return s.substr(0, x) + s.substr(y, z - y) + s.substr(x, y - x) + s.substr(z);
}
void printConfig(const string &s) {
    FORE(it, s) printf("%c ", *it + 1);
    printf("\n");
}
void BFS(string sta, map<string, int> &dist) {
    int n = sta.size();
    dist[sta] = 0;
    REP(step, 2) {
        vector<pair<string, int> > cur(ALL(dist));
        FORE(it, cur) if (it->se == step) {
            REP(i, n) FOR(j, i + 1, n - 1) FOR(k, j + 1, n) {
                string tmp = change(it->fi, i, j, k);
                if (dist.find(tmp) == dist.end()) {
                    dist[tmp] = step + 1;
                }
            }
        }
    }
}
void process(void) {
    string sta, fin;
    int n; scanf("%d", &n);
    REP(love, n) {
        int x; scanf("%d", &x);
        sta.push_back('0' + x - 1);
    }
    REP(i, n) fin.push_back('0' + i);
    map<string, int> staDist, finDist;
    BFS(sta, staDist);
    BFS(fin, finDist);
    int res = 5;
    FORE(it, staDist) {
        __typeof(finDist.begin()) jt = finDist.find(it->fi);
        if (jt != finDist.end()) {
                minimize(res, it->se + jt->se);
        }
    }
    if (res < 5) printf("%d\n", res); else printf("%s\n", noAns);
}
int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) process();
    return 0;
}
