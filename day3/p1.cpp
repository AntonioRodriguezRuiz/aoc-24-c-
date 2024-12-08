#include <bits/stdc++.h>
#include <iostream>
#include <regex>
using namespace std;

int main() {
  ifstream f("input.txt");
  if (!f.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  string line;
  getline(f, line);

  f.close();

  regex mul_regex("mul\\(\\d+,\\d+\\)");
  auto mul_begin = sregex_iterator(line.begin(), line.end(), mul_regex);
  auto mul_end = sregex_iterator();

  int count = 0;
  for (sregex_iterator i = mul_begin; i != mul_end; ++i) {
    smatch match = *i;
    string match_str = match.str();
    int acc = 1;

    // Now we get the numbers
    smatch nums;
    regex num_regex("\\d+");
    auto beg = sregex_iterator(match_str.begin(), match_str.end(), num_regex);
    auto end = sregex_iterator();
    for (sregex_iterator j = beg; j != end; ++j) {
      smatch sm = *j;
      acc *= stoi(sm.str());
    }
    count += acc;
  }

  cout << "Count: " << count << endl;
}
