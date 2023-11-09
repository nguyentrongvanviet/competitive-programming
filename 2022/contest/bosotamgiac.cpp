#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ;
int a[N] ; 
void inp()
{
    cin>> n ; 
    for(int i= 1 ;i<=n;i++)cin>>a[i] ; 
    sort(a+1,a+n+1) ; 
    int res= 0 ; 
    for(int i= 3 ;i<=n;i++)
    {
        for(int j= i-1;j>=2;j--)
        {
            int  l =1 ; 
            int r = j-1 ;
            int x=oo;   
            while(l<=r) 
            {
                int mid =(l+r)/2; 
                if(a[mid]>a[i]-a[j])
                {
                    x=mid;  
                    r=mid-1; 
                }
                else
                {
                    l=mid+1; 
                }
            }
            l= 1; 
            r = j-1;  
            int y =0;
            while(l<=r)
            {
                int mid=(l+r)/2; 
                if(a[mid]<a[i]+a[j])
                {
                    y=mid; 
                    l=mid+1; 
                }
                else
                {
                    r=mid-1 ; 
                }
            }
            res+=max(0,y-x+1); 
        }
    }
    cout<<res;   
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}