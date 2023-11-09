#include<bits/stdc++.h>
using namespace std;

#define TASK "DELCHAR"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second   

const int N =2e5+5  ,maxN=20, oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 

void doc()
{
    cin>> n;
    FOR(i,1,n)
    {
        string a;  
        cin>>a; 
        int n=  a.size() ;
        a = '#'+a ; 
        int res= 0 ;
        for(int i= 1;i<=n;i++)
        {
            if(a[i]=='1')
            {
                if(a[i+1]=='0')
                {
                    i++;
                }
                else 
                {
                    res++;
                }
            } 
            else if(a[i]=='0')
            {
                if(a[i+1]=='1')
                {
                    i++;
                }
            }
        }
        cout<<res<<"\n";
    }
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }   
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}