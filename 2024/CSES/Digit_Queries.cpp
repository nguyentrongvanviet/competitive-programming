#include<bits/stdc++.h>
using namespace std ; 

long long pw(long long a , long long b )
{
    long long res = 1 ; 
    for(long long i=1;i<=b;i++) res*=a ; 
    return res ; 
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ;
        freopen("text.OUT","w",stdout) ;
    }
    int q ; 
    cin >> q ; 
    while(q--)
    {
        long long n ; 
        cin>> n; 
        if(n<=9)
        {
            cout<<n<<endl; 
            continue ; 
        }
        long long sumNumOfDigits = 9  ; 
        long long  numOfDigits = 1 ; 
        for(long long  i=2;i<=18;i++)
        {
            // cout<<sumNumOfDigits<<endl;
            if(sumNumOfDigits>=n-i*(pw(10,i)-pw(10,i-1)))
            { 
                numOfDigits = i ; 
                break ; 
            }
            sumNumOfDigits+= i*(pw(10,i)-pw(10,i-1)) ;
            // cout<<sumNumOfDigits<<endl;
        }   
        assert(numOfDigits!=1) ; 
        long long rank =  n-sumNumOfDigits ;
        long long num =  pw(10,numOfDigits-1) + rank/numOfDigits + (rank%numOfDigits!=0) - 1 ; 
        int order =  rank%numOfDigits+ (rank%numOfDigits==0)*numOfDigits ;
        //  int order =  rank - (num-pow(10,numOfDigits-1))*numOfDigits ; 
        assert(order<=numOfDigits) ;
        auto getTheDigit = [](long long num , int order ) -> int 
        {
            string s = to_string(num) ; 
            return s[order-1] -'0' ; 
        } ; 
        cout<<getTheDigit(num,order)<<endl; 
    }
}