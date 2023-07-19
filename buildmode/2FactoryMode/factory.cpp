#include <iostream>
#include <memory>
#include <string>
using namespace std;

// 真实父类
class Shape
{
public:
    Shape()
    {
        id_ = ++total;
    }
    virtual void draw() = 0;

protected:
    string m_name;
    int id_;
    static int total;
};

int Shape::total = 0;
// 具体形状
class Circle : public Shape
{
public:
    Circle(string name)
    {
        Shape::m_name = name;
    }

public:
    void draw()
    {
        cout << Shape::m_name << "  circle " << id_ << ": draw" << endl;
    }
};
class Square : public Shape
{
public:
    Square(string name)
    {
        Shape::m_name = name;
    }

public:
    void draw()
    {
        cout << Shape::m_name << "  square " << id_ << ": draw" << endl;
    }
};
class Ellipse : public Shape
{
public:
    Ellipse(string name)
    {
        Shape::m_name = name;
    }

public:
    void draw()
    {
        cout << Shape::m_name << "  ellipse " << id_ << ": draw" << endl;
    }
};
class Rectangle : public Shape
{
public:
    Rectangle(string name)
    {
        Shape::m_name = name;
    }

public:
    void draw()
    {
        cout << Shape::m_name << "  rectangle " << id_ << ": draw" << endl;
    }
};

// 工厂父类
class Factory
{
public:
    // 返回类型为形状父类  return每个子类 按曲直划分方法返回不同具体形状
    virtual Shape *createCurvedInstance() = 0;
    virtual Shape *createStraightInstance() = 0;
};
// 按绘制难易程度划分 不同工厂子类
class SimpleShapeFactory : public Factory
{
public:
    Shape *createCurvedInstance()
    {
        return new Circle("Factory::SimpleShapeFactory::createCurvedInstance() 圆形");
    }
    Shape *createStraightInstance()
    {
        return new Square("Factory::SimpleShapeFactory::createStraightInstance() 正方形");
    }
};
class RobustShapeFactory : public Factory
{
public:
    Shape *createCurvedInstance()
    {
        return new Ellipse("Factory::RobustShapeFactory::createCurvedInstance() 椭圆");
    }
    Shape *createStraightInstance()
    {
        return new Rectangle("Factory::RobustShapeFactory::createStraightInstance() 矩形");
    }
};

int main()
{
    // 添加次数统计  退出循环条件
    int num = 0;
    while (num < 5)
    {
        Factory *factory = nullptr;
        if (num % 2 == 0)
        {
            cout << "简单形状SimpleShapeFactory" << endl;
            factory = new SimpleShapeFactory();
        }
        else
        {
            cout << "复杂形状RobustShapeFactory" << endl;
            factory = new RobustShapeFactory();
        }

        Shape *shapes[2];

        shapes[0] = factory->createCurvedInstance();
        shapes[1] = factory->createStraightInstance();

        for (int i = 0; i < 2; i++)
        {
            shapes[i]->draw();
        }
        num++;
    }
    cout << "程序结束" << endl;
}
