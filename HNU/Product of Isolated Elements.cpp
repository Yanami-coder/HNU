/*
* 【题目描述】
小 A 有一排数字卡片，每张卡片上写着一个整数。他想给每张卡片计算一个“孤立值”：
某张卡片的孤立值 = 把这张卡片拿走后，剩下的所有卡片上数字的乘积。
请你帮小 A 算出每张卡片的孤立值，按卡片原来的顺序输出。

【输入格式】
第一行一个整数 n，表示卡片数量。
第二行 n 个整数，表示每张卡片上的数字，即数组 nums。

【输出格式】
一行 n 个整数，第 i 个数表示第 i 张卡片的孤立值，即数组 answer。

【样例输入】
4
1 2 3 4

【样例输出】
24 12 8 6

(1)2 $\le$ nums.length $\le$ $10^5$；
(2)-30 $\le$ nums[i] $\le$ 30;
(3) 输出的ans数组的值，保证不溢出
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> nums(n);
	int zeroCnt = 0;
	int zeroIdx = 0;
	for (int i = 0;i < n;i++) {
		cin >> nums[i];
		if (nums[i] == 0) {
			zeroCnt++;
			zeroIdx = i;
		}
	}

	vector<long long> ans(n, 0);
	if (zeroCnt >= 2) {
		//至少两个 0，拿走任一后剩余数组依旧含 0，故所有孤立值为 0
	}
	else if (zeroCnt == 1) {
		long long prod = 1;
		for (int i = 0;i < n;i++) {
			if (i != zeroIdx) prod *= nums[i];
		}
		ans[zeroIdx] = prod;
		//只有拿走这个 0，孤立值不为0
	}
	else {
		//没有 0，使用前缀积和后缀积
		vector<long long> pre(n, 1);

		//pre[i] = num[0] * ... * num[i - 1]
		for (int i = 1;i < n;i++) {
			pre[i] = pre[i - 1] * nums[i - 1];
		}

		//suf = num[i + 1] * ... * num[n - 1]
		long long suf = 1;
		for (int i = n - 1;i >= 0;i--) {
			ans[i] = pre[i] * suf;
			//避免最后多乘nums[0]导致溢出
			if (i > 0) suf *= nums[i];
		}
	}

	for (int i = 0;i < n;i++) cout << ans[i] << " ";

	return 0;
}