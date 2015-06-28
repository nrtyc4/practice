//constructing vectors
#include <iostream>
#include <vector>

int main() {
	std::vector<int> first;	// empty vector of ints
	std::vector<int> second (4, 100);	//four ints with values 100
	std::vector<int> third (second.begin(), second.end());	// iterating through second
	std::vector<int> fourth (third);	// a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return 0;
}
