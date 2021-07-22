#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> table;
unordered_map<string, int> table1;
const int MAX_CHAR = 256;
void init(){
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		table1[ch] = i;
	}
}

vector<int> encoding(string s1, string unique)
{
	cout << "Encoding\n";
	unordered_map<string, int> table;
	for (int i = 0; i <unique.length() ; i++) {
		string ch = "";
		ch += unique[i];
		table[ch] = i;
	}

	string p = "", c = "";
	p += s1[0];
	int code = unique.length();
	vector<int> output_code;
	cout << "String\tOutput_Code\tAddition\n";
	for (int i = 0; i < s1.length(); i++) {
		if (i != s1.length() - 1)
			c += s1[i + 1];
		if (table.find(p + c) != table.end()) {
			p = p + c;
		}
		else {
			// cout<< p << "\t"<< table[p]<<"\t\t"<< p+c << "\t" << code << endl;
			cout << p << "\t" << table[p] << "\t\t"
				<< p + c << "\t" << code << endl;
			output_code.push_back(table[p]);
			table[p] = code;
			code++;
			p = c;
		}
		c = "";
	}
	cout << p << "\t" << table[p] << endl;
	output_code.push_back(table[p]);
	return output_code;
}

void decoding(vector<int> op)
{
	cout << "\nDecoding\n";
	unordered_map<int, string> table;
	// for (int i = 0; i <= 255; i++) {
	// 	string ch = "";
	// 	ch += char(i);
	// 	table[i] = ch;
	// }
	table[0] = 'T'; 
	int old = op[0], n;
	string s = table[old];
	string c = "";
	c += s[0];
	cout << s;
	int count = 0;
	for (int i = 0; i < op.size() - 1; i++) {
		n = op[i + 1];
		if (table.find(n) == table.end()) {
			s = table[old];
			s = s + c;
		}
		else {
			s = table[n];
		}
		cout << s<<"  ";
		c = "";
		c += s[0];
		table[count] = table[old] + c;
		count++;
		old = n;
	}
}


string printDistinctCharacters(string str) {
   int n = str.length();
   int count[MAX_CHAR];
   int index[MAX_CHAR];
   string ans="";
   for (int i = 0; i < MAX_CHAR; i++) {
      count[i] = 0;
      index[i] = n;
   }
   for (int i = 0; i < n; i++) {
      char x=str[i];
      ++count[x];
      if (count[x] == 1 && x !=' ')
         index[x] = i;
      if (count[x] == 2)
         index[x] = n;
   }
   sort(index, index+MAX_CHAR);
   for (int i=0; i<MAX_CHAR && index[i] != n; i++)
   	ans+=str[index[i]];
	return ans;
}



int main()
{
	string s = "This is test";
	string unique = printDistinctCharacters(s);
	vector<int> output_code = encoding(s,unique);
	cout << "Output Codes are: ";
	for (int i = 0; i < output_code.size(); i++) {
		cout << output_code[i] << " ";
	}
	cout << endl;
	decoding(output_code);
}
