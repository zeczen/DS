#include <iostream>
#include "BinaryTree.h"

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree &bt) {
    if (nullptr != bt.root) {
        this->root = clone(bt.root);
    } else {
        root = nullptr;
    }

};

template<typename T>
bool BinaryTree<T>::operator<(BinaryTree<T> tree) {
    return this->root->element < tree.root->element;
}

template<typename T>
bool BinaryTree<T>::operator>(BinaryTree<T> tree) {
    return this->root->element > tree.root->element;
}

template<typename T>
bool BinaryTree<T>::operator<=(BinaryTree<T> tree) {
    return this->root->element <= tree.root->element;
}

template<typename T>
bool BinaryTree<T>::operator>=(BinaryTree<T> tree) {
    return this->root->element >= tree.root->element;
}

template<typename T>
BinaryTree<T>::BinaryTree(const T &theElement, const BinaryTree &l, const BinaryTree &r) {
    root = new BinaryNode(theElement, l.root, r.root);
}

template<typename T>
BinaryTree<T>::BinaryTree(const T &theElement) {
    root = new BinaryNode(theElement);
    /*root->element = theElement;
    root->leftNode = nullptr;
    root->rightNode = nullptr;*/
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    makeEmpty();
    /* root->~BinaryNode();*/
};

template<typename T>
T BinaryTree<T>::getRoot() {
    return this->root;
}

template<typename T>
std::vector<T> BinaryTree<T>::getLeaves() {
    std::vector<T> vec = std::vector<T>();
    return getLeaves(this->root, vec);
}

template<typename T>
std::vector<T> BinaryTree<T>::getLeaves(BinaryNode *bNode, std::vector<T> vec) {
    if (bNode->leftNode == NULL && bNode->rightNode == NULL) {
        vec.push_back(bNode->element);
        return vec;
    }
    if (bNode->leftNode != NULL) {
        std::vector<T> leftLeaves = getLeaves(bNode->leftNode);
        vec.insert(vec.end(), leftLeaves.begin(), leftLeaves.end());
    }
    if (bNode->rightNode != NULL) {
        std::vector<T> rightLeaves = getLeaves(bNode->rightNode);
        vec.insert(vec.end(), rightLeaves.begin(), rightLeaves.end());
    }
    return vec;
}

template<typename T>
void BinaryTree<T>::insert(const T &theElement) {
    insert(theElement, root);
};

template<typename T>
void BinaryTree<T>::remove(const T &theElement) {
    remove(theElement, root);
};

template<typename T>
void BinaryTree<T>::makeEmpty() {
    makeEmpty(root);
};

template<typename T>
bool BinaryTree<T>::isFind(const T &theElement) const {
    isFind(theElement, root);
};

template<typename T>
void BinaryTree<T>::setPaths() const {
    std::string path = "";
    setPaths(root, path);
};

template<typename T>
void BinaryTree<T>::preOrder() const {
    preOrder(root);
};

template<typename T>
void BinaryTree<T>::inOrder() const {
    inOrder(root);
};


template<typename T>
void BinaryTree<T>::postOrder() const {
    postOrder(root);
};


template<typename T>
typename BinaryTree<T>::BinaryNode *BinaryTree<T>::clone(const BinaryNode *r) {
    if (nullptr == r) {
        return nullptr;
    } else {
        return new BinaryNode(r->element, clone(r->leftNode), clone(r->rightNode));
    }


}

template<typename T>
void BinaryTree<T>::insert(const T &theElement, BinaryNode *&t) {
    if (nullptr == t) {
        t = new BinaryNode(theElement);
    } else if (theElement < t->element) {
        insert(theElement, t->leftNode);
    } else if (theElement > t->element) {
        insert(theElement, t->rightNode);
    } else {//重复的数据不添加到树中
    }
};

template<typename T>
void BinaryTree<T>::remove(const T &theElement, BinaryNode *&t) {
    if (nullptr == t) {
        return;
    } else {
        if (theElement < t->element) {
            remove(t->leftNode);
        } else if (theElement > t->element) {
            remove(t->rightNode);
        } else if (nullptr != t->leftNode && nullptr != t->rightNode) {  //需要删除的节点两个儿子

            t->element = findMin(t->rightNode)->element;
            remove(t->element, t->rightNode);
        } else {
            BinaryNode *oldNode = t;
            t = (nullptr != t->leftNode) ? t->leftNode : t->rightNode;
            delete oldNode;
        }
    }
};

template<typename T>
void BinaryTree<T>::makeEmpty(BinaryNode *&t) {
    if (nullptr != t) {
        makeEmpty(t->leftNode);
        makeEmpty(t->rightNode);
        std::cout << "delete: " << t->element << std::endl;
        delete t;
    }
    t = nullptr;
};

template<typename T>
bool BinaryTree<T>::isFind(const T &theElement, BinaryNode *t) const {
    if (nullptr == t) {
        return false;
    } else if (theElement < t->element) {
        return isFind(theElement, t->leftNode);
    } else if (theElement > t->element) {
        return isFind(theElement, t->rightNode);
    } else { //匹配
        return true;
    }
};


template<typename T>
typename BinaryTree<T>::BinaryNode *BinaryTree<T>::findMin(BinaryNode *bNode) const {
    if (nullptr != bNode) {
        while (nullptr != bNode->leftNode) {
            bNode = bNode->leftNode;
        }
    }

    return bNode;
}

template<typename T>
typename BinaryTree<T>::BinaryNode *BinaryTree<T>::findMax(BinaryNode *bNode) const {
    if (nullptr != bNode) {
        while (nullptr != bNode->rightNode) {
            bNode = bNode->rightNode;
        }
    }
    return bNode;
}


template<typename T>
void BinaryTree<T>::setPaths(BinaryNode *bNode, std::string path) const {
    if (bNode->leftNode != NULL) {
        setPaths(bNode->leftNode, path.append(reinterpret_cast<const char *>('0')));
    }
    if (bNode->rightNode != NULL) {
        setPaths(bNode->rightNode, path.append(reinterpret_cast<const char *>('1')));
    }
    if (bNode->leftNode == NULL && bNode->rightNode == NULL) {
        bNode->element.path = path;
    }

};

template<typename T>
void BinaryTree<T>::preOrder(BinaryNode *bNode) const {
    if (nullptr != bNode) {
        std::cout << bNode->element << " ";
        preOrder(bNode->leftNode);
        preOrder(bNode->rightNode);
    }

};

template<typename T>
void BinaryTree<T>::inOrder(BinaryNode *bNode) const {
    if (nullptr != bNode) {
        inOrder(bNode->leftNode);
        std::cout << bNode->element << " ";
        inOrder(bNode->rightNode);
    }
};

template<typename T>
void BinaryTree<T>::postOrder(BinaryNode *bNode) const {
    postOrder(bNode->leftNode);
    postOrder(bNode->rightNode);
    std::cout << bNode->element << " ";
};