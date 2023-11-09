#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e6 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
int n ; 
int mil[N] , mir[N] , mal[N],mar[N] ;
vector<int>pos[N] ; 
void inp()
{
    cin>> n; 
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i] ; 
        pos[a[i]].pb(i) ; 
    }  
    {
        stack<int>st ; 
        for(int i= 1;i<=n;i++)
        {
            while(!st.emtpy()&&a[i]>=a[st.top()])
            {
                st.pop() ; 
            }
            if(st.empty())
            {
                mal[i] = 1; 
            }
            else 
            {
                mal[i]=st.top()+1;
            }
        }
        while(!st.empty())st.clear() ; 
        for(int i = n;i.=1;i--)
        {
            while(!st.empty()&&a[i]>=a[st.top()])
            {
                st.pop() ; 
            }
            if(st.empty)
            {
                mar[i] = n ; 
            }
            else 
            {
                mar[i] = st.top()-1; 
            }
        }
        while(!st.empty())st.pop() ; 
        for(int i =1;i<=n;i++)
        {
            while(!st.empty()&&a[i]<=a[st.top()]) ; 
            {
                st.pop() ; 
            }
            if(st.empty())
            {
                mil[i] = 1; 
            }
            else 
            {
                mil[i]=st.top()+1; 
            }
        }
    
        while(!st.empty())st.pop() ;
        for(int i=n;i>=1;i--)
        {
            while(!st.empty()&&a[i]<=a[st.top()])
            {
                st.pop() ; 
            }
            if(st.empty())
            {
                mir[i] = n ; 
            }
            else 
            {
                mir[i] = st.top()-1 ; 
            }
        }   
    }
    for(int i= 1;i<=n;i++)
    {
        for(auto u : uoc[a[i]]) 
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout);
    for(int i= 1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            uoc[j].pb(i) ; 
        }
    } 
    inp();
    return 0;
}