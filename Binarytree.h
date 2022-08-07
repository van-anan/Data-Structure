#pragma once
#include <iostream>
#include <algorithm>
namespace Binarytree {
	struct Node {
		Node(int info) :m_info(info), m_right(nullptr), m_left(nullptr) {}
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node() {}
		bool is_leaf() { return( (this->m_left == nullptr) && (this->m_right == nullptr)); }
		bool has_left() { return m_left != nullptr; }
		bool has_right() { return m_right != nullptr; }
		bool has_both() { return m_left != nullptr && m_right != nullptr; }
		int m_info;
		Node* m_left;
		Node* m_right;
	};
	int max_info(Node*);
	int height(Node*);
	int nodes(Node*);
	int leaves(Node*);
	bool is_strict(Node*);
}

int Binarytree::height(Node* root) {
	if (root == nullptr || root->is_leaf()) { return 0; }
	else
	{
		int left = height(root->m_left);
		int right = height(root->m_right);
		if (left > right) { return left + 1; }
		else { return right + 1; }
	}
}
int Binarytree::max_info(Node* root) {
	if (root == nullptr) { return 0; }
	if (root->is_leaf()) { return root->m_info; }
	int leftinfo = max_info(root->m_left);
	int rightinfo = max_info(root->m_right);
	int max1 = root->m_info;
	max1 = std::max(std::max(leftinfo, rightinfo),max1);
	return max1;
}
int Binarytree::nodes(Node* root) {
	if (root == nullptr) { return 0;}
	int leftnode = nodes(root->m_left);
	int rightnode = nodes(root->m_right);
	return leftnode + rightnode + 1;
}
int Binarytree::leaves(Node* root) {
	if (root == nullptr)return 0;
	if (root->is_leaf())return 1;
	int left = leaves(root->m_left);
	int right= leaves(root->m_right);
	return left + right;
}
bool Binarytree::is_strict(Node* root) {
	if (root->is_leaf() || root == nullptr)return true;
	if (root->m_right==nullptr||root->m_left==nullptr)return false;
	bool left = is_strict(root->m_left);
	bool right = is_strict(root->m_right);
	return left && right;
}
