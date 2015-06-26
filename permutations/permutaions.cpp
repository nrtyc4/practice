#include <iostream>
#include <string>
using namespace std;

string swap(string topermute, int x, int y);
void permute(string topermute, int place);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        cout << "Proper input is './a.out permute string'" << endl;
        return 1;
    }
    permute(argv[2], 0);
    return 0;
}

string swap(string topermute, int x, int y) {
    string newstring = topermute;
    newstring[x] = newstring[y];
    newstring[y] = topermute[x];    //avoids temp variable
    return newstring;
}

void permute(string topermute, int place) {
    if(place == topermute.length() -1)
        cout << topermute << endl;

    for(int nextchar = place; nextchar < topermute.length(); nextchar++ )
        permute(swap(topermute, place, nextchar), place+1);
}
