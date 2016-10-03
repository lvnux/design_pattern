/*����¼ģʽ
 ������¼ģʽ��Memento�����ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬�������Ϳ��Խ��ö���ָ���ԭ�ȱ����״̬����
 */

#ifndef __MEMENTO_H__
#define __MEMENTO_H__

#include <iostream>
#include <string>

class Originator;

//����¼
//����洢Originator������ڲ�״̬�����ɷ�ֹOriginator����������������Memento
class Memento
{
private:
	//��������ؼ��ĵط�����Originator����Ϊ��Ԫ�࣬���Է����ڲ���Ϣ�����������಻�ܷ���
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

//������
//���𴴽�һ������¼Memento�����Լ�¼��ǰʱ�������ڲ�״̬������ʹ�ñ���¼�ָ��ڲ�״̬
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