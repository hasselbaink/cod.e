#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

ifstream in;
ofstream out;

vector<string> split(string s) {
	istringstream iss(s);
	vector<string> tokens;
	copy(istream_iterator<string>(iss),
		 istream_iterator<string>(),
		 back_inserter(tokens));
	return tokens;
}

void print(vector<string> tokens, bool nl = false) {
	out << "cout << ";
	for (int i = 1; i < tokens.size(); i++)
		out << tokens.at(i);
	if (nl)
		out << " << endl";
	out << ";\n";
}

int main()
{
	string line;
	in.open("cod.e");
	out.open("src.cpp");
	if (in.is_open()) {
		out << "#include <iostream>\n\
#include <fstream>\n\
#include <string>\n\
using namespace std;\n\
int main(int argc, char *argv[]){" << endl;
		while (getline(in, line)) {
			vector<string> tokens = split(line);
			if (tokens.at(0) == "print")
				print(tokens);
			else if (tokens.at(0) == "println")
				print(tokens, true);
		}
		out << "return 0;\n}";
		in.close();
		out.close();
		system("g++ src.cpp -o prog.r");
	} else {
		cout << "Unable to open file" << endl;
	}
	return 0;
}
