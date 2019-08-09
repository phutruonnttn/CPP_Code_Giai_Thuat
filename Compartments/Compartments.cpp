#include <bits/stdc++.h>
using namespace std;

long n,a[5],ans=0;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Compartments.inp","r",stdin);
    freopen("Compartments.out","w",stdout);
	cin >> n;
	for (long i=1;i<=n;i++)
	{
		long w; cin >> w;
		a[w]++;
	}

	long mini=min(a[1],a[2]);
	ans+=mini;
	a[1]-=mini;a[2]-=mini;
	a[3]+=mini;

	if (a[1]>0)
	{
		mini=a[1]/3;ans+=mini*2;a[1]-=mini*3;a[3]+=mini;
		if (a[3]>=a[1])
		{
			ans+=a[1];
			cout << ans;
		}
		else if (3-a[1]<=a[4])
		{
			ans+=2;
			cout << ans;
		}
		else cout << -1;
	}
	else if (a[2]>0)
	{
		mini=a[2]/3;ans+=mini*2;
		a[3]+=mini*2;a[2]-=mini*3;
		if (a[2]==0) cout << ans;
		else if (a[2]==1)
		{
			if (a[4]>=1) cout << ans+1;
			else if (a[3]>=2) cout << ans+2;
			else cout << -1;
		}
		else cout << ans+2;
	}
	else cout << ans;
}
