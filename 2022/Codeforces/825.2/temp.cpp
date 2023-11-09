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
#define int long long 
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int a[N];
ll s1[N] ,s2[N] ; 
void input()
{
    cin>> n;  
    for(int i=1;i<=n;i++)cin>>a[i] ;
}
void output()
{
   	vector<int>leftmost(n+1) ; 
   	vector<int>rightmost(n+1) ; 
   	vector<int>rightsecondmost(n+1) ; 
   	for(int l = 1,r=1,r2=1;l<=n;l++)
   	{
   		while(r<=n&&a[r]>=r-l+1)
   		{
   			leftmost[r]=l ; 
   			r++ ; 
   		}
   		rightmost[l]=r-1; 
   		r2=max(r2,min(r+1,n+1)) ; 
   		while(r2<=n&&a[r2]>=r2-l+1)
   		{
   			r2++ ; 
   		}
   		rightsecondmost[l]=r2-1;
   	}
   	vector<ll>s1(n+1) ; 
   	vector<ll>s2(n+1) ; 
   	for(int i=1;i<=n;i++)
   	{
   		s1[i] =s1[i-1]+rightmost[i]-i+1; 
   		s2[i] =s2[i-1]+rightsecondmost[i]-i+1;
   	}
   	ll total = s1.back();
   	int q; 
   	cin>>q; 
   	while(q--)
   	{
   		int p ,x ; 
   		cin>>p>>x ; 
   		if(a[p]==x)
   		{
   			cout<<total<<"\n";
   		}
   		else if(x<a[p]) 
   		{
 			int nowleftmost=max(p-x+1,leftmost[p]);
 			if(nowleftmost==leftmost[p])
 			{
 				cout<<total<<"\n";
 				continue; 
 			}  			
 			ll cutoff = s1[nowleftmost-1]-s1[leftmost[p]-1];
            ll remain = (p-nowleftmost+p-leftmost[p]+1)*(nowleftmost-leftmost[p])/2; 
            cout<<total-cutoff+remain<<"\n";
   		}
        else 
        {
            int nowleftmost=max((ll)(lower_bound(rightmost.begin()+1,rightmost.end(),p-1)-rightmost.begin()),p-x+1LL); 
            if(nowleftmost==leftmost[p])
            {
                cout<<total<<"\n";
                continue; 
            }
            ll oldsum=s1[leftmost[p]-1]-s1[nowleftmost-1];
            ll newsum=s2[leftmost[p]-1]-s2[nowleftmost-1];
            cout<<total-oldsum+newsum<<"\n";
        }
   	}
}
signed main()
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