#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =  1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , t;  
int a[N] ; 
void inp()
{
    cin>> n>>t ;
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i] ; 
    }   
    int res=0 ; 
    for(int i= 1;i<=n;i++)
    {
        int themi = a[i]-t ;
        int thema = a[i]+t ;
        int len = 1;   
        for(int j =i-1;j>=1;j--)
        {
            if(a[j]>=themi&&a[j]<=thema)
            {
                themi=max(themi,a[j]-t) ; 
                thema=min(thema,a[j]+t) ; 
                len++; 
            }
            else 
            {
                break ; 
            }
        }
        res=max(res,len);
    }
    cout<<res ; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}