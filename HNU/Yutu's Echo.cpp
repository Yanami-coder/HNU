/*
玉兔独自在月宫走廊敲木鱼，却总觉得有另一只玉兔在跟着它敲。

其实，走廊有一个固定的正整数回声延迟 d：如果玉兔在第 i 秒敲了一下，就会在第 i+d 秒听到这一下的回声。每次敲击只产生一次回声，回声不会再产生回声。

玉兔每秒最多敲一下。当一次新敲击与一次回声出现在同一秒时，这一秒会记录到两声。

录音从第一次声音开始，到最后一次声音结束，共有 n 秒；它包含了这次敲击活动中的所有敲击和所有回声。第 i 秒记录的声音次数为 a_i。

现在录音还在，玉兔却忘记了自己什么时候敲过木鱼。

请问有多少个整数 d，满足 1 ≤ d < n，能解释这段完整录音？

输入格式

第一行一个整数 n。

第二行 n 个整数 $a_1, a_2, ..., a_n.$

输出格式

输出可能的延迟 d 的数量。不同的延迟分别计数。
*/

#include <iostream>
#include <vector>
using namespace std;

int n;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1;i <= n;i++) cin >> n;

	if (a[1] != 1 || a[n] != 1) {
		cout << "Impossible!\n";
		return 0;
	}

	for (int d = 1;d < n;d++) {
		vector<int> x(n + 1, 0);
		bool ok = true;

		for (int i = 1;i <= n;i++) {
			int prev = (i > d ? x[i - d] : 0);
			int cur = a[i] - prev;
			/*
			- 根据题意：第 i 秒记录到的声音次数 a[i] 等于：
			- 第 i 秒的敲击 x[i]（0 或 1）
			- 加上第 i-d 秒敲击产生的回声（如果 i > d，则回声在 i 秒；否则没有回声）。
			- 因此 a[i] = x[i] + (i > d ? x[i-d] : 0)。
			- 移项得 x[i] = a[i] - (i > d ? x[i-d] : 0)。
			- 代码中 prev 就是 i > d 时的 x[i-d]，否则为 0。
			- cur 就是计算出的 x[i]。
			*/

			if (cur < 0 || cur>1) {
				ok = false;
				break;
			}
			x[i] = cur;

			if (i > n - d && x[i] != 0) {
				ok = false;
				break;
			}
			/*
			• 如果第 i 秒敲击，那么它会在第 i+d 秒产生回声。
			• 录音只包含从第 1 秒到第 n 秒的声音，所以回声必须在录音范围内，即 i + d <= n ，也就是 i <= n - d 。
			• 如果 i > n - d 时还有敲击（x[i] = 1），那么回声会落在第 n 秒之后，不在录音中，矛盾。
			• 因此检查 i > n - d 且 x[i] != 0 时，当前 d 不合法。
			*/
		}
		
		if (ok) ans++;
	}

	cout << ans << "\n";

	return 0;
}