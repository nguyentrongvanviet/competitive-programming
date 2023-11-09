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
int n , k ;
unordered_map<int,int>sl;  
int a[N];
void inp()
{
    cin>>n>>k ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i]  ; 
    }
    int st = 1 ; 
    sl[a[1]]++; 
    int dif=1; 
    int res= 1; 
    for(int i= 2;i<=n;i++)
    {
        if(sl[a[i]]==0)
        {
            dif++ ; 
        }
        sl[a[i]]++;
        if(dif<=k+1)
        {
            res=max(res, sl[a[i]]);
            continue ;
        }
        while(dif>k+1)
        {
            sl[a[st]]-- ; 
            if(sl[a[st]]==0)
            {
                dif--;
            }
            st++;
        }
        res=max(res, sl[a[i]]);
    }
    cout<<res; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}