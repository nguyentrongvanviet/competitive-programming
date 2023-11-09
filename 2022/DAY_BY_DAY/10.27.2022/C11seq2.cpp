#include<bits/stdc++.h>
using namespace std;

#define TASK "C11seq2"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =60+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n  , k ;
int a[N]; 
string C[N][N] ;
map<int,int>pos; 
string cong(string a, string b )
{
	string ans="" ; 
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b; 
	int du= 0 ; 
	for(int i= b.size()-1;i>=0;i--)
	{
		int tmp = a[i]+b[i]-'0'-'0'+du ;
		du = tmp/10 ;
		int x = tmp%10;
		ans=(char)(x+'0')+ans;
	}
	if(du)
	{
		ans=(char)(du+'0')+ans; 
	}
	return ans ; 
} 	
string mul(string a, int b )
{
	string ans="";
	int du=0 ; 
	for(int i =a.size()-1;i>=0;i--)
	{
		int tmp = (a[i]-'0')*b+du;
		int x= tmp%10 ; 
		du = tmp/10 ; 
		ans= (char)(x+'0')+ans;
	}
	if(du)
	{
		ans=(char)(du+'0')+ans; 
	}
	return ans ; 
}	
string nhan(string a,  string b)
{	
	string ans = "" ;
	string zero="" ;  
	for(int  i= b.size()-1;i>=0;i--)
	{
		string tmp = mul(a,b[i]-'0') ; 
		tmp+=zero ; 
		ans=cong(ans,tmp) ; 
		zero+='0'; 
	}
	return ans ;
}	
string To_string(int a )
{
	string ans ="" ;
	while(a) 
	{
		int x = a%10 ; 
		ans=(char)(x+'0')+ans;
		a/=10 ; 
	}
	return ans ; 
}
int b[N] ;
void init()
{
	C[0][0] ="1" ; 
	for(int i=1 ;i<=n;i++)
	{
		C[i][0 ]="1";
		for(int  j= 1 ;j<=i;j++)
		{
			C[i][j] =cong(C[i-1][j-1],C[i-1][j]) ; 
		} 
	}
}
string tru(string a, string b )
{
	string ans ="";
	while(b.size()<a.size())
	{
		b='0'+b ; 
	}
	int thieu = 0;  
	for(int i= b.size()-1;i>=0;i--)
	{
		int tmp  = a[i]-b[i]-thieu ; 
		if(tmp<0)
		{
			tmp+=10 ; 
			thieu =1 ; 
		}
		else 
		{
			thieu = 0 ; 
		}
		int c= tmp%10; 
		ans=(char)(c+'0')+ans;
	}
	while(ans.size()>1&&ans[0]=='0')
	{
		ans.erase(0,1); 
	}
	return ans; 
}
bool ss(string a, string b )
{
	if(a.size()<b.size())return 1; 
	if(a.size()>b.size())return 0 ; 
	return a<=b ;
}
void doc()
{
    cin>> n >> k; 
    init() ; 
    for(int i =1 ;i<=n;i++)cin>>a[i],pos[a[i]]=i; 
    string s; 
    cin>>s ; 
    s=tru(s,"1") ; 
    int la = 0 ; 
    for(int i= 1 ;i<=k;i++)
    {
    	for(auto it : pos)
    	{
    		int j = it.second ; 
    		int val = it.first;
    		if(j<=la)continue ;  
    		if(ss(C[n-j][k-i],s))
    		{
    			s= tru(s,C[n-j][k-i]);
    		}	
    		else 
    		{
    			cout<<val<<" ";
    			la=j;
    			break ; 
    		}
    	}
    }
    cout<<"\n";
    for(int i=1 ;i<=n;i++)cin>>b[i] ;
    la =0 ; 
    string ans ="0" ;  
  	for(int i= 1;i<=k;i++)
  	{
  		for(int j = la+1;j<=n;j++)
  		{
  			if(b[i]>a[j])
  			{
  				ans=cong(ans,C[n-j][k-i]);
  			}
  		}
  		la=pos[b[i]];
  	}
    cout<<cong(ans,"1");
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