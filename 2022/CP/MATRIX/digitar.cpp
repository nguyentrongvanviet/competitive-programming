/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "digitar"

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

int n ; 
string s ; 
char a[N] ; 
bool cmp(string a, string b)
{	
	if(a.size()<b.size())return 1 ;
	if(a.size()>b.size())return 0 ; 
	return a<b;
}
string cong(string a , string b)
{
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b; 
	int nho = 0 ;
	string ans =  "" ;
	FORD(i,b.size()-1,0)
	{
		int tmp= a[i]-'0'+b[i]-'0'+nho ; 
		nho=tmp/10 ;
		int c= tmp%10 ; 
		ans=(char)(c+'0')+ans; 
	}
	if(nho)
	{	
		ans=(char)(nho+'0')+ans; 
	}	
	return ans ;
}
void doc()
{
    cin>>s ; 
    n  =s.size() ; 
    s='$'+s ;
    string res="";
    string s1 = "" ;
    FOR(i,1,n-2)
    {
    	s1=s1+s[i];
        int mid =(i+1+n)/2 ;
        ++mid ; 
    	string tmp ;
    	while(a[mid]=='0'&&mid<n)
    	{
    		 		++mid ;
    	}
    	string s3=s.substr(mid) ; 
    	string s2=s.substr(i+1,mid-1-(i+1)+1);
    	tmp =cong(cong(s1,s2),s3) ;
    	if(res==""||cmp(tmp,res))
    	{
    		res=tmp;
    	}
    	mid= (i+1+n)/2;
    	++mid; 
    	while(a[mid]=='0'&&mid>i)
    	{
    		--mid;
    	}
    	if(mid>i+1)
    	{
    		s3=s.substr(mid) ; 
			s2=s.substr(i+1,mid-1-(i+1)+1);
	    	tmp =cong(cong(s1,s2),s3) ;
	    	if(res==""||cmp(tmp,res))
	    	{
	    		res=tmp;
	    	}
    	}
    }
    cout<<res;
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}