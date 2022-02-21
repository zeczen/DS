cmake_minimum_required(VERSION 3.17)
project(DS)

set(CMAKE_CXX_STANDARD 14)

add_executable(DS
        DT.cpp
        DT.h
        HashClient.h
        HashInt.h
        HashVolunteer.h
        Item.h
        Stock.h
        Stock.cpp
#        taskRun1.cpp
#        taskRun2.cpp
#        taskRun3.cpp
#        taskRun4.cpp
        taskRun5.cpp
        Trie.h
        Trie.cpp
        Volunteer.h
        Huffman.cpp
        Huffman.h
        BinaryTree.h
        Pair.h
        PriorityQueue.h
        Vertex.h
        Edge.h

        Graph.h)