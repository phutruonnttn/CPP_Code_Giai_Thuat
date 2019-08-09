#include <bits/stdc++.h>

using namespace std;

struct data
{
    long x,y;
};

data diem[7];

bool comp(data q,data p)
{
    if (q.x!=p.x) return q.x < p.x;
    return q.y < p.y;
}

long kc(data p, data q)
{
    return ((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("HIVU.inp","r",stdin);
    freopen("HIVU.out","w",stdout);
    for (long i=1; i<=4; i++)
      cin >> diem[i].x >> diem[i].y;

    bool ok=true;
    for (long i=1; i<=3; i++) if (diem[i].x!=diem[4].x) ok=false;
    if (ok)
    {
        cout << "NO";
        return 0;
    }

    ok=true;
    for (long i=1; i<=3; i++) if (diem[i].y!=diem[4].y) ok=false;
    if (ok)
    {
        cout << "NO";
        return 0;
    }
    sort(diem+1,diem+5,comp);
    data d1=diem[1], d2=diem[2], d3=diem[4], d4=diem[3];
    if (kc(d1,d2)==kc(d2,d3) && kc(d2,d3)==kc(d3,d4) && kc(d3,d4)==kc(d4,d1) && kc(d1,d3)==kc(d2,d4)) cout << "YES";
    else cout << "NO";
}
