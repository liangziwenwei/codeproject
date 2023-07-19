#include <iostream>
#include <memory>
#include <string>
using namespace std;

// 抽象猫类
class Cat
{
public:
    virtual string getType() = 0;
};

// 白颜色猫
class WhiteCat : public Cat
{
public:
    WhiteCat() : Cat(), m_type("WhiteCat")
    {
    }
    string getType()
    {
        cout << m_type << endl;
        return m_type;
    }

private:
    string m_type;
};

// 黑色猫类
class BlackCat : public Cat
{
public:
    BlackCat() : Cat(), m_type("BlackCat")
    {
    }
    string getType()
    {
        cout << m_type << endl;
        return m_type;
    }

private:
    string m_type;
};

// 抽象狗类
class Dog
{
public:
    virtual string getType() = 0;
};

// 白色狗类
class WhiteDog : public Dog
{
public:
    WhiteDog() : Dog(), m_type("WhiteDog")
    {
    }
    string getType()
    {
        cout << m_type << endl;
        return m_type;
    }

private:
    string m_type;
};

// 黑色狗类
class BlackDog : public Dog
{
public:
    BlackDog() : Dog(), m_type("BlackDog")
    {
    }
    string getType()
    {
        cout << m_type << endl;
        return m_type;
    }

private:
    string m_type;
};

// 抽象工厂类
class PetFactory
{
public:
    // 返回宠物分类
    virtual Cat *createCat() = 0;
    virtual Dog *createDog() = 0;
};

// 按颜色划分子工厂
//  白色宠物工厂
class WhitePetFactory : public PetFactory
{
public:
    Cat *createCat()
    {
        return new WhiteCat();
    }
    Dog *createDog()
    {
        return new WhiteDog();
    }
};
// 黑色宠物工厂
class BlackPetFactory : public PetFactory
{
public:
    Cat *createCat()
    {
        return new BlackCat();
    }
    Dog *createDog()
    {
        return new BlackDog();
    }
};

int main()
{
    // 添加次数统计  退出循环条件
    int num = 0;
    while (num < 5)
    {
        PetFactory *factory = nullptr;
        if (num % 2 == 0)
        {
            cout << "" << endl;
            factory = new WhitePetFactory();
        }
        else
        {
            cout << "" << endl;
            factory = new BlackPetFactory();
        }

        Cat *cat = factory->createCat();
        Dog *dog = factory->createDog();
        cat->getType();
        dog->getType();
        num++;
    }
    cout << "程序结束" << endl;
}
