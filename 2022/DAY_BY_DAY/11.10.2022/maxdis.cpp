#include<bits/stdc++.h>
using namespace std;

#define TASK ""

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 

string cong(string a , string b)
{
	while(a.size()<b.size())
	{
		a='0'+a; 
	}
	while(b.size()<a.size())
	{
		b='0'+b; 
	}
	string ans="" ;  
	int du=  0 ; 
	for(int i= a.size()-1;i>=0;i--)
	{
		int tmp = a[i]+b[i]-'0'-'0'+du;
		du = tmp/10 ; 
		int c= tmp%10 ; 
		ans = (char)(c+'0')+ans ;
	}
	return ans ; 
}
bool ss(string a, string b)
{
	if(a[0]=='-')
	{
		if(b[0]!='-')return 1;  
		string x = a.substr(1) ;
		string y = b.substr(1) ; 
		if(x<=y)return 1 ;  
	}
	if(a[0]=='-')

}
void doc()
{
    
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}