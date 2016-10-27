#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "ContextInterpreter.h"
#include <string>

class AbstractExpression
{
public:
	virtual ~AbstractExpression();
	virtual void Interpreter(const ContextInterpreter& context);

protected:
	AbstractExpression();
};


class TerminalExpression : public AbstractExpression
{
public:
	TerminalExpression(const std::string& statement);
	~TerminalExpression();

public:
	virtual void Interpreter(const ContextInterpreter& context);

private:
	std::string m_strStatement;
};


class NonterminalExpression : public AbstractExpression
{
public:
	NonterminalExpression();
	NonterminalExpression(AbstractExpression* pExpression, int times);
	~NonterminalExpression();

public:
	virtual void Interpreter(const ContextInterpreter& context);

private:
	AbstractExpression* m_pExpression;
	int m_iTimes;
};

#endif  //__INTERPRETER_H__