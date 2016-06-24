#include "observer.h"
#include "decorator.h"
#include "factory.h"
#include "abstractFactory.h"
#include "singleton.h"
#include "command.h"

#define _CLASS_ADAPTER__  //测试类模式Adapter还是对象模式Adapter的标识
#include "adapter.h"

void test_observe()
{
	Blog* blog = new BlogCSDN("lvnux");
	Observer* observer1 = new ObserverBlog("lvpj", blog);
	Observer* observer2 = new ObserverBlog("lvpingjie", blog);

	blog->Attach(observer1);
	blog->Attach(observer2);
	blog->SetStatus("状态变了");
	blog->Notify();

	delete blog;
	delete observer1;
}

void test_decorator()
{
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();
}

void test_factory()
{
	Factory* fac = new ConcreteFactory();
	Product* pro = fac->CreateProduct();
}

void test_abstract_factory()
{
	AbstractFactory* cf1 = new ConcreteFactory1();
	cf1->CreateProductA();
	cf1->CreateProductB();

	AbstractFactory* cf2 = new ConcreteFactory2();
	cf2->CreateProductA();
	cf2->CreateProductB();
}

void test_singlnton()
{
	Singlnton* sgn1 = Singlnton::Instance();
	Singlnton* sgn2 = Singlnton::Instance();
	if (sgn1 == sgn2)
	{
		cout << "singln ..." << endl;
	}
	else
	{
		cout << "not singln ..." << endl;
	}
}

void test_command()
{
	Receiver* rev = new Receiver();
	ConcreteCommand* concmd = new ConcreteCommand(rev);
	Invoker* inv = new Invoker(concmd);
	inv->Invoke();
}

#ifdef _CLASS_ADAPTER__
void test_adapter()
{
	Target* tag = new Adapter;
	tag->Request();
}
#else
void test_adapter()
{
	Adaptee* ade = new Adaptee;
	Target* tag = new Adapter(ade);
	tag->Request();
}
#endif

int main(int argc , char *argv [])
{
	//test_observe();

	//test_decorator();

	//test_factory();

	//test_abstract_factory();

	//test_singlnton();

	//test_command();

	test_adapter();

	return 0;
}