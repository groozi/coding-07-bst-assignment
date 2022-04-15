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

BinTree::~BinTree(){
    clear();
}

bool BinTree::isEmpty(){
    bool flag = false;
    if(!root){
        flag = true;
    }
    return flag;
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data* dataStruct){
    bool dataObtained = false;

    if(root){
        dataStruct->id = root->data.id;
        dataStruct->information = root->data.information;
        dataObtained = true;
    } else{
        dataStruct->id = -1;
        dataStruct->information = "";

    }
    return dataObtained;
}

//public clear method
void BinTree::clear(){
    clear(root);
}

//private clear method
void BinTree::clear(DataNode* temproot){
    if (!temproot){
        return;
    }else{
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = NULL;
        temproot->right = NULL;
        delete (temproot);
        root = NULL;
        count--;
    }
}


//public getNode method
bool BinTree::getNode(Data* dataStruct, int id){
    bool gotNode = false;

    if (id > 0){
        gotNode = getNode(dataStruct, id, root);
    }
    return gotNode;
}

//private getNode method
bool BinTree::getNode(Data* dataStruct, int id, DataNode* root){
    bool flag;

    if (!root){
        flag = false;
    }else{
        if (id == root->data.id){
            dataStruct->id = root->data.id;
            dataStruct->information = root->data.information;
            flag = true;
        }else{
            if (id < root->data.id){
                flag = getNode(dataStruct, id, root->left);
            }
            if (id > root->data.id){
                flag = getNode(dataStruct, id, root->right);
            }
        }
    }
    return flag;

}

//public contains method
bool BinTree::contains(int id){
    bool flag = false; 

    if (id > 0){
        flag = contains(id, root);       
    }
    return flag;

}

//private contains method
bool BinTree::contains(int id, DataNode* temproot){
    bool flag;

    if (!temproot){
        flag = false;
    }else{
        if (id == temproot->data.id){
            flag = true;
        }else{
            if (id < temproot->data.id){
                flag = contains(id, temproot->left);
            }
            if (id > temproot->data.id){
                flag = contains(id, temproot->right);
            }
        }
    }
    return flag;
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
bool BinTree::addNode(DataNode* newNode, DataNode** temproot){
    bool added = true;

    //checking to see if root is empty
    if (!(*temproot)){
        *temproot = newNode;
    }else{
        if (newNode->data.id < (*temproot)->data.id){
            if(!addNode(newNode, &(*temproot)->left)){
                added = false;
            }
        }
        if (newNode->data.id > (*temproot)->data.id){
            if(!addNode(newNode, &(*temproot)->right)){
                added = false;
            }
        }
    }
    return added;
}

//private getHeight
int BinTree::getHeight(DataNode *temproot){
    int lh = 0;
    int rh = 0;

    if(!temproot){  
        return 0;
    }else{
        lh = getHeight(temproot->left);
        rh = getHeight(temproot->right);
    }
    return std::max(lh, rh) + 1;
}

//public getHeight
int BinTree::getHeight(){
    return getHeight(root);
}

//private displayTree
void BinTree::displayTree(){
    if(isEmpty()){
        cout << "Tree is empty" << endl;
    }else{
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << getCount() << endl;
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
