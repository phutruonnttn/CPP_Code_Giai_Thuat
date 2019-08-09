


for (long i=1; i<=n; i++)
{
    while (!sl.empty() && a[sl.top()]>=a[i]) sl.pop();
    if (sl.empty()) l[i]=0;
    else l[i]=sl.top();
    sl.push(i);
}

for (long i=n; i>=1; i--)
{
    while (!sr.empty() && a[sr.top()]>=a[i]) sr.pop();
    if (sr.empty()) r[i]=0;
    else r[i]=sr.top();
    sr.push(i);
}

