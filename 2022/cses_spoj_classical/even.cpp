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

int n ; 
int a[N] ;
int dd[2][105][105][2] ; 
int f[2][105][105][2] ; 
ll tinh(int turn , int c , int l, int s )
{
    if(dd[turn][c][l][s])return f[turn][c][l][s]; 
    dd[turn][c][l][s] = 1; 
    if(c==0&&l==0)
    {
        if(s%2==0)return f[turn][c][l][s]=1 ; 
        else return f[turn][c][l][s]=2 ; 
    }
    if(turn ==1)
    {
        if(c>0)
        {
            if(tinh(1-turn,c-1,l,s)==1)return f[turn][c][l][s]=1 ; 
        }
        if(l>0)
        {
            if(tinh(1-turn,c,l-1,(s+1)%2)==1)return f[turn][c][l][s]=1; 
        }
        return f[turn][c][l][s]=2;  
    }
    else 
    {
        if(c>0)
        {
            if(tinh(1-turn,c-1,l,s)==2)return f[turn][c][l][s]= 2; 
        }
         if(l>0) 
        {
            if(tinh(1-turn,c,l-1,s)==2)return f[turn][c][l][s]=2; 
        }
        return f[turn][c][l][s]=1 ; 
    }
}
void inp()
{
    cin>> n; 
    memset(dd,0,sizeof(dd)); 
    int x = 0 , y = 0;
    for(int i=1 ;i<=n;i++)
    {
        cin>>a[i] ; 
        if(a[i]%2==0)
        {
            x++; 
        }
        else 
        {
            y++; 
        }
    }   
    cout<<(tinh(1,x,y,0)==1? "Alice":"Bob" );
    cout<<"\n";  
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test ;
    cin>>test;
    while(test--)inp();
    return 0;
}