// hw15_yz10746.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

using namespace std;
using namespace linkedlistofclasses;

void openInputFile(ifstream& inFile) {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    inFile.open(filename);
    if (!inFile) {
        cout << "Failed to open file " << filename << endl;
        exit(1);
    }
}
    

int main()
{   
    ifstream inFile;
    openInputFile(inFile);
    
    pp_Ptr head = nullptr;
    pp_Ptr current = nullptr;
    for (int i = 0;i < 5;i++) {
        double money;
        string name;
        inFile >> money;
        inFile.ignore(1);
        getline(inFile, name);
        pp_Ptr newpp = new paid_Person;
        newpp->setPaid(money);
        newpp->setName(name);
        if (head == nullptr) {
            head = newpp;
            current = newpp;
        }
        else {
            current->setLink(newpp);
            current = newpp;
        }
    }

    double sum = 0.0;
    double average;
    current = head;
    while (current != nullptr) {
        sum += current->getPaid();
        current = current->getLink();
    }
    average = sum / 5;
    
    current = head;
    op_Ptr head2 = nullptr;
    op_Ptr current2 = nullptr;
    int countOwed = 0;
    while(current != nullptr) {
        double diff = current->getPaid() - average;
        current->setOwed(diff); 
        op_Ptr newop = new owed_to_Person;
        if (diff > 0) {
            string name = current->getName();
            newop->setName(name); 
            double money = current->getOwed();
            newop->setOwed(money);
            if (head2 == nullptr) {
                head2 = newop;
            }
            else {
                current2->setLink(newop);
            }
            current2 = newop;
            countOwed++;
        }
        current = current->getLink();
    }

    current = head;
    while (current != nullptr) {
        if (current->getOwed() == 0) {
            cout << current->getName() << ", you don't need to do anything" << endl;
        }
        else {
            current2 = head2;
            int opIndex = 0;
            while (current->getOwed() < 0 && opIndex < countOwed) {
                if (current->getOwed() * (-1) < current2->getOwed()) {
                    double balance = current2->getOwed() - current->getOwed() * (-1);
                    cout << current->getName() << ", you give " << current2->getName() << " $" << -current->getOwed() << endl;
                    current2->setOwed(balance);
                    current->setOwed(0.0);
                }
                else if (current->getOwed() * (-1) > current2->getOwed()) {
                    cout << current->getName() << ", you give " << current2->getName() << " $" << current2->getOwed() << endl;
                    double amount = current->getOwed() + current2->getOwed();
                    current->setOwed(amount);
                    current2->setOwed(0.0);
                    current2 = current2->getLink();
                    opIndex++;
                }
                else {
                    cout << current->getName() << ", you give " << current2->getName() << " $" << -current->getOwed() << endl;
                    current2->setOwed(0.0);
                    current->setOwed(0.0);
                }
            }
        }
        current = current->getLink();
    }

    cout << "In the end, you should all have spent around $" << average << endl;


    /*vector<paid_Person> pp;
    paid_Person temp1;
    while (inFile >> temp1.paid) {
        inFile.ignore(1);
        getline(inFile, temp1.name);
        pp.push_back(temp1);
    }
    double sum = 0.0;
    double average;
    int number1 = pp.size();
    for (int i = 0;i < number1;i++) {
        sum += pp[i].paid;
    }
    average = sum / number1;

    vector<owed_to_Person> op;
    owed_to_Person temp2;
    for (int i = 0;i < number1;i++) {
        double diff = pp[i].paid - average;
        pp[i].owed = diff;
        if (diff > 0) {
           pp[i].owed = diff;
           temp2.name = pp[i].name;
           temp2.owed = diff;
           op.push_back(temp2);
        }
    }
    
    int number2 = op.size();

    for (int i = 0;i < number1;i++) {
        if (pp[i].owed == 0) {
            cout << pp[i].name << ", you don't need to do anything" << endl;
        }
        else {
            int j = 0;
            while (pp[i].owed < 0 && j < op.size()) {
                if (pp[i].owed * (-1) < op[j].owed) {
                    double balance = op[j].owed - pp[i].owed*(-1);
                    cout << pp[i].name << ", you give " << op[j].name << " $" << -pp[i].owed << endl;
                    op[j].owed = balance;
                    pp[i].owed = 0;
                }
                else if (pp[i].owed * (-1) > op[j].owed){
                    cout << pp[i].name << ", you give " << op[j].name << " $" << op[j].owed << endl;
                    pp[i].owed += op[j].owed;
                    op[j].owed = 0;
                    j++;
                }
                else {
                    cout << pp[i].name << ", you give " << op[j].name << " $" << pp[i].owed * (-1) << endl;
                    op[j].owed = 0;
                    pp[i].owed = 0;
                    break;
                }
            }        
        }
    }
    
    cout << "In the end, you should all have spent around $" << average << endl;*/


    //current = head;
    //while (current != nullptr) {
    //    cout << "Name: " << current->getName() << "Money: $" << current->getPaid() << endl;
    //    current = current->getLink();
    //}

    /*current2 = head2;
    while (current2 != nullptr) {
    cout << "Name: " << current2->getName() << "Money: $" << current2->getOwed() << endl;
    current2 = current2->getLink();
    }*/
}

