#include "observer.h"

SubjectObserver::SubjectObserver()
{

}

SubjectObserver::~SubjectObserver()
{

}

void SubjectObserver::Attach(Observer* obv)
{
	m_observers.push_back(obv);
}

void SubjectObserver::Detach(Observer* obv)
{
	m_observers.remove(obv);
}

void SubjectObserver::Notify()
{
	std::list<Observer*>::iterator iter = m_observers.begin();
	for (; iter != m_observers.end(); ++iter)
	{
		(*iter)->Update(this);
	}
}

//
ConcreteSubjectObserverA::ConcreteSubjectObserverA()
{
	m_status = "";
}

ConcreteSubjectObserverA::~ConcreteSubjectObserverA()
{

}

void ConcreteSubjectObserverA::SetState(const std::string& st)
{
	m_status = st;
}

std::string ConcreteSubjectObserverA::GetState()
{
	return m_status;
}


//
ConcreteObserverA::ConcreteObserverA(SubjectObserver* sub)
	: m_pSub(sub)
{
	m_pSub->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA()
{
	m_pSub->Detach(this);
}

void ConcreteObserverA::Update(SubjectObserver* sub)
{
	m_status = sub->GetState();
	PrintInfo();
}

void ConcreteObserverA::PrintInfo()
{
	std::cout << "ConcreteObserverA observer ... " << m_status << std::endl;
}


//
ConcreteObserverB::ConcreteObserverB(SubjectObserver* sub)
	: m_pSub(sub)
{
	m_pSub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB()
{
	m_pSub->Detach(this);
}

void ConcreteObserverB::Update(SubjectObserver* sub)
{
	m_status = sub->GetState();
	PrintInfo();
}

void ConcreteObserverB::PrintInfo()
{
	std::cout << "ConcreteObserverB observer ... " << m_status << std::endl;
}