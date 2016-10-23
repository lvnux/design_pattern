/*职责链模式（Chian Of Responsibility）
【使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。
  将这些对象连成一条链，并沿着这条链传递该请求，知道有一个对象处理它为止。】

  意图：把请求发送给一条职责链，职责链上的多个对象都有机会处理请求，对象自己决定如何处理该请求。
		很容易添加、删除或改变职责链上的处理环节。
  实现要点：定义请求处理接口，派生类可以自己决定如何处理请求，具体的请求处理对象被组织成了一条职责链。
*/
#ifndef __CHIAN_OF_RESPONSIBILITY_H__
#define __CHIAN_OF_RESPONSIBILITY_H__

class Handler
{
public:
	virtual ~Handler();

public:
	virtual void HandleRequest() = 0;
	void SetSuccessor(Handler* pSuccessor);
	Handler* GetSuccessor();

protected:
	Handler();
	Handler(Handler* pSuccessor);

private:
	Handler* m_pSuccessor;
};


class ConcreteHandlerA : public Handler
{
public:
	ConcreteHandlerA();
	ConcreteHandlerA(Handler* pSuccessor);
	~ConcreteHandlerA();

public:
	virtual void HandleRequest();
};


class ConcreteHandlerB : public Handler
{
public:
	ConcreteHandlerB();
	ConcreteHandlerB(Handler* pSuccessor);
	~ConcreteHandlerB();

public:
	virtual void HandleRequest();
};

#endif  //__CHIAN_OF_RESPONSIBILITY_H__