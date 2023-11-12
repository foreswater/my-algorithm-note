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
struct res {
	long long set_moti;
	long long moti_by_fa;
	long long moti_by_chi;
	res(long long set_moti = INT_MAX, long long moti_by_fa = 0, long long moti_by_chi = 0) {
		this->set_moti = set_moti;
		this->moti_by_chi = moti_by_chi;
		this->moti_by_fa = moti_by_fa;
	}
};
res dfs(node* i) {
	if (!i) {
		res N;
		N.set_moti = INT_MAX;
		N.moti_by_chi = 0;
		N.moti_by_fa = 0;
		return N;
	}
	res Res;
	vector<res> res_list; //����һ��װ��������i�ڵ�Ϊ���ڵ�ķ���ֵ
	for (auto j : i->children) {
		res_list.push_back(dfs(j)); //����i������ڵ�������ӽڵ�
	}
	long long red = 0;//����һ����ֵ��С
	for (auto i : res_list) {
		Res.set_moti += min(i.set_moti, i.moti_by_fa); //��ɫ =min(��1,��1)+ min(��2,��2)+min(��3,��3)+ cost [x]
		red = min(i.set_moti - i.moti_by_chi, red); //��ɫ =��ɫ+max(0,min (��1 - ��1,��2 - ��2,��3 - ��3) ����red���ǻ�ɫ����Ĳ���
		Res.moti_by_fa += min(i.set_moti, i.moti_by_chi);// ��ɫ = min(��1,��1) + min(��2,��2) + min(��3,��3)
	}
	Res.set_moti += i->val; //�����ÿ���ڵ㰴��صĴ��۶���1����ô�������1
	Res.moti_by_chi = Res.moti_by_fa + red;
	return Res;
}
int Find_MIN_Monitor(node* root) {
	if (!root) {
		return 0;
	}
	res R = dfs(root);
	return min(R.set_moti, R.moti_by_chi);
}
int main() {
	node tree;
	node* root = &tree;
	return 0;
}