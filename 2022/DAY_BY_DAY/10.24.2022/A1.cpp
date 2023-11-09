#include<bits/stdc++.h>
using namespace std;
#define TASK "A1"
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
int a[N]  ;
void doc()
{
	cin>> n; 
	for(int i= 1;i<=n;i++)cin>>a[i] ; 
	if(n&1)
	{
		cout<<-1<<"\n";
		return  ; 
	}
	vector<pii>q;     
	for(int i=2 ;i<=n;i+=2)
	{
		if(a[i]==a[i-1])
		{
			q.pb({i-1,i});
		}
		else 
		{
			q.pb({i-1,i-1});
			q.pb({i,i});
		}
	}
	cout<<q.size()<<"\n" ;
	for(int i= 0 ;i<q.size();i++)
	{
		cout<<q[i].fi<<" "<<q[i].se<<"\n";
	}
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
    cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}