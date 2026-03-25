#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;

int main() {
	char userYoN = ' ';
	string infix;

	cout << "Greetings..... Welcome to Leo's Tree Calculator" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;

	while (userYoN != 'N') {
		BinaryTree tree;

		// get infix expression from user
		cout << "Please enter an infix expression using only the following characters (0-9, +, -, *, /, (, and )): " << endl;
		cin >> infix;
		cout << endl;

		// create tree
		tree.buildTree(infix);

		// print tree
		cout << "Prefix: ";
		tree.printTreePre();
		cout << endl;

		cout << "Postfix: ";
		tree.printTreePost();
		cout << endl;

		// calc tree and print out result
		cout << "Result: ";
		cout << tree.evaluate();
		cout << endl;

		// continue looping if user wants to
		cout << "Would you like to enter another expression (y/n)?: ";
		cin >> userYoN;
		userYoN = toupper(userYoN);
	};

	cout << "Thank you for using my program!";

	return 0;
};