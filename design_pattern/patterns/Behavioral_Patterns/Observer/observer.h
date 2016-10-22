/*观察者模式
 【观察者模式（Observer）：定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象。这个主题在状态发生变化时，会通知所有观察者对象，使它们能够自动更新自己。】
 */

#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
#include <list>
#include <string>

class Observer;
class SubjectObserver
{
public:
	SubjectObserver();
	virtual ~SubjectObserver();

public:
	virtual void Attach(Observer* obv);
	virtual void Detach(Observer* obv);
	virtual void Notify();
	virtual void SetState(const std::string& st) = 0;
	virtual std::string GetState() = 0;

private:
	std::list<Observer*> m_observers;
};

class ConcreteSubjectObserverA : public SubjectObserver
{
public:
	ConcreteSubjectObserverA();
	~ConcreteSubjectObserverA();

public:
	void SetState(const std::string& st);
	std::string GetState();
private:
	std::string m_status;
};


class Observer
{
public:
	Observer(){}
	~Observer(){}

public:
	virtual void Update(SubjectObserver* sub) = 0;
	virtual void PrintInfo() = 0;

protected:
	std::string m_status;

};

class ConcreteObserverA : public Observer
{
public:
	ConcreteObserverA(SubjectObserver* sub);
	~ConcreteObserverA();

public:
	void Update(SubjectObserver* sub);
	void PrintInfo();

private:
	SubjectObserver* m_pSub;
};

class ConcreteObserverB : public Observer
{
public:
	ConcreteObserverB(SubjectObserver* sub);
	~ConcreteObserverB();

public:
	void Update(SubjectObserver* sub);
	void PrintInfo();

private:
	SubjectObserver* m_pSub;
};

#endif  //__OBSERVER_H__