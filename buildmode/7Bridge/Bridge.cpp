/*
�Ž�ģʽ
�������ʵ�ֽ��ʹ�����߿��Զ����ر仯
*/
#include <iostream>
using namespace std;

// ����״����ɫ �ֿ�ʵ��Ϊ������
//  ������ɫ��
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

// ������״��   ��ɫ������Ϊ�β�
class AbstractShape
{
public:
    virtual void draw(Color *color) = 0;
};

// ������״��
class Circle : public AbstractShape
{
    void draw(Color *color)
    {
        cout << "draw a " + color->getColor() + " Circle" << endl;
    }
};
// ������״��
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