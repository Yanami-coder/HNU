/*Anon 最近学会了一个判断整数能否被 3 整除的简单规则：如果一个整数的各位数字之和能被 3 整除，那么这个整数就能被 3 整除。

后来她又知道，同样的规则也可以用来判断一个整数能否被 9 整除：如果一个整数的各位数字之和能被 9 整除，那么这个整数就能被 9 整除。

Soyorin 想逗一逗 Anon，于是故意说：其实这个规则对任意正整数 d 都成立。为了向 Anon 展示这个说法，Soyorin 需要找到一个正整数 n，使得 n 能被 d 整除，并且 n 的各位数字之和也能被 d 整除。

现在给定 d，请你帮 Soyorin 找出满足条件的最小 n。

输入格式
一行一个整数 d（1 ≤ d ≤ 1000）。

输出格式
输出一个正整数 n。要求 n 能被 d 整除，并且 n 的各位数字之和也能被 d 整除。n 不能有前导零，位数不超过 10^6。题目保证一定存在这样的 n。

时间限制：2 秒
内存限制：1024 兆字节*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int d;
	cin >> d;
	if (d <= 9) {
		cout << d << endl;
		return 0;
	}
	int total = d * d;
	/* 状态总数。状态由两个模 d 的余数组成：
       • r：当前数对 d 取模的结果；
       • s：当前数字和对 d 取模的结果。
       每个余数有 d 种取值，所以总状态数为 d * d。*/
	vector<char> visited(total, 0);
	vector<int> prev(total, -1);//prev[state] 记录状态 state 的前驱状态，用于最后回溯出完整数字。初始化为 -1，表示没有前驱。
	vector<int> prev_digit(total, -1); //prev_digit[state] 记录从哪个数字转移到状态 state，也就是当前状态下最后一位数字是什么，用于回溯时还原每一位数字。
	vector<int> q(total);//手写队列
	int head = 0, tail = 0;

	for (int digit = 1;digit <= 9;digit++) {//枚举最高位数字
		int r = digit % d;
		int s = digit % d;
		int state = r * d + s;
		if (!visited[state]) {
			visited[state] = 1;
			prev[state] = 1;
			prev_digit[state] = digit;
			q[tail++] = state;
		}
	}
	
	//BFS
	while (head < tail) {
		int state = q[head++];
		int r = state / d;
		int s = state % d;
		if (r == 0 && s == 0) {
			string ans;
			int cur = state;
			while (cur != 1) {
				ans += char('0' + prev_digit[cur]);
				cur = prev[cur];
			}
			reverse(ans.begin(), ans.end());
			cout << ans << "\n";
			return 0;
		}
		for (int digit = 0;digit <= 9;digit++) {
			int nr = (r * 10 + digit) % d;
			int ns = (s + digit) % d;
			int nstate = nr * d + ns;
			if (!visited[nstate]) {
				visited[nstate] = 1;
				prev[nstate] = state;
				prev_digit[nstate] = digit;
				q[tail++] = nstate;
			}
		}
	}
	return 0;
}