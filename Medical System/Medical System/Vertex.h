#include <iostream>
#include <string>
#include <vector>
#include "Edge.h"
#include<bits/stdc++.h>

using namespace std;

#ifndef TEST_VERTEX_H
#define TEST_VERTEX_H

enum Colors {
    NONE = 0,
    WHITE,
    GRAY,
    BLACK,
};

class Color {
public:
    Color(Colors c) { this->color = c; }

    Color() { this->color = NONE; }

    Colors getColor() { return this->color; }

    void updateColor() { this->color = static_cast<Colors>(this->color + 1); }

    void resetColor() { this->color = NONE; }

    bool operator==(Colors c) const { return this->color == c; }

private:
    Colors color;
};

class Vertex {
private:
    string key;

    Color color;

    Vertex *pi;

    vector<Edge> edgeList;

    int d = -1;

    int f = -1;

public:
    Vertex(string k, vector<Edge> el) : edgeList(el), key(k) {
        this->color = Color();
    }

    Vertex(string k) : key(k) {
        this->color = Color();
    }

//    ~Vertex() {
//        for (auto itr = this->edgeList.begin(); itr != this->edgeList.end(); itr++)
//            delete *itr;
//    }

    void addEdge(Vertex *v) { edgeList.push_back(Edge(v->key)); }

    const vector<Edge> getEdges() const { return edgeList; }

    bool const operator==(const string key) const {
        return key == this->key;
    }

    void initialized() {
        this->color.resetColor();
        this->color.updateColor();
        this->pi = NULL;
        this->d = -1;
        this->f = -1;
    }

    void discover(Vertex *p, int time) {
        this->pi = p;
        this->d = time;
        this->color.updateColor();
    }

    void finish(int time) {
        this->f = time;
        this->color.updateColor();
    }

    void print() const {
        cout << this->key << ": ";
        for (auto itr = this->edgeList.begin(); itr != this->edgeList.end(); itr++)
            cout << (*itr).dest << ' ';
        cout << endl;
    }

    void removeEdge(const Edge edge) {
        remove(this->edgeList.begin(), this->edgeList.end(), edge);
    }

    const Color getColor() const { return this->color; }

    const string getKey() const { return this->key; }

    const int getD() const { return this->d; }

    const int getF() const { return this->f; }

};

#endif //TEST_VERTEX_H
