#include<bits/stdc++.h>
using namespace std;

#define TASK "pair00"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =1000+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

string cong(string a , string b )
{
	string ans ="" ; 
	while(a.size()<b.size())
	{
		a='0'+a;  
	}
	while(b.size()<a.size())
	{
		b='0'+b;  
	}
	int du = 0 ; 
	for(int i = b.size()-1;i>=0;i--)
	{
		int tmp =a[i]+b[i] -'0'-'0'+du ; 
		int x  = tmp%10; 
		du=tmp/10; 
		ans=(char)(x+'0')+ans; 
	}
	if(du)
	{
		ans= (char)(du+'0')+ans;  
	}
	return ans ;
}
int n ; 
string sum[N] ;
string f[N];
void doc()
{ 
	f[1]="0";
	sum[1] = "0" ;
	for(int i= 2; i<=1000;i++)
	{	
		if(i%2==0)
		{
			f[i]=cong(sum[i-1],"1") ;	
		}
		else 
		{
			f[i] =sum[i-1]; 
		}
		sum[i] = cong(sum[i-1],f[i]); 
	}
	int x;  
	while(cin>>x)
	{
		cout<<f[x]<<"\n";
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