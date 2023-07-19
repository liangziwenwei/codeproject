/*
外观模式
要求一个子系统的外部与其内部的通信必须通过一个统一的对象进行。外观模式提供一个高层次的接口，使得子系统更易使用。
*/
#include <iostream>
using namespace std;
class Airport
{
public:
    void bookTicket(string from, string to)
    {
        cout << "订购了从" + from + "到" + to + "的机票" << endl;
    }
};
class Hotel
{
public:
    void reserve(int days)
    {
        cout << "定了" << days << "天的房间" << endl;
    }
};
class Chauffeur
{
public:
    void drive(string to)
    {
        cout << "司机开车去" + to << endl;
    }
};
class Secretary
{
public:
    void trip(string to, int days)
    {
        cout << "老板告诉秘书出差" << days << "天" << endl;
        airport.bookTicket("上海", to);
        chauffeur.drive("机场");
        hotel.reserve(days);
    }

private:
    Chauffeur chauffeur;
    Hotel hotel;
    Airport airport;
};
int main()
{
    Secretary s;

    s.trip("青岛", 10);
}