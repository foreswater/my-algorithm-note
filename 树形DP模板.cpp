#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {                           //����һ���ж���ӽڵ����
	int val;
	vector<node*> children;
	node(int val = 0) {
		this->val = val;
		children.push_back(NULL);
	}
};
int ans = 0;
int dfs(node* i) { //����ֵ��i����ڵ㣨����i�Լ�������ڵ����
	if (i == NULL) {
		return 0;   //�߽���������������Ҷ�ӽڵ�ĵ�ʱ�򷵻�0���ڵ����
	}
	vector<int> lens; //����һ��װ��������i�ڵ�Ϊ���ڵ����������
	for (auto j : i->children) {
		lens.push_back(dfs(j) + 1); //����i������ڵ�������ӽڵ㣬֮��+1�����Լ�
	}
	int max1 = 0;
	for (auto m1 : lens) {
		max1 = max(m1, max1); //ѡ����һ��������
	}
	swap(*(find(lens.begin(), lens.end(), max1)), *(lens.end() - 1));
	lens.pop_back();
	int max2 = 0;
	for (auto m2 : lens) {
		max2 = max(m2, max1); //ѡ���ڶ���������
	}
	if (true) { //��������е������жϣ����ϲŸ��´�
	ans = max(ans, max1 + max2 - 1);//���´�Ϊ��һ���������͵ڶ����������ĺͣ�����i������ڵ��������飬������-1��
	}
	return max1;
}
void TreeModeDP(node* root) {
	if (!root) {
		return;
	}
	dfs(root);//��������������ı߳�����ans-1����Ϊ��������ǽڵ����
}
int main() {
	node tree;
	node* root = &tree;
	return 0;
}