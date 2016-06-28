/*ге╫сдёй╫
 */

#ifndef __BRIDGE_H__
#define __BRIDGE_H__

#include <iostream>

class Abstraction
{
public:
	virtual ~Abstraction(){}
	virtual void Operation() = 0;

protected:
	Abstraction(){};
};

class AbstractionImp
{
public:
	virtual ~AbstractionImp(){}
	virtual void Operation() = 0;
protected:
	AbstractionImp(){}
private:
};

class RefinedAbstraction: public Abstraction
{
public:
	RefinedAbstraction(AbstractionImp* imp) : m_pImp(imp){}
	~RefinedAbstraction(){}

public:
	void Operation(){ m_pImp->Operation(); }

private:
	AbstractionImp* m_pImp;
};

class ConcreteAbstractionImpA : public AbstractionImp
{
public:
	ConcreteAbstractionImpA(){}
	~ConcreteAbstractionImpA(){}

public:
	virtual void Operation(){ std::cout << "ConcreteAbstractionImpA::Operation ..." << std::endl; }
};

class ConcreteAbstractionImpB : public AbstractionImp
{
public:
	ConcreteAbstractionImpB(){}
	~ConcreteAbstractionImpB(){}

public:
	virtual void Operation(){ std::cout << "ConcreteAbstractionImpB::Operation ..." << std::endl; }
};

#endif