/*中介者模式(Mediator)
用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。

意图：用中介者隔离发送者和接收者，发送者和接收者之间没有耦合，可以独立地发生变化。
实现要点；定义中介者和协作者接口类，中介者管理所有的协作者之间的关联关系。
*/

#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__

#include <string>

class Mediator;
class Colleage
{
public:
	virtual ~Colleage();
	virtual void Action() = 0;
	virtual	void SetState(const std::string& strState) = 0;
	virtual std::string GetState() = 0;

protected:
	Colleage();
	Colleage(Mediator* pMdt);

protected:
	Mediator* m_pMediator;
};


class ConcreteColleageA : public Colleage
{
public:
	ConcreteColleageA();
	ConcreteColleageA(Mediator* pMdt);
	~ConcreteColleageA();

public:
	virtual void Action();
	virtual void SetState(const std::string& strState);
	virtual std::string GetState();

private:
	std::string m_strState;
};


class ConcreteColleageB : public Colleage
{
public:
	ConcreteColleageB();
	ConcreteColleageB(Mediator* pMdt);
	~ConcreteColleageB();

public:
	virtual void Action();
	virtual void SetState(const std::string& strState);
	virtual std::string GetState();

private:
	std::string m_strState;
};


class Mediator
{
public:
	virtual ~Mediator();
	virtual void DoActionFromAtoB() = 0;
	virtual void DoActionFromBtoA() = 0;

protected:
	Mediator();
};

class ConcreteMediator : public Mediator
{
public:
	ConcreteMediator();
	ConcreteMediator(Colleage* pClgA, Colleage* pClgB);
	~ConcreteMediator();

public:
	void SetConcreteColleageA(Colleage* pClg);
	void SetConcreteColleageB(Colleage* pClg);
	Colleage* GetConcreteColleageA();
	Colleage* GetConcreteColleageB();
	void IntroColleage(Colleage* pClgA, Colleage* pClgB);

public:
	virtual void DoActionFromAtoB();
	virtual void DoActionFromBtoA();

private:
	Colleage* m_pColleageA;
	Colleage* m_pColleageB;
};

#endif  //__MEDIATOR_H__