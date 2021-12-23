
#ifndef BINARYTREE_BINARYTREE_H_H
#define BINARYTREE_BINARYTREE_H_H

#include <iostream>
#include <vector>
#include "Pair.h"

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

    std::vector<T> getLeaves() {
        std::vector<T> vec = std::vector<T>();
        return getLeaves(this->root, vec);
    }

    void insert(const T &theElement) {
        insert(theElement, root);
    }

    void remove(const T &theElement) {
        remove(theElement, root);
    }

    void setPaths() const {
        std::string path = "";
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

    void makeEmpty(BinaryNode *&t) {


        if (NULL != t) {
            makeEmpty(t->leftNode);
            makeEmpty(t->rightNode);
            delete t;
        }
        t = NULL;
    }

    std::vector<T> getLeaves(BinaryNode *bNode, std::vector<T> &vec) {
        if (bNode->leftNode == NULL && bNode->rightNode == NULL) {
            vec.push_back(bNode->element);
            return vec;
        }
        if (bNode->leftNode != NULL) {
            std::vector<T> leftLeaves = getLeaves(bNode->leftNode, vec);
        }
        if (bNode->rightNode != NULL) {
            std::vector<T> rightLeaves = getLeaves(bNode->rightNode, vec);
        }

        return vec;
    }

    void setPaths(BinaryNode *bNode, std::string path) const {
        const std::string ZERO = "0";
        const std::string ONE = "1";

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