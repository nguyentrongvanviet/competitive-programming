#include<bits/stdc++.h>
using namespace std;

#define TASK "SPBINARY"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =600+5 ,  oo = INT_MAX ;
const ll sm = 1e9,cs=330 ,inf = LLONG_MAX;
string cong(string a, string b )
{
    string ans="";
    while(a.size()<b.size())a='0'+a; 
    while(b.size()<a.size())b='0'+b ; 
    int du =0  ; 
    for(int i= b.size()-1;i>=0;i--)
    {
        int tmp = a[i]+b[i]-'0'-'0'+du ;
        int c=tmp%10 ; 
        du =tmp/10 ; 
        ans=(char)(c+'0')+ans;  
    }
    if(du)
    {
        ans=(char)(du+'0')+ans; 
    }
    return ans; 
}
string tru(string a , string b)
{
    string ans="";
    while(b.size()<a.size())b='0'+b;
    int thieu = 0 ;  
    for(int i= b.size()-1;i>=0;i--)
    {
        int tmp = a[i]-b[i]-thieu ; 
        if(tmp<0)
        {
            tmp+=10 ; 
            thieu = 1 ; 
        }
        else thieu = 0;  
        int c= tmp%10 ; 
        ans=(char)(c+'0')+ans;
    }
    while(ans.size()>1&&ans[0]=='0')ans.erase(0,1);
    return ans;  
}
int n , k ; 
string s[N]  ,f[N]; 
void doc()
{
    cin>> n>> k;
   	s[0] = "1"; 
  	f[1] = "1"; 
  	s[1]= "2"; 
   	for(int i=2;i<=n;i++)
   	{
        string x= s[i-1] ; 
        string y= (i-k-1<0?"0":s[i-k-1]);
        f[i] =tru(x,y);
        f[i]  =tru(x,y);
        s[i] =cong(s[i-1],f[i]);
   	}
    cout<<cong(f[n],f[n]);
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