#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

using namespace std;

// Function to check if input is a valid integer
bool isInteger(const string& str) {
    stringstream ss(str);
    int num;
    ss >> num;
    return ss.eof() && !ss.fail();
}

int main() {
    int size;
    cout << "Enter the size of the list: ";
    
    string input;
    cin >> input;
    
    // Check if size is a valid integer
    if (!isInteger(input)) {
        cout << "Invalid input! Please enter an integer for the size." << endl;
        return 1; // Exit the program if input is invalid
    }

    // Convert the input string to integer
    size = stoi(input);

    // Check if the size is a valid positive number
    if (size <= 0) {
        cout << "Size should be a positive integer!" << endl;
        return 1; // Exit the program if size is not valid
    }

    vector<int> numbers;
    int number;
    cout << "Enter " << size << " numbers:" << endl;

    // Take input numbers
    for (int i = 0; i < size; ++i) {
        string numInput;
        cin >> numInput;
        
        // Check if the entered value is an integer
        if (!isInteger(numInput)) {
            cout << "Invalid input! Please enter a valid integer." << endl;
            return 1; // Exit the program if input is invalid
        }
        
        number = stoi(numInput);
        numbers.push_back(number);
    }

    // Find the smallest number
    int smallest = numeric_limits<int>::max(); // Initialize with the largest possible integer

    for (int num : numbers) {
        if (num < smallest) {
            smallest = num;
        }
    }

    // Output the smallest number
    cout << "The smallest number is: " << smallest << endl;

    return 0;
}
