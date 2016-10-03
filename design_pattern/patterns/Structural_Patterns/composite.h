/*组合模式（Composite）
 *【将对象组合成树形结构以表示‘部分-整体’的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。】
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

	//以下三个函数没有声明为纯虚函数，是考虑到叶子节点没有子节点，不需要重写这些方法。
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