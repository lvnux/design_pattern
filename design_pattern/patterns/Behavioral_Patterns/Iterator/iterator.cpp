#include "iterator.h"
#include <iostream>

//Iterator
Iterator::Iterator()
{

}

Iterator::~Iterator()
{

}


//ConcreteIterator
ConcreteIterator::ConcreteIterator(Aggregate* pAg, int index)
	: m_pAggregate(pAg), m_iIndex(index)
{

}

ConcreteIterator::~ConcreteIterator()
{

}

Object ConcreteIterator::CurrentItem()
{
	return m_pAggregate->GetItem(m_iIndex);
}

void ConcreteIterator::First()
{
	m_iIndex = 0;
}

void ConcreteIterator::Next()
{
	if (m_iIndex < m_pAggregate->GetSize())
	{
		m_iIndex++;
	}
}

bool ConcreteIterator::IsDone()
{
	return (m_pAggregate->GetSize() == m_iIndex);
}