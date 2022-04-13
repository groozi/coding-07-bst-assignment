/******************************************************
 * Name: Graziella Buitron
 * Coding 07
 * Purpose: To create a binary search tree object that
 * will work with our struct Data and struct Node.
 *****************************************************/

#include "bintree.h"

BinTree::BinTree(int ids[], string strings[]){
    root = new DataNode;
    root->left = NULL;
    root->right = NULL;
    root->data.id = ids[0];
    root->data.information = strings[0];

    root->left = new DataNode;
    root->left->left = NULL;
    root->left->right = NULL;
    root->left->data.id = ids[1];
    root->left->data.information = strings[1];

    root->right = new DataNode;
    root->right->left = NULL;
    root->right->right = NULL;
    root->right->data.id = ids[2];
    root->right->data.information = strings[2];

    root->left->right = new DataNode;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->left->right->data.id = ids[3];
    root->left->right->data.information = strings[3];
    
    root->left->left = new DataNode;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->left->data.id = ids[4];
    root->left->left->data.information = strings[4];
    
    root->left->right->right = new DataNode;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    root->left->right->right->data.id = ids[5];
    root->left->right->right->data.information = strings[5];
    
    root->left->right->left = new DataNode;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->left->data.id = ids[6];
    root->left->right->left->data.information = strings[6];

    return;
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




