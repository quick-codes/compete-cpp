//
// Created by sudha on 4/14/21.
//

#include "ListNode.h"
#include "../utils/utils.h"

ListNode::ListNode() : ListNode(0, nullptr) {}
ListNode::ListNode(int x) : ListNode(x, nullptr) {}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}

ListNode *vector_to_linked_list(const vector<int> &nums) {
  ListNode *head = nullptr;
  for (const auto &num : vector<int>(nums.rbegin(), nums.rend())) {
	head = new ListNode(num, head);
  }
  return head;
}

ostream &operator<<(ostream &output_stream, const ListNode *head) {
  vector<string> nodes;
  while (head) {
	nodes.emplace_back(to_string(head->val));
	head = head->next;
  }
  return output_stream << "[" << join(nodes.begin(), nodes.end(), ", ") << "]";
}
