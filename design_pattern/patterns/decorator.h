//в╟йндёй╫
#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <iostream>

class Component
{
public:
	virtual ~Component(){}
	virtual void Operation(){}

protected:
	Component(){}
	
private:
};

class ConcreteComponent : public Component
{
public:
	ConcreteComponent(){}
	~ConcreteComponent(){}
	void Operation()
	{
		std::cout << "ConcreteComponent Operation ..." << std::endl;
	}
};

class Decorator : public Component
{
public:
	Decorator(Component* com) : _com(com) {}
	virtual ~Decorator(){ delete _com; }
	void Operation(){}

protected:
	Component* _com;
};

class ConcreteDecorator : public Decorator
{
public:
	ConcreteDecorator(Component* com) : Decorator(com) {}
	~ConcreteDecorator(){}
	void AddedBehavior()
	{
		std::cout << "ConcreteDecorator AddedBehavior..." << std::endl;
	}

	void Operation()
	{
		_com->Operation();
		AddedBehavior();
	}
};

#endif