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
#define int long long
struct pt 
{
    int x, y ; 
}; 
pt p[N];
int n ;
map<pii,int>dd; 
ll ma , mi , slma , slmi ;
ll dthcn(pt a , pt b )
{
    return abs(1LL*(b.x-a.x)*(b.y-a.y)) ; 
}  
void inp()
{
    cin>> n ; 
    ma= -inf ; 
    mi =inf;
    slma= 0 ;  
    slmi = 0 ;
    for(int i  =1; i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;  
        dd[{p[i].x,p[i].y}]=1; 
    }
    ll res= 0 ; 
    for(int i =1;i<=n;i++)
    {
        for(int j =i+1;j<=n;j++)
        {
            if(p[i].x==p[j].x||p[i].y==p[j].y) continue ; 
            if(dd[{p[i].x,p[j].y}]!=0&&dd[{p[j].x,p[i].y}]!=0) 
            {
                res++  ; 
                ll hcn = dthcn(p[i],p[j]) ; 
                if(hcn>ma)
                {
                    ma= hcn ; 
                    slma=1; 
                }
                else if(hcn==ma)
                {
                    slma++ ; 
                }
                if(hcn<mi)
                {
                    mi = hcn ; 
                    slmi= 1 ; 
                }
                else if (hcn==mi) 
                {
                    slmi++ ; 
                }
            }
        }
    }
    if(res==0) 
    {
        cout<< 0 ;
        return ;
    }
    cout<<res/2<<endl;
    cout<<ma<<" "<<slma/2<<"\n"; 
    cout<<mi<<" "<<slmi/2;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}