#include "integer/Integer.h"
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}// NOLINT(google-explicit-constructor)
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vector_to_linked_list(const vector<int> &nums) {
  ListNode *head = nullptr;
  for (const auto &num : vector<int>(nums.rbegin(), nums.rend())) {
	head = new ListNode(num, head);
  }
  return head;
}

//void print_linked_list(ListNode *head) {
//  cout << "[";
//  if (head) {
//	cout << head->val;
//	head = head->next;
//  }
//  while (head) {
//	cout << ", " << head->val;
//	head = head->next;
//  }
//  cout << "]";
//}

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

//void print_tree(TreeNode *root) {
//  vector<TreeNode *> complete_tree;
//  bool is_next_available = root;
//  complete_tree.push_back(root);
//
//  unsigned long long num_of_parents = 1;
//  while (is_next_available) {
//	is_next_available = false;
//	for (unsigned long long parent = num_of_parents - 1; parent < (2 * num_of_parents - 1); ++parent) {
//	  if (complete_tree[parent]) {
//		is_next_available = is_next_available or complete_tree[parent]->left or complete_tree[parent]->right;
//		complete_tree.push_back(complete_tree[parent]->left);
//		complete_tree.push_back(complete_tree[parent]->right);
//	  } else {
//		complete_tree.push_back(nullptr);
//		complete_tree.push_back(nullptr);
//	  }
//	}
//	num_of_parents *= 2;
//  }
//
//  cout << "[";
//  cout << complete_tree[0];
//  for (int i = 1; i < complete_tree.size() - num_of_parents; ++i) {
//	cout << ", ";
//	cout << complete_tree[i];
//  }
//  cout << "]";
//}
//
//void print_vector(vector<char> nums) {
//  cout << "[";
//  if (!nums.empty()) cout << nums[0];
//  for (int i = 1; i < nums.size(); ++i) cout << ", " << nums[i];
//  cout << "]";
//}
//
//void print_vector(vector<Integer> nums) {
//  cout << "[";
//  if (!nums.empty()) cout << nums[0];
//  for (int i = 1; i < nums.size(); ++i) cout << ", " << nums[i];
//  cout << "]";
//}
//
//void print_vector(vector<string> strings) {
//  cout << "[";
//  if (!strings.empty()) cout << strings[0];
//  for (int i = 1; i < strings.size(); ++i) cout << ", " << strings[i];
//  cout << "]";
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
  const vector<vector<Integer>> inputs = {
	  {1, 2, 3, 4, 5, null, 6, 7, null, null, null, null, 8},
	  {6, 7, 8, 2, 7, 1, 3, 9, null, 1, 4, null, null, null, 5},
  };
  for (const auto &input : inputs) {
	TreeNode *root = vector_to_binary_tree(input);
	cout << "root = " << root << endl;
  }
  return 0;
}
