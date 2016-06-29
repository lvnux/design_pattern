/*建造者模式
 *【将一个复杂对象的构建和它的表示分离，使得同样的构建过程可以创建不同的表示】
 */

#ifndef __BUILDER_H__
#define __BUILDER_H__

#include <iostream>
#include <string>

class ProductBuild
{
public:
	ProductBuild(){}
	~ProductBuild(){}

public:
	void SetProductPartA(const std::string& part){ m_partA = (std::string)part; }
	void SetProductPartB(const std::string& part){ m_partB = part; }
	void SetProductPartC(const std::string& part){ m_partC = part; }

	void Show()  //为了展示添加的函数
	{
		std::cout << "PartA: " << m_partA << std::endl;
		std::cout << "PartB: " << m_partB << std::endl;
		std::cout << "PartC: " << m_partC << std::endl;
	}

private:
	std::string m_partA;
	std::string m_partB;
	std::string m_partC;
};

class Builder
{
public:
	virtual ~Builder(){}

public:
	virtual void BuildPartA(const std::string& part) = 0;
	virtual void BuildPartB(const std::string& part) = 0;
	virtual void BuildPartC(const std::string& part) = 0;
	virtual ProductBuild* GetProduct() = 0;

protected:
	Builder(){}
};

class ConcreteBuilder: public Builder
{
public:
	ConcreteBuilder(){ m_pProduct = new ProductBuild(); }
	~ConcreteBuilder(){ delete m_pProduct; }

public:
	void BuildPartA(const std::string& part)
	{
		m_pProduct->SetProductPartA(part);
		std::cout << "ConcreteBuilder::BuildPartA ..." << std::endl;
	}

	void BuildPartB(const std::string& part)
	{
		m_pProduct->SetProductPartB(part);
		std::cout << "ConcreteBuilder::BuildPartB ..." << std::endl;
	}

	void BuildPartC(const std::string& part)
	{
		m_pProduct->SetProductPartC(part);
		std::cout << "ConcreteBuilder::BuildPartC ..." << std::endl;
	}

	ProductBuild* GetProduct()
	{
		return m_pProduct; 
	}

private:
	ProductBuild* m_pProduct;
};

class Director
{
public:
	Director(Builder* bld) : m_pBld(bld){}
	~Director(){}

public:
	void Construct()
	{
		m_pBld->BuildPartA("head");
		m_pBld->BuildPartB("body");
		m_pBld->BuildPartC("footer");
	}

private:
	Builder* m_pBld;
};

#endif