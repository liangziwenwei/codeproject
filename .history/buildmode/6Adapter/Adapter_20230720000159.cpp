/*
适配器模式
结构型模式（Structural Pattern）描述如何将类或者对象结合在一起形成更大的结构。结构型模式的目的是通过组合类或对象产生更大结构以适应更高层次的逻辑需求
将一个类的接口变换成客户端所期待的另一种接口，从而使原本因接口不匹配而无法在一起工作的两个类能够在一起工作。
*/
#include <iostream>
#include <memory>
using namespace std;
// 海鲜抽象类
class haixian
{
public:
    virtual ~haixian() { cout << "delte haixian" << endl; }
    haixian() { cout << "add haixian" << endl; }

public:
    virtual void makehaixian() = 0;
};

// 做鱼
class fish : public haixian
{
public:
    virtual ~fish() { cout << "delte fish" << endl; }
    fish() { cout << "add fish" << endl; }
    fish(const fish &stu) // 拷贝构造函数
    {
        cout << "add fish 1" << endl;
    }
    fish &operator=(const fish &stu) // 重载赋值运算符
    {
        cout << "add fish 2" << endl;
        return *this;
    }

public:
    void makehaixian()
    {
        cout << "蒸鱼" << endl;
    }
};

// 做贝壳
class beike : public haixian
{
public:
    virtual ~beike() { cout << "delte beike" << endl; }
    beike() { cout << "add beike" << endl; }
    beike(const beike &stu) // 拷贝构造函数
    {
        cout << "add beike 1" << endl;
    }
    beike &operator=(const beike &stu) // 重载赋值运算符
    {
        cout << "add beike 2" << endl;
        return *this;
    }

public:
    void makehaixian()
    {
        cout << "炒贝壳" << endl;
    }
};

// 做食物的抽象类
class MakeFood
{
protected:
    static int memflag;

public:
    virtual ~MakeFood() { cout << "delte MakeFood" << endl; }
    MakeFood()
    {
        // memflag = 1;
        // cout << "--------" << memflag << "-------" << endl;
        cout << "add MakeFood" << endl;
    }
    void SetMemFlag(int flag)
    {
        memflag = flag;
        cout << "--------" << memflag << "-------" << endl;
    }

public:
    virtual void MakeFoodCom() = 0; // 做食物的公共接口
};
// 做混沌
int MakeFood::memflag = 1;
class Hudun : public MakeFood
{
public:
    virtual ~Hudun() { cout << "delte Hudun" << endl; }
    Hudun() { cout << "add Hudun" << endl; }

public:
    void MakeFoodCom()
    {
        cout << "做混沌" << endl;
    }
};

// 适配做海鲜的类
class FoodAdapter : public MakeFood
{
private:
    haixian *hx_p = nullptr;

public:
    ~FoodAdapter()
    {
        cout << "--------" << memflag << "-------" << endl;
        if (1 == memflag)
        {
            cout << "由适配器管理内存" << endl;
            delete hx_p;
        }
        else
        {
            cout << "由实际类自己管理内存" << endl;
        }

        cout << "delte FoodAdapter" << endl;
    }
    FoodAdapter(haixian *hx) : hx_p(hx) { cout << "add FoodAdapter" << endl; }

public:
    void MakeFoodCom() // 公共接口调外部类的接口
    {
        cout << "----------适配------------" << endl;
        hx_p->makehaixian();
    }
};

int main()
{
    cout << "----------------------" << endl;
    MakeFood *makefood = new Hudun();
    makefood->SetMemFlag(1);
    makefood->MakeFoodCom();
    cout << "----------------------" << endl;
    // 1+new   由外层适配器类管理   正常        0+new 由自己管理   会泄露
    // 1+普通  由外层适配器类管理   会过删       0+普通 由自己管理   正常
    makefood = new FoodAdapter(new fish());
    makefood->MakeFoodCom();
    cout << "----------------------" << endl;
    makefood = new FoodAdapter(new beike());
    makefood->MakeFoodCom();
    cout << "----------------------" << endl;
    delete makefood;
    return 0;
}