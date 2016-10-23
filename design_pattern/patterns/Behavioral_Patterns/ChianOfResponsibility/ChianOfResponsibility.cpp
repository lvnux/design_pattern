#include "ChianOfResponsibility.h"
#include <iostream>

//Handler
Handler::Handler()
	: m_pSuccessor(NULL)
{

}

Handler::Handler(Handler* pSuccessor)
	: m_pSuccessor(pSuccessor)
{

}

Handler::~Handler()
{

}

void Handler::SetSuccessor(Handler* pSuccessor)
{
	m_pSuccessor = pSuccessor;
}

Handler* Handler::GetSuccessor()
{
	return m_pSuccessor;
}


//ConcreteHandlerA
ConcreteHandlerA::ConcreteHandlerA()
	: Handler()
{

}

ConcreteHandlerA::ConcreteHandlerA(Handler* pSuccessor)
	: Handler(pSuccessor)
{

}

ConcreteHandlerA::~ConcreteHandlerA()
{

}

void ConcreteHandlerA::HandleRequest()
{
	if (NULL != GetSuccessor())
	{
		std::cout << "ConcreteHandlerA: �ҰѴ�������̽ڵ㡣" << std::endl;
		GetSuccessor()->HandleRequest();
	}
	else
	{
		std::cout << "ConcreteHandlerA: û�к���ˣ��ұ����Լ����������" << std::endl;
	}
}


//ConcreteHandlerB
ConcreteHandlerB::ConcreteHandlerB()
	: Handler()
{

}

ConcreteHandlerB::ConcreteHandlerB(Handler* pSuccessor)
	: Handler(pSuccessor)
{

}

ConcreteHandlerB::~ConcreteHandlerB()
{

}

void ConcreteHandlerB::HandleRequest()
{
	if (NULL != GetSuccessor())
	{
		std::cout << "ConcreteHandlerB: �ҰѴ�������̽ڵ㡣" << std::endl;
		GetSuccessor()->HandleRequest();
	}
	else
	{
		std::cout << "ConcreteHandlerB: û�к���ˣ��ұ����Լ����������" << std::endl;
	}
}