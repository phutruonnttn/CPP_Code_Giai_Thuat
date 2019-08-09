#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define LL long long

using namespace std;

const int N=101110;
int s[N];
int type;
LL L,k;

// SUB2

int w[20],r[20];
LL f[20][200][3];
int n,m;

LL cal(int i,int S,int pre){
    if(S<0) return 0;
    if(i>n) return f[i][S][pre]=(S==0&&pre!=2);
    if(f[i][S][pre]!=-1) return f[i][S][pre];
    LL ans=0;
    if(S==0) ans=(i<=n||pre!=2);
    for(int j=0;j<=9;j++)
    if(i!=1||j!=0){
        int now=pre;
        if(now==0&&j<w[i]) now=1;
        if(now==0&&j>w[i]) now=2;
        ans+=cal(i+1,S-j,now);
    }
    //cout<<i<<" "<<n<<" "<<S<<" "<<pre<<" "<<ans<<endl;
    return f[i][S][pre]=ans;
}

void solve_1(){
    LL ans=0;
    for(int u=1;u<=n*9;u++){
        if(cal(1,u,0)>=k){
            k--;
            int pre=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=9;j++){
                    if(u==0){
                        if(k>=1) k--;
                        else
                            break;
                    }
                    if(i!=1||j!=0){
                        int now=pre;
                        if(now==0&&j<w[i]) now=1;
                        if(now==0&&j>w[i]) now=2;
                        if(cal(i+1,u-j,now)<=k)
                            k-=cal(i+1,u-j,now);
                        else{
                            pre=now;
                            u-=j;
                            ans=ans*10+j;
                            break;
                        }
                    }
                }
                if(u==0&&k==0) break;
            }
            break;
        }
        else
            k-=cal(1,u,0);
    }
    cout<<ans<<endl;
}

void solve_2(){
    LL u=k;
    int S=0,pre=0;
    int m=0;
    while(u>0) s[++m]=u%10,u/=10;
    for(int i=1;i<=m;i++) r[i]=s[m-i+1],S+=r[i];
    LL ans=1;
    for(int i=1;i<S;i++) ans+=cal(1,i,0);
    for(int i=1;i<=m;i++){
        if(S==0&&r[i]==0) ans++;
        for(int j=0;j<r[i];j++)
        if(i!=1||j!=0){
            int now=pre;
            if(now==0&&j>w[i]) now=2;
            if(now==0&&j<w[i]) now=1;
            ans+=cal(i+1,S-j,now);
        }
        if(pre==0&&r[i]>w[i]) pre=2;
        if(pre==0&&r[i]<w[i]) pre=1;
        S-=r[i];
    }
    cout<<ans<<endl;
}

void sub2(){
    n=0;
    LL u=L;
    while(u>0) s[++n]=u%10,u/=10;
    for(int i=1;i<=n;i++) w[i]=s[n-i+1];
    memset(f,255,sizeof(f));
    if(type==1) solve_1();
    else
        solve_2();
}

//SUB 2
void solve(){
    cin>>type>>L>>k;
    sub2();
}
int main(){
    //freopen("bach.inp","r",stdin);
    //freopen("bach.out","w",stdout);
    int nT;
    cin>>nT;
    while(nT--)
        solve();
}

