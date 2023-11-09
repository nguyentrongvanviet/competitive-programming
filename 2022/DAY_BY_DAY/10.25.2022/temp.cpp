#include<bits/stdc++.h>
using namespace std;

#define TASK "temp"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 

string cong(string a , string b )
{
	string res=""  ; 
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b; 
	int carry = 0 ;
	for(int i= a.size()-1;i>=0;i--)
	{
		int tmp = a[i]-'0'+b[i]-'0'+carry ; 
		carry= tmp/10 ; 
		tmp%=10 ; 
		res=(char)(tmp+'0')+res;
	}
	if(carry>0)res='1'+res; 
	return res; 
}
string tru(string a , string b )
{
	string res =""; 
	bool neg =false ;
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b; 
	if(a<b)swap(a,b),neg=true;
	int borrow = 0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int tmp = a[i]-'0'-(b[i]-'0')-borrow;
		if(tmp<0)
		{
			tmp+=10 ; 
			borrow =1 ; 
		} 
		else borrow = 0  ;
		res=(char)(tmp+'0')+res;
	}
	while(res.size()>1&&res[0]=='0')res.erase(0,1);
	if(neg)res='-'+res;
	return res ; 
}
string mul(string a , int b )
{
	string res="" ; 
	int nho = 0 ; 
	for(int  i= a.size()-1;i>=0;i--)
	{
		int tmp = (a[i]-'0')*b+nho;
		int x = tmp%10 ; 
		nho = tmp/10 ; 
		res=(char)(x+'0')+res;
	}
	if(nho>0)
	{
		res=(char)(nho+'0')+res;
	}
	return res ;
}
string nhan(string a , string b)
{
	string res="";
	string so="";
	for(int i= b.size()-1 ; i>=0;i--)
	{
		string tmp= mul(a,b[i]-'0');
		tmp +=so;
		res=cong(res,tmp);
		so+='0';
	}
	return res;
}
bool ss(string a , string b)
{
	if(a.size()<b.size())return 1; 
	if(a.size()>b.size())return 0 ;
	return !(a<b); 
}
void doc()
{	

}	
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    
    return 0;
}