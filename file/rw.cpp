#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char data[100];

    //open a file in write mode
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writig to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // write inputted data into the file
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    outfile << data << endl;

    outfile.close();

    // open a file in read mode
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;
    cout << data << endl;

    infile >> data;
    cout << data << endl;

    infile.close();
    return 0;
}
