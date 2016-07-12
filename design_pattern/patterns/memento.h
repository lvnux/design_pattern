/*备忘录模式
 【备忘录模式（Memento）：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样就可以将该对象恢复到原先保存的状态。】
 */

#ifndef __MEMENTO_H__
#define __MEMENTO_H__

#include <iostream>
#include <string>

class Originator;

//备忘录
//负责存储Originator对象的内部状态，并可防止Originator以外的其他对象访问Memento
class Memento
{
private:
	//这里是最关键的地方，将Originator声明为友元类，可以访问内部信息，但是其他类不能访问
	friend class Originator;

	Memento(){}
	Memento(const std::string& st) : m_status(st){}
	~Memento(){}

private:
	void SetState(const std::string& st){ m_status = st; }
	std::string GetState(){ return m_status; }

private:
	std::string m_status;
};

//发起人
//负责创建一个备忘录Memento，用以记录当前时刻它的内部状态，并可使用备忘录恢复内部状态
class Originator
{
public:
	Originator() : m_status(""), m_pMt(NULL){}
	Originator(const std::string& st) : m_status(st), m_pMt(NULL){}
	~Originator(){}

public:
	Memento* CreateMemento()
	{
		return new Memento(m_status);
	}

	void SetMemento(Memento* mt)
	{
		m_status = mt->GetState();
	}

	void RestoreToMemento(Memento* mt)
	{
		m_status = mt->GetState();
	}

	void SetState(const std::string& st)
	{
		m_status = st;
	}

	std::string GetState()
	{
		return m_status;
	}

	void PrintState()
	{
		std::cout << "Originator status ..." << m_status << std::endl;
	}

private:
	std::string m_status;
	Memento* m_pMt;
};


#endif