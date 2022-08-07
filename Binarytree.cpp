#include"Binarytree.h"
#include <iostream>
int main() {
	Binarytree::Node* a1=new Binarytree::Node(81);
	Binarytree::Node* a2 = new Binarytree::Node(58);
	Binarytree::Node* a3 = new Binarytree::Node(1);	
	Binarytree::Node* a4 = new Binarytree::Node(29);
	Binarytree::Node* a5 = new Binarytree::Node(165);
	Binarytree::Node* a6 = new Binarytree::Node(16);
	Binarytree::Node* a7= new Binarytree::Node(17);
	a1->m_left = a2;
	a1->m_right = a3;
	a2->m_left = a4;
	a3->m_right = a5;
	a3->m_left = a6;
	a6->m_right = a7;
	std::cout<<is_strict(a1);
}
