#include<bits/stdc++.h>
using namespace std;

#define TASK "hanoitower"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

int n ;
int x =0;
void  tower(int a , char x , char y, char z ){
    if (a==1){
        cout<<x<<z<<endl;
        // x+=1
    }else { tower(a-1 ,x,z,y );cout<<x<<z<<endl;
    tower(a-1,y,x,z);
    }
}
int main(){
    IOS();
    cin>>n;
    tower(n,'A','B','C');
 
}