namespace linkedlistofclasses {
	class Node {
	public:
		Node();
		Node(double paid, string name, Node* next);
		double getPaid() const;
		string getName() const;
		Node* getLink() const;
		void setPaid(double value);
		void setName(string person_name);
		void setLink(Node* next);
	private:
		double paid;
		string name;
		Node* link;
	};
	typedef Node* NodePtr;
}#pragma once
