#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue <long> pq;
    for (long i=1; i<=10; i++) pq.push(i);
    long vt=upper_bound(pq,pq.size(),3);
    /*while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }*/
}
