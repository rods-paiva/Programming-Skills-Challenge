#include <iostream>

int main() {
    char inputString[100]; // Assuming the input string won't exceed 100 characters
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, sizeof(inputString)); // Read the input string with spaces

    // Calculate the length of the string
    int length = 0;
    while (inputString[length] != '\0') {
        length++;
    }

    // Reversing the string in-place
    int start = 0;
    int end = length - 1;
    while (start < end) {
        // Swap characters without using a temporary variable
        inputString[start] = inputString[start] + inputString[end];
        inputString[end] = inputString[start] - inputString[end];
        inputString[start] = inputString[start] - inputString[end];

        // Move the pointers towards each other
        start++;
        end--;
    }

    std::cout << "Reversed string: " << inputString << std::endl;

    return 0;
}
