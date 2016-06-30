/*��Ԫģʽ��Flyweight��
 *�����ù�������Ч��֧�ִ�����ϸ���ȵĶ���
 */

#ifndef __FLYWEIGHT_H__
#define __FLYWEIGHT_H__

#include <iostream>
#include <string>
#include <vector>

class Flyweight
{
public:
	virtual ~Flyweight(){}

public:
	virtual void Operation(const std::string& extrinsicState){}
	std::string GetIntrinsicState(){ return m_intrinsicState; }

protected:
	Flyweight(std::string intrinsicState) : m_intrinsicState(intrinsicState){}

private:
	std::string m_intrinsicState;   //��������״̬
};

class ConcreteFlyweight: public Flyweight
{
public:
	ConcreteFlyweight(std::string intrinsicState) : Flyweight(intrinsicState)
	{
		std::cout << "ConcreteFlyweight build ..." << intrinsicState << std::endl;
	}
	~ConcreteFlyweight(){}

public:
	void Operation(const std::string& extrinsicState)
	{
		std::cout << "ConcreteFlyweight: intrinsicState: [" << GetIntrinsicState() << "], extrinsic: [" << extrinsicState << "]" << std::endl;
	}
};

//������ľ���Flyweight��
class UnsharedConcreteFlyweight: public Flyweight
{
public:
	UnsharedConcreteFlyweight(std::string intrinsicState) : Flyweight(intrinsicState){}
	~UnsharedConcreteFlyweight(){}

public:
	void Operation(const std::string& extrinsicState)
	{
		std::cout << "Unshared ConcreteFlyweight ..." << std::endl;
	}
};

//��Ԫ����������������Flyweight����
class FlyweightFactory
{
public:
	FlyweightFactory(){}
	~FlyweightFactory(){}

public:
	Flyweight* GetFlyweight(const std::string& key)
	{
		std::vector<Flyweight*>::iterator iter = m_pFlyVct.begin();
		for (; iter != m_pFlyVct.end(); ++iter)
		{
			if ((*iter)->GetIntrinsicState() == key)
			{
				return *iter;
			}
		}

		Flyweight* fn = new ConcreteFlyweight(key);
		m_pFlyVct.push_back(fn);
		return fn;
	}

private:
	std::vector<Flyweight*> m_pFlyVct;
};

#endif