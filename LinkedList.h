#pragma once
#ifndef LINKEDLISK_H
#define LINKEDLISK_H

#include <iostream>
#include <string>

using namespace std;
class Node
{
private:
    string data;
    Node* next;

public:
    Node(string data, Node* next) : data(data), next(next) {}
    friend class LinkedList;
};
class LinkedList
{
private:
    Node* head;

public:
    LinkedList();
    LinkedList(const LinkedList& p);
    ~LinkedList();
    LinkedList InsertNode(string data);
    LinkedList InsertNodeAfter(string data);
    LinkedList DeleteNode(string data);
    LinkedList getNode() const;
    void printList() const;
    void printListFile(string filename) const;
    int sizeofList() const;
    bool findData(string data) const;
    string& findNode(int i) const;
};

#endif // !LINKEDLISK_H
