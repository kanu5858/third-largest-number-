#include <iostream> 
using namespace std; 
 
int findSmallestNumber(int arr[], int size) { 
    int smallest = arr[0]; 
    for (int i = 1; i < size; i++) { 
        if (arr[i] < smallest) { 
            smallest = arr[i]; 
        } 
    } 
    return smallest; 
} 
 
int main() { 
    int arr[] = {10, 20, 30, 40, 50}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int smallest = findSmallestNumber(arr, size); 
    cout << "The smallest number in the array is: " << smallest << 
endl; 
    return 0; 
} 
//https://github.com/kanu5858/roba.git