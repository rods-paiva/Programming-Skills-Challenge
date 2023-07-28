#include <iostream>

int main() {
    char inputString[100]; // Assuming the input string won't exceed 100 characters
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, sizeof(inputString)); // Read the input string with spaces

    int length = 0;
    while (inputString[length] != '\0') {
        length++;
    }

    std::cout << "Length of the string: " << length << std::endl;

    return 0;
}
