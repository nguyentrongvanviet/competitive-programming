#include<bits/stdc++.h>
using namespace std;

#define TASK "chuoihat"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =250+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
string cong(string a , string b)
{
	string ans=""; 
	while(a.size() < b.size() ) a= '0' + a; 
	while( b.size() <  a.size() ) b='0' +b ;
	int du =0 ;  
	for(int i =b.size()-1;i>=0;i--)
	{
		int tmp = a[i]+b[i] -'0'-'0'+du ; 
		int c=  tmp%10  ; 
		du = tmp/10 ; 
		ans=(char)(c+'0')+ans; 
	}
	if(du)
	{
		ans=(char)(du+'0')+ans; 
	}
	return ans ; 
}
string tru(string a , string b )
{
	string ans ="";
	while(b.size()<a.size()) b='0'+b ;
	int thieu = 0 ; 
	for(int i= b.size()-1;i>=0;i--)
	{
		int tmp =a[i]-b[i]-thieu ; 
		if(tmp<0)
		{
			tmp+=10 ; 
			thieu =1 ; 
		}
		else 
		{
			thieu =0  ; 
		}
		int c= tmp%10 ; 
		ans=(char)(c+'0')+ans; 
	} 
	while(ans.size()>1&&ans[0]=='0')ans.erase(0,1) ; 
	return ans ;
}
bool ss(string a ,string b )
{
	if(a.size()<b.size())return 1 ; 
	if(a.size()>b.size())return 0 ; 
	return a<=b; 
}
int n ; 
string x; 
string s[N][N*2];
string  f[N][N*2];

void doc()
{
 	cin>> n; 
 	cin>>x; 
 	for(int i=2*n;i>=1;i--)
 	{
 		f[n][i] ="1"; 
 		s[n][i] =cong(s[n][i+1],f[n][i]); 
 	}    
 	for(int i= n-1;i>=1;i--)
 	{
 		for(int j=2*i;j>=1;j--)
 		{
 			f[i][j] =s[i+1][j+1];
 			s[i][j] =cong(s[i][j+1],f[i][j]);
 		}
 	}
 	x=tru(x,"1");
 	int la = 0 ;
 	for(int i=1;i<=n;i++)
 	{
 		for(int j= la+1;j<=2*i;j++)
 		{
 			if(ss(f[i][j],x))
 			{
 				x= tru(x,f[i][j]);
 			}
 			else 
 			{
 				cout<<j<<" ";
 				la=j;
 				break ; 
 			}
 		}
 	}	
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