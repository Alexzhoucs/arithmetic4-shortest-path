#include "head.h"

void FW(int D[Vertexnum+1][Vertexnum+1] , int P[Vertexnum+1][Vertexnum+1]) {	//������ʼ���ڽӾ���D�����·���ĳ���Ϊ�ھ���D�У�ǰ������ΪP
	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			if (i == j)
				P[i][j] = Maxint;
			else{
				if (D[i][j] == Maxint)
					P[i][j] = -1;

				else
					P[i][j] = i;
			}
		}
	}
	for (int k = 1; k <= Vertexnum; k++) {
		for (int i = 1; i <= Vertexnum; i++) {
			for (int j = 1; j <= Vertexnum; j++) {
				if ((D[i][k] == Maxint) || (D[k][j] == Maxint))
					continue;
				int temp = D[i][k] + D[k][j];
				if (D[i][j] > temp) {
					D[i][j] = temp;
					P[i][j] = P[k][j];
				}
			}
		}
	}
}



void FWpath(int P[Vertexnum + 1][Vertexnum + 1], int i, int j) {
	if (j == -1) {
		cout << "û��·" << endl;
		return;
	}
	if (i == j)
		cout << j;
	else
	{
		FWpath(P, i, P[i][j]);
		cout << "->";
		cout << j;
	}
}


void FWshowall(int P[Vertexnum + 1][Vertexnum + 1], int W[Vertexnum + 1][Vertexnum + 1]) {		//����ǰ����������·�����Ⱦ����������i��j�����·��Ϊ��i->a->b->��->j������Ϊx��
	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			cout << "��" << i << "��" << j << "�����·��Ϊ��\t";
			FWpath(P, i, j);
			cout << endl << "����Ϊ" << W[i][j] << endl;
		}
	}
}
