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

struct dt
{
    int l , r ; 
    bool operator<(dt a )
    {
        return l <a.l ; 
    }
}
int n ; 

void inp()
{
    for(int i= 1 ;i<=n;i++)
    {
        int pos , bk ; 
        cin>>pos>>bk  ; 
        a[i].l  = pos-bk+1; 
        a[i].r= pos+bk-1; 
    }
    sort(a+1,a+n+1,cmp); 
    int it = 1;
      
    while(
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    while(cin>>n>>l>>w)
    {
        inp() ; 
    }
    return 0;
}