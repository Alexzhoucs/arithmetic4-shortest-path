#include "head.h"


void Link(Chainhead G[], int i, int j) 
{		//��G�м���ߣ�i��j��
	Chain* newnode = (Chain*)malloc(sizeof(Chain));
	newnode->next = NULL;
	newnode->node = j;
	if (G[i].last == NULL) {
		G[i].next = newnode;
		G[i].last = newnode;
	}
	else {
		G[i].last->next = newnode;
		G[i].last = newnode;
	}
}

int InputGraph(int W[Vertexnum + 1][Vertexnum + 1]) {
	string s;
	stringstream ss;
	ifstream finput;					//��ȡ����
	finput.open(INPUTF, ios::binary);
	getline(finput, s);
	ss.clear();
	ss.str(s);
	finput.close();

	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			int temp;
			ss >> temp;
			if (ss.fail())
				return(0);

			if (temp >= Maxint) {
				W[i][j] = Maxint;
				continue;
			}
			if (i != j) {
				W[i][j] = temp;
			}
			else {
				W[i][j] = 0;
				if (temp != 0)
					cout << "��" << i << "�е�" << j << "����������Ѹ���Ϊ0.\n";
			}
		}
	}
	for (int i = 1; i <= Vertexnum; i++)
		W[i][0] = Maxint;
	for (int j = 1; j <= Vertexnum; j++)
		W[0][j] = 0;
	return(1);
}

void InitGraph(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[]) {		//�������ݲ������ڽӾ�����ڽ�����
	for (int i = 0; i <= Vertexnum; i++) {
		G[i].next = NULL;
		G[i].last = NULL;
		G[i].Pi = Maxint;
		G[i].d = 0;
	}
	G[0].d = Maxint;
	for (int i = 0; i <= Vertexnum; i++)
		for (int j = 0; j <= Vertexnum; j++)
			if ((i != j) && (W[i][j] != Maxint))
				Link(G, i, j);
}

void showweightmatrix(int W[Vertexnum + 1][Vertexnum + 1]) {		//��ӡ���·�������ǰ������
	cout << "���·������Ϊ��" << endl;
	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			if (W[i][j] >Vertexnum*weightdif)
				cout << "NoPath\t";
			else
				cout << W[i][j] << "\t";
		}
		cout << endl;
	}

}
void showpathmatrix(int P[Vertexnum + 1][Vertexnum + 1]) {
	cout << endl << "ǰ������Ϊ��" << endl;
	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			if (P[i][j] == Maxint)
				cout << "NIL" << "\t";
			else
				if (P[i][j] == -1)
					cout << "NoPath\t";
				else
					cout << P[i][j] << "\t";
			
		}
		cout << endl;
	}
	cout << endl;
}

void RandomArray(int M[Vertexnum+1][Vertexnum+1]) {	//������Vertexnum�����㡢Edgenum���ߵ�ͼ��д�뵽randomgraph.txt
	srand((unsigned)time(NULL));

	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			if (i == j)
				M[i][j] = 0;
			else
				M[i][j] = Maxint;
		}
	}
	for (int j = 0; j <= Vertexnum; j++)
		M[j][0] = Maxint;
	for (int j = 1; j <= Vertexnum; j++)
		M[0][j] = 0;

	int i = 0;
	while(i < Edgenum) {
		int position1 = rand() % Vertexnum;
		int position2 = rand() % Vertexnum;
		if ((position1 != position2) && (M[position1+1][position2+1] == Maxint)) {
			M[position1+1][position2+1] = rand() % weightdif + Lweight;
			i++;
		}
	}
}