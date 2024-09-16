ng long pow(long long a ,  long long b)
{
    long long res=1 ;
    for(int i=1;i<=b;i++)res*=a ;
    return res ;
}