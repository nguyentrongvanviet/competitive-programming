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

int n, k  ; 
int a[N] ; 
int bit[50][N] ;   
int s[50][N] ;
map<vector<int>,int> q; 
map<vector<int>,int>dd;
void inp()
{
    cin>>n>>k;  
    for(int i= 1; i<=n;i++)cin>>a[i] ;     
    for(int i= 1;i<=k;i++)
    {
        for(int j= 1 ;j<=n;j++)
        {
            if(a[j]>>(i-1)&1)bit[i][j]=1; 
            else bit[i][j]=0;
        }
    }
    for(int i = 1;i<=k;i++)
    {
        for(int j= 1;j<=n;j++)
        {
            s[i][j] = s[i][j-1]+bit[i][j] ;
        }
    }
    int res= 0 ; 
    vector<int>temp(k,0) ;
    q[temp]=0;
    dd[temp]=1 ;
    for(int i =1;i<=n;i++)
    {
        int mi = oo ; 
        for(int j =1 ;j<=k;j++)
        {
            mi =min(mi,s[j][i]); 
        }
        for(int  j= 1;j<=k;j++)
        {
            s[j][i]-=mi ; 
            temp[j-1]=s[j][i];
        }
        if(dd[temp]==0)
        {
            dd[temp]=1;
            q[temp]= i ; 
        }
        else
        {
            res=max(res,i-q[temp]) ;
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