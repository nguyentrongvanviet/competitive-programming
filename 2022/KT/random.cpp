
#include <iostream>
#include <cstdlib>
using namespace std;

int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int main(){
    freopen("i.txt","r",stdin) ; 
    freopen("o.txt","w",stdout);
    int min = 1, max = 10000;

    for (int i = 0;i < 18;i++) {
        cout << GetRandom(1,56)<<endl;
    }
    
    return 0;
}