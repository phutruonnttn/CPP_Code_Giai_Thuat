#include <bits/stdc++.h>

using namespace std;

long q;
//string a,b;
long long a,b,m;

/*void chuanhoa(string &a,string &b)
{
    while (a.size() < b.size()) a="0"+a;
    while (a.size() > b.size()) b="0"+b;
}

long sosanh(string a, string b)
{
    chuanhoa(a,b);
    if (a<b) return -1;
    else
    if (a==b) return 0;
    else return 1;
}

string add(string a,string b)
{
   string c=""; long nho=0;
   chuanhoa(a,b);
   for (long i=a.size()-1; i>=0; i--)
    {
        long x=a[i]-48;
        long y=b[i]-48;
        long s=x+y+nho;
        nho=s/10;
        c=char(s%10 +48) +c;
     }
   if (nho>0) c="1"+c;
   return c;
}

string sub(string a,string b)
{
   string c=""; long muon=0;
   chuanhoa(a,b);
   for (long i=a.size()-1; i>=0; i--)
    {
        long x=a[i]-48;
        long y=b[i]-48;
        long h=x-y-muon;
        if (h<0) {h=h+10; muon=1;}
        else muon=0;
        c=char(h+48) +c;
     }
   while (c.size()>1 && c[0]=='0') c.erase(0,1);
   return c;
}

string itoa_(long i)
{
    string ss="";
    long aa[100000];
    long dem=0;
    while (i!=0)
    {
        aa[++dem]=i%10;
        i=i/10;
    }
    for (long j=dem; j>=1; j--)
       ss+=(char)aa[j]+48;
    return ss;
}

string mul1(string a, long b)
{
    string c=""; long nho=0;
    for (long i=a.size()-1; i>=0; i--)
     {
         long s=(a[i]-48)*b+nho;
         nho=s / 10;
         c=char(s%10 +48) +c;
     }
    if (nho>0) c=itoa_(nho)+c;
    return c;
}

string mul2(string a, string b)
{
    string sum=""; long nho=0,m=-1;
    for (long i=a.size()-1; i>=0; i--)
     {
         string tmp=mul1(b,(a[i]-48));
         m=m+1;
         for (long j=1; j<=m; j++) tmp=tmp+"0";
         sum=add(sum,tmp);
     }
    return sum;
}

string div2(string a, string b)
{
    string kb[17];
    kb[0]="0";
    string nho="",c="";
    for (long i=1; i<=11; i++) kb[i]=add(kb[i-1],b);
    for (long i=0; i<a.size(); i++)
     {
         nho=nho+a[i];
         long k=1;
         while (sosanh(nho,kb[k])!=-1) k++;
         c=c+char(k-1+48);
         nho=sub(nho,kb[k-1]);
     }
    while (c.size()>1 && c[0]=='0') c.erase(0,1);
    return c;
}

long long mod1(string a,long long b)
{
    long long h=0;
    for (long i=0; i<a.size(); i++)
     h=(a[i]-48+h*10)%b;
    return h;
}*/

long long nhan(long long a, long long b)
{
    if (b==0) return 0;
    long long tmp=nhan(a,b/5);
    return ((5*tmp)%m+(a*(b%5))%m)%m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> q;
    for (long i=1; i<=q; i++)
    {
        cin >> a >> b >> m;
        //string tich=mul2(a,b);
        //string ans=sub(tich,mul2(m,div2(tich,m)));
        cout << nhan(a,b) << '\n';
    }
}
