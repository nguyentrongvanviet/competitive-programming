#include<bits/stdc++.h>
using namespace std ;


class A {
private:
    int value;  // Example data member

public:
    // Constructor to initialize value
    A(int val = 0) : value(val) {}

    // Prefix increment operator (++A)
    A& operator++() {
        ++value;        // Increment the value
        return *this;   // Return the updated object by reference
    }
    // Postfix increment operator (A++)
    A operator++(int) {
        A temp(*this); // Create a copy of the current state
        ++value;        // Increment the value
        return temp;    // Return the original state (copy)
    }

    // Optional: Accessor to get the current value
    int getValue() const {
        return value;
    }
    friend ostream& operator<<(ostream& out, const A& rhs);
}; 
ostream& operator<<(ostream& out , const A&rhs)
{
	out<<rhs.value ; 
	return out ; 
}
signed main()
{	
	A x(10) ; 
	cout<<(++x)<<endl;
	cout<<x<<endl;
}