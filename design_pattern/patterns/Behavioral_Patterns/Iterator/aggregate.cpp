#include "aggregate.h"
#include "iterator.h"
#include <iostream>

//Aggregate
Aggregate::Aggregate()
{

}

Aggregate::~Aggregate()
{

}


//ConcreteAggregate
ConcreteAggregate::ConcreteAggregate()
{
	for (int i = 0; i < SIZE; ++i)
	{
		m_Obj[i] =i;
	}
}

ConcreteAggregate::~ConcreteAggregate()
{

}


Iterator* ConcreteAggregate::CreateIterator()
{
	return new ConcreteIterator(this);
}

Object ConcreteAggregate::GetItem(int iIndex)
{
	if (iIndex < GetSize())
	{
		return m_Obj[iIndex];
	}
	else
	{
		return -1;
	}
}

int ConcreteAggregate::GetSize()
{
	return SIZE;
}
