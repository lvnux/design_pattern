/*������ģʽ(Visitor)
��ʾһ��������ĳ����ṹ�еĸ�Ԫ�صĲ�������ʹ������ڲ��ı��Ԫ�ص����ǰ���¶�����������ЩԪ�ص��²�����

��ͼ������һ����ṹ�Ͷ����������ṹ֮�ϵĲ����������ڲ��ı���ṹ��ǰ��������µĲ�����
ʵ��Ҫ�㣺��������߽ӿڣ�����ķ�������ʵ�־���Ĳ�����

Visitorģʽ�Ĺؼ���˫����(Double-Dispatch)
˫���ɣ�ִ�еĲ�����ȡ�������������ͽ����ߵ����͡�
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