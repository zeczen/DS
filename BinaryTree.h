
#ifndef BINARYTREE_BINARYTREE_H_H
#define BINARYTREE_BINARYTREE_H_H

#include <iostream>
#include <vector>
#include "Pair.h"

using namespace std;

template<typename T>
class BinaryTree {
public:

    BinaryTree() {
        this->root = NULL;
    }

    BinaryTree(const BinaryTree &bt) {
        if (NULL != bt.root) {
            *this = bt;
        } else {
            this->root = NULL;
        }
    }

    BinaryTree(string structure, vector<T> elements, T node) {
        int i = 0;
        buildTree(structure, elements, node, this->root, i);
    }

    BinaryTree(const T &theElement) {
        root = new BinaryNode(theElement);
    }

    BinaryTree(const T &theElement, const BinaryTree *l, const BinaryTree *r) {

        root = new BinaryNode(theElement, l->root, r->root);
    }

    ~BinaryTree() {
        makeEmpty();
        /* root->~BinaryNode();*/
    }


    T getRoot() {
        return this->root->element;
    }

    void makeEmpty() {
        makeEmpty(root);
    }

    vector<T> getLeaves() {
        vector<T> vec = vector<T>();
        return getLeaves(this->root, vec);
    }

    void insert(const T &theElement) {
        insert(theElement, root);
    }

    void remove(const T &theElement) {
        remove(theElement, root);
    }

    string getStructure() {
        return getStructure(this->root);
    }

    void setPaths() const {
        string path = "";
        setPaths(root, path);
    }

    friend bool operator<(const BinaryTree<T> tree1, const BinaryTree<T> tree2) {
        return tree1.root->element < tree2.root->element;
    }

    friend bool operator>(const BinaryTree<T> tree1, const BinaryTree<T> tree2) {
        return tree1.root->element > tree2.root->element;
    }


private:

    struct BinaryNode {
        T element;
        BinaryNode *leftNode = NULL;
        BinaryNode *rightNode = NULL;

        BinaryNode(const T &ele, BinaryNode *left, BinaryNode *right)
                : element(ele), leftNode(left), rightNode(right) {};

        BinaryNode(const T &ele)
                : element(ele), leftNode(NULL), rightNode(NULL) {};

        BinaryNode(const BinaryNode *bNode)
                : element(bNode->element), leftNode(bNode->leftNode), rightNode(bNode->rightNode) {
        }

    };

    BinaryNode *root = NULL;


    void insert(const T &theElement, BinaryNode *&t) {
        if (NULL == t) {
            t = new BinaryNode(theElement);
        } else if (theElement < t->element) {
            insert(theElement, t->leftNode);
        } else if (theElement > t->element) {
            insert(theElement, t->rightNode);
        } else {
        }
    }

    void remove(const T &theElement, BinaryNode *&t) {
        if (NULL == t) {
            return;
        } else {
            if (theElement < t->element) {
                remove(t->leftNode);
            } else if (theElement > t->element) {
                remove(t->rightNode);
            } else if (NULL != t->leftNode && NULL != t->rightNode) {

                t->element = findMin(t->rightNode)->element;
                remove(t->element, t->rightNode);
            } else {
                BinaryNode *oldNode = t;
                t = (NULL != t->leftNode) ? t->leftNode : t->rightNode;
                delete oldNode;
                oldNode = NULL;
            }
        }
    }

    void buildTree(string structure, vector<T> &elements, T node, BinaryNode *&t, int &i) {
        if (structure.length() == i)
            return;
        else if (structure.at(i) == '1') {
            t = new BinaryNode(elements[0]);
            elements.erase(elements.begin());
        } else if (structure.at(i) == '0') {
            t = new BinaryNode(node);
            buildTree(structure, elements, node, t->leftNode, ++i);
            buildTree(structure, elements, node, t->rightNode, ++i);
        } else {
            throw "ERROR";
        }
    }

    void makeEmpty(BinaryNode *&t) {
        if (NULL != t) {
            makeEmpty(t->leftNode);
            makeEmpty(t->rightNode);
            delete t;
        }
        t = NULL;
    }

    vector<T> getLeaves(BinaryNode *bNode, vector<T> &vec) {
        if (bNode->leftNode == NULL && bNode->rightNode == NULL) {
            vec.push_back(bNode->element);
            return vec;
        }
        if (bNode->leftNode != NULL) {
            vector<T> leftLeaves = getLeaves(bNode->leftNode, vec);
        }
        if (bNode->rightNode != NULL) {
            vector<T> rightLeaves = getLeaves(bNode->rightNode, vec);
        }

        return vec;
    }

    string getStructure(BinaryNode *bNode, string path = "") const {
        if (bNode->leftNode == NULL && bNode->rightNode == NULL)
            return path + "1";
        if (bNode->leftNode != NULL) {
            path = getStructure(bNode->leftNode, path + "0");
        }
        if (bNode->rightNode != NULL) {
            path = getStructure(bNode->rightNode, path);
        }
        return path;
    }

    void setPaths(BinaryNode *bNode, string path) const {
        const string ZERO = "0";
        const string ONE = "1";

        if (bNode->leftNode == NULL && bNode->rightNode == NULL) {
            bNode->element.path = path;
        }
        if (bNode->rightNode != NULL) {
            setPaths(bNode->rightNode, path + ONE);
        }
        if (bNode->leftNode != NULL) {
            setPaths(bNode->leftNode, path + ZERO);
        }


    }

};


#endif //BINARYTREE_BINARYTREE_H_H