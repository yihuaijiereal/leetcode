#ifndef _LEE_H
#define _LEE_H

#include <iostream>
using std::cin;using std::cout;using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;using std::max;

#include <unordered_map>
using std::unordered_map;
using std::sort;
#include <limits>

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <stack>

using std::stack;

struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr){ }
};

struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x):val(x),left(nullptr),right(nullptr){ }
};

#endif
