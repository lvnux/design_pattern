/*ԭ��ģʽ��Prototype��
 *����ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
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