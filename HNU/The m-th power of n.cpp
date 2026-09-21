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
	if (p_str.empty() || q_str.empty()) return false; //Numerator or denominator is 0
	//Check and convert to integer
	try {
		size_t idx_p, idx_q;
		p = stoll(p_str, &idx_p);
		q = stoll(q_str, &idx_q);
		if (idx_p != p_str.size() || idx_q != q_str.size()) return false; //Contains non-digit characters
	}
	catch (...) {
		return false;
	}
	if (q == 0) return false;
	return true;
}
int main() {

	return 0;
}