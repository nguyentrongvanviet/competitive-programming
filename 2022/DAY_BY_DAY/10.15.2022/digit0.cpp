#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll res =0  ; 
ll cnt[N] ; 
pii f[N] ; 
pii fac[N]; 
void input()
{
    string s;  
    cin>> s; 
    n = s.size() ; 
    for(int i= 1;i<=n;i++)
    {
    	cnt[s[i-1]-'a']++ ;
    }
    f[1]={0,0}; 
    f[2]={1,0}; 
    f[5]={0,1}; 
    for(int  i=4 ;i<=n;i++)
    {
    	if(i%2==0)
    	{
    		f[i]={f[i/2].fi+1,f[i/2].se};
    	}
    	else if(i%5==0)
    	{
    		f[i] = {f[i/5].fi,f[i/5].se+1};
    	}
    }
}
void output()
{
    for(int i= 1 ;i<=n;i++)
    {
    	fac[i].fi=fac[i-1].fi+f[i].fi ; 
    	fac[i].se+=fac[i-1].se+f[i].se ; 
    }
    pii ans = {0,0}  ;
    for(int i=0;i<26;i++)
    {
    	ans.fi+=fac[cnt[i]].fi ; 
    	ans.se+=fac[cnt[i]].se;
    }
    pii cl ={fac[n].fi-ans.fi,fac[n].se-ans.se}; 
    cout<<min(fac[n].fi-ans.fi,fac[n].se-ans.se);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}