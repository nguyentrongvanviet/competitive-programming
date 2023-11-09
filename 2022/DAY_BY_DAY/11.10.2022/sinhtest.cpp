#include <bits/stdc++.h>
using namespace std;

#define NAME "p9robot1"
const int NTEST = 1000;
#define ll long long 
#define rd rand

long long Rand(long long l, long long h) {
    return l + 1LL * rd() % (h - l + 1);
}

void create()
{
    ofstream cout(NAME  ".inp");

    int n=18; 
    int m=20;  
    cout<<m<<" "<<n<<'\n'; 
    for(int i= 1;i<=n;i++)
    {
        for(int j= 1;j<=m;j++)
        {
            if(i==1&&j==1)
            {
                cout<<".";
            }
            else if(i==n&&j==m)
            {
                cout<<".";
            }
            else 
            {
                int u  = Rand(1,4); 
                if(u<=3)cout<<"." ; 
                else cout<<"#";
            }
        }cout<<"\n";
    }
    cout.close();
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        create();
        system(NAME".exe");
        system(NAME"_trau.exe");
        
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