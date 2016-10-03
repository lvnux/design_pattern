/*���ģʽ��Composite��
 *����������ϳ����νṹ�Ա�ʾ������-���塯�Ĳ�νṹ�����ģʽʹ���û��Ե����������϶����ʹ�þ���һ���ԡ���
 */

#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

#include <iostream>
#include <vector>

class ComponentComposite
{
public:
	ComponentComposite(){}
	~ComponentComposite(){}

public:
	virtual void Operation() = 0;

	//������������û������Ϊ���麯�����ǿ��ǵ�Ҷ�ӽڵ�û���ӽڵ㣬����Ҫ��д��Щ������
	virtual void Add(const ComponentComposite* com){}
	virtual void Remove(const ComponentComposite* com){}
	virtual ComponentComposite* GetChild(int index){ return NULL; }
};

class Composite: public ComponentComposite
{
public:
	Composite(){}
	~Composite(){}

public:
	void Operation()
	{
		std::vector<ComponentComposite*>::iterator iter = m_pComVec.begin();
		for (; iter != m_pComVec.end(); ++iter)
		{
			(*iter)->Operation();	
		}
	}

	void Add(const ComponentComposite* com)
	{
		m_pComVec.push_back((ComponentComposite*)com);
	}

	void Remove(const ComponentComposite* com)
	{
		std::vector<ComponentComposite*>::iterator iter = m_pComVec.begin();
		for (; iter != m_pComVec.end();)
		{
			if (*iter == com)
			{
				iter = m_pComVec.erase(iter);
			}else{
				++iter;
			}
		}
	}

	ComponentComposite* GetChild(int index)
	{
		return m_pComVec[index];
	}

private:
	std::vector<ComponentComposite*> m_pComVec;
};

class Leaf: public ComponentComposite
{
public:
	Leaf(){}
	~Leaf(){}

public:
	void Operation()
	{
		std::cout << "Leaf Operation ..." << std::endl;
	}
};

#endif