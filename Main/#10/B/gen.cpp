#include <bits/stdc++.h>
using namespace std;
map<string, char>used;
vector<string>used_v, int_v, char_v, string_v;
map<string, char>char_m;
bool in_for = false;

bool ASCII(int c) {
	return (c >= 32 && c <= 126);
}

int to_int(string str) {
	stringstream ss;
	ss << str;
	int ret;
	ss >> ret;
	return ret;
}

string gen_variable_name() {
	int len = rand() % 50 + 1, temp;
	string ret;
	if (rand() % 2 == 0) {
		ret += ('a' + rand() % 26);
	} else {
		ret += ('A' + rand() % 26);
	}
	for (int i = 1; i < len; ++i) {
		temp = rand() % 3;
		if (temp == 0) {
			ret += ('0' + rand() % 10);
		} else if (temp == 1) {
			ret += ('a' + rand() % 26);
		} else {
			ret += ('A' + rand() % 26);
		}
	}
	if (!used[ret]) {
		return ret;
	} else {
		return gen_variable_name();
	}
}

string gen_type_name() {
	string temp[3] = {"string", "int", "char"};
	return temp[rand() % 3];
}

int _int() {
	string ret_str;
	if (rand() % 2 == 0) {
		for (int i = 1; i <= 9; ++i) {
			ret_str += ('0' + rand() % 10);
		}
	} else {
		ret_str += '1';
		for (int i = 1; i <= 9; ++i) {
			ret_str += ('0' + rand() % 10);
		}
	}
	return to_int(ret_str);
}

string _string() {
	string ret;
	int len = rand() % 3 + 5;
	int temp = rand() % 3;
	if (temp == 0) {
		ret += ('0' + rand() % 10);
	} else if (temp == 1) {
		ret += ('a' + rand() % 26);
	} else if (temp == 2) {
		ret += ('A' + rand() % 26);
	}
	for (int i = 1; i < len; ++i) {
		int temp = rand() % 3;
		if (temp == 0) {
			ret += ('0' + rand() % 10);
		} else if (temp == 1) {
			ret += ('a' + rand() % 26);
		} else {
			ret += ('A' + rand() % 26);
		}
	}
	return ret;
}

char _char() {
	char ret_list[63];
	for (int i = 1; i <= 26; ++i) {
		ret_list[i] = 'A' + i - 1;
	}
	for (int i = 1; i <= 26; ++i) {
		ret_list[i + 26] = 'a' + i - 1;
	}
	for (int i = 1; i <= 10; ++i) {
		ret_list[i + 52] = '0' + i - 1;
	}
	return ret_list[rand() % 62 + 1];
}

void __int() {
	string v_name = gen_variable_name();
	cout << "int " << v_name << " " << _int() << endl;
	used[v_name] = true;
	int_v.push_back(v_name);
	used_v.push_back(v_name);
}

void __char() {
	char temp = _char();
	string v_name = gen_variable_name();
	cout << "char " << v_name << " " << temp << endl;
	used[v_name] = true;
	char_m[v_name] = temp;
	char_v.push_back(v_name);
	used_v.push_back(v_name);
}

void __string() {
	string v_name = gen_variable_name();
	cout << "string " << v_name << " " << _string() << endl;
	used[v_name] = true;
	string_v.push_back(v_name);
	used_v.push_back(v_name);
}

void setint() {
	string v_name = int_v[rand() % int_v.size()];
	cout << "set " << v_name << " value " << _int() << endl;
}

void setchar() {
	char temp = _char();
	string v_name = char_v[rand() % char_v.size()];
	cout << "set " << v_name << " value " << temp << endl;
	char_m[v_name] = temp;
}

void setstring() {
	string v_name = string_v[rand() % string_v.size()];
	cout << "set " << v_name << " value " << _string() << endl;
}

void output() {
	if (rand() % 2 == 0) {
		cout << "output value " << _string() + _string() + _string() << endl;
	} else {
		cout << "output variable " << used_v[rand() % used_v.size()] << endl;
	}
}

