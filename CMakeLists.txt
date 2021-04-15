cmake_minimum_required(VERSION 3.17)
project(compete)

set(CMAKE_CXX_STANDARD 14)

add_executable(compete main.cpp treenode/TreeNode.cpp treenode/TreeNode.h integer/Integer.cpp integer/Integer.h utils/utils.h utils/utils.cpp listnode/ListNode.cpp listnode/ListNode.h)
