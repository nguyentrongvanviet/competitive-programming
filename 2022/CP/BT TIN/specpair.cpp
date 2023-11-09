#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long
int n ; 
int a[N] ; 
int cnt[N] ;
vector<int>sl;
void inp()
{
    cin>> n ;
    for(int i = 1;i<=9;i++)
    {
        int u = i ;  
        for(int j=1;j<=7;j++)
        {
            sl.pb(u) ;
            u=u*10+i; 
        }
    }
    // sort(sl.begin(),sl.end()); 
    // for(int i= 0;i<sl.size();i++)
    // {
        // cout<<sl[i]<<" ";
    for(int i =1 ;i<=n;i++)
    {
        cin>>a[i]; 
    }   
    int res= 0 ;
    for(int i=1;i<=n;i++)
    {
        for(int j =sl.size()-1;j>=0;j--)
        {
            // if(sl[j]<=a[i])break;
            if(sl[j]-a[i]<=0||sl[j]-a[i]>(int)2e6)continue;
            res+=cnt[sl[j]-a[i]]; 
        }
        cnt[a[i]]++; 
    }
    cout<<res; 
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}