void add() {
	if (int_v.empty() && string_v.empty() && char_v.empty()) {
		return;
	}
	int temp = rand() % 3;
	if (in_for && temp == 1) temp = 2;
	if (temp == 0 && !int_v.empty()) {
		if (rand() % 2 == 0) {
			cout << "add " << int_v[rand() % int_v.size()] << " value " << _int() << endl;
		} else {
			cout << "add " << int_v[rand() % int_v.size()] << " variable " << int_v[rand() % int_v.size()] << endl;
		}
	} else if (temp == 1 && !string_v.empty()) {
		if (rand() % 2 == 0) {
			cout << "add " << string_v[rand() % string_v.size()] << " value " << _string() << endl;
		} else if (!string_v.empty()) {
			cout << "add " << string_v[rand() % string_v.size()] << " variable " << string_v[rand() % string_v.size()] << endl;
		}
	} else if (temp == 2 && !char_v.empty()) {
		string v_name = char_v[rand() % char_v.size()];
		int temp2 = rand() % 255 - 127;
		while (!ASCII(char_m[v_name] + temp2)) {
			temp2 = rand() % 255 - 127;
		}
		cout << "add " << v_name << " value " << temp2 << endl;
	} else {
		if (!int_v.empty()) {
			if (rand() % 2 == 0) {
				cout << "add " << int_v[rand() % int_v.size()] << " value " << _int() << endl;
			} else {
				cout << "add " << int_v[rand() % int_v.size()] << " variable " << int_v[rand() % int_v.size()] << endl;
			}
		} else if (!string_v.empty()) {
			if (rand() % 2 == 0) {
				cout << "add " << string_v[rand() % string_v.size()] << " value " << _string() << endl;
			} else {
				cout << "add " << string_v[rand() % string_v.size()] << " variable " << string_v[rand() % string_v.size()] << endl;
			}
		} else if (!char_v.empty()) {
			string v_name = char_v[rand() % char_v.size()];
			int temp2 = rand() % 255 - 127;
			while (!ASCII(char_m[v_name] + temp2)) {
				temp2 = rand() % 255 - 127;
			}
			cout << "add " << v_name << " value " << temp2 << endl;
		}
	}
}

void _minus() {
	if (int_v.empty() && char_v.empty()) {
		return;
	}
	int temp = rand() % 2;
	if (temp == 0 && !int_v.empty()) {
		if (rand() % 2 == 0) {
			cout << "minus " << int_v[rand() % int_v.size()] << " value " << _int() << endl;
		} else {
			cout << "minus " << int_v[rand() % int_v.size()] << " variable " << int_v[rand() % int_v.size()] << endl;
		}
	} else if (!char_v.empty()) {
		string v_name = char_v[rand() % char_v.size()];
		int temp2 = rand() % 255 - 127;
		while (!ASCII(char_m[v_name] - temp2)) {
			temp2 = rand() % 255 - 127;
		}
		cout << "minus " << v_name << " value " << temp2 << endl;
	} else if (!int_v.empty()) {
		if (rand() % 2 == 0) {
			cout << "minus " << int_v[rand() % int_v.size()] << " value " << _int() << endl;
		} else {
			cout << "minus " << int_v[rand() % int_v.size()] << " variable " << int_v[rand() % int_v.size()] << endl;
		}
	}
}

void _for() {
	int temp2 = 1 + rand() % 100;
	cout << "for " << temp2 << " ";
	int temp = rand() % 5;
	if (temp == 0) {
		setstring();
	} else if (temp == 1) {
		output();
	} else if (temp == 2) {
		add();
	} else if (temp == 3) {
		setint();
	} else if (temp == 4) {
		setchar();
	} else if (temp == 5) {
		_minus();
	}
}

void gen() {
	int temp = rand() % 10;
	if (temp == 0) {
		__int();
	} else if (temp == 1) {
		__char();
	} else if (temp == 2) {
		__string();
	} else if (temp == 3) {
		setint();
	} else if (temp == 4) {
		setchar();
	} else if (temp == 5) {
		setstring();
	} else if (temp == 6) {
		add();
	} else if (temp == 7) {
		_minus();
	} else if (temp == 8) {
		output();
	} else if (temp == 9) {
		in_for = true;
		_for();
		in_for = false;
	}
}

int main() {
	srand(time(NULL));
	for (int i = 4; i <= 25; i++) {
		used.clear();
		used_v.clear();
		int_v.clear();
		char_v.clear();
		string_v.clear();
		char_m.clear();
		freopen((to_string(i) + ".in").c_str(), "w", stdout);
		int t = rand() % 100 + 900;
		cout << t << endl;
		__int();
		__char();
		__string();
		__int();
		__char();
		__string();
		__int();
		__char();
		__string();
		for (int i = 1; i <= t - 9; i++) {
			gen();
		}
		fclose(stdout);
	}
	return 0;
}
