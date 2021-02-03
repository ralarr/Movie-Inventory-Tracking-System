// --------------------------------------------- binarytree.cpp -------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implements a binary tree to insert and retrieve in sorted orders. 
// --------------------------------------------------------------------------------------------------------------------

#include "binarytree.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data member size root is initialized to NULL.
// ----------------------------------------------------------------------------------------------
BinaryTree::BinaryTree() : root(NULL) {}

// --------------------------------------- destructor -------------------------------------------
// Description: Calls the deleteTree function to deallocate memory in the heap.
// ----------------------------------------------------------------------------------------------
BinaryTree::~BinaryTree(){
	if (root != NULL) deleteTree(root);
} 

// --------------------------------------- insert -----------------------------------------------
// Description: Inserts a movie object in its correct location, so it can be properly retrieved. 
// ----------------------------------------------------------------------------------------------
bool BinaryTree::insert(Inventory* newMovie, const int numStock){
	Node* nodePtr = new Node();    
	nodePtr->movie = newMovie; 
	nodePtr->movie->setMaxCopies(numStock);
	newMovie = NULL; 
	nodePtr->left = nodePtr->right = NULL;
	
	if (isEmpty()){
		root = nodePtr; 
	} else {
		Node* current = root;
		bool inserted = false;

		while (!inserted){
			if (*nodePtr->movie == *current->movie){
				delete nodePtr; 
				return false;
			} else if (*nodePtr->movie < *current->movie){
				if (current->left == NULL){
					current->left = nodePtr;
					inserted = true;
				}else current = current->left;               
			} else {
				if (current->right == NULL){
					current->right = nodePtr;
					inserted = true;
				} else current = current->right;              
			}
		}
	}
	return true;
} 

// --------------------------------------- isEmpty ----------------------------------------------
// Description: Checks if the binary tree is empty and returns true or false depending on that.
// ----------------------------------------------------------------------------------------------
bool BinaryTree::isEmpty() const {
	return (root == NULL); 
}

// ---------------------------------------- deleteTree ------------------------------------------
// Description: Function that is used by the destructor to deallocate memory on the heap.
// ----------------------------------------------------------------------------------------------
void BinaryTree::deleteTree(Node*& tree){
	if (tree != NULL){
		deleteTree(tree->left); 
		deleteTree(tree->right); 

		delete tree->movie; 
		delete tree; 
	}
} 

// ---------------------------------------- retrieve --------------------------------------------
// Description: Function to return either true or false if a movie title is found or not.
// ----------------------------------------------------------------------------------------------
bool BinaryTree::retrieve(const Inventory& dataItem, Inventory*& dataFound) const {
	retrieveHelper(root, dataItem, dataFound);

	if (dataFound != NULL) return true;
	else return false;
} 

// ----------------------------------- retrieveHelper -------------------------------------------
// Description: Recursive function to check if a movie is in the binary tree.
// ----------------------------------------------------------------------------------------------
void BinaryTree::retrieveHelper(Node* curPtr, const Inventory& dataItem, Inventory*& dataFound) const {
	if (curPtr == NULL)	dataFound = NULL;
	else if (dataItem == *curPtr->movie) dataFound = curPtr->movie;
	else if (dataItem < *curPtr->movie)	retrieveHelper(curPtr->left, dataItem, dataFound);
	else retrieveHelper(curPtr->right, dataItem, dataFound);
}

// --------------------------------- displayInOrder ----------------------------------------
// Description: Prints out the movie titles followed by its stock number.
// ----------------------------------------------------------------------------------------------
void BinaryTree::displayInOrder(Node* current) const {
	if (current == root) current->movie->displayBanner();

	if (current != NULL){
		displayInOrder(current->left);

		cout << right << setw(2) << current->movie->getAmountIn() << "	 " <<
			left << setw(3) << current->movie->getAmountOut() << "        ";
		current->movie->display();

		displayInOrder(current->right);
	}
}
