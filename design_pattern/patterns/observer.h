//观察者模式
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

	virtual void SetStatus(std::string s){m_status = s;}
	virtual std::string GetStatus(){return m_status;}

private:
	list<Observer*> m_observers;

protected:
	std::string m_status;
};

class BlogCSDN : public Blog
{
public:
	BlogCSDN(std::string name) : m_name(name){}
	~BlogCSDN(){}
	void SetStatus(std::string s){ m_status = "CSDN通知：" + m_name + s;}
	std::string GetStatus(){return m_status;}
private:
	std::string m_name;
};

class ObserverBlog : public Observer
{
public:
	ObserverBlog(std::string name, Blog* blog) : m_name(name), m_blog(blog){}
	~ObserverBlog(){}
	void Update()
	{
		std::string status = m_blog->GetStatus();
		std::cout << m_name << "----" << status << endl;
	}

private:
	std::string m_name;
	Blog* m_blog;
};

#endif  //__OBSERVER_H__