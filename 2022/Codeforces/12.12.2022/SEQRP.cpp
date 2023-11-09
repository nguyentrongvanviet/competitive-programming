/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "SEQRP"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)	
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}
#define int long long 
const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , h ;
int a[N] ;
int la[N] ;
int res= oo ;
int s[N];
int st[4*N];
void build(int id , int l, int r)
{
	if(l==r)
	{
		st[id] =a[l] ; 
		return ;  
	}
	int mid = (l+r)/2;
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id] =min(st[id*2],st[id*2+1]) ; 
}
int get(int id ,int l ,int r , int t, int p )
{
	if(l==r)
	{

	}
}
void sub1()
{
	ll res= inf ; 
	FOR(i,1,n-h+1)
	{
		int t=1 ; 
		bool ok =1 ; 
		ll tmp = 0 ;
		FOR(j,i,i+h-1)
		{
			if(a[j]>t)
			{
				ok =0 ; 
				break;   
			}
			tmp+=a[j] ; 
			++t; 
		}
		if(ok)
		{
			cout<<i<<endl;
			res=min(res,h*(h+1)/2-tmp) ;
		}
	}
	cout<<(res==inf?-1:res);
}
void doc()
{
    cin>>n >>h ;
    FOR(i,1,n)cin>>a[i] ;
    FOR(i,1,n)s[i] = s[i-1]+a[i] ;
    sub1(); 
    return ; 
    FOR(i,1,n)a[i] = a[i]-i ;
    build(1,1,n) ; 
    int len= 0 ;  
    FOR(i,1,n)
    {
    	if(a[i]>h)len= 0;
    	else if(len==0)
    	{
    		if(a[i]<=1)
    		{
    			len = 1; 
    		}
    	}
    	else 
    	{
    		if(a[i]<=len+1)
    		{
    			++len; 
    		}
    		else 
    		{
    			len= 0 ;
    		}
    	}
    	len = min(len,h);
    	if(len==h)
    	{
    		res=min(res,h*(h+1)/2-(s[i]-s[i-h]));
    	}
    }
    cout<<(res==oo?-1:res);
}
void xuly()
{
    
}
main()
{
    IOS();  
    doc(); 
    xuly();
}