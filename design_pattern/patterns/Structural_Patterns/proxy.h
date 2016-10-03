/*����ģʽ
 *��Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�
 */

#ifndef __PROXY_H__
#define __PROXY_H__

#include <iostream>

//Subject�࣬������ConcreteSubject��ʹ�����Ĺ��ýӿ�
class Subject
{
public:
	virtual ~Subject(){}
	virtual void Request() = 0;

protected:
	Subject(){}
};

class ConcreteSubject: public Subject
{
public:
	ConcreteSubject(){}
	~ConcreteSubject(){}

public:
	void Request(){ std::cout << "ConcreteSubject::Request ..." << std::endl; }
};

//������
class Proxy: public Subject
{
public:
	Proxy(Subject* sbj) : m_pSbj(sbj){}
	~Proxy(){}

public:
	void Request(){ m_pSbj->Request(); }

private:
	Subject* m_pSbj;
};

#endif