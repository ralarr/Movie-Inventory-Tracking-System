#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "movie.h"

class BinaryTree {
	friend ostream& operator<<(ostream&, BinaryTree&);
	struct Node;

  private:
        struct Node {
                Inventory* movie; 
                Node* left, *right;  
        };
        Node *root; 
        void deleteTree(Node*&);

  public:
	BinaryTree();		
	~BinaryTree();			

	bool insert(Inventory*, const int);
	bool isEmpty() const; 
	bool retrieve(const Inventory&, Inventory*&) const;
	void retrieveHelper(Node*, const Inventory&, Inventory*&) const;
	void displayInOrder(Node*) const;
	Node* getRoot() const { return root; };
};

#endif
