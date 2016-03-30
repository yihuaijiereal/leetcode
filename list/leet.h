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

struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr){ }
};

#endif
