/******************************************************
 * Name: Graziella Buitron
 * Coding 07
 * Purpose: To create a binary search tree object that
 * will work with our struct Data and struct Node.
 *****************************************************/

#include "bintree.h"

BinTree::BinTree(){
    root = NULL;
    count = 0;
}


//public addNode
bool BinTree::addNode(int id, const string* info){
    bool added = false;

    if (id > 0 && *info != "/0"){
        //allocates new node
        DataNode *newNode = new DataNode;
        //puts data into node
        newNode->data.id = id;
        newNode->data.information = *info;
        //initializing node's left and right pointers to null
        newNode->left = NULL;
        newNode->right = NULL;
        //passing new node to private addNode method and checking if sucessful to add 1 to count
        if(addNode(newNode, &root)){
            count++;
            added = true;
        }
    }
    return added;
}

//private addNode
bool BinTree::addNode(DataNode* newNode, DataNode** root){
    bool added = true;

    //checking to see if root is empty
    if (!(*root)){
        *root = newNode;
    }else{
        if (newNode->data.id < (*root)->data.id){
            if(!addNode(newNode, &(*root)->left)){
                added = false;
            }
        }
        if (newNode->data.id > (*root)->data.id){
            if(!addNode(newNode, &(*root)->right)){
                added = false;
            }
        }
    }
    return added;
}



//private getHeight
int BinTree::getHeight(DataNode *temproot){
    return 2;

}

//public getHeight
int BinTree::getHeight(){
    return getHeight(root);
}

//private displayTree
void BinTree::displayTree(){
    cout << "tree is _____ empty" << endl;
    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << count << endl;
    cout << endl;
    cout << "Pre-Order Traversal" << endl;
    displayPreOrder();
    cout << endl;
    cout << "In-Order Traversal" << endl;
    displayInOrder();
    cout << endl;
    cout << "Post-Order Traversal" << endl;
    displayPostOrder();
    cout << endl;

}


//private displayPostOrder
void BinTree::displayPostOrder(DataNode *temproot){
    if (temproot){
        if (temproot->left){
            displayPostOrder(temproot->left);
        }

        if (temproot->right){
            displayPostOrder(temproot->right);
        }

        cout << temproot->data.id << " " << temproot->data.information << endl;


    }


}

//public displayPostOrder
void BinTree::displayPostOrder(){
    displayPostOrder(root);
}

//private displayPreOrder
void BinTree::displayPreOrder(DataNode *temproot){
    if (temproot){
        cout << temproot->data.id << " " << temproot->data.information << endl;

        if (temproot->left){
            displayPreOrder(temproot->left);
        }
        if (temproot->right){
            displayPreOrder(temproot->right);
        }
    }
    return;
}

//public displayPreOrder
void BinTree::displayPreOrder() {
    displayPreOrder(root);
}

//private displayInOrder method
void BinTree::displayInOrder(DataNode *temproot) {
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }
    return;
}

//public displayInOrder
void BinTree::displayInOrder() {
    displayInOrder(root);
}
