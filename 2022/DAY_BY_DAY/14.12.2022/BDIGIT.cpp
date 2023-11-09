/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "BDIGIT"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
//  [ i   , mask , ok  , sl ] 
//[ i digit  , mask the empty pos , la the last i  , ok the first number which is less than value[i] , sl so luong so i da xet ] 

int n  , k , l ,r ;
bool dd[12] ;
ll f[4][1<<11][12][12][11]; 
ll mu[12] ; 
void doc()
{
	cin>>n>>k  >> l >> r ;
	dd[0] =1 ;
	mu[0] =1 ;  
	FOR(i,1,11)mu[i] = mu[i-1]*10;
	FOR(i,1,n){int x ; cin>>x ; dd[x] = 1 ; } ;  	
}	

ll value ; 
bool ss(int digit , int pos , ll value )
{
	int cl =11-pos ; 
	int c = value/(mu[cl])%10; 
	return digit<c; 
}
ll tinh(int digit , int mask , int pos , int ok , int sl)
{
	if(f[digit][mask][pos][ok][sl]!=-1)return f[digit][mask][pos][ok][sl] ;
	if(mask==(1<<3)-1)
	{
		cout<<pos<<" "<<ok<<" "<<sl<<endl;
		if(ok&&dd[sl])return f[digit][mask][pos][ok][sl] = 1; 
		return f[digit][mask][pos][ok][sl] = 0;
	} 
	ll ans= 0 ;
	int thefi  ;
	FOR(i,0,1)
	{
		if(mask>>i&1)continue ; 
		thefi =i+1; 
		break ;
	}
	if(pos>=2-k+1)
	{
		if(dd[sl+1]&&digit)
		{
			int nok = ok;
			if(ss(digit,pos,value)){nok= min(ok,pos);if(ok==0)nok=pos;}
			ans+= tinh(digit-1, mask|(1<<(pos-1)) , thefi , nok , 0);
		}
	}
	else 
	{
		FOR(i,pos+k,2)
		{
			if(mask>>(i-1)&1)continue ; 
			int nok = ok;
			if(ss(digit,pos,value)){nok= min(ok,pos);if(ok==0)nok=pos;}
			ans+= tinh(digit , mask|(1<<(pos-1)) , i , nok , sl+1);
		}
	}
	if(dd[sl]&&digit)
	{
		ans+= tinh(digit-1,mask,thefi,ok,0);
	}
	return f[digit][mask][pos][ok][sl] =ans ; 
}
void xuly()
{
	value  =10 ; 
	memset(f,-1,sizeof(f)) ; 
  	value =r ; 
  	ll R = tinh(1,0,1,0,0) ;
  	// value = l-1 ;
  	cout<<R<<endl; 
  	// memset(f,-1,sizeof(f)) ; 
  	// ll L = tinh(9,0,1,0,0) ;
  	// cout<<R<<" "<<L<<endl; 
  	// cout<<R-L;
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}