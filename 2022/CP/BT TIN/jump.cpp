#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e6+5 ,  oo = 1e9 ;
const ll cs= 330 , sm = 1e9+7 ,inf = 1e17;
int n ;  
ll ha[N] ;
ll a[N];  
ll mu[N] ; 
string s;
ll gethash(int l , int  r )
{
    return (ha[r]-ha[l-1]*mu[r-l+1]+sm*sm)%sm;
}  
bool check(int le )
{
    for(int i =le;i<=n;i+=le)
    {
        if(gethash(i-le+1,i)!=gethash(1,le))
        {
            return false ;
        }
    }
    if(n%le!=0)
    {
        int nle= n-n/le*le; 
        if(gethash(1,nle)!=gethash(n-nle+1,n))
        {
            return false; 
        }
    }
    return true; 
}
void inp()
{
    cin>> s ; 
    n = s.size();
    for(int i = 1 ;i<=s.size();i++)
    {
        a[i] =s[i-1]-'A' ; 
    }   
    mu[0] =1 ; 
    for(int i = 1;i<=n;i++)
    {
        mu[i] =(mu[i-1]*cs)%sm ;
        ha[i] = (ha[i-1]*cs+a[i])%sm ; 
    }
    for(int i= 1;i<=n;i++)
    {
        if(check(i))
        {
            for(int j =1;j<=i;j++)
            {
                cout<<s[j-1]; 
            }
            return ; 
        }
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