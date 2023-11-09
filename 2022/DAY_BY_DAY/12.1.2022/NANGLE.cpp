#include<bits/stdc++.h>
using namespace std;

#define TASK "NANGLE"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20  ; 
double  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
double sq(double a)
{
	return a*a; 
}
struct DL  
{
	double val;  
	int id;  
	bool operator <(const DL&a)const
	{
		return val<a.val; 
	}  
};

int n  ; 
double P ,  Q  ; 
DL a[N] ;

void doc()
{
 	cin>>n >>P>>Q  ; 

 	FOR(i,1,n)cin>>a[i].val  , a[i].id = i ;

}

bool check(ll a,ll b,ll c )
{
	return Q*(sq(a)+sq(b))-2*a*b*P>=sq(c)*Q; 
}

int tknp(int i , int j )
{
	int l =1 ; 
	int r=  n; 
	int ans =-1; 
	while(l<=r)
	{
	 	int mid =(l+r)/2;
	 	if(check(a[i].val,a[j].val,a[mid].val))
	 	{
	 		ans= mid ;
	 		l=mid+1; 
	 	} 
	 	else 
	 	{
	 		r=mid-1;
	 	}
	}
	return ans;  
}
struct BBD
{
	int a, b, c ; 
};
double cosin(BBD tmp)
{	
	double A= a[tmp.a].val;
	double B = a[tmp.b].val; 
	double C =a[tmp.c].val;
	return (sq(A)+sq(B)-sq(C))/(2*A*B); 
}
// a>b -> 1 
bool cmp(BBD a, BBD b )
{
	if(P<=0)
	{
		return cosin(a)<=cosin(b);
	}	
	return cosin(a)>=cosin(b);
}
void xuly()
{
    sort(a+1,a+n+1) ; 
    BBD res={0,0,0}; 
  	FOR(i,1,n)	
    {
    	FOR(j,i+1,n)
    	{
    		int k = tknp(i,j); 
    		if(k==j)--k;
    		if(k==i)--k;
    		while(!(a[i].val+a[j].val>a[k].val&&a[i].val+a[k].val>a[j].val)&&k>0)--k;
    		if(k<=0)continue;
    		if(res.a==0||cmp(res,BBD{i,j,k}))
    		{	
    			res={i,j,k};
    		}
    	}
    }
    if(res.a==0)
    {
    	cout<<-1 ;
    }
    else
    {
    	// cout<<res.a<<" "<<res.b<<" "<<res.c<<endl;
    	cout<<a[res.a].id<<" "<<a[res.b].id<<" "<<a[res.c].id;
    }
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}