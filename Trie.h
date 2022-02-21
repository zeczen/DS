#ifndef TEST_TRIE_H
#define TEST_TRIE_H

#include<string>

class Trie {
protected:
    static const int ALPHABET = 26;

    class TrieNode {
    public:
        //constructors
        TrieNode();
        TrieNode(TrieNode*, bool, int i);

        //private variables of the inside class
        TrieNode* parent;
        TrieNode* children[ALPHABET];
        int childrenCount;
        bool endWord;

    };

    TrieNode* _trie; //pointer to the current node.
private:
    //helpful recursive functions.

    void _insert(const std::string, TrieNode*, int i = 0);

    bool _del(const std::string, TrieNode*, int i = 0);

    bool _search(const std::string, TrieNode*, bool prefix, int i = 0);

    int _printAutoSuggestions(TrieNode*, std::string);

public:
    //constructor
    Trie();

    //addtional public function

    void insert(std::string);

    bool del(const std::string);

    bool search(const std::string, bool prefix = false);

    int printAutoSuggestions(const std::string);

};


#endif //TEST_TRIE_H
