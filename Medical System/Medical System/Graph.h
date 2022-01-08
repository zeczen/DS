#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include "Vertex.h"

using namespace std;

class Graph {
private:
    vector<Vertex *> graph;
    int timer = 0;


public:
    Graph() : timer(0) {}


    ~Graph() {
        for (auto itr = graph.begin(); itr != graph.end(); itr++)
            delete *itr;
    }

    Vertex *_find(string str) const {
        for (auto itr = graph.begin(); itr != graph.end(); itr++) {
            if (*(*itr) == str) return *itr;
        }
        return NULL;
    }

    bool const addEdge(string a, string b) {
        Vertex *va = this->_find(a);
        Vertex *vb = this->_find(b);

        if (
                (va != NULL) &&
                (vb != NULL)) {
            va->addEdge(vb);
            return true;
        }
        return false;
    }

    bool const addVertex(string a) {
        if (_find(a) == NULL) {
            Vertex *vertex = new Vertex(a);
            this->graph.push_back(vertex);
            return true;
        }
        return false;
    }

    void printAll() const {
        for (auto itr = this->graph.begin(); itr != this->graph.end(); itr++) {
            (*itr)->print();
        }
    }
    static bool compareVertex(Vertex* a, Vertex* b){return a->getF() > b->getF();}

    const string topologicalSort() {
        string res = "order: ";

        this->DFS();

        sort(this->graph.begin(), this->graph.end(), compareVertex);

        for (auto itr = this->graph.begin(); itr != this->graph.end(); itr++) {
            res +=  (*itr)->getKey() + ' ';
        }
        return res;

    }

    void DFS() {
        for (auto itr = this->graph.begin(); itr != this->graph.end(); itr++) {
            (*itr)->initialized();
        }
        this->timer = 0;
        for (auto itr = this->graph.begin(); itr != this->graph.end(); itr++) {
            if ((*itr)->getColor() == Colors::WHITE)
                this->_DFS(*itr);

        }
    }

    void _DFS(Vertex *v, Vertex *pi = NULL) {
        v->discover(pi, timer++);
        for (auto i = v->getEdges().begin(); i != v->getEdges().end(); ++i) {
            Vertex *n = (*i).getV();
            if (n->getColor() == Colors::WHITE)
                this->_DFS(n, v);
        }

        v->finish(timer++);
    }
};


#endif //TEST_GRAPH_H
