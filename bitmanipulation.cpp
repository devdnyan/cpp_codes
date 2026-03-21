#include <iostream>
using namespace std;

int main() {

    //BIT MANIPULATION
    cout << "BIT MANIPULATION" << endl;

    cout << "1. Swap the Numbers" << endl;
    int a = 5, b = 10;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "After swapping: a = " << a << ", b = " << b << endl;

    cout << "2. Check if i th bit is set or not" << endl;
    cout << "Left shift operator method" << endl;
    int n = 13 , i = 2;
    cout << "Number: " << n << ", i: " << i << endl;
    if (n & (1 << i)) {
        cout << "i th bit is set" << endl;
    } else {
        cout << "i th bit is not set" << endl;
    }
    cout << "Right shift operator method" << endl;
    cout << "Number: " << n << ", i: " << i << endl;
    if (n>>i & 1) {
        cout << "i th bit is set" << endl;
    } else {
        cout << "i th bit is not set" << endl;
    }

    cout << "3. Set the i th bit" << endl;
    n = 13, i = 1;
    cout << "Number: " << n << ", i: " << i << endl;
    n = n | (1 << i);
    cout << "After setting the i th bit: " << n << endl;

    cout << "4. Clear i th bit"<< endl;

    n = 15, i = 1;
    cout << "Number: " << n << ", i: " << i << endl;
    n = n & (~(1 << i));
    cout << "After clearing the i th bit: " << n << endl;

    cout<< "5. Toggle i th bit" << endl;
    n = 13, i = 2;
    cout << "Number: " << n << ", i: " << i << endl;
    n = n ^ (1 << i);
    cout << "After toggling the i th bit: " << n << endl;

    cout<<"6. Remove the last set bit" << endl;
    n = 13;
    cout << "Number: " << n << endl;
    n = n & n-1;
    cout << "After removing the last set bit: " << n << endl;

    cout<<"7. Count the number is of power of 2" << endl;
    n = 13;
    cout << "Number: " << n << endl;
    if((n & (n-1)) == 0) {
        cout << "Number is a power of 2" << endl;
    } else {
        cout << "Number is not a power of 2" << endl;
    }

    cout<< "8. Count the number of set bits" << endl;
    n = 13;
    cout << "Number: " << n << endl;
    int count = 0;
    while(n > 1){
        count += n & 1;
        n = n >> 1;
    }
    if(n == 1) {
        count++;
    }
    cout << "Number of set bits: " << count << endl;
}