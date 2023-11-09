#include<bits/stdc++.h>
using namespace std;

#define TASK "PTIT121K"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =105	 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
string f[N][N];
char a[N][N] ;
string convert(string s)
{
	while(s.size()%4!=0)
	{
		s='0'+s ;
	}
	string res ="";
	for(int i =0 ; i<s.size();i+=4)
	{
		string tmp = s.substr(i,4) ; 
		int val= 0 ;
		for(int j = 0 ;j<4;j++)
		{
			val+= (tmp[j]-'0')*pow(2,3-j);
		}
		if(val<10&&val>0)
		{
			res+=(char)(val+'0');
		}
		else 
		{
			res+=('A'+val-10);
		}
	}
	while(res.size()>1&&res[0]==0)
	{
		res.erase(0,1);
	}
	if(res=="")return "0";
	return res; 
} 
void doc()
{
    cin>>n ; 
    for(int i= 1;i<=n;i++)
    {
    	for(int j=1 ;j<=n;j++)
    	{
    		cin>>a[i][j] ; 
    	}
    }
    for(int i =1 ;i<=n;i++)
    {
    	for(int  j=1 ;j<=n;j++)
    	{
    		if(i==1&&j==1)
    		{
    			f[i][j] = a[1][1] ; 
    		}
    		else
    		{
    			if(i==1)
    			{
    				f[i][j] =f[i][j-1]+a[i][j];
    			}
    			else if(j==1)
    			{
    				f[i][j] = f[i-1][j]+a[i][j] ;
    			}
    			else f[i][j] =max(f[i-1][j],f[i][j-1])+a[i][j];
    		}
    	}
    }
 	string res = convert(f[n][n]) ; 
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
    }
    return 0;
}