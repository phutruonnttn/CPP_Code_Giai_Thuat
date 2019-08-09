#include <bits/stdc++.h>

using namespace std;

long n,t;
string s;

bool make_test(std::string p) {
  for (int i = 0; i < p.size(); i++) {
    if (p[i] != '0' && p[i] != '1') {
      return false;
    }
  }
  string ss = p + '#' + s;
  vector<int> pr(ss.size() + 1);
  pr[0] = -1;
  bool answer = false;
  for (int i = 1; i <= ss.size(); i++) {
    int k = pr[i - 1];
    while (k >= 0 && ss[k] != ss[i - 1])
      k = pr[k];
    pr[i] = k + 1;
    if (pr[i] == p.size()) {
      answer = true;
      break;
    }
  }
  return answer;
}

string analyse(long n, long t)
{
    std::string ss[1007];
    ss[0]="";
    for (long i=1; i<=n; i++) ss[i]=ss[i-1]+'1';

    long ll=0, rr=n, i=(ll+rr)/2;
    while (ll!=i && i!=rr)
    {
        if (make_test(ss[i])) ll=i;
        else rr=i;
        i=(ll+rr)/2;
    }
    std::string ans=ss[ll];
    long nn=ans.size(),dem=ll;
    if (nn==n) return ans;
    while (1<2)
    {
        std::string s1=ans+'0';
        if (make_test(s1)) {ans=s1;if (ans.size()==n) break;dem=0; continue;}
        dem++;
        if (dem>ll) break;
        ans=ans+'1';
        if (ans.size()==n) break;
    }
    nn=ans.size();
    if (nn==n) return ans;
    dem=ll;
    while (1<2)
    {
        std::string s1='0'+ans;
        if (make_test(s1)) {ans=s1;if (ans.size()==n) break;dem=0; continue;}
        dem++;
        if (dem>ll) break;
        ans='1'+ans;
        if (ans.size()==n) break;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("dna.inp","r",stdin);
    freopen("dna.out","w",stdout);
    cin >> s ; n=s.size();
    cin >> t;
    cout << analyse(n,t);
}
