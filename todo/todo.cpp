// to do list
#include <iostream>
#include <string>
#include <fstream>
#define OUTPUT_FILE "output.txt"
using namespace std;

bool isVisitor(string fname);
void printHello();
string getResponse();
void writeResponse(ofstream& output, string res);

int main() {
    bool welcome = isVisitor(OUTPUT_FILE);
    if(!welcome) { printHello(); }
    string response(getResponse()); //get user response and assign to string response
    ofstream myfile;
    writeResponse(myfile, response);
    return 0;
}

bool isVisitor(string fname) {
    ifstream infile(fname);
    return infile.good();
}

void printHello() {
    cout << "hello, what is there to do?" << endl;
}

string getResponse() {
    string response = "Some text";
    getline (cin, response);
    return response;  
}

void writeResponse(ofstream& output, string res) {
    output.open ("output.txt");
    output << res << endl;
    output.close();
}
