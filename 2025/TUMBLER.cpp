#include<stdio.h> 
#include<vector>
#include<fstream>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std; 

int val[15] ; 
struct DL
{
    long long val; 
    int dis ; 
} ;
bool cmp(DL a , DL b)
{
    return a.val<b.val||(a.val==b.val&&a.dis<b.dis) ; 
}
vector<DL>A ; 
vector<DL>B ; 
void gofoward(int step)
{
    long long  V = 0 ; 
    for(int i=1;i<=14;i++)
    {
        V=V*15+val[i] ;
    }
    for(int i=1;i<=14;i++)A.push_back(DL{V,step}) ; 
    if(step==9)
    {
        return ;  
    }    

    {
        val[0] = val[1] ; 
        for(int i=1;i<=4;i++)
        {
            val[i] = val[i+1] ; 
        }
        val[5] = val[0] ; 
     
        gofoward(step+1) ;
     
        val[0] = val[5] ;  
        for(int i =5;i>=2;i--)
        {
            val[i]=val[i-1] ; 
        }
        val[1] = val[0] ; 
    }
    {

        int val14 = val[14] ; 
        for(int i = 14;i>=7;i--)
        {
            val[i] = val[i-1] ; 
        }
        val[6] = val[1] ;  
        val[1] = val14 ; 
        
        gofoward(step+1) ; 
        
        val14 = val[1] ; 
        val[1] = val[6] ; 
        for(int i=6;i<=13;i++)
        {
            val[i] = val[i+1]; 
        }
        val[14] = val14; 
    }
}
int res = 19 ; 
void gobackward(int step)
{
    long long V = 0 ; 
    for(int i=1;i<=14;i++)V=V*15+val[i];  
    for(int i=1;i<=14;i++)B.push_back(DL{V,step}) ; 
    if(step==9)return ; 
    
    {
        val[0] = val[5] ;  
        for(int i =5;i>=2;i--)
        {
            val[i]=val[i-1] ; 
        }
        val[1] = val[0] ; 
        gobackward(step+1); 
        val[0] = val[1] ; 
        for(int i=1;i<=4;i++)
        {
            val[i] = val[i+1] ; 
        }
        val[5] = val[0] ; 
    }
    {
        int val14 = val[1] ; 
        val[1] = val[6] ; 
        for(int i=6;i<=13;i++)
        {
            val[i] = val[i+1]; 
        }
        val[14] = val14; 

        gobackward(step+1) ; 

        val14 = val[14] ; 
        for(int i = 14;i>=7;i--)
        {
            val[i] = val[i-1] ; 
        }
        val[6] = val[1] ;  
        val[1] = val14 ; 

    }
}
void solve()
{ 
    // for(int i=1;i<=1000;i++)
    {
        A.clear() ; 
        for(int i=1;i<=14;i++)cin>>val[i]; 

        gofoward(0); 
        sort(A.begin(),A.end(),cmp) ;         
        int res = 19 ; 
        int id = 0 ; 
        for(int i=0;i<B.size();i++)
        {
            while(id<A.size()&&cmp(A[id],B[i]))
            {
                id++ ; 
            }
            if(id<A.size()&&A[id].val==B[i].val)
            {
                res = min(res,A[id].dis+B[i].dis) ; 
            }
        }
        cout<<res<<endl; 
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i=1;i<=5;i++)val[i]  = i ; 
    for(int i=6;i<=14;i++)val[i] = i-4 ;
    gobackward(0) ;  
    sort(B.begin(),B.end(),cmp) ;

    int test ; 
    cin>>test; 
    while(test--)
    {
        solve() ; 
    }
    // cerr<<"clocK"<<clock()<<"ms"<<endl;
    return 0 ; 
}