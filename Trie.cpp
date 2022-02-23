#include "Trie.h"
#include<string>
#include<iostream>

/*
* Description: Function for convert char to int.
* Input: char variable.
* Output: int value of the variable, example: '97' -> 97.
*/
int getNum(const char chr) {
    if (!(97 <= (int) chr && (int) chr <= 122))
        throw ("ERROR: char not in range");

    return ((int) chr) - 97;
    // getNum(a): 0
    // getNum(b): 1
    // getNum(c): 2
    // ...
    // getNum(z): 25
}

/*
* Description: Function for convert int to char.
* Input: int variable.
* Outpu: char value of the variable, example: 97 -> '97'.
*/
char getChar(const int a) {
    if (!(0 <= a && a <= 26))
        throw ("ERROR: int not in range");

    return (char) a + 97;
    // getChar(0): a
    // getChar(1): b
    // getChar(2): c
    // ...
    // getChar(25): z
}


// const string Trie::ALPHABET = 26;

Trie::TrieNode::TrieNode() {
    this->childrenCount = 0;
    this->endWord = false;
    this->parent = NULL; // this is the root node
}

Trie::TrieNode::TrieNode(TrieNode *parent, bool isEndWord, int i) {
    this->childrenCount = 0;
    this->endWord = isEndWord;
    this->parent = parent;

    if (parent->children[i] == NULL) {
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

/*
* Description: recursive function for insert string to the trie structure.
* Input: string, pointer to node in the trie (the begining value will be pointer to head), number of iteration in the function (begin with 0).
* Output: None.
*/
void Trie::_insert(const std::string str, TrieNode *trie, int i) {
    if (str.length() == i)  //if this is the last char.
    {
        trie->endWord = true; //mark as last char of the word.
        return; //break.
    }

    int index = getNum(str.at(i)); //convert the next char to int, for get index in node.

    if (trie->children[index] == NULL) //if this letter has not been used yet.
    {
        //create new TrieNode.
        TrieNode *node = new TrieNode(trie, false, index);
        _insert(str, node, i + 1); //conitnue the insertion process.

        return; //break.
    } else {
        //if the letter is already exist.
        _insert(str, trie->children[index], i + 1); //conitnue the insertion process.

        return; //break.
    }
}

/*
* Description: recursive function for delete string from the trie structure.
* Input: string, pointer to node in the trie, number of iteration (begin with 0).
* Output: True - operation success, False - else.
*/
bool Trie::_del(const std::string str, TrieNode *trie, int i) {
    if (str.length() == i) //if this is the last char.
    {
        trie->endWord = false;
        return true;
    }

    int index = getNum(str.at(i)); //convert the next char to int, for get index in node.
    bool finish = _del(str, trie->children[index], i + 1); //continue the process.

    if (finish) //if _del operation success
    {
        return true;
    }

    if (trie->endWord == false && trie->children[index]->childrenCount == 1) // if we have a leaf
    {
        //delete the child's node.
        delete trie->children[index];
        trie->childrenCount--;
        trie->children[index] = NULL;
    }

    return true;

}

/*
* Description: recursive function for search string in the trie.
* Input: string, pointer to trie node, prefix - if true - the function will check if the substring is exist (even if the last letter isn't end of word)
*                                               if false - the fuction will check if the whole string exist, it mean if the last char of the string is marked
*                                                          as end of word (endWord = true).
*        i - number of iteration (begin with 0).
*
* Output: True - if string / substring (depend on prefix flag) is found, False - else.
*/
bool Trie::_search(const std::string str, TrieNode *trie, bool prefix, int i) {
    // O(n)
    if (i == str.length()) // if this is the last char in the string.
    {
        if (prefix ||
            trie->endWord) // endWord - mean that is the last char in the word, and we also that is the last char in the string.
            // Therefore, we know that the string is exist in the trie. And we return True.
            // Another case is if prefix = True, and then, if we success to reach the last char in the perfix.
            // It mean the prefix exist in the trie. And we return true.
        {
            return true;
        } else //in every other case
        {
            return false; // we understand that the string / substring is not exist in the trie, and we return False.
        }
    }

    // else if this isn't the last char in the string

    int index = getNum(str.at(i)); // convert the next char in string to int, for get node's index.

    if (trie->children[index] == NULL) // if the letter isn't exist in the trie.
    {
        return false; // it mean that the string / substring is not exist in the trie, and we return False.
    } else // if the letter is exist in the trie.
    {
        return _search(str, trie->children[index], prefix, i + 1); //continue process with next letter.
    }
}

/*
* Description: recursive function for print all the strings that exist in the trie and start with some prefix.
* Input: pointer to trie's node, prefix to start with.
* Output: number of suggestions that found.
*/
int Trie::_printAutoSuggestions(TrieNode *trie, std::string str) {
    int num = 0; // how many children does this node have
    if (trie->endWord == true) {
        num++;
        std::cout << str << std::endl;
    }

    for (int i = 0; i < ALPHABET; i++) {
        if (trie->children[i] != NULL) {
            char letter = getChar(i);
            num += _printAutoSuggestions(trie->children[i], str + letter);
            if (trie->children[i]->endWord == true) {
                num++;
            }
        }
    }

    return num;
}

void Trie::insert(std::string str) {
    if (search(str)) {
        return;
    }

    _insert(str, _trie);

}

bool Trie::del(const std::string str) {
    if (!search(str)) {
        return false;
    }

    return _del(str, _trie);
}

bool Trie::search(const std::string str, bool prefix) {
    return _search(str, _trie, prefix);
}

int Trie::printAutoSuggestions(const std::string str) {
    if (!search(str, true)) {
        return 0;
    }

    TrieNode *node = this->_trie;

    for (int i = 0; i < str.length(); i++) {
        node = node->children[getNum(str.at(i))];
    }

    return _printAutoSuggestions(node, str);
}
