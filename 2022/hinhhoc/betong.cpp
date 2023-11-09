#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long 
struct bg 
{
    int h, id ; 
};
int n ; 
bg b[N] ; 
int tt = 0 ; 
int res= 0 , pre= 0 ;
int dd[N]; 
int a[N];
vector<int>pos ;
bool cmp(bg a , bg b )
{
    return a.h<b.h ;  
}
void inp()
{
    cin>> n ;
    for(int i =1;i<=n;i++)
    {
        cin>>a[i] ;  
    }   
    a[0] = -oo ; 
    for(int i= 1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            b[++tt].h=a[i]; 
            b[tt].id = tt; 
        } 
    }
    sort(b+1,b+tt+1,cmp) ; 
    n=tt; 
    int it = n ; 
    while(it) 
    {
        pos.pb(b[it].id); 
        while(it-1>=1&&b[it-1].h==b[it].h)
        {
            it--;
            pos.pb(b[it].id); 
        }
        int ans=0 ; 
        for(int i = 0 ;i<pos.size();i++)
        {
            if(dd[pos[i]-1]&&dd[pos[i]+1])
            {
                ans-=1;    
            }
            else if(dd[pos[i]-1]||dd[pos[i]+1])
            {
                // cout<<pos[i]-1<<" "<<pos[i]+1<<endl;
                ans+=0 ;
            }
            else 
            {
                if(pos[i]-1>=1||pos[i]+1<=n)
                {
                    ans+=1;
                }
            }
            dd[pos[i]]=1 ; 
        }
        it--;
        pre=pre+ans;  
        res=max(res,pre) ;  
        pos.clear() ;   
    }
    cout<<res ; 
}   

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}