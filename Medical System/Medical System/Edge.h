#include <iostream>
#include <string>

using namespace std;

#ifndef TEST_EDGE_H
#define TEST_EDGE_H

class Vertex;

class Edge {
public:
    Edge(string d) : dest(d) {}

    bool operator==(const Edge &other) const {
        return this->dest == other.dest;
    }

    string dest;
};

#endif //TEST_EDGE_H
