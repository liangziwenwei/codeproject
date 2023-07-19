#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int sz = 100;

struct X
{
    int a[sz];
};

void print(X *x)
{
    for (int i = 0; i < sz; i++)
    {
        cout << x->a[i] << ' ';
    }
    cout << endl
         << "-------------------------" << endl;
}

int main()
{
    X x;
    int *xp = reinterpret_cast<int *>(&x);
    // 指针i指向xp  i偏移
    for (int *i = xp; i < xp + sz; i++)
    {
        *i = 0;
    }
    print(reinterpret_cast<X *>(xp));
    print(&x);
}