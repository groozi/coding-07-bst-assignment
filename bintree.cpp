/******************************************************
 * Name: Graziella Buitron
 * Coding 07
 * Purpose: To create a binary search tree object that
 * will work with our struct Data and struct Node.
 *****************************************************/

#include "bintree.h"

//public methods
BinTree::BinTree(){
    root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}

bool BinTree::isEmpty(){
    bool listEmpty = false;

    if(!root){
        listEmpty = true;
    }
    return listEmpty;
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
    }else{
        dataStruct->id = -1;
        dataStruct->information = "";
    }
    return dataObtained;
}

void BinTree::displayTree(){
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;

    if(isEmpty()){
        cout << "Tree is empty" << endl;
    }else{
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << getCount() << endl << endl;
    cout << "Pre-Order Traversal" << endl;
    displayPreOrder();
    cout << endl << "In-Order Traversal" << endl;
    displayInOrder();
    cout << endl<< "Post-Order Traversal" << endl;
    displayPostOrder();
    cout << "==============================================" << endl << endl;
}

//public removeNode
bool BinTree::removeNode(int id){
    bool removed = false;
    int tempcount = count;
    root = removeNode(id, root);

    if(count < tempcount){
        removed = true;
    }
    return removed;
}

//private removeNode
DataNode* BinTree::removeNode(int id, DataNode* temproot){
    if (temproot != NULL){
        if(id < temproot->data.id){
            temproot->left = removeNode(id, temproot->left);
        }else if(id > temproot->data.id){
            temproot->right = removeNode(id, temproot->right);
        }else{
            DataNode* temp;

            if(temproot->left == NULL){
                temp = temproot->right;
                temproot = temp;
                delete temproot;
                count--;
            }else if(temproot->right == NULL){
                temp = temproot->left;
                temproot = temp;
                delete temproot;
                count--;
            }
            else{
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    } 
    return temproot;
}

DataNode* BinTree::minValueNode(DataNode* node){
    DataNode* current = node;

    while (current && current->left != NULL) {
        current = current->left; 
    }
    return current; 
}

//public clear
void BinTree::clear(){
    clear(root);
    count = 0;
}

//private clear
void BinTree::clear(DataNode* temproot){
    if (temproot){
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = NULL;
        temproot->right = NULL;
        delete temproot;
        root = NULL;
    }
    return;
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
    bool found;

    if (!temproot){
        found = false;
    }else{
        if (id == temproot->data.id){
            found = true;
        }else{
            if(id < temproot->data.id){
                found = contains(id, temproot->left);
            }
            if(id > temproot->data.id){
                found = contains(id, temproot->right);
            }
        }
    }
    return found;
}

//public addNode
bool BinTree::addNode(int id, const string* info){
    bool added = false;

    if (id > 0 && *info != "/0"){
        DataNode *newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *info;
        newNode->left = NULL;
        newNode->right = NULL;
        
        if(addNode(newNode, &root)){
            count++;
            added = true;
        }
    }
    return added;
}

//private addNode
bool BinTree::addNode(DataNode* newNode, DataNode** temproot){   
    bool added = false;
    
    if (!(*temproot)){
        *temproot = newNode;
        added = true;
    }else{
        if (newNode->data.id < (*temproot)->data.id){
            if(addNode(newNode, &(*temproot)->left)){
              added = true;  
            }
        }
        else if(newNode->data.id > (*temproot)->data.id){
            if(addNode(newNode, &(*temproot)->right)){
                added = true;
            }
        }
    }
    return added;
}

//private getHeight
int BinTree::getHeight(DataNode *temproot){
    int lh = 0;
    int rh = 0;
    int finalHeight = 0;

    if (temproot){
        lh = getHeight(temproot->left);
        rh = getHeight(temproot->right);
        finalHeight = std::max(lh, rh) + 1;
    }
    return finalHeight;
}

//public getHeight
int BinTree::getHeight(){
    return getHeight(root);
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
    if (temproot){
        if(temproot->left){
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