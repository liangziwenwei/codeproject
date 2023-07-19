#include <iostream>
#include <string>
using namespace std;
class Hardware;
class ComputerVisitor;
class CPU;
class Harddisk;

// 抽象硬件
class Hardware
{
protected:
    string type;

public:
    Hardware() {}
    // 返回硬件信息的接口
    virtual string getType() = 0;
    virtual void run() = 0;
    // 接收访问行为的接口
    virtual void accept(ComputerVisitor *computerVisitor) = 0;
};

// 抽象访问行为   不同的访问行为从硬件获得不同的信息
class ComputerVisitor
{
public:
    // 访问不同硬件接口
    virtual void vistCpu(CPU *cpu) = 0;
    virtual void vistHarddisk(Harddisk *harddisk) = 0;
};

class CPU : public Hardware
{
public:
    CPU(string type)
    {
        this->type = type;
    }
    string getType()
    {
        return this->type;
    }
    void run()
    {
        cout << "CPU型号为" << this->type << "正在运行" << endl;
    }
    void accept(ComputerVisitor *computerVisitor)
    {
        computerVisitor->vistCpu(this);
    }
};

class Harddisk : public Hardware
{
public:
    Harddisk(string type)
    {
        this->type = type;
    }
    string getType()
    {
        return this->type;
    }
    void run()
    {
        cout << "Harddisk型号为" << this->type << "正在运行" << endl;
    }
    void accept(ComputerVisitor *computerVisitor)
    {
        computerVisitor->vistHarddisk(this);
    }
};
class TypeVisitor : public ComputerVisitor
{
public:
    void vistCpu(CPU *cpu)
    {
        cout << "CPU型号为" << cpu->getType() << endl;
    }
    void vistHarddisk(Harddisk *harddisk)
    {
        cout << "Harddisk型号为" << harddisk->getType() << endl;
    }
};
class RunVisitor : public ComputerVisitor
{
public:
    void vistCpu(CPU *cpu)
    {
        cpu->run();
    }
    void vistHarddisk(Harddisk *harddisk)
    {
        harddisk->run();
    }
};

class Computer
{
private:
    Hardware *cpu;
    Hardware *harddisk;

public:
    Computer()
    {
        this->cpu = new CPU("aa");
        this->harddisk = new Harddisk("bb");
    }
    void accept(ComputerVisitor *computerVistor)
    {
        cpu->accept(computerVistor);      // cpu
        harddisk->accept(computerVistor); // 硬盘
    }
};
int main()
{
    Computer *computer = new Computer();
    ComputerVisitor *typeVisitor = new TypeVisitor();
    ComputerVisitor *runVisitor = new RunVisitor();
    computer->accept(typeVisitor); // 硬件类型访问
    computer->accept(runVisitor);  // 运行访问
    delete computer;
    computer = nullptr;
    return 0;
}