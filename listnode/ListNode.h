//
// Created by sudha on 4/14/21.
//

#ifndef COMPETE_LISTNODE_LISTNODE_H_
#define COMPETE_LISTNODE_LISTNODE_H_

#include <ostream>
#include <vector>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode *next;
  ListNode();
  ListNode(int x);
  ListNode(int x, ListNode *next);
  friend ostream &operator<<(ostream &output_stream, const ListNode *head);
};

ListNode *vector_to_linked_list(const vector<int> &nums);

#endif//COMPETE_LISTNODE_LISTNODE_H_
