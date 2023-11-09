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
unordered_map<string,int>cnt; 
void inp()
{
    cin>> n ; 
    for(int i = 1;i<=n;i++)
    {
        int t ;
        string s ; 
        cin>>t>>s ;
        if(t==1)
        {
            cnt[s]++ ; 
        }
        else 
        {
            cout<<cnt[s]<<"\n";
        }
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