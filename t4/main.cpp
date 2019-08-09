void sangnt(long n)
{
    memset(nt,true,sizeof(nt));
    nt[1]=false;
    for (long i=2; i<=trunc(sqrt(n)); i++)
       if (nt[i])
         {
            long j=i*i;
            while (j<=n)
            {
                nt[j]=false;
                j+=i;
            }
         }
}
