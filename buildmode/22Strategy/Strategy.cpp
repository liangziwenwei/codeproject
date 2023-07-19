#include <iostream>
using namespace std;
// 打折策略
class product
{
protected:
    double price = 0;
    int number = 0;

public:
    product(double price, int number)
    {
        this->price = price;
        this->number = number;
    }
    double getPrice()
    {
        return price;
    }
    int getNumber()
    {
        return number;
    }
};

class DisCountStrategy
{
protected:
    product *pro;

public:
    DisCountStrategy()
    {
    }
    // 折后价
    virtual double calculateDiscount() = 0;
};
class NoDiscountStrategy : public DisCountStrategy
{
public:
    NoDiscountStrategy(product *pro)
    {
        this->pro = pro;
    }
    double calculateDiscount()
    {
        cout << "无折扣" << endl;
        return pro->getNumber() * pro->getPrice();
    }
};
class FixDiscountStrategy : public DisCountStrategy
{
public:
    FixDiscountStrategy(product *pro)
    {
        this->pro = pro;
    }
    double calculateDiscount()
    {
        return (pro->getNumber() - 1) * pro->getPrice();
    }
};
class PercentageDiscountStrategy : public DisCountStrategy
{
public:
    PercentageDiscountStrategy(product *pro)
    {
        this->pro = pro;
    }
    double calculateDiscount()
    {
        return pro->getNumber() * pro->getPrice() * 0.85;
    }
};

int main()
{
    product *pro = new product(10.0, 5);
    DisCountStrategy *dcStra = new NoDiscountStrategy(pro);
    cout << dcStra->calculateDiscount() << endl;
    dcStra = new FixDiscountStrategy(pro);
    cout << dcStra->calculateDiscount() << endl;
    dcStra = new PercentageDiscountStrategy(pro);
    cout << dcStra->calculateDiscount() << endl;
    delete dcStra;
    dcStra = nullptr;
    delete pro;
    pro = nullptr;
    return 0;
}