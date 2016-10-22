/*�н���ģʽ(Mediator)
��һ���н��������װһϵ�еĶ��󽻻����н���ʹ��������Ҫ��ʽ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ظı�����֮��Ľ�����

��ͼ�����н��߸��뷢���ߺͽ����ߣ������ߺͽ�����֮��û����ϣ����Զ����ط����仯��
ʵ��Ҫ�㣻�����н��ߺ�Э���߽ӿ��࣬�н��߹������е�Э����֮��Ĺ�����ϵ��
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