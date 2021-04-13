//
// Created by sudha on 4/12/21.
//

#ifndef COMPETE__TREENODE_H_
#define COMPETE__TREENODE_H_

#include "../integer/Integer.h"
#include <vector>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);
};

ostream &operator<<(ostream &output_stream, TreeNode *root);

TreeNode *vector_to_binary_tree(const vector<Integer> &nodes);

#endif//COMPETE__TREENODE_H_
