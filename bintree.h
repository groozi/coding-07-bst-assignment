/******************************************************
 * Name: Graziella Buitron
 * Coding 07
 * Purpose: To create a binary search tree object that
 * will work with our struct Data and struct Node.
 *****************************************************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>
#include <string>
#include "data.h"

using std::cout;
using std::endl;
using std::string;

class BinTree{

public:
    BinTree(int[], string[]);
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree(); //working

    //public method prototypes with private overloads
    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight(); //stubbed with random height but working
    void displayPreOrder(); //working with hard coded constructor
    void displayPostOrder(); //working with hard coded constructor
    void displayInOrder(); //working with hard coded constructor

private: 
    //attributes
    DataNode *root;
    int count;

    //private methods with public overloads
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*); //stubbed with random height but working
    void displayPreOrder(DataNode*); //working with hard coded constructor
    void displayPostOrder(DataNode*); //working with hard coded constructor
    void displayInOrder(DataNode*); //working with hard coded constructor

};


#endif /* BINTREE_BINTREE_H */

