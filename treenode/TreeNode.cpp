//
// Created by sudha on 4/12/21.
//

#include "TreeNode.h"
#include "../utils/utils.h"
#include <ostream>
#include <queue>
#include <vector>
using namespace std;

TreeNode::TreeNode() : TreeNode(0, nullptr, nullptr) {}

TreeNode::TreeNode(int x) : TreeNode(x, nullptr, nullptr) {}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

ostream &operator<<(ostream &output_stream, TreeNode *root) {
  vector<TreeNode *> all_nodes;
  vector<string> nodes;
  queue<TreeNode *> fifo;
  if (root) {
	fifo.push(root);
  }
  while (!fifo.empty()) {
	auto current = fifo.front();
	all_nodes.emplace_back(current);
	fifo.pop();

	if (current) {
	  fifo.push(current->left);
	  fifo.push(current->right);
	}
  };

  for (int i = all_nodes.size() - 1; i >= 0; i--) {
	if (!all_nodes[i]) {
	  all_nodes.pop_back();
	} else {
	  break;
	}
  }
  for (auto node : all_nodes) {
	if (node) {
	  nodes.emplace_back(to_string(node->val));
	} else {
	  nodes.emplace_back("null");
	}
  }
  return output_stream << "[" << join(nodes.begin(), nodes.end(), ", ") << "]";
}

TreeNode *vector_to_binary_tree(const vector<Integer> &nodes) {
  if (nodes.empty()) return nullptr;

  // create nodes
  vector<TreeNode *> complete_tree;
  complete_tree.reserve(nodes.size());
  for (Integer node : nodes) {
	complete_tree.push_back(node == null ? nullptr : new TreeNode(node.val));
  }

  // fix children
  for (int i = 0, left, right = 0; i < nodes.size(); ++i) {
	if (!complete_tree[i]) continue;

	left = right + 1;
	right = left + 1;
	if (left < nodes.size()) complete_tree[i]->left = complete_tree[left];
	if (right < nodes.size()) complete_tree[i]->right = complete_tree[right];
  }

  // return root
  return complete_tree.front();
}
