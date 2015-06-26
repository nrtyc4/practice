#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char** argv){
    std::string line;
    int number;
    std::vector<int> numbers;

    std::cout << "Enter numbers separated by spaces: " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number)
        numbers.push_back(number);

    for (auto it : numbers)
        std::cout << it << std::endl;
}