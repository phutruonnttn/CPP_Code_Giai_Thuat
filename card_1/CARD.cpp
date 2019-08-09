#include <bits/stdc++.h>

using namespace std;

long m,k,bai[100000007]; string s;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CARD.inp","r",stdin);
    freopen("CARD.out","w",stdout);
    cin >> m >> k;
    cin >> s;
    long j=0;

    for (long i=1; i<=m; i++)
       bai[i]=i-1;

    //for (long i=1; i<=m; i++) cout << bai[i] << " "; cout << endl;
    long dau=1, cuoi=m;
    while (s[j]!='.')
    {
        if (s[j]=='A')
        {
            bai[++cuoi]=bai[dau++];
        };
        if (s[j]=='B')
        {
            //bai[d+1]=bai[d];
            bai[++cuoi]=bai[dau+1];
            bai[dau+1]=bai[dau++];
        }
        //for (long i=1; i<=m; i++) cout << bai[i] << " "; cout << endl;
        j++;
    }
    cout << bai[k+dau-1] <<  " " << bai[k+dau] <<" " << bai[k+1+dau];
}
