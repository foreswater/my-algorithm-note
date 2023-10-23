#include<iostream>
using namespace std;
int bag[];
int v[];
//@catch记忆化搜索不再写出
/*
		关于记忆化搜索形参有两个变量，那么用map<pair<int ,int>,int> memo来记录
		还有就是INT_MAX+1溢出问题，把memo改为map<pair<int,int>,long long> memo来记录
		之后为了保险把INT_MAX也静态转换成long long   ——》 statc_cast<long long>(INT_MAX)
*/

int dfs0_1(int i, int capacity) {
	if (i < 0) {
		return capacity == 0 ? 1 : 0;                                               //边界条件为所有数都遍历过一遍且容量恰好等于0
	}
	if (capacity < bag[i]) {
		return dfs0_1(i - 1, capacity);                                             //当容量不足时只能不选这个背包
	}
	return max(dfs0_1(i - 1, capacity), dfs0_1(i - 1, capacity - bag[i]) + v[i]);   //选或不选，选则减去相应的容量，加上相应的价值
}                                                                                   //max、min、+对应题目中的最多、最少、恰好
int dp0_1(int n, int capacity) {
	int** f = new int* [n + 1];                        //初
	for (int i = 0; i < n + 1; i++) {                  //始
		f[i] = new int[capacity + 1];                  //化
		for (int j = 0; j < capacity + 1; j++) {       //二
			f[i][j] = 0 || INT_MAX;                    //维
		}                                              //数
	}                                                  //组
	f[0][0] = 0 || 1;                                  //确定边界情况（递归基）
	for (int i = 0; i < n + 1; i++) {
		for (int c = 0; c < capacity + 1; c++) {       //把f[i]都替换成f[i+1]防止数组越界
			if (c < bag[i]) {
				f[i + 1][c] = f[i][c];                 //对应上面递归不选的情况
			}
			else {
				f[i + 1][c] = max(f[i][c], f[i][c - bag[i]]);
			}
		}
	}
	return f[n][capacity];
}
//完全背包就是选择第i个bag之后还可以再选i，把所有选bag[i]的情况中f[i]都改成f[i+1]即可
int main() {
	return 0;
}