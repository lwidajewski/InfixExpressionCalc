#ifndef CHARSTACK_H
#define CHARSTACK_H


class CharStack {
	private:
		struct Node;
		Node* top;
	public:
		// constructor
		CharStack();

		// observers
		bool isEmpty();
		char peek();

		// modifiers
		void push(char x);
		void pop();

		// destructor
		~CharStack();
};

#endif