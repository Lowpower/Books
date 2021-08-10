#include <iostream>
#include <cstring>
#include <string_view>

using namespace std;

int editdistance(std::string_view str1, std::string_view str2) {
	return 0;
}

int main() {
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	cout << str1 << "::" << str2 << "::" << editdistance(str1, str2);
	return 0;
}
