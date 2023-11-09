#include<bits/stdc++.h>
using namespace std;

#define TASK "SHTH"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =300+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

string cong(string a , string b )
{
	string res=""; 
	while(a.size()<b.size())
	{
		a='0'+a; 
	}
	while(b.size()<a.size())
	{
		b='0'+b; 
	}
	int du= 0  ; 
	for(int i= a.size()-1;i>=0;i--)
	{
		int tmp = a[i]-'0'+b[i]-'0'+du; 
		du=tmp/10 ; 
		int c= tmp%10 ;
		res=(char)(c+'0')+res;
	}	
	if(du)res=(char)(du+'0')+res;
	return res; 
}
string tru(string a , string b )
{
	string res="";
	while(b.size()<a.size())
	{
		b='0'+b;
	}
	int thieu = 0 ; 
	for(int i= a.size()-1;i>=0;i--)
	{
		int tmp = a[i]-b[i]-thieu;
		if(tmp<0)tmp+=10,thieu=1; 
		else thieu= 0 ;  
		int c= tmp%10  ; 
		res=(char)(c+'0')+res; 
	}
	while(res.size()>1&&res[0]=='0')res.erase(0,1);
	return res;
}
string mul(string a ,int  b)
{
	string res="";  
	int du=  0 ; 
	for(int i= a.size()-1;i>=0;i--)
	{
		int tmp = (a[i]-'0')*b+du ; 
		int c= tmp%10 ; 
		du =tmp/10 ;
		res=(char)(c+'0')+res; 
	}
	if(du)res=(char)(du+'0')+res;
	return res;
}
string nhan(string a , string b )
{
	string res="";
	string zero="";
	for(int i= b.size()-1;i>=0;i--)
	{
		string tmp = mul(a,b[i]-'0');
		tmp+=zero;
		res=cong(res,tmp);
		zero+='0';
	}
	return res;
}
bool ss(string a ,string b)
{
	if(a.size()<b.size())return 1; 
	if(a.size()>b.size())return 0 ;
	return a<=b; 
}
int n , k ; 
string s; 
int a[N] ;
int dd[N] ;  
string C[N][N];
void doc()
{
 	cin>> n>> k ;
 	cin>>s;  
 	for(int i=1 ;i<=k;i++)cin>>a[i] ;    
}
void init()
{
	C[0][0]="1" ;
	for(int i=1 ;i<=n;i++)
	{
		C[i][0]="1";
		for(int  j=1 ;j<=i;j++)
		{
			C[i][j] =cong(C[i-1][j-1],C[i-1][j]);
		}
	}
}
string To_string(ll val)
{
	string res=""; 
	while(val)
	{
		res=(char)(val%10+'0')+res;
		val/=10;
	}
	return res;
}
void xuly()
{
	init();
	vector<int>dd(n+1,0);
	s=tru(s,"1");
	int ma= 0 ;
	for(int i= 1;i<=k;i++)
	{
		for(int j= ma+1;j<=n;j++)
		{
			if(dd[j]==0)
			{
				if(ss(C[n-j][k-i],s))
				{
					s=tru(s,C[n-j][k-i]);
				}
				else 
				{
					cout<<j<<" ";
					dd[j]=1;
					ma= j ;
					break;
				}
			}
		}
	}
	dd=vector<int>(n+1,0);
	cout<<"\n";
	string res="0";
	for(int i=1 ;i<=k;i++)
	{
		int cnt = 0 ;
		for(int j= a[i-1]+1;j<a[i];j++)
		{
			res=cong(res,C[n-j][k-i]);
		}
	}
	res=cong(res,"1");
	cout<<res;
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
        xuly();
    }
    return 0;
}