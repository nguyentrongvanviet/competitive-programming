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
string s ; 
void inp()
{   
    vector<int>res;  
    cin>>s;
    int n  = s.size() ; 
    s='!'+s;
    int mi = s[n]-'0';   
    res.pb(mi);
    for(int i=n-1;i>=1;i--)
    {
        if(s[i]-'0'<=mi)
        {
            mi =min(s[i]-'0',mi) ; 
            res.pb(s[i]-'0') ; 
        }
        else 
        {
            res.pb(min(9,s[i]-'0'+1)) ; 
        }
    } 
    sort(res.begin(),res.end());
    for(auto it : res)
    {
        cout<<it;
    }cout<<"\n";  
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test; 
    cin>>test ; 
    while(test--)inp();
    return 0;
}