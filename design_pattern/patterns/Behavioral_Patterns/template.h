/*模板方法模式
 */

#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include <iostream>

class AbstractClass
{
public:
	virtual ~AbstractClass(){}
	void TemplateMethod()
	{
		this->PrimitiveOperation1();
		this->PrimitiveOperation2();
	}

protected:
	AbstractClass(){}

protected:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;
};


class ConcreteClass1 : public AbstractClass
{
public:
	ConcreteClass1(){}
	~ConcreteClass1(){}

protected:
	void PrimitiveOperation1(){ std::cout << "ConcreteClass1::PrimitiveOperation1 ..." << std::endl; }
	void PrimitiveOperation2(){ std::cout << "ConcreteClass1::PrimitiveOperation2 ..." << std::endl; }
};

class ConcreteClass2 : public AbstractClass
{
public:
	ConcreteClass2(){}
	~ConcreteClass2(){}

protected:
	void PrimitiveOperation1(){ std::cout << "ConcreteClass2::PrimitiveOperation1 ..." << std::endl; }
	void PrimitiveOperation2(){ std::cout << "ConcreteClass2::PrimitiveOperation2 ..." << std::endl; }
};

#endif