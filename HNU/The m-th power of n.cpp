#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <limits>
using namespace std;

//Parse the rational - number string "$\frac{p}{q}$" into its numerator p and denominator q
bool parse_rational(const string& s, long long& p, long long& q) {
	//Remove whitespace
	string str;
	for (char c : s)
		if (!isspace(c)) str += c;
	size_t pos = str.find('/');
	if (pos == string::npos) return false; //There is no /
	if (str.find('/', pos + 1) != string::npos) return false; //Multiple /
	string p_str = str.substr(0, pos);
	string q_str = str.substr(pos + 1);
	if (p_str.empty() || q_str.empty()) return false; //Check whether numerator or denominator is 0
	//Check and convert to integer
	try {
		size_t idx_p, idx_q;
		p = stoll(p_str, &idx_p);
		q = stoll(q_str, &idx_q);
		if (idx_p != p_str.size() || idx_q != q_str.size()) return false; //Check whether the input contains non-digit characters
	}
	catch (...) {
		return false;
	}
	if (q == 0) return false;
	return true;
}
int main() {
	double n;
	string m_str;
	long long p, q;
	while (true) {
		cout << "Please enter the base n and the rational exponent m (format:p/q) \n";
		if (!(cin >> n >> m_str)) {
			cout << "Invalid Input! \n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (!parse_rational(m_str, p, q)) {
			cout << "Invalid Input! \n" << endl;
			continue;
		}

		if (n == 0.0) {
			if (p <= 0) {
				cout << "Invalid Input! \n" << endl;
				continue;
			}
			cout << fixed << setprecision(15);
			cout << "The result is 0" << endl;
			break;
		}

		if (n < 0.0 && q % 2 == 0) {
			cout << "Invalid Input! A negative number cannot have an even root. \n" << endl;
			continue;
		}

		double ans;
		if (n > 0.0) ans = exp((double)p / (double)q * log(n));//$n^{\frac{p}{q}}=e^{\frac{p}{q} \ln n}$
		else {
			double abs_n = -n;
			ans = -exp((double)p / (double)q * log(abs_n));
			if (p % 2 != 0) ans = -ans;
		}
		cout << fixed << setprecision(15);
		cout << "The result is " << ans << endl;
		break;
	}
	return 0;
}