#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
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
int gcd(int a,int b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>=b) a%=b; else b%=a;
    }
}
int a[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
int solve(int x,int lim) {
    int res=0;
    FOR(i,1,n) {
        if (res>0 && res<=lim) return (res);
        if (a[i]%x!=0) res=gcd(res,a[i]);
    }
    return (res==0?x:res);
}
void process(void) {
    int res=0;
    int id=1+rand()%n;
    for (int i=1;1LL*i*i<=a[id];i=i+1) if (a[id]%i==0) {
        if (i>res) maximize(res,min(i,solve(i,res)));
        if (a[id]/i>res) maximize(res,min(a[id]/i,solve(a[id]/i,res)));
    }
    printf("%d\n",res);
}
int main(void) {
    int t; scanf("%d",&t);
    REP(love,t) {
        init();
        process();
    }
    return 0;
}
