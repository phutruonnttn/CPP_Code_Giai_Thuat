#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

string p,t;
long z[2*nmax];

void calcZ(long n)
{
	z[1]=0;
	long r=0, l=0, k=0, next, j=0;
	for(long i=2; i<=n; ++i)
    {
		next=0;
		if (i>=r)
		{
			k=i; j=1;
			next=1;
		}
        else
        {
			long al=i-l+1, be =r-l+1;
			if (i+z[al]-1<r) z[i]=z[al];
            else
            {
				k=r+1;
				j=be-al+2;
				next=1;
			}

		}
		if (next==1)
        {
			while (k<=n && t[k]==t[j])
			{
				k++; j++;
			}
			z[i]=j-1;
            l=i; r=l+z[i]-1;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("substr.inp","r",stdin);
    freopen("substr.out","w",stdout);
    getline(cin, t);
    getline(cin, p);
    t="."+p+"#"+t;
    long n=t.size(), m=p.size();
    calcZ(n+m+1);
    for (long i=m+2; i<=n+m+1; ++i)
		if (z[i] == m) cout << i-m-1 << " ";
}
