#pragma once

#include <iostream>
#include <list>

using std::string;
using std::list;
using std::cout;
using std::cin;
using std::endl;

class DT
{

	private:

		class Answer;
		class Node;

		//Node: each node in the decision tree
		class Node {
			private:
				string _value;
				list<Answer*> _answersList;

			public:
				//constructors and destructors:

				Node();
				Node(string v);
				Node(const Node& n);
				~Node();

				//additional functions:

				string getValue(); //return the value in the node.
				Node* find(string v); //search a node with the required value, return NULL if not found.
				void addAnswer(string ans, string next); //add a possible answer to some question.
				void print(int level); //print all tree from current node.
				bool printPath(string v); //print how to get a node with the given value.
				void run(); //run a process of questions
				bool deleteSubTree(string v);
		};

		//Answer: for each answer, the string, and the pointer to the node where to continue
		class Answer
		{
			private:
				string _answer;
				Node* _next;

			public:
				//constructors and destructors:

				Answer();
				Answer(string ans, string next);
				Answer(const Answer& node);
				~Answer();

				//additional functions:
				string getAnswer(); //return current answer
				Node* getNext(); //return the next node
				void print(int level); //print answers
		};

		Node* _root;
		Node* find(string q); //find a node with the given question

	public:
		//constructors and destructors:

		DT();
		DT(string n);
		DT(const DT& dt);
		~DT();

		//additional functions:

		bool addNode(string q, string ans, string next);
		void removeSubTree(string v);
		void print(); //print all tree from the root
		void printPath(string v); //print how to get a node with the given value form the root
		void run(); //run a process of questions from the root
		string printToString();

		//operators:

		DT& operator=(const DT& dt);
};
