#include <bits/stdc++.h>
using namespace std;

#define NAME "p9robot1"
const int NTEST = 100;
#define ll long long 
#define rd rand
#define FOR(i,a,b) for(int i =a;i<=b;i++)
long long Rand(long long l, long long h) {
    return l + 1LL * rd() % (h - l + 1);
}

void create()
{
    ofstream cout(NAME  ".inp");

    int n=20 ; 
    int m=25; 
    int q= 10; 
    cout<<m<<" "<<n<<'\n'; 
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            if(i==1&&j==1)cout<<"." ; 
            else if(i==n&&j==m)cout<<"." ; 
            else 
            {
                int u = Rand(1,5) ; 
                if(u<=3)cout<<".";
                else cout<<"#";
            }cout<<"\n";
        }
    }    
    cout.close();
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        create();
        
        system(NAME"_trau.exe");
        system(NAME".exe");
        
        if (system("fc " NAME  ".OUT "  NAME  ".ANS") != 0)
        {
            cout << "Test " << iTest << ": Sai cmnr!!!\n";
            return 0;
        }
        else 
        {
            cout << "Test " << iTest << ": Accepted.\n";
        }
        
    }
    return 0;
}