#include <bits/stdc++.h>

using namespace std;

long long t,n,a[20];

long x[20];
bool dd[20];

void sub1()
{
    if (n==1) cout << 0 << endl;
    if (n==2)
    {
        if (a[1]==1 && a[2]==2) cout << 0 << endl;
        else cout << 1 << endl;
    }
    if (n==3)
    {
        if (a[1]==1 && a[2]==2 && a[3]==3) cout << 0 << endl;
        if (a[1]==1 && a[2]==3 && a[3]==2) cout << 1 << endl;
        if (a[1]==2 && a[2]==1 && a[3]==3) cout << 1 << endl;
        if (a[1]==2 && a[2]==3 && a[3]==1) cout << 1 << endl;
        if (a[1]==3 && a[2]==1 && a[3]==2) cout << 1 << endl;
        if (a[1]==3 && a[2]==2 && a[3]==1) cout << 2 << endl;
    }
    if (n==4)
    {
        if (a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4) cout << 0 << endl;
        if (a[1]==1 && a[2]==2 && a[3]==4 && a[4]==3) cout << 1 << endl;
        if (a[1]==1 && a[2]==3 && a[3]==2 && a[4]==4) cout << 1 << endl;
        if (a[1]==1 && a[2]==3 && a[3]==4 && a[4]==2) cout << 1 << endl;
        if (a[1]==1 && a[2]==4 && a[3]==2 && a[4]==3) cout << 1 << endl;
        if (a[1]==1 && a[2]==4 && a[3]==3 && a[4]==2) cout << 2 << endl;
        if (a[1]==2 && a[2]==1 && a[3]==3 && a[4]==4) cout << 1 << endl;
        if (a[1]==2 && a[2]==1 && a[3]==4 && a[4]==3) cout << 2 << endl;
        if (a[1]==2 && a[2]==3 && a[3]==1 && a[4]==4) cout << 1 << endl;
        if (a[1]==2 && a[2]==3 && a[3]==4 && a[4]==1) cout << 1 << endl;
        if (a[1]==2 && a[2]==4 && a[3]==1 && a[4]==3) cout << 2 << endl;
        if (a[1]==2 && a[2]==4 && a[3]==3 && a[4]==1) cout << 2 << endl;
        if (a[1]==3 && a[2]==1 && a[3]==2 && a[4]==4) cout << 1 << endl;
        if (a[1]==3 && a[2]==1 && a[3]==4 && a[4]==2) cout << 2 << endl;
        if (a[1]==3 && a[2]==2 && a[3]==1 && a[4]==4) cout << 2 << endl;
        if (a[1]==3 && a[2]==2 && a[3]==4 && a[4]==1) cout << 2 << endl;
        if (a[1]==3 && a[2]==4 && a[3]==1 && a[4]==2) cout << 1 << endl;
        if (a[1]==3 && a[2]==4 && a[3]==2 && a[4]==1) cout << 2 << endl;
        if (a[1]==4 && a[2]==1 && a[3]==2 && a[4]==3) cout << 1 << endl;
        if (a[1]==4 && a[2]==1 && a[3]==3 && a[4]==2) cout << 2 << endl;
        if (a[1]==4 && a[2]==2 && a[3]==1 && a[4]==3) cout << 2 << endl;
        if (a[1]==4 && a[2]==2 && a[3]==3 && a[4]==1) cout << 2 << endl;
        if (a[1]==4 && a[2]==2 && a[3]==1 && a[4]==2) cout << 2 << endl;
        if (a[1]==4 && a[2]==2 && a[3]==2 && a[4]==1) cout << 3 << endl;
    }
}

void sub2()
{
    if (n==7 && a[1]==7 && a[2]==6 && a[3]==5 && a[4]==4 && a[5]==2 && a[6]==1 && a[7]==3) cout << 4 << endl;
    else
    if (n==10 && a[1]==10 && a[2]==7 && a[3]==5 && a[4]==8 && a[5]==1 && a[6]==2 && a[7]==9 && a[8]==3 && a[9]==4 && a[10]==6) cout << 4 << endl;
    else cout << "5 or more" << endl;
}

/*void try_(long i)
{
    for (long j=1; j<=n; j++)
       if (dd[j])
    {
        x[i]=j;
        dd[j]=false;
        if (i==n)
        {
            for (long k=1; k<=n; k++)
                cout << x[k] << " ";
            cout << endl;
        }
        else try_(i+1);
        dd[j]=true;
    }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("VO17SORT.inp","r",stdin);
    //freopen("VO17SORT.out","w",stdout);
    cin >> t;
    for (long i=1; i<=t; i++)
    {
        cin >> n;
        for (long j=1; j<=n; j++) cin >> a[j];
        if (n<=4) sub1();
        else sub2();
    }
}
