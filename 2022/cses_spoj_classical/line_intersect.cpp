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

struct pt 
{
    int x , y;
};
struct line
{
    int a , b ; 
};
int n ; 
ll cross(pt a , pt b , pt c , pt d )
{
    pii A = {b.x-a.x,b.y-a.y}; 
    pii B ={}
}
void inp()
{
    for(int i= 1 ;i<=4;i++)
    {
        cin>>a[i].x>>a[i].y ;
    }
    if(cross()==0)
    {
        
    }
    else
    {
        cout<<"YES"<<"\n"; 
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test ;
    cin>>test ;
    while(test--)inp();
    return 0;
}