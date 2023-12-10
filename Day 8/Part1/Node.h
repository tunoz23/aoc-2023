#pragma once
#include <string>
using std::string;
struct Node
{
	
	string val;
	Node*  left;
	Node*  right;

	Node(string _val): val(_val), left(nullptr), right(nullptr) {};
	Node(string _val,Node* _left, Node* _right): val(_val), left(_left), right(_right) {};
};

