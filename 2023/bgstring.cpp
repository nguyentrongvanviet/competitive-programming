#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =200+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m ; 
string s, x ; 
vector<string>v ;
bool dd[N][N][N] ; 
bool f[N][N][N] ; 
bool cmp(string a ,string b)
{
    if(a.size()==b.size())return a<b;
    return a.size()<b.size(); 
} 
bool tinh(int l , int r , int k)
{
    if(dd[l][r][k])return f[l][r][k] ;
    if(l>r)
    {
        if(k==0||k==x.size())return 1;  
        else return 0  ;
    }
    if(((r-l+1-(m-k))%m)!=0)
    {
        return f[l][r][k]=false;
    }
    dd[l][r][k]=1;   
    for(int i = l;i<=r;i++)
    {
        if(x[k]==s[i])
        {
            if(tinh(l,i-1,0)&&tinh(i+1,r,k+1))
            {
                return f[l][r][k] =1; 
            }
        }
    }
    return f[l][r][k]=0; 
}
void inp()
{
    cin>> s;
    n = s.size() ;
    s="#"+s;  
    for(int i= 1;i<=n;i++)
    {
        if(n%i==0)
        {
            for(int j=1;j<=n-i+1;j++)
            {
                v.pb(s.substr(j,i));
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it:v )
    {
        x= it ; 
        m=x.size() ; 
        if(tinh(1,n,0))
        {
            cout<<x ; 
            return ; 
        }
        for(int i= 1;i<=n;i++)
        {
            for(int j=i-1;j<=n;j++)
            {
                for(int t = 0 ;t<=x.size();t++)
                {
                    dd[i][j][t]=0;
                }
            }
        }
    }
    cout<<-1 ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
    inp();
    return 0;
}
