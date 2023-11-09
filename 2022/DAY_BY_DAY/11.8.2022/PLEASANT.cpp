#include<bits/stdc++.h>
using namespace std;

#define TASK "PLEASANT"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =200+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
string s ;
ll f[N][12][2]  ; 
bool dd[N][12][2];	
string tru(string a , string b )
{
	string ans = ""; 
	while(b.size()<a.size())b='0'+b;
	int thieu = 0 ;	
	for(int  i=a.size()-1;i>=0;i--)
	{
		int tmp =  a[i]-b[i]-thieu ; 
		if(tmp<0)
		{
			thieu =1 ; 
			tmp +=10 ; 
		}
		else 
		{
			thieu = 0  ; 
		}
		ans=(char)(tmp%10+'0')+ans; 
	}
	while(ans.size()>1&&ans[0]=='0')ans.erase(0,1) ;
	return ans;  
}
ll tinh(int pos, int pre,int smaller)
{
	if(dd[pos][pre][smaller])return f[pos][pre][smaller]; 
	dd[pos][pre][smaller] =1 ; 
	if(pos==n)
	{
		return f[pos][pre][smaller]=1; 
	}
	ll ans= 0 ;
	if(smaller)
	{
		for(int i= pre ;i<=9;i++)
		{
			ans+=tinh(pos+1,i,1) ;
			ans%=sm ;
		}
	}
	else 
	{
		for(int i = pre;i<=s[pos]-'0';i++)
		{
			if(s[pos]-'0'>i)
			{
				ans+=tinh(pos+1,i,1);
			}
			else
			{
				ans+=tinh(pos+1,i,0);
			}
			ans%=sm; 
		}
	}
	return f[pos][pre][smaller]=ans ; 
} 
void init()
{
	memset(f,0,sizeof(f)) ;
	memset(dd,0,sizeof(dd));
	n=s.size();
}
ll solve()
{
	init() ;
	ll ans = tinh(0,0,0);		
	return ans ;
}
void doc()
{	
    string s1; cin>>s1;  
    string s2 ; cin>>s2;
   	s=s2 ;
    ll x = solve(); 
    s1 =  tru(s1,"1"); 
    s =s1;  
    ll y = solve() ;
    cout<<(x-y+sm)%sm; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}