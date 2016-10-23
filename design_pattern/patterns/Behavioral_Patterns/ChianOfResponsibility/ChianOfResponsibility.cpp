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
		std::cout << "ConcreteHandlerA: 我把处理交给后继节点。" << std::endl;
		GetSuccessor()->HandleRequest();
	}
	else
	{
		std::cout << "ConcreteHandlerA: 没有后继了，我必须自己处理该请求。" << std::endl;
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
		std::cout << "ConcreteHandlerB: 我把处理交给后继节点。" << std::endl;
		GetSuccessor()->HandleRequest();
	}
	else
	{
		std::cout << "ConcreteHandlerB: 没有后继了，我必须自己处理该请求。" << std::endl;
	}
}