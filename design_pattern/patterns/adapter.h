//适配器模式
#ifndef __ADAPTER_H__
#define __ADAPTER_H__

class Target
{
public:
	Target(){}
	virtual ~Target(){}

public:
	virtual void Request(){ std::cout << "Target::Request ..." << std::endl; }
};

class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}

public:
	void SpecificRequest(){ std::cout << "Adaptee::SpecificRequest ..." << std::endl; }
};

#ifdef _CLASS_ADAPTER__
//类模式Adapter，通过多重继承方式实现
class Adapter : private Adaptee, public Target
{
public:
	Adapter(){}
	~Adapter(){}

public:
	void Request(){ this->SpecificRequest(); }
};
#else
//对象模式Adapter，通过类对象的组合方式实现
class Adapter : public Target
{
public:
	Adapter(Adaptee* ade) : _ade(ade) {}
	~Adapter(){}

public:
	void Request(){ _ade->SpecificRequest(); }

private:
	Adaptee* _ade;
};
#endif

#endif