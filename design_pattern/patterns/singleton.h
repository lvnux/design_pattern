//����ģʽ
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
	Singlnton(){ cout << "Singlnton ..." << endl; }  //���ﹹ�캯��һ��������public���Σ���Ϊ����ģʽ����������ֱ�ӹ������

private:
	static Singlnton* _instance;  //���ﲻ��ֱ�ӳ�ʼ���� ֻ�о�̬�����������ݳ�Ա�ſ��������г�ʼ��
};

Singlnton* Singlnton::_instance = NULL;   //ǰ�治���ټ�static����

#endif