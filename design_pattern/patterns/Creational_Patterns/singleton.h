/*����ģʽ
 */

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>

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
	Singlnton(){ std::cout << "Singlnton ..." << std::endl; }  //���ﹹ�캯��һ��������public���Σ���Ϊ����ģʽ����������ֱ�ӹ������

private:
	static Singlnton* _instance;  //���ﲻ��ֱ�ӳ�ʼ���� ֻ�о�̬�����������ݳ�Ա�ſ��������г�ʼ��
};

Singlnton* Singlnton::_instance = NULL;   //ǰ�治���ټ�static����

#endif