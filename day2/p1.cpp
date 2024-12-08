#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<string> split(string &s, const string &delimiter) {
  vector<string> tokens;
  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
    token = s.substr(0, pos);
    tokens.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  tokens.push_back(s);

  return tokens;
}

bool floors_compatible(int &a, int &b, int &order) {
  int diff = a - b;

  // We make an exception only once
  // break the loop if there is no diff or if diff is too big
  if (diff == 0 || abs(diff) >= 4) {
    return false;
  }

  switch (order) {
  // We initialize order
  case 0:
    order = diff > 0 ? 1 : -1;
    break;
  // Break if neg diff
  case 1:
    if (diff < 0) {
      return false;
    }
    break;
  // Break if pos diff
  case -1:
    if (diff >= 0) {
      return false;
    }
    break;
  }

  return true;
}

int main() {
  ifstream f("input.txt");
  if (!f.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  vector<vector<int>> reports;

  string line;
  const string sep = " ";

  // Build the arrays
  int i = 0;
  while (getline(f, line)) {
    vector<string> tokens = split(line, sep);
    reports.push_back(vector<int>());

    for (int j = 0; j < tokens.size(); j++) {
      reports[i].push_back(stoi(tokens[j]));
    }
    i++;
  }

  f.close();

  // Now we count valid reports
  int valid_reports = reports.size();
  for (int i = 0; i < reports.size(); i++) {
    int order = 0; // 0 means unknown, 1 up, -1 down.
    bool is_valid = true;
    for (int j = 0; j < reports[i].size() - 1; j++) {
      int diff = reports[i][j + 1] - reports[i][j];
      if (!floors_compatible(reports[i][j + 1], reports[i][j], order)) {
        is_valid = false;
        goto next;
      }
    }

  // Goto if needed
  next:
    if (!is_valid)
      valid_reports--;
  }

  cout << "Valid reports: " << valid_reports << endl;

  return 0;
}
