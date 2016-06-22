#include "patterns/observer.h"
#include "patterns/decorator.h"
#include "patterns/factory.h"
#include "patterns/abstractFactory.h"
#include "patterns/singleton.h"

void test_observe()
{
	Blog* blog = new BlogCSDN("lvnux");
	Observer* observer1 = new ObserverBlog("lvpj", blog);
	Observer* observer2 = new ObserverBlog("lvpingjie", blog);

	blog->Attach(observer1);
	blog->Attach(observer2);
	blog->SetStatus("×´Ì¬±äÁË");
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

int main(int argc , char *argv [])
{
	//test_observe();

	//test_decorator();

	//test_factory();

	//test_abstract_factory();

	test_singlnton();

	return 0;
}