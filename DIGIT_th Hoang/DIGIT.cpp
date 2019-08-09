#include <bits/stdc++.h>

using namespace std;

uint64_t a,b,k;

uint64_t mul(uint64_t x, uint64_t y)
{
    if (y==0) return 0;
    uint64_t tmp=mul(x,y/2);
    if (y%2==0) return 2*tmp%b;
    else return (2*tmp+x)%b;
}

uint64_t power10(uint64_t k)
{
    if (k==0) return 1%b;
    //if (k==1) return x%b;
    uint64_t tmp=power10(k/2);
    tmp=mul(tmp,tmp)%b;
    if (k%2==1) tmp=tmp*10%b;
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DIGIT.inp","r",stdin);
    freopen("DIGIT.out","w",stdout);
    cin >> a >> b >> k;
    cout << mul(a%b,power10(k-1))%b*10/b;
}
