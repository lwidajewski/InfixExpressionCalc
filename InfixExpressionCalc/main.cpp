#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree tree;

	string infix = "3+5";

	tree.buildTree(infix);

	cout << "Prefix: ";
	tree.printTreePre();
	cout << endl;

	cout << "Postfix: ";
	tree.printTreePost();
	cout << endl;
	
	cout << "Result: ";
	cout << tree.evaluate();
	cout << endl;


	return 0;
};