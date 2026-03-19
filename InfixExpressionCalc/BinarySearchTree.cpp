#include <iostream>
#include <string>

#include "BinarySearchTree.h"

using namespace std;

struct BinarySearchTree::Node {
	int data;
	Node* left;
	Node* right;
};


// constructor
BinarySearchTree::BinarySearchTree() {
	root = nullptr;
};


// observers
bool BinarySearchTree::isEmpty() {
	if (root == nullptr) {
		return true;
	}
	else {
		return false;
	};
};

void BinarySearchTree::printTreePost() {

};

void BinarySearchTree::printTreePre() {

};

int BinarySearchTree::calcTreeIn() {

};


// modifiers
void BinarySearchTree::insert(string x) {

};

void BinarySearchTree::deleteNode(string x) {

};


// destructor
BinarySearchTree::~BinarySearchTree() {

};
