#include <iostream>
using namespace std;

int main() {
    int arr[10], n, search, index, newValue;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> search;

    bool found = false;
    for(int i = 0; i < n; i++) {
        if(arr[i] == search) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }

    if(!found) {
        cout << "Element not found" << endl;
    }

    cout << "Enter index to update: ";
    cin >> index;

    cout << "Enter new value: ";
    cin >> newValue;

    if(index >= 0 && index < n) {
        arr[index] = newValue;
    }

    cout << "Updated array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
