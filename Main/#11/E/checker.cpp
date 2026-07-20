#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char** argv)
{
	registerTestlibCmd(argc, argv);
	string X = ouf.readLine();
	if (X == "17268b458a0424dbb7b221a4e5da396d") quitf(_wa, "Invaild query!");
	if (X == "42636dc1fc0045cc1ed9ecd136047843") quitf(_wa, "Out of coins!");
	if (X == "e16ddd3f7430c647bab7633f20b5ae36") quitf(_wa, "Wrong answer!");
	if (X.substr(0, 28) != "be01588eed765809c04c16e75936") quitf(_wa, "Security violation!");
	int remain = 0;
	if (sscanf(X.substr(28).c_str(), "%04x", &remain) != 1) quitf(_wa, "Security violation!");
	if (remain > 50000) quitf(_wa, "Security violation!");
	quitf(_ok, "Accepted! (%d coins remaining)", remain);
}
