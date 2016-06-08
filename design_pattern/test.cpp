#include "patterns/observer.h"
#include "patterns/decorator.h"

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


int main(int argc , char *argv [])
{
	//test_observe();

	test_decorator();

	return 0;
}