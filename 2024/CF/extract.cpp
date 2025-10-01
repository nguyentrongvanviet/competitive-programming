#include<bits/stdc++.h>

int main() {
    freopen("text.INP","r",stdin) ;
    freopen("text.OUT","w",stdout) ; 
    std::string text;
    std::string line;
    int lineNumber = 0;

    int t = 0; 
    while (std::getline(std::cin, line) ) {
        ++t ;
        if(t%4==3)
        {
            std::cout<<line<<std::endl;
        }
    }

    return 0;
}