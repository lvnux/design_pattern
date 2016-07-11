/*���ģʽ������ģʽ��
 �����ģʽ��Facade����Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һ�µĽ��档��ģʽ������һ���߲�ӿڣ�����ӿ�ʹ����һ��ϵͳ��������ʹ�á���
 */

#ifndef __FACADE_H__
#define __FACADE_H__

#include <iostream>

class Subsystem1
{
public:
	Subsystem1(){}
	~Subsystem1(){}

public:
	void Operation(){ std::cout << "Subsystem1::Operation ..." << std::endl; }
};

class Subsystem2
{
public:
	Subsystem2(){}
	~Subsystem2(){}

public:
	void Operation(){ std::cout << "Subsystem2::Operation ..." << std::endl; }
};

class Facade
{
public:
	Facade()
	{
		m_pSys1 = new Subsystem1;
		m_pSys2 = new Subsystem2;
	}

	~Facade()
	{
		delete m_pSys1;
		delete m_pSys2;
	}

public:
	void OperationWrapper()
	{
		m_pSys1->Operation();
		m_pSys2->Operation();
	}

private:
	Subsystem1* m_pSys1;
	Subsystem2* m_pSys2;
};

#endif