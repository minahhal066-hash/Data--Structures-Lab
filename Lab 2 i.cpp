#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int *p;

    cout << "Enter 5 numbers:" << endl;
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    p = arr;   

    cout << "Array elements are:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << *(p + i) << endl;
    }

    return 0;
}
