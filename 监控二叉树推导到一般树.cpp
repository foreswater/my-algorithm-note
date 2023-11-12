#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {                           //这是一棵有多个子节点的树
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
	vector<res> res_list; //定义一个装着所有以i节点为父节点的返回值
	for (auto j : i->children) {
		res_list.push_back(dfs(j)); //遍历i这个父节点的所有子节点
	}
	long long red = 0;//定义一个差值最小
	for (auto i : res_list) {
		Res.set_moti += min(i.set_moti, i.moti_by_fa); //蓝色 =min(蓝1,黄1)+ min(蓝2,黄2)+min(蓝3,黄3)+ cost [x]
		red = min(i.set_moti - i.moti_by_chi, red); //红色 =黄色+max(0,min (蓝1 - 红1,蓝2 - 红2,蓝3 - 红3) 现在red就是黄色后面的部分
		Res.moti_by_fa += min(i.set_moti, i.moti_by_chi);// 黄色 = min(蓝1,红1) + min(蓝2,红2) + min(蓝3,红3)
	}
	Res.set_moti += i->val; //如果在每个节点按监控的代价都是1，那么这里就填1
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