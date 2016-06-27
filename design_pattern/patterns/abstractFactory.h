/*���󹤳�ģʽ
 */

#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

#include <iostream>

//�����Ʒ��A
class AbstractProductA
{
public:
	virtual ~AbstractProductA(){}

protected:
	AbstractProductA(){}
};


//�����Ʒ��B
class AbstractProductB
{
public:
	virtual ~AbstractProductB(){}

protected:
	AbstractProductB(){}
};


//A���Ʒ
class ProductA1 : public AbstractProductA
{
public:
	ProductA1(){ std::cout << "ProductA1 ..." << std::endl; }
	~ProductA1(){}
};

class ProductA2 : public AbstractProductA
{
public:
	ProductA2(){ std::cout << "ProductA2 ..." << std::endl; }
	~ProductA2(){}
};


//B���Ʒ
class ProductB1 : public AbstractProductB
{
public:
	ProductB1(){ std::cout << "ProductB1 ..." << std::endl; }
	~ProductB1(){}
};


class ProductB2 : public AbstractProductB
{
public:
	ProductB2(){ std::cout << "ProductB2 ..." << std::endl; }
	~ProductB2(){}
};


//���󹤳�
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


//���幤��
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