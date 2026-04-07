#include <bits/stdc++.h>
using namespace std;

struct Var {
	string type;
	unsigned int int_val;
	string str_val;
	unsigned char char_val;
};

map<string, Var> vars;

void process_instruction(const string& line) {
	stringstream ss(line);
	string cmd;
	ss >> cmd;
	if (cmd == "string" || cmd == "int" || cmd == "char") {
		string var_name, val;
		ss >> var_name;
		if (cmd == "string") {
			ss >> val;
			Var v;
			v.type = "string";
			v.str_val = val;
			vars[var_name] = v;
		} else if (cmd == "int") {
			unsigned int x;
			ss >> x;
			Var v;
			v.type = "int";
			v.int_val = x;
			vars[var_name] = v;
		} else if (cmd == "char") {
			char c;
			ss >> c;
			Var v;
			v.type = "char";
			v.char_val = (unsigned char)c;
			vars[var_name] = v;
		}
	} else if (cmd == "set") {
		string var_name, op, val;
		ss >> var_name >> op;
		if (op == "value") {
			Var& v = vars[var_name];
			if (v.type == "string") {
				ss >> val;
				v.str_val = val;
			} else if (v.type == "int") {
				unsigned int x;
				ss >> x;
				v.int_val = x;
			} else if (v.type == "char") {
				char c;
				ss >> c;
				v.char_val = (unsigned char)c;
			}
		} else if (op == "variable") {
			string other_var;
			ss >> other_var;
			Var& v = vars[var_name];
			Var& other = vars[other_var];
			if (v.type == "string") {
				v.str_val = other.str_val;
			} else if (v.type == "int") {
				v.int_val = other.int_val;
			} else if (v.type == "char") {
				v.char_val = other.char_val;
			}
		}
	} else if (cmd == "output") {
		string op, val;
		ss >> op;
		if (op == "value") {
			string rest;
			getline(ss, rest);
			size_t start = rest.find_first_not_of(' ');
			if (start != string::npos) {
				rest = rest.substr(start);
			}
			cout << rest << endl;
		} else if (op == "variable") {
			string var_name;
			ss >> var_name;
			Var& v = vars[var_name];
			if (v.type == "string") {
				cout << v.str_val << endl;
			} else if (v.type == "int") {
				cout << (int)v.int_val << endl;
			} else if (v.type == "char") {
				cout << "[ASCII " << (int) ((int8_t) v.char_val) << "]" << endl;
			}
		}
	} else if (cmd == "add") {
		string var_name, op;
		ss >> var_name >> op;
		Var& v = vars[var_name];
		if (op == "value") {
			if (v.type == "string") {
				string val;
				ss >> val;
				v.str_val += val;
			} else if (v.type == "int") {
				unsigned int x;
				ss >> x;
				v.int_val += x;
			} else if (v.type == "char") {
				int x;
				ss >> x;
				v.char_val = (unsigned char)((unsigned int)v.char_val + x);
			}
		} else if (op == "variable") {
			string other_var;
			ss >> other_var;
			Var& other = vars[other_var];
			if (v.type == "string") {
				v.str_val += other.str_val;
			} else if (v.type == "int") {
				v.int_val += other.int_val;
			}
		}
	} else if (cmd == "minus") {
		string var_name, op;
		ss >> var_name >> op;
		Var& v = vars[var_name];
		if (op == "value") {
			if (v.type == "int") {
				unsigned int x;
				ss >> x;
				v.int_val -= x;
			} else if (v.type == "char") {
				int x;
				ss >> x;
				v.char_val = (unsigned char)((unsigned int)v.char_val - x);
			}
		} else if (op == "variable") {
			string other_var;
			ss >> other_var;
			Var& other = vars[other_var];
			if (v.type == "int") {
				v.int_val -= other.int_val;
			}
		}
	} else if (cmd == "for") {
		int times;
		ss >> times;
		string rest;
		getline(ss, rest);
		size_t start = rest.find_first_not_of(' ');
		if (start != string::npos) {
			rest = rest.substr(start);
		}
		for (int i = 0; i < times; ++i) {
			process_instruction(rest);
		}
	}
}

int main() {
	freopen("interpretation.in", "r", stdin);
	freopen("interpretation.out", "w", stdout);
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		string line;
		getline(cin, line);
		process_instruction(line);
	}
	return 0;
}
