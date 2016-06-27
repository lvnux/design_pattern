/* ����ģʽ
 * 1�����崴������Ľӿڣ���װ�˶���Ĵ���
 * 2��ʹ�þ��廯��Ĺ����ӳٵ�������
 */

#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <iostream>

//�����Ʒ��
class Product
{
public:
	virtual ~Product() = 0;
protected:
	Product(){}
};
Product::~Product(){}   //����������Ϊ���麯��������Ҫ��ʵ�֡����򱨴�error LNK2019: �޷��������ⲿ���� "public: virtual __thiscall Product::~Product(void)" (??1Product@@UAE@XZ)���÷����ں��� __unwindfunclet$??0ConcreteProduct@@QAE@XZ$0 �б����á�


//�����Ʒ��
class ConcreteProduct : public Product
{
public:
	ConcreteProduct(){ std::cout << "ConcreteProduct ..." << std::endl; }
	~ConcreteProduct(){}
};


//������ĳ���
class Factory
{
public:
	virtual ~Factory() = 0;	  //����������Ϊ���麯��������Ҫ��ʵ�֡�
	virtual Product* CreateProduct() = 0;   //��ͨ����Ϊ���麯����������ʵ�֣�Ҳ���Բ���Ҫʵ��

protected:
	Factory(){}
};
Factory::~Factory(){}


//���幤����
class ConcreteFactory : public Factory
{
public:
	~ConcreteFactory(){}
	ConcreteFactory(){ std::cout << "ConcreteFactory ..." << std::endl; }
	Product* CreateProduct(){ return new ConcreteProduct(); }
};

#endif