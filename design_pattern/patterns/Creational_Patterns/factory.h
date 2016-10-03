/* 工厂模式
 * 1、定义创建对象的接口，封装了对象的创建
 * 2、使得具体化类的工作延迟到了子类
 */

#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <iostream>

//抽象产品类
class Product
{
public:
	virtual ~Product() = 0;
protected:
	Product(){}
};
Product::~Product(){}   //若析构函数为纯虚函数，必须要有实现。否则报错“error LNK2019: 无法解析的外部符号 "public: virtual __thiscall Product::~Product(void)" (??1Product@@UAE@XZ)，该符号在函数 __unwindfunclet$??0ConcreteProduct@@QAE@XZ$0 中被引用”


//具体产品类
class ConcreteProduct : public Product
{
public:
	ConcreteProduct(){ std::cout << "ConcreteProduct ..." << std::endl; }
	~ConcreteProduct(){}
};


//工厂类的抽象
class Factory
{
public:
	virtual ~Factory() = 0;	  //若析构函数为纯虚函数，必须要有实现。
	virtual Product* CreateProduct() = 0;   //普通函数为纯虚函数，可以有实现，也可以不需要实现

protected:
	Factory(){}
};
Factory::~Factory(){}


//具体工厂类
class ConcreteFactory : public Factory
{
public:
	~ConcreteFactory(){}
	ConcreteFactory(){ std::cout << "ConcreteFactory ..." << std::endl; }
	Product* CreateProduct(){ return new ConcreteProduct(); }
};

#endif