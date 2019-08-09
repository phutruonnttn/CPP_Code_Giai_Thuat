#include <bits/stdc++.h>

using namespace std;

struct data
{
    string ten; long long tongtran,diem,tranthang,tranthua,tranhoa,banthang,banthua,hieuso;
};

long n,dd[1007];
data doi[1007];
map <string,int> M;

bool comp(data p, data q)
{
    if (p.diem!=q.diem) return p.diem > q.diem;
    if (p.hieuso!=q.hieuso) return p.hieuso > q.hieuso;
    if (p.banthang!=q.banthang) return p.banthang > q.banthang;
    if (p.ten!=q.ten) return p.ten < q.ten;
}

long chuyendoi(string s)
{
    if (s=="10") return 10;
    return s[0]-48;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SERIEA.inp","r",stdin);
    freopen("SERIEA.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
       {
           cin >> doi[i].ten;
           M[doi[i].ten]=i;
       };
    while (1<2)
    {
       string s1,s2,n1,n2;
       cin >> s1;
       if (s1=="") break;
       cin >> s2 >> n1 >> n2;
       long ts1=chuyendoi(n1),ts2=chuyendoi(n2),u=M[s1],v=M[s2];
       if (ts1==ts2)
       {
         doi[u].diem +=1;
         doi[v].diem +=1;
         doi[u].tongtran +=1;
         doi[v].tongtran +=1;
         doi[u].tranhoa +=1;
         doi[v].tranhoa +=1;
         doi[u].banthang +=ts1;
         doi[u].banthua +=ts1;
         doi[v].banthang +=ts1;
         doi[v].banthua +=ts1;
       }
       else
       if (ts1<ts2)
       {
         doi[u].diem +=0;
         doi[v].diem +=3;
         doi[u].tongtran +=1;
         doi[v].tongtran +=1;
         doi[u].tranthua +=1;
         doi[v].tranthang +=1;
         doi[u].banthang +=ts1;
         doi[u].banthua +=ts2;
         doi[v].banthang +=ts2;
         doi[v].banthua +=ts1;
       }
       else
       if (ts1>ts2)
       {
         doi[u].diem +=3;
         doi[v].diem +=0;
         doi[u].tongtran +=1;
         doi[v].tongtran +=1;
         doi[u].tranthang +=1;
         doi[v].tranthua +=1;
         doi[u].banthang +=ts1;
         doi[u].banthua +=ts2;
         doi[v].banthang +=ts2;
         doi[v].banthua +=ts1;
       };
    };
    for (long i=1; i<=n; i++)
        doi[i].hieuso=doi[i].banthang-doi[i].banthua;

    sort(doi+1,doi+n+1,comp);

    for (long i=1; i<=n; i++)
        cout << doi[i].ten << " " << doi[i].tongtran << " " << doi[i].diem << " " << doi[i].tranthang << " " << doi[i].tranthua << " " << doi[i].tranhoa << " " << doi[i].banthang << " " << doi[i].banthua<< " " << doi[i].hieuso << endl;
}
