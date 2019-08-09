#include "dna.h"

#include <cstdlib>

std::string analyse(int n, int t) {
    /*std::string ss="";
    if (make_test("0")) ss="0";
    else ss="1";
    for (long i=1; i<n; i++)
    {
        std::string s1=ss+'0';
        if (make_test(s1)) {ss=s1; continue;}
        s1=ss+'1';
        if (make_test(s1)) {ss=s1; continue;}
        s1='0'+ss;
        if (make_test(s1)) {ss=s1; continue;}
        ss='1'+ss;
    }
    return ss;*/
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
