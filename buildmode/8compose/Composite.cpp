/*
组合模式
将对象组合成树形结构以表示“部分—整体”的层次结构，使得用户对单个对象和组合对象的使用具有一致性
*/
#include <iostream>
#include <list>
#include <memory>
#include <stdio.h>
#include <string>
using namespace std;

class Company
{
public:
    virtual string getInfo() = 0;
    virtual string getName()
    {
        return name;
    }
    virtual string getType() = 0;

protected:
    string name;
    string position;
    int salary;
};
class ConcreteCompany : public Company
{
public:
    ConcreteCompany(string name, string position, int salary)
    {
        this->name = name;
        this->position = position;
        this->salary = salary;
    }
    // Employee  ConcreteCompany都继承自Company    所以形参兼容。因此，便可以向指针companyList的列表添加数据
    void add(Company *company)
    {
        shared_ptr<Company> temp(company);
        companyList.push_back(temp);
    }
    string getType()
    {
        return "ConcreteCompany";
    }
    void remove(string companyName)
    {
        list<shared_ptr<Company>>::iterator iter = companyList.begin();
        for (; iter != companyList.end(); iter++)
        {
            if ((*iter).get()->getName() == companyName)
            {
                companyList.erase(iter);
                return;
            }
        }
    }
    list<shared_ptr<Company>> getChild()
    {
        return companyList;
    }
    string getInfo()
    {
        string info = "";
        if (this->position == "CEO")
        {
            info = "领导名称：" + this->name;
        }
        else
        {
            info = "组长名称：" + this->name;
        }
        info = info + "\t职位：" + this->position;
        info = info + "\t薪水：" + to_string(this->salary);
        return info;
    }

private:
    list<shared_ptr<Company>> companyList;
};

class Employee : public Company
{
public:
    Employee(string name, string position, int salary)
    {
        this->name = name;
        this->position = position;
        this->salary = salary;
    }
    string getType()
    {
        return "Employee";
    }
    string getInfo()
    {
        string info = "";
        info = "员工名称：" + this->name;
        info = info + "\t职位：" + this->position;
        info = info + "\t薪水：" + to_string(this->salary);
        return info;
    }
};
int num = 0;
void disPlay(ConcreteCompany *root)
{

    cout << "disPlay begin " << ++num << endl;
    cout << root->getInfo() << endl;
    list<shared_ptr<Company>> tmp = root->getChild();
    list<shared_ptr<Company>>::iterator iter = tmp.begin();
    for (; iter != tmp.end(); iter++)
    {
        if ((*iter).get()->getType() == string("Employee"))
        {
            cout << (*iter).get()->getInfo() << endl;
        }
        else if ((*iter).get()->getType() == string("ConcreteCompany"))
        {
            disPlay((ConcreteCompany *)(*iter).get()); // 递归调用
        }
    }
    cout << "disPlay end" << num << endl;
}
int main()
{
    ConcreteCompany *root = new ConcreteCompany("张三", "CEO", 100000);
    ConcreteCompany *develop = new ConcreteCompany("李四", "研发组长", 100000);
    ConcreteCompany *sale = new ConcreteCompany("王二", "销售组长", 100000);
    Employee *e1 = new Employee("A", "研发", 200);
    Employee *e2 = new Employee("B", "销售", 200);
    Employee *e3 = new Employee("C", "研发", 200);
    Employee *e4 = new Employee("D", "销售", 200);
    root->add(develop);
    root->add(sale);
    develop->add(e1);
    develop->add(e3);
    sale->add(e2);
    sale->add(e4);
    disPlay(root);
    cout << "-------------------------------------" << endl;
    develop->remove("A");
    disPlay(root);
    delete root;
    root = NULL;
}