/*����ģʽ
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

//������
//�������Strategyģʽ�Ĺؼ���Ҳ��Strategyģʽ��Templateģʽ�ĸ����������ڡ�
//Strategyģʽ������ϣ�ί�У��ķ�ʽʵ���㷨��ʵ�֣����칹����Templateģʽ���ȡ���Ǽ̳еķ�ʽ
//������ģʽ������Ҳ�Ǽ̳к��������ʵ�ֽӿ����õķ�ʽ������
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