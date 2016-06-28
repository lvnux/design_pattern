/*代理模式
 *【为其他对象提供一种代理以控制对这个对象的访问】
 */

#ifndef __PROXY_H__
#define __PROXY_H__

#include <iostream>

//Subject类，定义了ConcreteSubject类和代理类的共用接口
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

//代理类
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