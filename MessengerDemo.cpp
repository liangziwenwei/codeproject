#include <iostream>
#include <string>

using namespace std;
class point
{
public:
    int x, y, z;
    point(int xi, int yi, int zi) : x(xi), y(yi), z(zi) {}
    point(const point &p) : x(p.x), y(p.y), z(p.z) {}
    point &operator=(const point &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }
    friend ostream &
    operator<<(ostream &os, const point &p)
    {
        return os << "x=" << p.x << " y=" << p.y << " z=" << p.z;
    }
};

class vector
{
public:
    int magnitude, direction;
    vector(int m, int d) : magnitude(m), direction(d){};
    ~vector();
};
vector ::~vector(){};
class space
{
public:
    static point translate(point p, vector v)
    {
        p.x += v.magnitude + v.direction;
        p.y += v.magnitude + v.direction;
        p.z += v.magnitude + v.direction;
        return p;
    }
};

int main()
{
    point p(1, 2, 3);
    point q = space::translate(p, vector(11, 47));
    cout << "p:" << p << endl
         << "q:" << q << endl;
}
