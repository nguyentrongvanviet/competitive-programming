#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =5e4+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , k ;
int a[N] ; 
int dd[2*N] ; 
void inp()
{
    cin>>n>> k; 
    while(k--)
    {
        for(int i= 1;i<=n;i++)
        {
            int u ;  
            cin>>u ;
            dd[u] =1 ; 
            a[i]=u ;   
        }
        sort(a+1,a+n+1) ;
        int t= 0 ; 
        vector<int>q ; 
        for(int i=1;i<=2*n;i++)
        {
            if(dd[i]==0)
            {   
                q.pb(i) ;  
            }
        }
        int res= 0;
        int it = n ;  
        for(int i =n;i>=1;i--)
        {
            if(q.back()>a[i])
            {
                res++ ; 
                q.pk() ; 
            }
        }
        for(int i=1 ;i<=2*n;i++)
        {
            dd[i] = 0 ;  
        }
        cout<<res<<"\n"; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}