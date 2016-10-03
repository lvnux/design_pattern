/*状态模式
 【状态模式（State），当一个对象的内在状态改变时允许改变其行为，这个对象看起来像是改变了其类。】
 */

#ifndef __STATE_H__
#define __STATE_H__

#include <iostream>

class ContextState;
class State
{
public:
	State(){}
	virtual ~State(){}

public:
	virtual void OperationChangeState(ContextState*) = 0;  //状态转换

protected:
	virtual void OperationInterface(ContextState*) = 0;  //算法的实现
	void ChangeState(ContextState* con, State* st);
};

class ContextState
{
public:
	ContextState(State* st) : m_pState(st){}
	~ContextState(){}

public:
	//void OpeartionInterface(){ m_pState->OperationInterface(this); }
	void OperationChangeState(){ m_pState->OperationChangeState(this); }
	void ChangeState(State* st){ m_pState = st; }

private:
	State* m_pState;
};

void State::ChangeState(ContextState* con, State* st){ con->ChangeState(st); } //这个函数定义需要放在ContextState类实现之后，因为需要创建ContextState对象

class ConcreteStateA : public State
{
public:
	ConcreteStateA(){}
	virtual ~ConcreteStateA(){}

public:
	virtual void OperationChangeState(ContextState* con);

protected:
	virtual void OperationInterface(ContextState* con){ std::cout << "ConcreteStateA::OperationInterface ..." << std::endl; }
};

class ConcreteStateB : public State
{
public:
	ConcreteStateB(){}
	virtual ~ConcreteStateB(){}

public:
	virtual void OperationChangeState(ContextState* con);

protected:
	virtual void OperationInterface(ContextState* con){ std::cout << "ConcreteStateB::OperationInterface ..." << std::endl; }
};

//需要放在ConcreteStateB实现之后
void ConcreteStateA::OperationChangeState(ContextState* con)
{
	OperationInterface(con);
	ChangeState(con, new ConcreteStateB);
}

//需要放在ConcreteStateA实现之后
void ConcreteStateB::OperationChangeState(ContextState* con)
{
	OperationInterface(con);
	ChangeState(con, new ConcreteStateA);
}

#endif