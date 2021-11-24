#include "Trie.h"
#include<string>
#include<iostream>


int getNum(const char chr) {
    return int(chr) - 97;
    // getNum(a): 0
    // getNum(b): 1
    // getNum(c): 2
    // ...
    // getNum(z): 25
}

int getChar(const int a) {
    return char(a + 97);
    // getChar(0): a
    // getChar(1): b
    // getChar(2): c
    // ...
    // getChar(25): z
}


// const string Trie::ALPHABET = 26;

Trie::TrieNode::TrieNode() {
    this->endWord = endWord;
    this->parent = nullptr; // this is the root node
}

Trie::TrieNode::TrieNode(TrieNode *parent, bool endWord, int i) {
    this->endWord = endWord;
    this->parent = parent;

    if (parent->children[i] == nullptr) {
        parent->childrenCount++;
        parent->children[i] = this;

    } else {
        // if the letter already exist

        parent->children[i] = this;

        char letter = getChar(i);
        std::string str = "Overwriting letter: ";
        str += letter;
        std::cout << str << std::endl;
        throw (str);
    }
}

Trie::Trie() {
    this->_trie = new Trie::TrieNode();
}


void Trie::_insert(const std::string str, TrieNode *trie, int i) {
    if (str.length() == i) {
        // if finish
        trie->endWord = true;
        return;
    }
    int index = getNum(str.at(i));
    if (trie->children[i] == nullptr) {
        // if we need to create new TrieNode
        TrieNode *node = new TrieNode(trie, false, index);
        _insert(str, node, i + 1);

        return;
    } else {
        // if the letter exist already
        _insert(str, trie->children[index], i + 1);

        return;
    }
}

bool Trie::_del(const std::string str, TrieNode *trie, int i) {
    if (str.length() == i) {
        // if finish
        trie->endWord = false;
        return true;
    }
    int index = getNum(str.at(i));
    _del(str, trie->children[index], i + 1);

    if (trie->endWord == false && trie->children[index]->childrenCount == 1) {
        // if the only child of that node is the one we delete
        delete trie->children[index];
        trie->childrenCount--;
        trie->children[index] = nullptr;
    }
    return true;

}

bool Trie::_search(const std::string str, TrieNode *trie, int i) {
    // O(n)
    if (i == str.length()) {
        if (_trie->endWord)
            return true;
        else
            return false;
    }
    // else

    int index = getNum(str.at(i));
    if (trie->children[index] == nullptr)
        return false;
    else
        return _search(str, trie->children[index], i + 1);
}

int Trie::_printAutoSuggestions(TrieNode *trie, std::string str) {
    int num = 0; // how many children does this node have

    std::cout << str << std::endl;
    for (int i = 0; i < ALPHABET; i++)
        if (trie->children[i] != nullptr) {
            num++;
            char letter = getChar(i);
            num += _printAutoSuggestions(trie->children[i], str + letter);
        }
    return num;
}

void Trie::insert(std::string str) {
    if (search(str))
        return;

    _insert(str, _trie);

}

bool Trie::del(const std::string str) {
    if (!search(str))
        return false;

    return _del(str, _trie);
}

bool Trie::search(const std::string str) {
    return _search(str, _trie);
}

int Trie::printAutoSuggestions(const std::string str) {
    if (!search(str))
        return 0;
    TrieNode *node = this->_trie;
    for (int i = 0; i < str.length(); i++)
        node = node->children[getNum(str.at(i))];
    return _printAutoSuggestions(node, str);
}
