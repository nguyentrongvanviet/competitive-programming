	#include<bits/stdc++.h>
	using namespace std;

	#define TASK "ADBRACK"

	#define ll long long
	#define pb push_back
	#define pk pop_back
	#define pii pair<int,int>
	#define fi first 	
	#define se second
	#define vii vector<int> 
	#define _sz(a) (int)a.size() 
	#define all(a) a.begin(),a.end()

	const int N =100+5 ,  oo = INT_MAX ;
	const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

	int n , k ; 
	int a[N] ; 
	map<char,int> id ;
	string cong(string a , string b)
	{
		string ans ="" ; 
		while(a.size()<b.size())a='0'+a; 
		while(b.size()<a.size())b='0'+b; 
		int du = 0 ; 
		for(int i = b.size()-1;i>=0;i--)
		{
			int tmp = a[i]-'0' +b[i]-'0'+du ; 
			int c = tmp%10 ; 
			du =tmp/10 ; 
			ans=(char)(c+'0')+ans;  
		}
		if(du)
		{
			ans=(char)(du+'0')+ans ;
		}
		return ans  ; 
	}
	string mul(string a , int b )
	{
		string ans="" ; 
		int du = 0;
		for(int i =a.size()-1;i>=0;i--)
		{	
			int tmp = (a[i]-'0')*b+du ; 
			int c =tmp%10 ; 
			du=tmp/10 ; 
			ans=(char)(c+'0') +ans ; 
		}
		if(du)
		{
			ans=  (char)(du+'0')+ans ;
		}
		return ans ;
	}
	string nhan(string a , string b)
	{	
		string ans ="" ; 
		string zero="";
		for(int i = b.size()-1;i>=0;i--)
		{
			string tmp =  mul(a,b[i]-'0');
			tmp+=zero;
			ans=cong(ans,tmp);
			zero+='0';
		}
		return ans;
	}
	string f[N][N];
	int dd[N][N];
	string tinh (int id , int s)
	{
		if(s>k)return "0";
		if(id==n+1)
		{
			if(s==0)return "1";
			return "0"; 
		} 
		if(dd[id][s])return f[id][s];
		string ans ="";
		if(s>0)
		{		
			ans=cong(ans,tinh(id+1,s-1));
		}	
		if(s<k)
		{
			ans=cong(ans,tinh(id+1,s+1));
		}
		dd[id][s]=1 ; 
		return f[id][s] =ans; 
	} 
	string mu[N];
	void doc()
	{
	    cin>> n>> k ;
	    id['(']=1 ; 
	    id[')']=2 ; 
	    id['[']=3 ;
	    id[']']=4 ;
	    id['{']=5 ; 
	    id['}']=6 ;
	    mu[0]="1";
	    for(int i=1 ;i<=n;i++)
	    {
	    	mu[i] =nhan(mu[i-1],"3") ; 
	    }
	    for(int i=1 ;i<=n;i++)
	    {
	    	char c ; cin>>c ;
	    	a[i] = id[c];
	    }  
	    string res ="";
	    int s = 0 ;  
	    stack<int>bracket;
	    for(int i= 1;i<=n;i++)
	    {
	    	for(int j = 1;j<a[i];j+=2)
	    	{
	    		if(n-i-s-1<0)continue;
	    		res =cong(res,nhan(mu[(n-i-s-1)/2],tinh(i+1,s+1)));
	    	}
	    	if(a[i]&1&&!bracket.empty())
	    	{
	    		int u = bracket.top();
	    		if(u+1<a[i])
	    		{
	    			res=cong(res,nhan(mu[(n-i-(s-1))/2],tinh(i+1,s-1)));
	    		}
	    	}
	    	if(a[i]&1)
	    	{
	    		s++ ; 
	    		bracket.push(a[i]) ;
	    	}
	    	else 
	    	{	
	    		bracket.pop();
	    		s-- ;
	    	}
	    }
	    cout<<cong(res,"1");
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