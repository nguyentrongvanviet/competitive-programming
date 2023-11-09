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

struct bg 
{
    int sum ; 
    int du ; 
};  
struct cmp
{
    bool operator()(bg a , bg b )
    {
        return a.sum>b.sum;
    }
};  
int n ; 
int f[50][N] , dd[50][N] ; 
int su(int x )
{
    int ans =0; 
    while(x)
    {
        ans+=x%10 ; 
        x/=10 ; 
    }
    return ans; 
}
void dij()
{
    priority_queue<bg,vector<bg>,cmp>q ;
    int ma= su(n) ; 
    int res= ma;  
    for(int i= 1;i<=9;i++)
    {       
        q.push({i,i%n});
    }
    while(!q.empty())
    {
        int u = q.top().sum ; 
        int du = q.top().du ;
        q.pop(); 
        if(du==0)
        {
            cout<<u;
            return ; 
        }
        if(dd[u][du])continue ; 
        dd[u][du]=1; 
        for(int i= 0;i<=9;i++)
        {
            int nu = u+i;  
            int ndu = (du*10+i)%n;
            if(dd[nu][ndu]||nu>ma)continue;
            q.push({nu,ndu});
        }
    }
}
void inp()
{
    cin>> n ; 
    dij() ;    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}