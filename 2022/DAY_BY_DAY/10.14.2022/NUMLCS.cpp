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
const int N =1e3+5 ,  oo = 1e9 ;
const ll sm =  20030101,cs=330 ,inf = 1e17;

int n  , m ; 
int a[N] , b[N]; 
int ne1[N][30];
int ne2[N][30];
int la[30];
int f[N][N]; 
ll sl[N][N];
int ma = 0 ; 
ll res =0  ;
string s1 ,s2 ; 
void input()
{
 	cin>>s1>>s2;   
    n=s1.size() ; 
    m=s2.size() ; 
    for(int i= 1;i<=n;i++)
    {
        a[i] =s1[i-1]-'a'+1; 
    }
    for(int i=1;i<=m;i++)
    {
        b[i] =s2[i-1]-'a'+1;
    }
}
void output()
{
    ma= 0;  
    res= 0 ;
    for(int i= 1;i<=26;i++)la[i] = n+1;  
    for(int i = n;i>=0;i--)
    {
        for(int j = 1; j<=26;j++)
        {
            ne1[i][j]=la[j];
        }
        la[a[i]]=i;
    }
    for(int i= 1;i<=26;i++)la[i]=m+1; 
    for(int i=m;i>=0;i--)
    {
        for(int j=  1;j<=26;j++)
        {
            ne2[i][j] = la[j] ; 
        }
        la[b[i]]= i ; 
    }
    for(int i=0;i<=n;i++)
    {
        for(int j= 0 ; j<=m;j++)
        {
            f[i][j] = 0 ; 
            sl[i][j] = 0 ;
        }
    }
    sl[0][0]=1 ; 
    for(int i=0 ;i<=n;i++)
    {
        for(int j= 0;j<=m;j++)
        {
            if(a[i]!=b[j])continue ; 
            if(a[i]==b[j])
            {
                for(int t= 1 ;t<=26;t++)
                {
                    int ni=ne1[i][t]; 
                    int nj=ne2[j][t];
                    if(f[ni][nj]<f[i][j]+1)
                    {
                        f[ni][nj]=f[i][j]+1 ; 
                        sl[ni][nj]=sl[i][j];
                    }
                    else if(f[ni][nj]==f[i][j]+1) 
                    {
                        sl[ni][nj]=(sl[i][j]+sl[ni][nj])%sm;
                    }
                }
            }
            ma=max(ma,f[i][j]) ;
        }
    }
    for(int i=1 ;i<=n;i++)
    {
        for(int j= 1;j<=m;j++)
        {
            if(f[i][j]==ma)
            {
                res=(res+sl[i][j])%sm;
            }
        }
    }
    cout<<ma<<" "<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}