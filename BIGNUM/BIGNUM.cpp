#include <bits/stdc++.h>

using namespace std;

string a,b;

void chuanhoa(string &a,string &b)
{
    while (a.size() < b.size()) a="0"+a;
    while (a.size() > b.size()) b="0"+b;
}

long cmp(string a, string b)
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
   bool neg=false;
   if (a<b)
   {
       swap(a,b);
       neg=true;
   }
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
   if (neg) c="-"+c;
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
         nho=s/10;
         c=char(s%10 +48) +c;
     }
    if (nho>0) c=itoa_(nho)+c;
    cout << nho << endl;
    return c;
}

string mul2(string a, string b)
{
    string res="";
    long n=a.size();
    long m=b.size();
    long len=n+m-1, carry=0;
    for (long i=len; i>=0; i--)
    {
        long tmp=0;
        for (long j=n-1; j>=0; j--)
            if (i-j<=m && i-j>=1)
            {
                long a1=a[j]-48;
                long b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}

/*string mul2(string a, string b)
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
}*/

long long mod1(string a, long b)
{
    long h=0;
    for (long i=0; i<a.size(); i++)
     h=(char(a[i])-48 +h*10) % b;
    return h;
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
         while (cmp(nho,kb[k])!=-1) k++;
         c=c+char(k-1+48);
         nho=sub(nho,kb[k-1]);
     }
    while (c.size()>1 && c[0]=='0') c.erase(0,1);
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BIGNUM.inp","r",stdin);
    freopen("BIGNUM.out","w",stdout);
    getline(cin,a);
    getline(cin,b);
    cout << add(a,b) << endl;
    cout << sub(a,b) << endl;
    cout << mul2(a,b) << endl;
    cout << mul1(a,1233) << endl;
    //cout << mod1("12345678987654321",100);
}
