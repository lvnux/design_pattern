#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <string>
#include <list>
#include <iostream>
using namespace std;

class Observer
{
public:
	Observer(){}
	virtual ~Observer(){}
	virtual void Update(){}
};

class Blog
{
public:
	Blog(){}
	virtual ~Blog(){}
	void Attach(Observer* observer){m_observers.push_back(observer);}
	void Remove(Observer* observer){m_observers.remove(observer);}
	void Notify()
	{
		list<Observer*>::iterator iter = m_observers.begin();
		for (; iter != m_observers.end(); ++iter)
		{
			(*iter)->Update();
		}
	}

	virtual void SetStatus(string s){m_status = s;}
	virtual string GetStatus(){return m_status;}

private:
	list<Observer*> m_observers;

protected:
	string m_status;
};

class BlogCSDN : public Blog
{
public:
	BlogCSDN(string name) : m_name(name){}
	~BlogCSDN(){}
	void SetStatus(string s){ m_status = "CSDNÍ¨Öª£º" + m_name + s;}
	string GetStatus(){return m_status;}
private:
	string m_name;
};

class ObserverBlog : public Observer
{
public:
	ObserverBlog(string name, Blog* blog) : m_name(name), m_blog(blog){}
	~ObserverBlog(){}
	void Update()
	{
		string status = m_blog->GetStatus();
		cout << m_name << "----" << status << endl;
	}

private:
	string m_name;
	Blog* m_blog;
};

#endif  //__OBSERVER_H__