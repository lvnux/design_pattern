//单例模式
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

using namespace std;

class Singlnton
{
public:
	static Singlnton* Instance()
	{
		if (NULL == _instance)
		{
			_instance = new Singlnton();
		}

		return _instance;
	}

protected:
	Singlnton(){ cout << "Singlnton ..." << endl; }  //这里构造函数一定不能用public修饰，因为单例模式不能在类外直接构造对象

private:
	static Singlnton* _instance;  //这里不能直接初始化， 只有静态常量整型数据成员才可以在类中初始化
};

Singlnton* Singlnton::_instance = NULL;   //前面不能再加static修饰

#endif