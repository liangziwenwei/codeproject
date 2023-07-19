#include <iostream>
#include <string>
#include <vector>
using namespace std;
class collectDemo : public vector<string>
{
};

class filter
{
public:
    void addstring(collectDemo &p, string name)
    {
        p.push_back(name);
    }
};

int main()
{
    filter p;
    collectDemo cp;
    p.addstring(cp, "a");
    p.addstring(cp, "b");
    p.addstring(cp, "d");
    vector<string>::iterator it = cp.begin();
    while (it != cp.end())
    {
        cout << *it << endl;
        it++;
    }
}