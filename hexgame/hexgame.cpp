#include <bits/stdc++.h>

using namespace std;

//map <string,int> M;
bool dd[100000000];


int mx[2][6] =
{
    {0,1,5,8,7,3},
    {1,2,6,9,8,4}
};

string xoay(string s, int t)
{
	string x = s;
	for (int i = 0; i < 6; i++)
			x[mx[t][(i + 1) % 6]] = s[mx[t][i]];
	return x;
}

string q[2000002];
string dest = "0000000000";

void nhap()
{
for (int i = 0 ; i < 10; i++)
{
    char x;
	cin >> x;
	dest[i] = x;
}
}

bool ktra(string a)
{
    long dem=0;
    for (long i=0; i<a.size(); i++)
    {
      int b=a[i]-48;
      dem=dem+b*(10-i);
    }
    if (dd[dem]==true)
    {
        dd[dem]=false;
        return true;
    };
    if (dd[dem]==false) return false;
}

int main()
{
    freopen("hexgame.inp","r",stdin);
    freopen("hexgame.out","w",stdout);
    nhap(); long d[10007];
    q[1] = dest;
    //M[q[1]] = 1;
    string ss="1238004765";
    memset(dd,true,sizeof(dd));
    long l =1, r = 1;
    while(l <= r)
    {
	string s = q[l++];
	string x = xoay(s,0);
	//if (M[x] == -1)
    {
	/*M[x] = ++r*/q[++r] = x, d[r] = d[l-1]+1;
		if (x == ss)
        {
            cout << d[r];
            return 0;
        }
    }
	string y = xoay(s,1);
	//if (M[y] == -1)
    {
    /*M[y] = ++r,*/q[++r] = y, d[r] = d[l-1] + 1;
		if (y == ss)
        {
            cout << d[r];
            return 0;
        }

    }
    }
}
