#include <cstdio>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

static vector<string> letter_combinations(string digits)
{
	vector<string> res;

	for (auto i = 0; i < digits.size(); ++i) {
		char digit = digits[i];

		vector<string> to_add;

		switch (digit) {
		case '2': to_add = { "a", "b", "c" }; break;
		case '3': to_add = { "d", "e", "f" }; break;
		case '4': to_add = { "g", "h", "i" }; break;
		case '5': to_add = { "j", "k", "l" }; break;
		case '6': to_add = { "m", "n", "o" }; break;
		case '7': to_add = { "p", "q", "r", "s" }; break;
		case '8': to_add = { "t", "u", "v" }; break;
		case '9': to_add = { "w", "x", "y", "z" }; break;
		default: assert(!"invalid input");
		}

		if (res.empty()) {
			res.swap(to_add);
		} else {
			vector<string> next_res;
			for (const auto& str : res) {
				for (const auto& s : to_add) {
					next_res.push_back(str + s);
				}
			}
			res.swap(next_res);
		}
	}
	return res;
}

int main(int argc, char** argv)
{
	string digits = "";

	auto res = letter_combinations(digits);
	for (const auto& s : res) {
		printf("%s\n", s.c_str());
	}
	return 0;
}

