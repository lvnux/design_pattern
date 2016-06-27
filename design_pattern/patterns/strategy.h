/*策略模式
 */

#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <iostream>

class Strategy
{
public:
	Strategy(){}
	virtual ~Strategy(){ std::cout << "~Strategy ..." << std::endl; }

public:
	virtual void AlgrithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
	ConcreteStrategyA(){}
	virtual ~ConcreteStrategyA(){ std::cout << "~ConcreteStrategyA ..." << std::endl; }

public:
	void AlgrithmInterface() { std::cout << "test ConcreteStrategyA ..." << std::endl; }

};

class ConcreteStrategyB : public Strategy
{
public:
	ConcreteStrategyB(){}
	virtual ~ConcreteStrategyB(){ std::cout << "~ConcreteStrategyB ..." << std::endl; }

public:
	void AlgrithmInterface() { std::cout << "test ConcreteStrategyB ..." << std::endl; }

};

//环境类
//这个类是Strategy模式的关键，也是Strategy模式和Template模式的根本区别所在。
//Strategy模式采用组合（委托）的方式实现算法（实现）的异构，而Template模式则采取的是继承的方式
//这两个模式的区别也是继承和组合两种实现接口重用的方式的区别
class Context
{
public:
	Context(Strategy* stg) : _stg(stg){}
	~Context(){ std::cout << "~Context ..." << std::endl; }

public:
	void DoAction(){_stg->AlgrithmInterface();}

private:
	Strategy* _stg;
};

#endif