#include "mediator.h"
#include <iostream>

//Colleage
Colleage::Colleage()
{
}

Colleage::~Colleage()
{
}

Colleage::Colleage(Mediator* pMdt)
	: m_pMediator(pMdt)
{
}


//ConcreteColleageA
ConcreteColleageA::ConcreteColleageA()
{
}

ConcreteColleageA::~ConcreteColleageA()
{
}

ConcreteColleageA::ConcreteColleageA(Mediator* pMdt)
	: Colleage(pMdt)
{
}

void ConcreteColleageA::Action()
{
	m_pMediator->DoActionFromAtoB();
	std::cout << "State of ConcreteColleageA: " << GetState() << std::endl;
}

void ConcreteColleageA::SetState(const std::string& strState)
{
	m_strState = strState;
}

std::string ConcreteColleageA::GetState()
{
	return m_strState;
}


//ConcreteColleageB
ConcreteColleageB::ConcreteColleageB()
{
}

ConcreteColleageB::~ConcreteColleageB()
{
}

ConcreteColleageB::ConcreteColleageB(Mediator* pMdt)
	: Colleage(pMdt)
{
}

void ConcreteColleageB::Action()
{
	m_pMediator->DoActionFromBtoA();
	std::cout << "State of ConcreteColleageB: " << GetState() << std::endl;
}

void ConcreteColleageB::SetState(const std::string& strState)
{
	m_strState = strState;
}

std::string ConcreteColleageB::GetState()
{
	return m_strState;
}


//Mediator
Mediator::Mediator()
{
}

Mediator::~Mediator()
{
}


//ConcreteMediator
ConcreteMediator::ConcreteMediator()
{
}

ConcreteMediator::~ConcreteMediator()
{
}

ConcreteMediator::ConcreteMediator(Colleage* pClgA, Colleage* pClgB)
	: m_pColleageA(pClgA), m_pColleageB(pClgB)
{

}


void ConcreteMediator::DoActionFromAtoB()
{
	m_pColleageB->SetState(m_pColleageA->GetState());
}

void ConcreteMediator::SetConcreteColleageA(Colleage* pClg)
{
	m_pColleageA = pClg;
}

void ConcreteMediator::SetConcreteColleageB(Colleage* pClg)
{
	m_pColleageB = pClg;
}

Colleage* ConcreteMediator::GetConcreteColleageA()
{
	return m_pColleageA;
}

Colleage* ConcreteMediator::GetConcreteColleageB()
{
	return m_pColleageB;
}

void ConcreteMediator::IntroColleage(Colleage* pClgA, Colleage* pClgB)
{
	m_pColleageA = pClgA;
	m_pColleageB = pClgB;
}

void ConcreteMediator::DoActionFromBtoA()
{
	m_pColleageA->SetState(m_pColleageB->GetState());
}