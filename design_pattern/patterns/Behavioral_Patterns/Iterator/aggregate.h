#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__

typedef int Object;  //这里示例以int类型元素表示

class Aggregate
{
public:
	virtual ~Aggregate();

public:
	virtual Object GetItem(int iIndex) = 0;
	virtual int GetSize() = 0;

protected:
	Aggregate();
};


class ConcreteAggregate : public Aggregate
{
public:
	ConcreteAggregate();
	~ConcreteAggregate();

public:
	virtual Object GetItem(int iIndex);
	virtual int GetSize();

public:
	enum {SIZE = 50};

private:
	Object m_Obj[SIZE];
};

#endif  //__AGGREGATE_H__