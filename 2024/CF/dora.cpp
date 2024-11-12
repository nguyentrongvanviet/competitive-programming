#include <iostream>
using namespace std;

class sth{
    public:
    int data;
    
    sth& decrease_data(){
        data--;
        return *this;
    }
};
int main()
{   
    sth p;
    p.data = 5;
    p.decrease_data().decrease_data();
    cout << p.data; 


    return 0;
}