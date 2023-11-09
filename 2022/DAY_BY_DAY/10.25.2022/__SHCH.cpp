#include<bits/stdc++.h>
using namespace std;

#define TASK "SHCH"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =200+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;


string To_string(ll s)
{
	string res= "";  
	while(s)
	{
		res=(char)(s%10+'0')+res; 
		s/=10;
	}
	if(res=="")
	{
		return "0";
	}
	return res ; 
}
string cong(string a , string b )
{
	string res="" ; 
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b; 
	int du =0 ;  
	for(int i=  a.size()-1;i>=0;i--)
	{
		int tmp  =a[i]-'0'+b[i]-'0'+du;
		du= tmp/10 ; 
		int c=tmp%10 ; 
		res=(char)(c+'0')+res;
	}
	if(du>0)res='1'+res;
	return res ;
}
string tru(string a, string b)
{
	string res="";
	int thieu = 0 ;
	while(a.size()<b.size())
	{
		a='0'+b; 
	}
	while(b.size()<a.size())
	{
		b='0'+b;
	}
	for(int  i=b.size()-1;i>=0;i--)
	{
		int tmp = a[i]-'0'-(b[i]-'0')-thieu ;
		if(tmp<0)thieu=1,tmp+=10 ; 
		else thieu = 0 ;
		res=(char)(tmp+'0')+res;
	}
	while(res.size()>1&&res[0]=='0')
	{
		res.erase(0,1);
	}
	return res; 
}
string mul(string a , int b )
{
	string res= "" ; 
	int du= 0 ; 
	for(int i = a.size()-1;i>=0;i--)
	{
		int tmp = (a[i]-'0')*b+du ; 
		du= tmp/10;
		int c= tmp%10 ; 
		res=(char)(c+'0')+res;
	} 
	if(du)res=(char)(du+'0')+res;
	return res; 
}
string nhan(string a , string b )
{
	string res="";
	string zero=""; 
	for(int i = b.size()-1;i>=0;i--)
	{
		string tmp=mul(a,b[i]-'0');
		tmp+=zero;
		res=cong(res,tmp);
		zero+='0';
	}
	return res; 
}
bool ss(string a , string b)
{
	if(a.size()<b.size())return 1 ; 
	if(a.size()>b.size())return 0 ; 
	return a<=b;
}
int n , k ; 
string x;  
int a[N] ; 
string f[N];
int dd[N];
void doc()
{	
    cin>>n>> k;
    cin>>x ; 
    for(int i=1;i<=k;i++)cin>>a[i] ; 
}

void xuly()
{

	f[0] ="1";
	for(int i=1 ;i<=k;i++)
	{
		int x= n+i-k;
		string tmp = To_string(x) ; 
		f[i] =nhan(f[i-1],tmp);
	}
	x=tru(x,"1");
	for(int i=1 ;i<=k;i++)
	{
		for(int j =1 ;j<=n;j++)
		{
			if(dd[j]==0)
			{
				if(ss(f[k-i],x))
				{
					x=tru(x,f[k-i]);
				}
				else 
				{
					cout<<j<<" " ; 
					dd[j] =1 ;
					break;
				}
			}
		}
	}
	cout<<"\n"; 
	for(int i=1 ;i<=n;i++)dd[i]=0;
	string res="0";
	for(int i= 1;i<=k;i++)
	{	
		int cnt = 0 ; 
		for(int j= 1 ;j<a[i];j++)
		{
			if(dd[j]==0)
			{
				cnt++;
			}
		}
		dd[a[i]]=1;
		string tmp = To_string(cnt);
		res=cong(res,nhan(f[k-i],tmp));
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
}