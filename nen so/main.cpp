v.assign(a + 1, a + n + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (int i=1;i<=n;i++)
         a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
