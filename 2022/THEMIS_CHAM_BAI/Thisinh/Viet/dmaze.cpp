#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =6e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , m , k  ,p  , q , a, b , c;
int dd[N];  
int pre[N] ; 
ll f[N] ;
void inp()
{

    cin>> m>>n>>k ;  
    cin>>p>>q>>a>>b>>c;
    dd[q] = 1;  
    for(int i =1 ;i<=p-1;i++)
    {
        q=(q*a+b)%c+1;  
        dd[q] =1;   
    }
    for(int i= 1 ;i<=m*n;i++)
    {
        f[i] =0; 
    }
    int res= 0; 
    for(int i= 1 ; i<=m;i++)
    {
        for(int j= 1 ;j<=n;j++)
        {
            int id = i+(j-1)*m;  
            if(dd[id])
            {
                f[id] =-inf ; 
                continue;  
            }
            if(id>1&&(id-1)%m!=0)if(f[id-1]+1>f[id])
            {
                f[id] = f[id-1]+1 ; 
                pre[id] =id-1; 
            }
            if(id>m)if(f[id-m]+1>f[id])
            {
                f[id] = f[id-m]+1;
                pre[id] = id-m ;  
            }
            if(id-m-1>0&&(id-1)%m!=0)if(f[id-m-1]+1>f[id])
            {
                pre[id] = id-m-1;  
                f[id] = f[id-m-1]+1 ;    
            }
            if(f[res]<f[id])
            {
                res=id; 
            }
        }
    }
    vector<int>pos ; 
    while(res)
    { 
        pos.pb(res);
        res=pre[res]; 
    }
    if(pos.size()<k)cout<<-1 ; 
    else 
    {
        cout<<pos.size()<<"\n"; 
        reverse(pos.begin(),pos.end()) ; 
        for(int  i=  0 ;i<pos.size();i++)
        {
            cout<<pos[i]<<" "; 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("DMAZE.INP","r",stdin); 
    freopen("DMAZE.OUT","w",stdout); 
    inp();
    return 0;
}