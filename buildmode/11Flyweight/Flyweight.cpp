/*
享元模式
使用共享对象可有效地支持大量的细粒度的对象。享元模式是以共享的方式高效地支持大量的细粒度对象。享元对象能做到共享的关键是区分内部状态（Internal State）和外部状态（External State）。
　　■ 内部状态是存储在享元对象内部的、可以共享的信息，并且不会随环境改变而改变。
　　■ 外部状态是随环境改变而改变且不可以共享的状态。享元对象的外部状态必须由客户端保存，并在享元对象被创建之后，在需要使用的时候再传入到享元对象内部。
*/
#include <iostream>
using namespace std;

// 棋子接口Chesspiece是抽象享元，该接口中规范一个落子put()方法，对棋子的坐标进行定位通过参数的形式将外部状态传入
class Chesspiece
{
public:
    virtual void put(int x, int y) = 0;
};

// 棋子具体享元ChesspieceFlyweight实现棋子接口Chesspiece
class ChesspieceFlyweight : public Chesspiece
{
public:
    ChesspieceFlyweight(string color)
    {
        this->color = color;
    }
    void put(int x, int y)
    {
        cout << color << "子在(" << x << "," << y << ")落子" << endl;
    }

private:
    string color;
};
// 棋子工厂ChesspieceFactory是享元工厂，负责创建和管理棋子
class ChesspieceFactory
{
public:
    static Chesspiece *WHITE;
    static Chesspiece *BLACK;

public:
    static Chesspiece *getChessPiece(string color)
    {
        if (color == "白")
        {
            return WHITE;
        }
        else if (color == "黑")
        {
            return BLACK;
        }
        return NULL;
    }
};
Chesspiece *ChesspieceFactory::BLACK = new ChesspieceFlyweight("黑");
Chesspiece *ChesspieceFactory::WHITE = new ChesspieceFlyweight("白");
int main()
{
    ChesspieceFactory chesspieceFactory;
    Chesspiece *p1 = chesspieceFactory.getChessPiece("黑");
    p1->put(1, 1);
    Chesspiece *p2 = chesspieceFactory.getChessPiece("白");
    p2->put(1, 1);
    delete p1;
    p1 = NULL;
    delete p2;
    p2 = NULL;
}