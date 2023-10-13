#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> ans;
vector<int> path;
int arr[] = { 1,2,3,4 };
bool is_in(vector<int>& path,int num) {
	for (vector<int>::iterator i = path.begin(); i != path.end(); i++) {
		if (*i == num) {
			return 1;
		}
	}
	return 0;
}
void dfs(int i) {
	if (i == sizeof(arr) / sizeof(int)) {                          //回溯模板
		ans.push_back(path);                                   //def dfs(已经进行到第i步):
		return;                                                    //	if 达到了要求的边界条件（比如数组的长度）:
	}                                                              //		记录答案
	for (int j = 0; j < sizeof(arr) / sizeof(int); j++) {          //		return
		if (is_in(path,arr[j])) {                            //	for 条件 in 条件列表:
			continue;                                              //		if 剪枝策略:
		}                                                          //			continue
		path.push_back(arr[j]);                               //		记录答案
		dfs(i + 1);                                                //		dfs(进行i+1步)
		path.pop_back();                                           //		回溯（还原现场）
	}
}
void A(int* arr) {
	if (!arr) {
		return;
	}
	dfs(0);
}
void dfs2(int i,int m) {                                          //本来有一个startx来规定严格的升序选择
	if (path.size() == m) {                                       //换一个角度想，dfs(i)是在i-size区间里选一个数j
		ans.push_back(path);                                  //那么下一步直接dfs(j+1)就可以保证从j+1到size区间里选一个数
		return;                                                   //这样也能保证升序，不会选重
	}
	for (int j = i; j < sizeof(arr) / sizeof(int); j++) {
		//if (is_in(path, arr[j]))continue;
		path.push_back(arr[j]);
		dfs2(j + 1, m);
		path.pop_back();
	}
}
void C(int* arr, int m) {
	if ((!arr) || (!m)) {
		return;
	}
	dfs2(0,m);
}
string s = "abc";
vector<vector<string>> ans2;
vector<string> pat;
void copy_n(string& a, string& b, int bg, int ed) {
	int j = 0;
	for (int i = bg; i < ed; i++) {
		a[j] = b[i];
		j++;
	}
}
bool is_spiral(string a) {
	if (!a.size()) {
		return 0;
	}
	int bg = 0;
	int ed = a.size() - 1;
	while (bg < ed) {
		if (a[bg] == a[ed]) {
			bg++;
			ed--;
		}
		else {
			return 0;
		}
	}
	return 1;
}
void dfs3(int i) {
	if (i == s.size()) {
		ans2.push_back(pat);
		return;
	}
	for (int j = i; j < s.size(); j++) {
		string t;
		t.resize(j + 1 - i);
		copy_n(t, s, i, j + 1);
		//if (!is_spiral(t))continue;
		pat.push_back(t);
		dfs3(j + 1);
		pat.pop_back();
	}
}
void Findspiral() {
	if (!s.size()) {
		return;
	}
	dfs3(0);
}
int main() {
	C(arr, 2);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}