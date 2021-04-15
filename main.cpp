#include "integer/Integer.h"
#include "listnode/ListNode.h"
#include "treenode/TreeNode.h"
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <utility>
#include <vector>
using namespace std;

class RandomNode {
 public:
  int val;
  RandomNode *next;
  RandomNode *random;

  RandomNode(int _val) {
	val = _val;
	next = nullptr;
	random = nullptr;
  }
};

RandomNode *vector_to_random_linked_list(vector<pair<int, int>> nodes) {
  RandomNode *head = new RandomNode(0);
  map<int, RandomNode *> cache;

  RandomNode *current = head;
  for (int i = 0; i < nodes.size(); ++i) {
	current->next = new RandomNode(nodes[i].first);
	cache[i] = current->next;
	current = current->next;
  }
  current = head->next;
  for (const auto &node : nodes) {
	current->random = node.second >= 0 ? cache[node.second] : nullptr;
	current = current->next;
  }

  return head->next;
}

//void print_random_linked_list(RandomNode *head) {
//  map<RandomNode *, int> cache;
//  RandomNode *current = head;
//  int i = 0;
//  while (current) {
//	cache[current] = i;
//	current = current->next;
//	i += 1;
//  }
//
//  current = head;
//  cout << "[";
//  if (current) {
//	cout << "[" << current->val << ", " << (current->random ? cache[current->random] : -1) << "]";
//	current = current->next;
//  }
//  while (current) {
//	cout << ", [" << current->val << ", " << (current->random ? cache[current->random] : -1) << "]";
//	current = current->next;
//  }
//  cout << "]";
//}

class MultilevelNode {
 public:
  Integer val;
  MultilevelNode *prev;
  MultilevelNode *next;
  MultilevelNode *child;
  MultilevelNode() : MultilevelNode(0, nullptr, nullptr, nullptr) {}
  MultilevelNode(int val) : MultilevelNode(val, nullptr, nullptr, nullptr) {}
  MultilevelNode(int val, MultilevelNode *prev, MultilevelNode *next, MultilevelNode *child) : val(val), prev(prev), next(next), child(child) {}
};

//ostream &operator<<(ostream &output_stream, const MultilevelNode *node) {
//  if (!node) return output_stream << "null";
//  return output_stream << node->val;
//}

//MultilevelNode *vector_to_multilevel_list(const vector<Integer> &nodes, const Integer &null) {
//  if (nodes.empty()) return nullptr;
//
//  // create nodes
//  vector<MultilevelNode *> all_nodes;
//  all_nodes.reserve(nodes.size());
//  for (Integer node : nodes) {
//	all_nodes.push_back(node == null ? nullptr : new MultilevelNode(node.val));
//  }
//
//  // fix children
//  for (int i = 0; i < nodes.size(); ++i) {
//	if (!all_nodes[i]) continue;
//
//	auto left = 2 * i + 1;
//	auto right = left + 1;
//	if (left < nodes.size()) all_nodes[i]->left = all_nodes[left];
//	if (right < nodes.size()) all_nodes[i]->right = all_nodes[right];
//  }
//
//  // return root
//  return all_nodes.front();
//}

template<class T>
ostream &operator<<(ostream &output_stream, const vector<T> &nums) {
  output_stream << "[";
  if (!nums.empty()) {
	output_stream << nums[0];
	for (int i = 1; i < nums.size(); ++i) {
	  output_stream << ", " << nums[i];
	}
  }
  output_stream << "]";
  return output_stream;
}

int main() {
  const vector<vector<int>> inputs = {
	  {1, 4, 3, 2, 5, 2},
	  {1, 2},
  };
  for (const auto &input : inputs) {
	auto head = vector_to_linked_list(input);
	cout << "list = " << head << endl;
  }
  return 0;
}
