#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

unordered_map<int, int> countFreq(vector<int> vec) {
  unordered_map<int, int> freqMap;

  for (int i = 0; i < vec.size(); i++) {
    freqMap[vec[i]]++;
  }

  return freqMap;
}

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
  int i = 0;
  while (getline(f, line)) {
    int num1 = stoi(line.substr(0, line.find(sep)));
    line.erase(0, line.find(sep) + sep.length());
    int num2 = stoi(line);

    vec1.push_back(num1);
    vec2.push_back(num2);
  }

  f.close();

  // Order each array
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());

  unordered_map<int, int> freq1 = countFreq(vec1);
  unordered_map<int, int> freq2 = countFreq(vec2);

  // Unique
  vec1.resize(distance(vec1.begin(), unique(vec1.begin(), vec1.end())));

  int total_dist;
  for (int i = 0; i < vec1.size(); i++)
    if (freq2.find(vec1[i]) != freq2.end())
      total_dist += vec1[i] * freq1.at(vec1[i]) * freq2.at(vec1[i]);

  cout << "Total dist: " << total_dist << endl;
  return 0;
}
