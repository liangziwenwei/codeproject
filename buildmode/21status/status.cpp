#include <iostream>
using namespace std;
class Channel
{
public:
    virtual void display() = 0;
};
class CCTV1 : public Channel
{
public:
    void display()
    {
        cout << "CCTV1" << endl;
    }
};
class CCTV2 : public Channel
{
public:
    void display()
    {
        cout << "CCTV2" << endl;
    }
};
class TV
{
private:
    Channel *channel;

public:
    void disCCTV(Channel *channel)
    {
        this->channel = channel;
        this->channel->display();
    }
};

int main()
{
    Channel *cha = new CCTV1();
    TV tv;
    tv.disCCTV(cha);
    cha = new CCTV2();
    tv.disCCTV(cha);
    delete cha;
    cha = nullptr;
    return 0;
}