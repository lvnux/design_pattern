#include "Interpreter.h"
#include <iostream>

//AbstractExpression
AbstractExpression::AbstractExpression()
{

}

AbstractExpression::~AbstractExpression()
{

}

void AbstractExpression::Interpreter(const ContextInterpreter& context)
{

}


//TerminalExpression
TerminalExpression::TerminalExpression(const std::string& statement)
	: m_strStatement(statement)
{
	
}

TerminalExpression::~TerminalExpression()
{

}

void TerminalExpression::Interpreter(const ContextInterpreter& context)
{
	std::cout << m_strStatement << "TerminalExpression" << std::endl;
}


//NonterminalExpression
NonterminalExpression::NonterminalExpression(AbstractExpression* pExpression, int times)
	:m_pExpression(pExpression), m_iTimes(times)
{

}

NonterminalExpression::~NonterminalExpression()
{

}

void NonterminalExpression::Interpreter(const ContextInterpreter& context)
{
	for (int i = 0; i < m_iTimes; ++i)
	{
		m_pExpression->Interpreter(context);
	}
}