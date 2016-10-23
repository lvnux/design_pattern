/*ְ����ģʽ��Chian Of Responsibility��
��ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ��
  ����Щ��������һ���������������������ݸ�����֪����һ����������Ϊֹ����

  ��ͼ���������͸�һ��ְ������ְ�����ϵĶ�������л��ᴦ�����󣬶����Լ�������δ��������
		��������ӡ�ɾ����ı�ְ�����ϵĴ����ڡ�
  ʵ��Ҫ�㣺����������ӿڣ�����������Լ�������δ������󣬾���������������֯����һ��ְ������
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