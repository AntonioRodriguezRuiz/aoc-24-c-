#include <bits/stdc++.h>
#include <iostream>
#include <regex>
using namespace std;

int calc_acc(smatch match, int &count) {
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
  return acc;
}

int main() {
  ifstream f("input.txt");
  if (!f.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  string line;
  getline(f, line);

  f.close();

  regex dodonts_regex("(?:do\\(\\)|^)(.*?)(?:don't\\(\\)|$)");
  regex mul_regex("mul\\(\\d+,\\d+\\)");
  regex num_regex("\\d+");

  auto dodonts_begin = sregex_iterator(line.begin(), line.end(), dodonts_regex);
  auto dodonts_end = sregex_iterator();

  int count = 0;
  for (sregex_iterator i = dodonts_begin; i != dodonts_end; ++i) {
    smatch enabled_set = *i;
    string enabled_set_str = enabled_set.str();

    auto mul_begin = sregex_iterator(enabled_set_str.begin(),
                                     enabled_set_str.end(), mul_regex);
    auto mul_end = sregex_iterator();

    for (sregex_iterator i = mul_begin; i != mul_end; ++i) {
      count += calc_acc(*i, count);
    }
  }

  cout << "Count: " << count << endl;
}
