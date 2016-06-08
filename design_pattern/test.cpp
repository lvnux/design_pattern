#include "patterns/observer.h"

int main(int argc , char *argv [])
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

	return 0;
}