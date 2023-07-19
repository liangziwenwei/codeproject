/*
桥接模式
将抽象和实现解耦，使得两者可以独立地变化
*/
#include <iostream>
using namespace std;

// 将形状和颜色 分开实现为抽象类
//  抽象颜色类
class Color
{
public:
    virtual string getColor() = 0;
};

class Red : public Color
{
    string getColor()
    {
        return "red";
    }
};

class Green : public Color
{
    string getColor()
    {
        return "Green";
    }
};

// 抽象形状类   颜色基类作为形参
class AbstractShape
{
public:
    virtual void draw(Color *color) = 0;
};

// 具体形状类
class Circle : public AbstractShape
{
    void draw(Color *color)
    {
        cout << "draw a " + color->getColor() + " Circle" << endl;
    }
};
// 具体形状类
class Square : public AbstractShape
{
    void draw(Color *color)
    {
        cout << "draw a " + color->getColor() + " Square" << endl;
    }
};

int main()
{
    Color *color = new Green();
    AbstractShape *shape = new Square();
    shape->draw(color);
    cout << "---------------------------" << endl;
    color = new Red();
    shape = new Circle();
    shape->draw(color);
    delete color;
    color = NULL;
    delete shape;
    shape = NULL;
}