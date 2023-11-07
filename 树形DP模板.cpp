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
int ans = 0;
int dfs(node* i) { //返回值是i这个节点（包括i自己）的最长节点个数
	if (i == NULL) {
		return 0;   //边界条件，当遍历到叶子节点的的时候返回0个节点个数
	}
	vector<int> lens; //定义一个装着所有以i节点为父节点的子链长度
	for (auto j : i->children) {
		lens.push_back(dfs(j) + 1); //遍历i这个父节点的所有子节点，之后+1代表自己
	}
	int max1 = 0;
	for (auto m1 : lens) {
		max1 = max(m1, max1); //选出第一长的子链
	}
	swap(*(find(lens.begin(), lens.end(), max1)), *(lens.end() - 1));
	lens.pop_back();
	int max2 = 0;
	for (auto m2 : lens) {
		max2 = max(m2, max1); //选出第二长的子链
	}
	if (true) { //加入题干中的条件判断，符合才更新答案
	ans = max(ans, max1 + max2 - 1);//更新答案为第一长的子链和第二长的子链的和（由于i这个父节点算了两遍，所以再-1）
	}
	return max1;
}
void TreeModeDP(node* root) {
	if (!root) {
		return;
	}
	dfs(root);//如果最后算的是链的边长，则ans-1，因为这题算的是节点个数
}
int main() {
	node tree;
	node* root = &tree;
	return 0;
}