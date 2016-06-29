/*原型模式（Prototype）
 *【用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象】
 */

#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

#include <iostream>

class Prototype
{
public:
	virtual ~Prototype(){}
	virtual Prototype* Clone() const = 0;

protected:
	Prototype(){}
};

class ConcretePrototype: public Prototype
{
public:
	ConcretePrototype(){}
	ConcretePrototype(const ConcretePrototype& cp){ std::cout << "ConcretePrototype::ConcretePrototype ..." << std::endl; }
	~ConcretePrototype(){}

public:
	Prototype* Clone() const
	{
		return new ConcretePrototype(*this);
	}
};

#endif