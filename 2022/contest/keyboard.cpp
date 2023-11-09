#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
int n , m; 
int T[N][30];  
int node= 1;
pii dd[N];  
int h[N]; 
int pa[N][25]; 
int tp[N]; 
void add(string s , int id )
{   
    int r= 1  ; 
    for(int i=  0 ; i<s.size();i++)
    {
        int j = s[i] - 'a' ; 
        if(T[r][j]==0)
        {
            ++node;
            h[node]=h[r]+1;
            pa[node][0]=r;
            tp[node]=id;  
            if(dd[id].X==0)dd[id].X=node; 
            T[r][j]=node;
        }           
        r=T[r][j] ;
    }
    if(dd[id].X!=0)
    {
        dd[id].Y=r;
    }
}
int lca(int u ,  int v )
{
    if(h[u]<h[v])
    { 
        swap(u,v);  
    }
    int dis=h[u]-h[v];    
    for(int i = 0 ;i<=22;i++)
    {
        if(dis>>i&1)
        {
            u=pa[u][i]; 
        }
    }
    if(u==v) return u ; 
    for(int i =22;i>=0;i--)
    {
        int nu =pa[u][i]; 
        int nv =pa[v][i];
        if(nu!=nv)
        {
            u=nu ; 
            v=nv ; 
        } 
    }
    return pa[u][0];
}
int solve(string s )
{   
    int r = 1;   
    for(int i = 0 ;i<s.size();i++)
    {
        int j = s[i]-'a'  ; 
        if(T[r][j]==0)
        {
            break ;   
        }
        r=T[r][j];
    }
    if(r==1)
    {
        return s.size() ; 
    } 
    int en =r; 
    r =T[1][s[0]-'a'];
    int res= 1;
    while(1)
    {
        int id= tp[r];
        int u =  dd[id].Y;
        int c = lca(u,en);
        res+=min(h[c]-h[r],h[u]-h[c]+1); 
        if(c==en)
        {
            break ; 
        }
        r= T[c][s[h[c]]-'a']; 
        res++; 
    }
    return res+s.size()-h[en]; 
}
void inp()
{
    cin>> n >>m;
    for(int i =1;i<=n;i++)
    {
        string s; 
        cin>>s;  
        add(s,i) ; 
    }
    for(int j =1;j<=22;j++)
    {
        for(int i= 1 ;i<=node;i++)
        {
            pa[i][j] = pa[pa[i][j-1]][j-1]; 
        }
    }
    for(int i =1 ;i<=m;i++)
    {
        string s;  
        cin>>s ;
        int u = solve(s);
        cout<<u<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}