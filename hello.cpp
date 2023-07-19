#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    int x = 0;
    int i = sizeof x;
    cout << i << endl;
    cout << sizeof(double) << " " << sizeof(char) << " " << sizeof(float) << endl;
    int a[10];
    cout << a << endl;
    cout << &a[0] << endl;
    cout << sizeof(int) << endl;
    for (int b = 0; b < 10; b++)
    {
        cout << &a[b] << endl; // 16½øÖÆ´òÓ¡
    }
    int *p = a;
    for (int i = 0; i < 10; i++)
    {
        p[i] = i * 10;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << *p++ << endl;
    }
    return 0;
}