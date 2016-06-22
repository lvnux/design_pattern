//抽象工厂模式
#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

using namespace std;

//抽象产品类A
class AbstractProductA
{
public:
	virtual ~AbstractProductA(){}

protected:
	AbstractProductA(){}
};


//抽象产品类B
class AbstractProductB
{
public:
	virtual ~AbstractProductB(){}

protected:
	AbstractProductB(){}
};


//A类产品
class ProductA1 : public AbstractProductA
{
public:
	ProductA1(){ cout << "ProductA1 ..." << endl; }
	~ProductA1(){}
};

class ProductA2 : public AbstractProductA
{
public:
	ProductA2(){ cout << "ProductA2 ..." << endl; }
	~ProductA2(){}
};


//B类产品
class ProductB1 : public AbstractProductB
{
public:
	ProductB1(){ cout << "ProductB1 ..." << endl; }
	~ProductB1(){}
};


class ProductB2 : public AbstractProductB
{
public:
	ProductB2(){ cout << "ProductB2 ..." << endl; }
	~ProductB2(){}
};


//抽象工厂
class AbstractFactory
{
public:
	virtual ~AbstractFactory(){}

public:
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;

protected:
	AbstractFactory(){}
};


//具体工厂
class ConcreteFactory1 : public AbstractFactory
{
public:
	ConcreteFactory1(){}
	~ConcreteFactory1(){}

public:
	AbstractProductA* CreateProductA(){ return new ProductA1(); }
	AbstractProductB* CreateProductB(){ return new ProductB1(); }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
	ConcreteFactory2(){}
	~ConcreteFactory2(){}

public:
	AbstractProductA* CreateProductA(){ return new ProductA2(); }
	AbstractProductB* CreateProductB(){ return new ProductB2(); }
};

#endif