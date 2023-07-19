/*
装饰模式
动态地给一个对象添加一些额外的职责。就增加功能来说，装饰模式比生成子类更为灵活�?
　　�? 装饰类和被装饰类可以独立发展，而不会相互耦合。即 Component 类无须知道Decorator类，Decorator类是从外部来扩展Component类的功能，而Decorator也不用知道具体的构件�?
　　�? 装饰模式是继承关系的一个替代方案。装饰类Decorator，不管装饰多少层，返回的对象还是Component。�?
　　�? 装饰模式可以动态地扩展一个实现类的功能�?
*/
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
// 抽象装饰对象
class Car
{
public:
    virtual void show() = 0;
};

// 具体装饰对象
class Benz : public Car
{
    void show()
    {
        cout << "奔驰车默认为黑色" << endl;
    }
};

// 装饰角色：该角色持有一个构件对象的实例，并定义一个与抽象构件接口一致的接口�?
class CarDecorator : public Car
{
public:
    CarDecorator(Car *car)
    {
        this->car = car;
    }
    void show()
    {
        this->car->show();
    }

private:
    Car *car;
};
// 具体装饰角色：该角色负责对构件对象进行装饰�?
class ConcreteCarDecorator : public CarDecorator
{
public:
    ConcreteCarDecorator(Car *car) : CarDecorator(car) {}
    void show()
    {
        CarDecorator::show();
        print();
        setGps();
    }

private:
    void print()
    {
        cout << "绘制字样" << endl;
    }
    void setGps()
    {
        cout << "安装GPS" << endl;
    }
};

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};
struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring &artist_, const std::wstring &title_) : artist{artist_}, title{title_} {}
};
struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring &date_,
        const std::wstring &location_,
        const std::wstring &subject_) : date{date_}, location{location_}, subject{subject_} {}
};
int main()
{
    Car *car = new Benz();
    CarDecorator *cd = new ConcreteCarDecorator(car);
    cd->show();
    delete cd;
    cd = NULL;
    delete car;
    car = NULL;
    // Use make_shared function when possible.
    auto sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");
    // Ok, but slightly less efficient.
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));
    // When initialization must be separate from declaration, e.g. class members,
    // initialize with nullptr to make your programming intent explicit.
    shared_ptr<Song> sp5(nullptr);
    // Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing");

    // Initialize with copy constructor. Increments ref count.
    auto sp3(sp2);
    // Initialize via assignment. Increments ref count.
    auto sp4 = sp2;
    // Initialize with nullptr. sp7 is empty.
    shared_ptr<Song> sp7(nullptr);
    // Initialize with another shared_ptr. sp1 and sp2
    // swap pointers as well as ref counts.
    sp1.swap(sp2);

    vector<shared_ptr<Song>> v{
        make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
        make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
        make_shared<Song>(L"Tha", L"Entre El Mar y Una Estrella")};
    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s)
                   { return s->artist.compare(L"Bob Dylan") == 0; });
    for (const auto &s : v2)
    {
        wcout << s->artist << L":" << s->title << endl;
    }

    vector<shared_ptr<MediaAsset>> assets{
        make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),
        make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
        make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")};
    vector<shared_ptr<MediaAsset>> photos;
    copy_if(assets.begin(), assets.end(), back_inserter(photos), [](shared_ptr<MediaAsset> p) -> bool
            {
// Use dynamic_pointer_cast to test whether
// element is a shared_ptr<Photo>.
shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
return temp.get() != nullptr; });
    for (const auto &p : photos)
    {
        // We know that the photos vector contains only
        // shared_ptr<Photo> objects, so use static_cast.
        wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location
              << endl;
    }

    // Initialize two separate raw pointers.
    // Note that they contain the same values.
    auto song1 = new Song(L"Village People", L"YMCA");
    auto song2 = new Song(L"Village People", L"YMCA");
    // Create two unrelated shared_ptrs.
    shared_ptr<Song> p1(song1);
    shared_ptr<Song> p2(song2);
    // Unrelated shared_ptrs are never equal.
    wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
    wcout << "p1 == p2 = " << std::boolalpha << (p1 == p2) << endl;
    // Related shared_ptr instances are always equal.
    shared_ptr<Song> p3(p2);
    wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
}