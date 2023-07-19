/*
代理模式
    为其他对象提供一种代理以控制对这个对象的访问
　　按照使用目的可以将代理划分为以下几种。
　　■ 远程（Remote）代理：为一个位于不同的地址空间的对象提供一个局部代表对象。这个不同的地址空间可以是在本机器中，也可以在另一台机器中。
　　■ 虚拟（Virtual）代理：有时需要创建一些消耗较多资源的对象，可以首先创建代理对象，而将真实对象的创建延迟。例如，加载一个很大的图片，可以通过图片的代理来代替真正的图片。
　　■ 保护（Protect or Access）代理：控制对一个对象的访问，如果需要，可以给不同的用户提供不同级别的使用权限。
　　■ 缓存（Cache）代理：为某一个目标操作的结果提供临时的存储空间，以便多个客户端可以共享这些结果。
　　■ 同步（Synchronization）代理：使几个用户能够同时使用一个对象而没有冲突。
　　■ 智能引用（Smart Reference）代理：当一个对象被引用时，提供一些额外的操作，例如，记录访问的流量和次数等。
代理模式的优点
　　■ 职责清晰：真实的角色实现实际的业务逻辑，不用关心其他非本职的事务，通过后期的代理完成附加的事务，附带的结果就是编程简洁清晰。
　　■ 高扩展性：具体主题角色随需求不同可能有很多种，但只要实现了接口，代理类就完全可以在不做任何修改的情况下代理各种真实主题角色。
　　■ 智能化：代理类可以在运行时才确定需要去代理的真实主题，这是一种强大的功能。
*/
#include <iostream>
#include <string>
using namespace std;
// IGamePlayer接口对游戏玩家进行抽象
class IGamePlayer
{
public:
    virtual void killBoss() = 0; // 杀怪
    virtual void upGrade() = 0;  // 升级
    float gettime()
    {
        return m_time;
    }
    string getanimal()
    {
        return m_animal;
    }

protected:
    float m_time;
    string m_animal;
};
// GamePlayer实现IGamePlayer接口中的方法
class GamePlayer : public IGamePlayer
{
public:
    GamePlayer(string name, float time, string animal) : m_name(name)
    {
        m_time = time;
        m_animal = animal;
    }
    void killBoss()
    {
        cout << m_name << "在打怪" << endl;
    }
    void upGrade()
    {
        cout << m_name << "升级中" << endl;
    }

private:
    string m_name;
};

// GamePlayerProxy是代理类   其他子类通过代理类
class GamePlayerProxy : public IGamePlayer
{
public:
    // 构造函数形参是父类  且有个类型为父类的数据成员   player
    GamePlayerProxy(IGamePlayer *player)
    {
        this->player = player;
    }
    void killBoss()
    {
        player->killBoss();
        this->log(player->getanimal());
    }
    void upGrade()
    {
        player->upGrade();
        this->count(player->gettime());
    }

private:
    IGamePlayer *player = NULL;
    void log(string animal)
    {
        cout << "怪兽是" << animal << endl;
    }
    void count(float time)
    {
        cout << "升级积累" << time << "小时经验" << endl;
    }
};
int main()
{
    IGamePlayer *player = new GamePlayerProxy(new GamePlayer("小明", 3.0f, "老虎"));
    player->killBoss();
    player->upGrade();
    cout << "-----------------------------" << endl;
    player = new GamePlayerProxy(new GamePlayer("小刚", 5.0f, "熊"));
    player->killBoss();
    player->upGrade();
    delete player;
    player = NULL;
}