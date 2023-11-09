#include<bits/stdc++.h>
using namespace std;

#define TASK "ediv"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second 
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

const int N =1e5+12 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
vector<int>L ; 
vector<int>R ; 
int a[N] ;
int x[N] ; 
void doc()
{
 	cin>>n ; 
 	FOR(i,1,n)
 	{
 		cin>>a[i] ; 	
 		if(a[i]==1)
 		{
 			L.pb(i) ; 
 		}
 		else 
 		{
 			R.pb(i) ; 
 		}
 		cin>>x[i] ;
 	}	   
}
int rd(int  l , int r )
{
	return l+rand()%(r-l+1);
}
pii res[N] ;
bool dd[N] ;
int t= 0  ; 
void xuly()
{

	// sort(all(L),cmp);
	bool ok  =  0 ; 
	FOR(i,1,n/2-1)
	{
		if(x[L[i]]!=x[L[i-1]])
		{
			ok= 1; 
			break ; 
		}
	}
	if(!ok)
	{
		cout<<-1 ; 
		return ; 
	}
	ok = 0 ;
	FOR(i,1,n/2-1)
	{
		if(x[R[i]]!=x[R[i-1]])
		{
			ok =1 ; 
		break; 
		}
	}
	if(!ok)
	{
		cout<<-1 ; 
		return ; 
	}
	FOR(i,0,n/2-1)
	{
		while(1)
		{
			int id= rd(0,n/2-i-1);	
			if(x[L[i]]!=R[id]&&x[R[id]]!=L[i])
			{
				res[i] ={L[i],R[id]};
				swap(R.back(),R[id]);
				R.pk();
				break; 
			}	
		}
	}
	FOR(i,0,n/2-1)cout<<res[i].fi<<" ";
	cout<<"\n"; 
	FOR(i,0,n/2-1)cout<<res[i].se<<" ";
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}