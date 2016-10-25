/*������ģʽ��Iterator��
���ṩһ�ַ���˳�����һ���ۺ϶����и���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ����

��ͼ�����н��߸��뷢���ߺͽ����ߣ������ߺͽ�����֮��û����ϣ����Զ����ط����仯��
ʵ��Ҫ�㣻�����н��ߺ�Э���߽ӿ��࣬�н��߹������е�Э����֮��Ĺ�����ϵ��
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