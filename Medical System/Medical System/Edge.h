#include <iostream>
#include <string>

using namespace std;

#ifndef TEST_EDGE_H
#define TEST_EDGE_H

class Vertex;

class Edge {
public:
    Edge() : dest(NULL) {}

    Edge(Vertex *d) : dest(d) {}

    bool operator==(const Edge &other) const {
        return this->dest == other.dest;
    }

    Vertex *getV() const { return this->dest; }

private:
    Vertex *dest;
};

#endif //TEST_EDGE_H
