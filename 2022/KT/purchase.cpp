#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define int long long 
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
int n  , k ;
struct cmp
{
    bool operator()(ll a , ll b )
    {
        return a<b ; 
    }
};  
stack<pii>st;  
ll a[N];
priority_queue<ll,vector<ll>,cmp>q;  
void inp()
{
    cin>> n >> k ; 
    for(int i= 1 ;i<=n;i++)cin>>a[i];
    int buy= 1;
    int sell= 0;   
    while(buy<=n-1)
    { 
        while(buy+1<=n-1&&a[buy]>=a[buy+1])
        {
            buy++; 
        }
        sell =buy+1 ;
        while(sell+1<=n&&a[sell]<=a[sell+1])
        {
            sell++ ; 
        }
        if(a[buy]>=a[sell])break ;
        // if(buy==sell)break; 
        while(!st.empty()&&a[buy]<a[st.top().X]) 
        {
            q.push({a[st.top().Y]-a[st.top().X]});
            st.pop();
        }
        while(!st.empty()&&a[sell]>=a[st.top().Y])
        {
            q.push(a[st.top().Y]-a[buy]);
            buy = st.top().X;  
            st.pop()  ; 
        }
        st.push({buy,sell});
        buy =sell+1; 
    }
    while(!st.empty())
    {
        q.push(a[st.top().Y]-a[st.top().X]); 
        st.pop() ; 
    }   
    ll res= 0 ; 
    for(int i =1;i<=k;i++)
    {
        if(q.empty())
        {
            break ; 
        }
        res+=q.top();
        q.pop(); 
    }
    cout<<res; 
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}