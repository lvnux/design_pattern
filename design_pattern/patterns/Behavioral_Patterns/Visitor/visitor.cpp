#include "visitor.h"

#include <iostream>


//Visitor
Visitor::Visitor()
{

}

Visitor::~Visitor()
{

}


//ConcreteVisitorA
ConcreteVisitorA::ConcreteVisitorA()
{

}

ConcreteVisitorA::~ConcreteVisitorA()
{

}

void ConcreteVisitorA::VisitorConcreteElementA(Element* pElm)
{
	std::cout << "I will visit ConcreteVisitorA::VisitorConcreteElementA" << std::endl;
}

void ConcreteVisitorA::VisitorConcreteElementB(Element* pElm)
{
	std::cout << "I will visit ConcreteVisitorA::VisitorConcreteElementB" << std::endl;
}


//ConcreteVisitorB
ConcreteVisitorB::ConcreteVisitorB()
{

}

ConcreteVisitorB::~ConcreteVisitorB()
{

}

void ConcreteVisitorB::VisitorConcreteElementA(Element* pElm)
{
	std::cout << "I will visit ConcreteVisitorB::VisitorConcreteElementA" << std::endl;
}

void ConcreteVisitorB::VisitorConcreteElementB(Element* pElm)
{
	std::cout << "I will visit ConcreteVisitorB::VisitorConcreteElementB" << std::endl;
}


//Element
Element::Element()
{

}

Element::~Element()
{

}


//ConcreteElementA
ConcreteElementA::ConcreteElementA()
{

}

ConcreteElementA::~ConcreteElementA()
{

}

void ConcreteElementA::Accept(Visitor* pVis)
{
	pVis->VisitorConcreteElementA(this);
	std::cout << "Visit ConcreteElementA" << std::endl;
}


//ConcreteElementB
ConcreteElementB::ConcreteElementB()
{

}

ConcreteElementB::~ConcreteElementB()
{

}

void ConcreteElementB::Accept(Visitor* pVis)
{
	pVis->VisitorConcreteElementA(this);
	std::cout << "Visit ConcreteElementB" << std::endl;
}