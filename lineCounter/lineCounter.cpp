#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	if(argc!=3){
		cout << "Input should be of the form 'count filename.txt'" << endl;
		return 1;
	} else {
		ifstream input_file(argv[2]);
		if(!input_file){
			cout << "File "<<argv[2]<<" does not exist" << endl;
			return 2;
		}
		char c;
		int count = 0;
		while(input_file.get(c)) {
			if(c == '\n')
				count++;
		}
		cout << "Total lines in file: " << count << endl;
	}
	return 0;
}

