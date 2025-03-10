#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // Required for numeric_limits

using namespace std;

int main() {
    int size;
    bool validSize = false;

    // 1. Ask user to enter the size of the element and 2. Check if it's an integer and greater than 3.
    while (!validSize) {
        cout << "Enter the size of the element (must be an integer greater than 3): ";

        // Input validation: check if it's an integer.
        if (cin >> size) {
            if (size > 3) {
                validSize = true;
            } else {
                cout << "Size must be greater than 3. Please enter again." << endl;
            }
        } else {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // 4. Ask user to enter elements, store in a vector, and avoid duplicates.
    vector<int> elements;
    cout << "Enter " << size << " elements, avoiding duplicates:" << endl;

    for (int i = 0; i < size; ++i) {
        int element;
        bool validElement = false;

        while (!validElement) {
            cout << "Enter element " << (i + 1) << ": ";
            if (cin >> element) {
                // Check for duplicates
                bool duplicate = false;
                for (int existingElement : elements) {
                    if (existingElement == element) {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate) {
                    elements.push_back(element);
                    validElement = true;
                } else {
                    cout << "Duplicate element. Please enter a unique element." << endl;
                }
            } else {
                cout << "Invalid input. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

     // Check if the user entered enough unique elements
    if (elements.size() < size) {
        cout << "You did not enter enough unique elements.  Exiting." << endl;
        return 1;  //Or however you want to handle the error.
    }


    // 5. Order entered numbers by ascending order.
    sort(elements.begin(), elements.end());

    // 6. Print out the third largest element.
    cout << "The third largest number is: " << elements[size - 3] << endl;

    return 0;
}
