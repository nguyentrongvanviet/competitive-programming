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
const int N =3e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ;
int a[N]  ;  
int l[N] ; 
int r[N] ;  
int k ; 	
int res= 0 ; 
multiset<int> s;
void input()
{
 	cin>> n >> k ; 
 	for(int i=1 ;i<=n;++i)cin>>a[i] ; 
 	int la  =  1 ; 
 	for(int i=1 ;i<=n;i++)
 	{
 		s.insert(a[i]) ; 
 		while(s.size()>1)
 		{
 			if(abs(*s.begin()-*s.rbegin())>k)
 			{
 				s.erase(s.find(a[la])) ; 
 				la++ ; 
 			}
 			else 
 			{
 				break ;
 			}
 		}
 		l[i] =max(l[i-1],(int)s.size());
 	}
 	s.clear() ; 
 	la=n  ; 
 	for(int i = n;i>=1;i--)
 	{
 		s.insert(a[i]) ; 
 		while(s.size()>1)
 		{
 			if(abs(*s.begin()-*s.rbegin())>k)
 			{
 				s.erase(s.find(a[la])) ; 
 				la--;
 			}
 			else break;
 		}
 		r[i] =max(r[i+1],(int)s.size());
 	}
 	res=0 ; 
 	for(int i= 1;i<=n-1;i++)
 	{
 		res=max(res,l[i]+r[i+1]); 
 	}
 	cout<<res ; 
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
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}