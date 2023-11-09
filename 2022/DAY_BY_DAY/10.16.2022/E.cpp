#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =1e8+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int  f[N];
int   p , q ;
int dd[10001][10001];
void input()
{
	if(p==q)
	{
		cout<< 0 ; 
		return ; 
	}
 	if(dd[p/__gcd(p,q)][q/__gcd(p,q)])
 	{
 		if(dd[p/__gcd(p,q)][q/__gcd(p,q)]==1e9) cout<<0<<endl;
 		else	cout<<dd[p/__gcd(p,q)][q/__gcd(p,q)]<<endl;
 		return;
 	}
 	cout<<-1<<"\n"; ;
}
void output()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    f[0] =1 ;
    for(int i =1 ;i<=(int)1e7;i++)
 	{
 		if(i%2==0)
 		{
 			f[i] =f[i/2]+f[i/2-1] ; 
 		}
 		else 
 		{
 			f[i]=f[i/2];
 		}
 		// if(dd[f[i-1]/__gcd(f[i],f[i-1])][f[i]/__gcd(f[i],f[i-1])]==0 && i-1>0)
 		// dd[f[i-1]/__gcd(f[i],f[i-1])][f[i]/__gcd(f[i],f[i-1])] = i-1;
 		// if(i==1) dd[f[i-1]/__gcd(f[i],f[i-1])][f[i]/__gcd(f[i],f[i-1])]=1e9;
 	}   
    while(cin>>p>>q)
    {
        input();
        output(); 
    }
    return 0;
}