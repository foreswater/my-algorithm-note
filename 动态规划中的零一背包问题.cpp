#include<iostream>
using namespace std;
int bag[];
int v[];
//@catch���仯��������д��
/*
		���ڼ��仯�����β���������������ô��map<pair<int ,int>,int> memo����¼
		���о���INT_MAX+1������⣬��memo��Ϊmap<pair<int,int>,long long> memo����¼
		֮��Ϊ�˱��հ�INT_MAXҲ��̬ת����long long   ������ statc_cast<long long>(INT_MAX)
*/

int dfs0_1(int i, int capacity) {
	if (i < 0) {
		return capacity == 0 ? 1 : 0;                                               //�߽�����Ϊ��������������һ��������ǡ�õ���0
	}
	if (capacity < bag[i]) {
		return dfs0_1(i - 1, capacity);                                             //����������ʱֻ�ܲ�ѡ�������
	}
	return max(dfs0_1(i - 1, capacity), dfs0_1(i - 1, capacity - bag[i]) + v[i]);   //ѡ��ѡ��ѡ���ȥ��Ӧ��������������Ӧ�ļ�ֵ
}                                                                                   //max��min��+��Ӧ��Ŀ�е���ࡢ���١�ǡ��
int dp0_1(int n, int capacity) {
	int** f = new int* [n + 1];                        //��
	for (int i = 0; i < n + 1; i++) {                  //ʼ
		f[i] = new int[capacity + 1];                  //��
		for (int j = 0; j < capacity + 1; j++) {       //��
			f[i][j] = 0 || INT_MAX;                    //ά
		}                                              //��
	}                                                  //��
	f[0][0] = 0 || 1;                                  //ȷ���߽�������ݹ����
	for (int i = 0; i < n + 1; i++) {
		for (int c = 0; c < capacity + 1; c++) {       //��f[i]���滻��f[i+1]��ֹ����Խ��
			if (c < bag[i]) {
				f[i + 1][c] = f[i][c];                 //��Ӧ����ݹ鲻ѡ�����
			}
			else {
				f[i + 1][c] = max(f[i][c], f[i][c - bag[i]]);
			}
		}
	}
	return f[n][capacity];
}
//��ȫ��������ѡ���i��bag֮�󻹿�����ѡi��������ѡbag[i]�������f[i]���ĳ�f[i+1]����
int main() {
	return 0;
}