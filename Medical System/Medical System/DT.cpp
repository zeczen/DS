#include "DT.h"

DT::Node::Node() //default constructor.
{
}

DT::Node::Node(string v) : _value(v) //default constructor, initalized all variables.
{
}

DT::Node::Node(const Node &n) //copy-constructor
{
    //full copy of node:

    this->_value = n._value; //copy value

    //copy answers
    for (list<Answer *>::const_iterator i = n._answersList.begin(); i != n._answersList.end(); i++) {
        this->_answersList.push_back(new Answer(**i));
    }
}

DT::Node::~Node() //destructor
{
    //delete allocated memory of answers
    for (list<Answer *>::iterator i = this->_answersList.begin(); i != this->_answersList.end(); i++) {
        delete *i;
    }
}

string DT::Node::getValue() {
    return this->_value;
}

DT::Node *DT::Node::find(string v) {
    if (this->_value == v) //if the value is in the current node
    {
        return this; //return current node
    }

    //else search the value in other nodes
    for (list<Answer *>::iterator i = this->_answersList.begin(); i != this->_answersList.end(); i++) {
        if ((*i)->getNext()->find(v)) //if I will find him in the next node
        {
            return (*i)->getNext(); //return the next node
        }
    }

    return NULL; //if I can't find him
}

void DT::Node::addAnswer(string ans, string next) {
    this->_answersList.push_back(new Answer(ans, next)); //push a new answer to the answer's list
}

void DT::Node::print(int level) //explanation in the header's file.
{
    cout << string(level * 3, ' ') << this->_value << endl;
    for (list<Answer *>::iterator i = this->_answersList.begin(); i != this->_answersList.end(); i++) {
        (*i)->print(level);
    }
}

bool DT::Node::printPath(string v) {
    if (this->_value == v) //if I already in the expected node.
    {
        cout << v; // print her value.
        return true; // for mark that I find the expected node.
    }

    //else start printing all the nodes I pass in oreder to get the expected noed
    for (list<Answer *>::iterator i = this->_answersList.begin(); i != this->_answersList.end(); i++) {
        if ((*i)->getNext()->printPath(v)) {
            cout << "=>" << this->_value;
            return true; // for mark that I find the expected node.
        }
    }

    return false; // for mark that I didn't find the expected node.
}

void DT::Node::run() {
    cout << this->_value << endl; //print the current question

    if (!this->_answersList.empty()) //if the system have possible answers in her list
    {
        //get an answer from the user
        string ans = "";
        cin >> ans;

        //pass all the possible answers the system have in order to get a match with the user's answer
        for (list<Answer *>::iterator i = this->_answersList.begin(); i != this->_answersList.end(); i++) {
            if ((*i)->getAnswer() == ans) // I got a match!
            {
                (*i)->getNext()->run(); //conitnue from there, maybe the system want to ask some more questions before making a decision.
                return;
            }
        }
    }
}

bool DT::Node::deleteSubTree(string v) {
    //pass all the sun tree in oreder to find the node with the expectec value.
    for (list<Answer *>::iterator i = this->_answersList.begin(); i != this->_answersList.end(); i++) {
        if ((*i)->getNext()->getValue() == v) //if the expected node is the next node
        {
            //deleting current node
            delete *i;
            this->_answersList.remove(*i);
            return true; //mark that the deleting success.
        }

        if ((*i)->getNext()->deleteSubTree(
                v)) //if the expected noed isn't the next node and there is more nodes -> continte search.
        {
            return true; //mark that the deleting success.
        }
    }

    return false; //mark that the deleting failed.
}

DT::Answer::Answer() : _answer(""), _next(nullptr) //default constructor, initalized all variables.
{
}

DT::Answer::Answer(string ans, string next) : _answer(ans),
                                              _next(new Node(next)) ////default constructor, initalized all variables.
{
}

DT::Answer::Answer(const Answer &node) //copy-constructor
{
    this->_answer = node._answer;
    this->_next = new Node(*node._next);
}

DT::Answer::~Answer() //destructor
{
    delete this->_next;
}

string DT::Answer::getAnswer() {
    return this->_answer;
}

DT::Node *DT::Answer::getNext() {
    return this->_next;
}

void DT::Answer::print(int level) {
    cout << string(level * 3, ' ') << ": " << this->_answer << endl;
    this->_next->print(level + 1);
}

DT::Node *DT::find(string q) {
    return this->_root->find(q);
}

DT::DT() : _root(NULL) //default constructor, initalized all variables.
{
}

DT::DT(string n) : _root(new Node(n)) //default constructor, initalized all variables.
{
}

DT::DT(const DT &dt) : _root(new Node(*dt._root)) //copy-constructor
{
}

DT::~DT() //destructor
{
    delete this->_root;
}

bool DT::addNode(string q, string ans, string next) {
    Node *qNode = this->find(q);

    if (qNode == NULL) {
        return false;
    }

    qNode->addAnswer(ans, next);
    return true;
}

void DT::removeSubTree(string v) {
    if (this->_root->getValue() == v) {
        delete this->_root;
        this->_root = NULL;
        return;
    }

    this->_root->deleteSubTree(v);
}

void DT::print() {
    this->_root->print(0);
}

void DT::printPath(string v) {
    this->_root->printPath(v);
}

void DT::run() {
    this->_root->run();
}

string DT::printToString() //TODO: Implementing this function
{
    return string("");
}

DT &DT::operator=(const DT &dt) {
    if (this != &dt) {
        Node *newRoot = new Node(*dt._root);
        delete this->_root;
        this->_root = newRoot;
    }

    return *this;
}
