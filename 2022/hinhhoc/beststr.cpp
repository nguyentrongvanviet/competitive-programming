#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , a,  b ; 
char s[N] ; 
ll res= 0 ; 
vector<char>v; 
void inp()
{
    cin>>n>>a>> b; 
    for(int i= 1; i<=n;i++)
    {
        cin>>s[i] ; 
    }
    int x = 0 ; 
    int y = 0 ; 
    if(s[1]=='1')
    {
        x++ ;
    }
    else 
    {
        y++; 
    }
    v.pb(s[1]) ;
    for(int i= 2 ;i<=n;i++)
    {
        if(s[i]!=v.back())
        {
            v.pb(s[i]) ; 
            if(s[i]=='1')x++ ;
            else y++ ; 
        }
    } 
    res= n*a;
    if(b>=0)
    {
        res+=b*n; 
    }
    else
    {   
        res+=min(x,y)*b+b; 
    }
    cout<<res;  
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}