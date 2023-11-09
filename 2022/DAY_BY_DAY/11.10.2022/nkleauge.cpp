#include<bits/stdc++.h>
using namespace std;

#define TASK "nkleauge"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =1e3+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , m;  
int a[N][N]  , b[N] ; 
bool cmp(int  x , int y)
{
    return a[x][y]==1;
}
void Sort(int l , int r )
{
    int mid = (l+r)/2;  
    int id = b[mid] ; 
    if(l>=r)return ; 
    int i = l ; 
    int j = r ; 
    while(i<=j)
    {
        while(a[b[i]][id]==1)
        {
            i++; 
        }
        while(a[id][b[j]]==1)
        {
            j--;
        }
        
        if(i<=j)
        {
            swap(b[i],b[j]);
            i++;
            j--;
        }
    } 
    Sort(l,j) ; 
    Sort(i,r) ;
}
void doc()
{
    cin>> n ; 
    FOR(i,1,n)FOR(j,1,n)
    {
        char x ; cin>>x ; 
        a[i][j] = (x=='1'); 
    }
    FOR(i,1,n)
    {
        b[i]= i ; 
    }
    sort(b+1,b+n+1,cmp);
    FOR(i,1,n)
    {
        cout<<b[i]<<" ";
    }
    // Sort(1,n);
    // FOR(i,1,n)
    // {
    //     cout<<b[i]<<" ";
    // }
}	
int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    // cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}