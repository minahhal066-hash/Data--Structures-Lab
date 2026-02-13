#include <iostream>
using namespace std;

struct Product
{
    string name;
    int code;
    float price;
};

int main()
{
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    Product *p = new Product[n];
    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of product " << i+1 << endl;
        cout << "Name: ";
        cin >> p[i].name;
        cout << "Code: ";
        cin >> p[i].code;
        cout << "Price: ";
        cin >> p[i].price;
    }
    cout << "\nAll Products Details:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i+1 << endl;
        cout << "Name: " << p[i].name << endl;
        cout << "Code: " << p[i].code << endl;
        cout << "Price: " << p[i].price << endl;
    }

    delete[] p;
    p = nullptr;

    return 0;
}
