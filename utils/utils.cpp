//
// Created by sudha on 4/12/21.
//
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/**
 * Joins strings to a single string.
 * Sample usage:
 * {@code vector<string> expressions = {"hello", "world"};}
 * {@code string possibility = join(expressions.begin(), expressions.end(), ", "); // possibility = "hello, world"}
 *
 * @param begin
 * @param end
 * @param delimiter
 * @return
 */
string join(vector<string>::iterator begin, vector<string>::iterator end, const string &delimiter = "") {
  ostringstream os;
  copy(begin, end, ostream_iterator<string>(os, delimiter.c_str()));
  string result = os.str();
  result = result.substr(0, result.size() - delimiter.size());
  return result;
}

vector<string> split(const string &s, char delimiter) {
  vector<string> tokens;
  istringstream is(s);
  string token;
  while (getline(is, token, delimiter)) {
	tokens.emplace_back(token);
  }
  return tokens;
}
