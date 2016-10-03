/*״̬ģʽ
 ��״̬ģʽ��State������һ�����������״̬�ı�ʱ����ı�����Ϊ����������������Ǹı������ࡣ��
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
	virtual void OperationChangeState(ContextState*) = 0;  //״̬ת��

protected:
	virtual void OperationInterface(ContextState*) = 0;  //�㷨��ʵ��
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

void State::ChangeState(ContextState* con, State* st){ con->ChangeState(st); } //�������������Ҫ����ContextState��ʵ��֮����Ϊ��Ҫ����ContextState����

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

//��Ҫ����ConcreteStateBʵ��֮��
void ConcreteStateA::OperationChangeState(ContextState* con)
{
	OperationInterface(con);
	ChangeState(con, new ConcreteStateB);
}

//��Ҫ����ConcreteStateAʵ��֮��
void ConcreteStateB::OperationChangeState(ContextState* con)
{
	OperationInterface(con);
	ChangeState(con, new ConcreteStateA);
}

#endif