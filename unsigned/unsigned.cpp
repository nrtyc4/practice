#include <iostream>
using namespace std;

// This program shows the difference between
// signed and unsigned ints
int main() {
    short int i;
    short unsigned int j;
    j = 50000;
    i = j;
    cout << i << " " << j << endl;
    return 0;
}
