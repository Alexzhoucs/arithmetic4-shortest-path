/**
 * C ����: 쳲�������
 *
 * @author skywang
 * @date 2014/04/06
 */
#include <iostream>
#include "FibHeap.h"
using namespace std;

#define DEBUG 0

// ��8��
int a[] = { 12,  7, 25, 15, 28,
		   33, 41,  1 };
// ��14��
int b[] = { 23,3,17,24,18,52,38,39,41,30,26,46,35 };

// ��֤"������Ϣ(쳲������ѵĽṹ)"
void testBasic()
{
	int i;
	int blen = sizeof(b) / sizeof(b[0]);
	FibHeap<int>* hb = new FibHeap<int>();

	// 쳲�������hb
	cout << "== 쳲�������(hb)���������: ";
	for (i = 0; i < blen; i++)
	{
		cout << b[i] << " ";
		hb->insert(b[i]);
	}
	cout << endl;
	cout << "== 쳲�������(hb)ɾ����С�ڵ�" << endl;
	hb->removeMin();
	hb->print();
}

// ��֤"�������"
void testInsert()
{
	int i;
	int alen = sizeof(a) / sizeof(a[0]);
	FibHeap<int>* ha = new FibHeap<int>();

	cout << "== 쳲�������(ha)���������: ";
	for (i = 0; i < alen; i++)
	{
		cout << a[i] << " ";
		ha->insert(a[i]);
	}
	cout << endl;
	cout << "== 쳲�������(ha)ɾ����С�ڵ�" << endl;
	ha->removeMin();
	ha->print();

	// 쳲�������hb
	cout << "== ����50" << endl;
	ha->insert(50);
	ha->print();
}

// ��֤"�ϲ�����"
void testUnion()
{
	int i;
	int alen = sizeof(a) / sizeof(a[0]);
	int blen = sizeof(b) / sizeof(b[0]);
	FibHeap<int>* ha = new FibHeap<int>();
	FibHeap<int>* hb = new FibHeap<int>();

	cout << "== 쳲�������(ha)���������: ";
	for (i = 0; i < alen; i++)
	{
		cout << a[i] << " ";
		ha->insert(a[i]);
	}
	cout << endl;
	cout << "== 쳲�������(ha)ɾ����С�ڵ�" << endl;
	ha->removeMin();
	ha->print();

	// 쳲�������hb
	cout << "== 쳲�������(hb)���������: ";
	for (i = 0; i < blen; i++)
	{
		cout << b[i] << " ";
		hb->insert(b[i]);
	}
	cout << endl;
	cout << "== 쳲�������(hb)ɾ����С�ڵ�" << endl;
	hb->removeMin();
	hb->print();

	// ��"쳲�������hb"�ϲ���"쳲�������ha"�С�
	cout << "== �ϲ�ha��hb" << endl;
	ha->combine(hb);
	ha->print();
}

// ��֤"ɾ����С�ڵ�"
void testRemoveMin()
{
	int i;
	int alen = sizeof(a) / sizeof(a[0]);
	int blen = sizeof(b) / sizeof(b[0]);
	FibHeap<int>* ha = new FibHeap<int>();
	FibHeap<int>* hb = new FibHeap<int>();

	cout << "== 쳲�������(ha)���������: ";
	for (i = 0; i < alen; i++)
	{
		cout << a[i] << " ";
		ha->insert(a[i]);
	}
	cout << endl;
	cout << "== 쳲�������(ha)ɾ����С�ڵ�" << endl;
	ha->removeMin();
	//ha->print();

	// 쳲�������hb
	cout << "== 쳲�������(hb)���������: ";
	for (i = 0; i < blen; i++)
	{
		cout << b[i] << " ";
		hb->insert(b[i]);
	}
	cout << endl;
	cout << "== 쳲�������(hb)ɾ����С�ڵ�" << endl;
	hb->removeMin();
	//hb->print();

	// ��"쳲�������hb"�ϲ���"쳲�������ha"�С�
	cout << "== �ϲ�ha��hb" << endl;
	ha->combine(hb);
	ha->print();


	cout << "== ɾ����С�ڵ�" << endl;
	ha->removeMin();
	ha->print();
}

// ��֤"��С�ڵ�"
void testDecrease()
{
	int i;
	int blen = sizeof(b) / sizeof(b[0]);
	FibHeap<int>* hb = new FibHeap<int>();

	// 쳲�������hb
	cout << "== 쳲�������(hb)���������: ";
	for (i = 0; i < blen; i++)
	{
		cout << b[i] << " ";
		hb->insert(b[i]);
	}
	cout << endl;
	cout << "== 쳲�������(hb)ɾ����С�ڵ�" << endl;
	hb->removeMin();
	hb->print();

	cout << "== ��20��СΪ2" << endl;
	hb->update(20, 2);
	hb->print();
}

// ��֤"����ڵ�"
void testIncrease()
{
	int i;
	int blen = sizeof(b) / sizeof(b[0]);
	FibHeap<int>* hb = new FibHeap<int>();

	// 쳲�������hb
	cout << "== 쳲�������(hb)���������: ";
	for (i = 0; i < blen; i++)
	{
		cout << b[i] << " ";
		hb->insert(b[i]);
	}
	cout << endl;
	cout << "== 쳲�������(hb)ɾ����С�ڵ�" << endl;
	hb->removeMin();
	hb->print();

	cout << "== ��20����Ϊ60" << endl;
	hb->update(20, 60);
	hb->print();
}

// ��֤"ɾ���ڵ�"
void testDelete()
{
	int i;
	int blen = sizeof(b) / sizeof(b[0]);
	FibHeap<int>* hb = new FibHeap<int>();

	// 쳲�������hb
	cout << "== 쳲�������(hb)���������: ";
	for (i = 0; i < blen; i++)
	{
		cout << b[i] << " ";
		hb->insert(b[i]);
	}
	cout << endl;
	cout << "== 쳲�������(hb)ɾ����С�ڵ�" << endl;
	hb->removeMin();
	hb->print();

	cout << "== ɾ���ڵ�20" << endl;
	hb->remove(20);
	hb->print();
}

int main()
{
	// ��֤"������Ϣ(쳲������ѵĽṹ)"
	testBasic();
	// ��֤"�������"
	//testInsert();
	// ��֤"�ϲ�����"
	//testUnion();
	// ��֤"ɾ����С�ڵ�"
	testRemoveMin();
	// ��֤"��С�ڵ�"
	testDecrease();
	// ��֤"����ڵ�"
	//testIncrease();
	// ��֤"ɾ���ڵ�"
	//testDelete();

	return 0;
}