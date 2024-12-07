#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  ifstream f("input.txt");
  if (!f.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  vector<int> vec1;
  vector<int> vec2;
  vector<int> subs;

  string line;
  const string sep = "   ";

  // Build the arrays
  while (getline(f, line)) {
    int num1 = stoi(line.substr(0, line.find(sep)));
    line.erase(0, line.find(sep) + sep.length());
    int num2 = stoi(line);

    vec1.push_back(num1);
    vec2.push_back(num2);
  }

  // Order each array
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());

  subs.resize(vec1.size());
  transform(vec1.cbegin(), vec1.cend(), vec2.cbegin(), subs.begin(),
            [](int a, int b) { return abs(a - b); });

  int total_diff = reduce(subs.cbegin(), subs.cend());

  cout << "diff: " << total_diff << endl;

  f.close();
  return 0;
}
