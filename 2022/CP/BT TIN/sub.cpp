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

void inp()
{
    string s ;
    cin>>s; 
    map<string,int>dd;
    int res =0  ;  
    int n =s.size() ; 
    for(int i =1;i<(1<<n);i++)
    {
        string tmp=""; 
        for(int j= 0 ;j<n;j++)
        {
            if(i>j&1)
            {
                tmp+=s[j];
            }
        }
        if(dd[tmp]==0)
        {
            dd[tmp]=1; 
            res++ ; 
        }
    }
    cout<<res<<"\n";
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