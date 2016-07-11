/*设计模式原则:
 1、单一职责原则（Single Responsibility Principle）
 2、里氏替换原则（Liskov Substitution Principle）
 3、依赖倒置原则（Dependence Inversion Principle）
 4、接口隔离原则（Interface Segregation Principle）
 5、迪米特法则（Law Of Demeter）
 6、开闭原则（Open Close Principle）
*/

#include <iostream>
#include "observer.h"
#include "decorator.h"
#include "factory.h"
#include "abstractFactory.h"
#include "singleton.h"
#include "command.h"
#include "template.h"
#include "strategy.h"
#include "bridge.h"
#include "proxy.h"
#include "prototype.h"
#include "builder.h"
#include "composite.h"
#include "flyweight.h"
#include "facade.h"
#include "state.h"

#ifndef _CLASS_ADAPTER__
//#define _CLASS_ADAPTER__  //测试类模式Adapter还是对象模式Adapter的标识
#include "adapter.h"
#endif

void test_observe()
{
	Blog* blog = new BlogCSDN("新闻");
	Observer* observer1 = new ObserverBlog("Lucy", blog);
	Observer* observer2 = new ObserverBlog("Lily", blog);

	blog->Attach(observer1);
	blog->Attach(observer2);
	blog->SetStatus("状态变了");
	blog->Notify();

	delete blog;
	delete observer1;
	delete observer2;
}

void test_decorator()
{
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();

	delete com;
	delete dec;	
}

void test_factory()
{
	Factory* fac = new ConcreteFactory();
	Product* pro = fac->CreateProduct();

	delete fac;
	delete pro;
}

void test_abstract_factory()
{
	AbstractFactory* cf1 = new ConcreteFactory1();
	cf1->CreateProductA();
	cf1->CreateProductB();

	AbstractFactory* cf2 = new ConcreteFactory2();
	cf2->CreateProductA();
	cf2->CreateProductB();

	delete cf1;
	delete cf2;
}

void test_singlnton()
{
	Singlnton* sgn1 = Singlnton::Instance();
	Singlnton* sgn2 = Singlnton::Instance();
	if (sgn1 == sgn2)
	{
		std::cout << "singln ..." << std::endl;
	}
	else
	{
		std::cout << "not singln ..." << std::endl;
	}
}

void test_command()
{
	Receiver* rev = new Receiver();
	ConcreteCommand* concmd = new ConcreteCommand(rev);
	Invoker* inv = new Invoker(concmd);
	inv->Invoke();

	delete rev;
	delete concmd;
	delete inv;
}

#ifdef _CLASS_ADAPTER__
void test_adapter()
{
	Target* tag = new Adapter;
	tag->Request();

	delete tag;
}
#else
void test_adapter()
{
	Adaptee* ade = new Adaptee;
	Target* tag = new Adapter(ade);
	tag->Request();

	delete ade;
	delete tag;
}
#endif

void test_template()
{
	AbstractClass* p1 = new ConcreteClass1;
	AbstractClass* p2 = new ConcreteClass2;
	p1->TemplateMethod();
	p2->TemplateMethod();

	delete p1;
	delete p2;
}

void test_strategy()
{
	Strategy* stg = new ConcreteStrategyA;
	Context* ctt = new Context(stg);
	ctt->DoAction();

	delete stg;
	delete ctt;
}

void test_bridge()
{
	AbstractionImp* impA = new ConcreteAbstractionImpA;
	Abstraction* act = new RefinedAbstraction(impA);

	act->Operation();

	delete impA;
	delete act;
}

void test_proxy()
{
	Subject* sbj = new ConcreteSubject;
	Proxy* pro = new Proxy(sbj);
	pro->Request();

	delete sbj;
	delete pro;
}

void test_prototype()
{
	Prototype* p = new ConcretePrototype;
	Prototype* p1 = p->Clone();

	delete p;
	delete p1;
}

void test_builder()
{
	Builder* bld = new ConcreteBuilder;
	Director* dct = new Director(bld);
	dct->Construct();

	ProductBuild* pdt = bld->GetProduct();
	pdt->Show();

	delete bld;
	delete dct;
}

void test_composite()
{
	Leaf* l = new Leaf;
	l->Operation();

	ComponentComposite* com = new Composite;
	com->Add(l);
	com->Operation();

	ComponentComposite* l1 = com->GetChild(0);
	l1->Operation();
}

void test_flyweight()
{
	FlyweightFactory* fc = new FlyweightFactory;

	Flyweight* fw1 = fc->GetFlyweight("hello");
	Flyweight* fw2 = fc->GetFlyweight("world");
	Flyweight* fw3 = fc->GetFlyweight("hello");

	fw1->Operation("Lucy");
	fw2->Operation("Lily");
	fw3->Operation("Samao");

	delete fc;
}

void test_facade()
{
	Facade* f = new Facade;
	f->OperationWrapper();

	delete f;
}

void test_state()
{
	State* st = new ConcreteStateA;
	ContextState* con = new ContextState(st);
	con->OperationChangeState();
	con->OperationChangeState();
	con->OperationChangeState();
	con->OperationChangeState();
	con->OperationChangeState();

	delete st;
	delete con;
}

int main(int argc , char *argv [])
{
	//test_observe();

	//test_decorator();

	//test_factory();

	//test_abstract_factory();

	//test_singlnton();

	//test_command();

	//test_adapter();

	//test_template();

	//test_strategy();

	//test_bridge();

	//test_proxy();

	//test_prototype();

	//test_builder();

	//test_composite();

	//test_flyweight();

	//test_facade();

	test_state();

	return 0;
}