#include<bits/stdc++.h>

#define TASK "union"
const bool multitest = false; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= (int)a;i<=(int)b;i++)
#define FORD(i,a,b) for(int i= (int)a;i>=(int)b;i--)
#define FORN(i,a,b) for(int i= (int)a;i<(int)b;i++)
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b
using namespace std;
#define str string 
const int N =2e3+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

str cong(str a, str b )
{
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b;
	string ans= "";  
	int nho  =0 ; 
	for(int i= b.size()-1;i>=0;i--)
	{
		int tmp = nho+ a[i]-'0'+b[i]-'0' ; 
		int c= tmp%10 ; 
		nho = tmp/10 ; 
		ans=(char)(c+'0')+ans; 
	}
	if(nho)ans='1'+ans;		 
	return ans; 
}
str tru(str a , str b)
{
	while(b.size()<a.size())b='0'+b;
	str ans="" ; 
	int thieu =0 ;
	FORD(i,b.size()-1,0)
	{
		int tmp = a[i]-b[i]-thieu ; 
		if(tmp<0)thieu = 1 , tmp+=10; 
		else thieu = 0 ;
		int c= tmp%10;
		ans=(char)(c+'0')+ans; 
	}
	while(ans.size()>1&&ans[0]=='0')ans.erase(0,1);
	return ans ; 
}
str mul(str a , int b)
{
	str ans="";
	int nho = 0 ;
	FORD(i,a.size()-1,0)
	{
		int tmp = (a[i]-'0')*b+nho ; 
		nho=tmp/10;  
		int c= tmp%10;
		ans=(char)(c+'0')+ans;  
	}
	if(nho)ans=(char)(nho+'0')+ans;
	return ans;  
}
str nhan(str a, str b)
{
	str ans=""; 
	str zero = "" ;
	FORD(i,b.size()-1,0)
	{
		str tmp = mul(a,b[i]-'0');
		tmp+=zero;  
		ans=cong(ans,tmp);
		zero+="0"; 
	}
	return ans; 
}

int n , m ;
vi q[N] ; 
str f[N][N] , duong ,am ,s[N] ;
int pa[N]; 

void read()
{
    cin>> n >>m ; 
    FORN(i,0,m)
    {
    	int sl;  
    	cin>>sl;  
    	FOR(j,1,sl)
    	{
    		int x; 
    		cin>>x;  
    		q[i].pb(x) ;
    	}
    }  
}
int goc(int u )
{
	return pa[u] == u ? u : pa[u] =goc(pa[u]) ; 
}
int cnt ; 
void hop(int u , int v)
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return ; 
	pa[chau]=chav;
	cnt-- ; 
}

void process()
{
    f[1][1] ="1" ; 
    FOR(i,2,n)
    {
    	FOR(j,1,i)
    	{
    		f[i][j] =cong(nhan(f[i-1][j],to_string(j)),f[i-1][j-1]);
    	}
    }
    FOR(i,1,n)FOR(j,1,i)s[i] = cong(s[i],f[i][j]) ;
    duong="0"; 
    am="0";
    FORN(msk,1,(1<<m))
    {
    	FOR(i,1,n)pa[i]=i; 
    	cnt= n ;
    	FORN(i,0,m)if(msk>>i&1)
    	{
			for(auto v :q[i])hop(v,q[i][0]);
    	}
    	if(btpc(msk)&1)duong=cong(duong,s[cnt]) ;    
    	else am = cong(am,s[cnt]); 
    }
}
void print()
{
 	string res= tru(duong,am) ; 
 	cout<<tru(s[n],res);	
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
    
}
