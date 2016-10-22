/*访问者模式(Visitor)
表示一个作用于某对象结构中的各元素的操作。它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。

意图：分离一个类结构和定义在这个类结构之上的操作，可以在不改变类结构的前提下添加新的操作。
实现要点：定义访问者接口，具体的访问者类实现具体的操作。

Visitor模式的关键是双分派(Double-Dispatch)
双分派：执行的操作将取决于请求的种类和接收者的类型。
*/
#ifndef __VISTIOR_H__
#define __VISTIOR_H__

class ConcreteElementA;
class ConcreteElementB;
class Element;
class Visitor
{
public:
	virtual ~Visitor();
	virtual void VisitorConcreteElementA(Element* pElm) = 0;
	virtual void VisitorConcreteElementB(Element* pElm) = 0;

protected:
	Visitor();
};


class ConcreteVisitorA : public Visitor
{
public:
	ConcreteVisitorA();
	~ConcreteVisitorA();

public:
	virtual void VisitorConcreteElementA(Element* pElm);
	virtual void VisitorConcreteElementB(Element* pElm);
};

class ConcreteVisitorB : public Visitor
{
public:
	ConcreteVisitorB();
	~ConcreteVisitorB();

public:
	virtual void VisitorConcreteElementA(Element* pElm);
	virtual void VisitorConcreteElementB(Element* pElm);
};


class Element
{
public:
	virtual ~Element();

public:
	virtual void Accept(Visitor* pVis) = 0;

protected:
	Element();
};

class ConcreteElementA : public Element
{
public:
	ConcreteElementA();
	~ConcreteElementA();

public:
	virtual void Accept(Visitor* pVis);
};

class ConcreteElementB : public Element
{
public:
	ConcreteElementB();
	~ConcreteElementB();

public:
	virtual void Accept(Visitor* pVis);
};

#endif  //__VISTIOR_H__