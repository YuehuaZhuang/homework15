#include <iostream>
#include "Node.h"
using namespace std;

namespace linkedlistofclasses {
	Node::Node() :paidMoney(0.0), personName(""), link(NULL) {};
	Node::Node(double paid, string name, Node* next) :paidMoney(paid), personName(name), link(next) {};
	double Node::getPaid() const { return paidMoney; }
	string Node::getName() const { return personName; }
	Node* Node::getLink() const { return link; }
	void Node::setPaid(double paid) { paidMoney = paid; }
	void Node::setName(string name) { personName = name; }
	void Node::setLink(Node* next) { link = next; }
}