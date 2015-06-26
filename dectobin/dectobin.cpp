#include <iostream>
#include <math.h>
#include <ctype.h>
using namespace std;

int dectobin(int dec, int powerOfTwo);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        cout << "Input is of format './a.out dectobin num'" << endl;
        return 1;
    }
    dectobin(atoi(argv[2]), 0);
    cout << endl;
    return 0;
}

int dectobin(int dec, int powerOfTwo) {
    if(dec == 0) {
            cout << "0" << endl;
    } else if(dec/(int)pow(2, powerOfTwo)) {
        int remainder = dectobin(dec, powerOfTwo+1);
        if(remainder/(int)pow(2, powerOfTwo)) {
            cout << "1";
            return remainder - (int)pow(2, powerOfTwo);
        } else {
            cout << "0";
            return remainder;
        }
    } else {
        return dec;
    }
}

