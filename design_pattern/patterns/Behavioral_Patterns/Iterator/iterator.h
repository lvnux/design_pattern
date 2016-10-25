/*迭代器模式（Iterator）
【提供一种方法顺序访问一个聚合对象中各个元素，而又不暴露该对象的内部表示。】

意图：用中介者隔离发送者和接收者，发送者和接收者之间没有耦合，可以独立地发生变化。
实现要点；定义中介者和协作者接口类，中介者管理所有的协作者之间的关联关系。
*/
#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "aggregate.h"

class Aggregate;

class Iterator
{
public:
	~Iterator();

public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;

protected:
	Iterator();
};


class ConcreteIterator : public Iterator
{
public:
	ConcreteIterator(Aggregate* pAg, int index = 0);
	~ConcreteIterator();

public:
	virtual void First();
	virtual void Next();
	virtual bool IsDone();
	virtual Object CurrentItem();

private:
	Aggregate* m_pAggregate;
	int m_iIndex;
};


#endif  //__ITERATOR_H__