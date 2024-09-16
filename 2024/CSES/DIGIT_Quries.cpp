#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std ; 
const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
long long pow(long long a ,  long long b)
{
    long long res=1 ;
    for(int i=1;i<=b;i++)res*=a ;
    return res ;
}
signed main()
{
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int q; 
    cin>>q ;
    while(q--)
    {
        long long val  ;cin>>val; 
        long long cnt = 0 , digit = 0  ; 
        for(int i=1;i<=18;i++)
        {
            cnt+=pow(10,i-1)*9*i ; 
            if(cnt>=val)
            {
                cnt-=pow(10,i-1)*9*i ;
                val-=cnt;  
                digit = i ;
                break;
            }
        }
        long long pos = (val%digit==0?digit:val%digit) ; 
        long long tmp = pow(10,digit-1)-1+(val/digit)+(val%digit>0?1:0);  
        cout<<tmp<<" "<<pos<<endl;;
        string s = to_string(tmp) ;
        // cout<<tmp<<" "<<pos<<endl;
        // cout<<tmp<<" "<<pos<<endl; 
        cout<<s[pos-1]<<'\n';
    }
}