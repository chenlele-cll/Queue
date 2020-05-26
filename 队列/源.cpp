#include<iostream>
using namespace std;

//����һ���ռ��ѭ�����У���ֹ�����
template<class datatype>
class Cirqueue
{
private:
	int front;
	int rear;
	datatype *base;
	int maxsize;
public:
	Cirqueue();
	Cirqueue(int max);
	~Cirqueue();
	bool empty();
	bool full();
	int getlength();
	void enqueue(datatype value);
	void dequeue();
	datatype getfront();
	datatype getrear();
	friend ostream &operator<<(ostream &output, Cirqueue& D)
	{
		if (D.empty())
			cout << "����Ϊ��" << endl;
		else
		{
			int p = D.front;
			for (int i = 0; i < D.getlength(); i++)
			{
				output << D.base[p] << " ";
				p = (p + 1) % D.maxsize;
			}
			cout << endl;
		}
		return output;
	}
};

template<class datatype>
Cirqueue<datatype>::Cirqueue()
{
	maxsize = 11;
	base = new datatype[maxsize];
	front = rear =0;
}

template<class datatype>
Cirqueue<datatype>::Cirqueue(int max)
{
	maxsize = max+1;
	base = new datatype[maxsize];
	front = rear = 0;
}

template<class datatype>
Cirqueue<datatype>::~Cirqueue()
{
	delete base;
}

template<class datatype>
bool Cirqueue<datatype>::empty()
{
	return front == rear;
}

template<class datatype>
bool Cirqueue<datatype>::full()
{
	return (rear + 1) % maxsize == front;
}

template<class datatype>
int  Cirqueue<datatype>::getlength()
{
	return (rear - front + maxsize) % maxsize;
}

template<class datatype>
void Cirqueue<datatype>::enqueue(datatype value)
{
	if (full())
		cout << "��������" << endl;
	else
	{
		base[rear] = value;
		rear++;
	}
}

template<class datatype>
void  Cirqueue<datatype>::dequeue()
{
	if (empty())
		cout << "����Ϊ��" << endl;
	else
		front = (front + 1) % maxsize;
}

template<class datatype>
datatype Cirqueue<datatype>::getfront()
{
	return base[front];
}

template<class datatype>
datatype Cirqueue<datatype>::getrear()
{
	return base[rear-1];
}

int main()
{
	//test
	Cirqueue<int> A(3);
	A.enqueue(1);
	A.enqueue(2);
	A.dequeue();
	A.enqueue(4);
	A.enqueue(4);
	cout << A;
	cout << A.getlength() << " " << A.getfront() <<" "<<A.getrear()<< endl;
	system("pause");
	return 0;
}