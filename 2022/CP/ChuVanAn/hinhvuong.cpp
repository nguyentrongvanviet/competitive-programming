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
const int N =2e5+5 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 

void input()
{
 	cin>> n; 
 	int miX= oo, miY =oo , maX=-oo , maY=-oo;
 	for(int i= 1;i<=n;i++)
 	{
 		int x , y ; 
 		cin>>x>>y ;  
 		maX=max(maX,x) ; 
 		maY=max(maY,y) ; 
 		miX=min(miX,x) ; 
 		miY=min(miY,y) ; 
 	}   
 	cout<<max((maX-miX),(maY-miY))*max((maX-miX),(maY-miY));
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