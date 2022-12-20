#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>


LinkedList::LinkedList()
{
    this->head = NULL;
}
LinkedList::LinkedList(const LinkedList& p)
{
    this->head = p.head;
}
LinkedList::~LinkedList()
{
}
LinkedList LinkedList::InsertNode(string data)
{
    Node* node = new Node(data, this->head);
    this->head = node;
    return *this;
}
LinkedList LinkedList::InsertNodeAfter(string data)
{
    Node* temp = new Node(data, NULL);
    if (this->head == NULL)
    {
        this->head = temp;
    }
    else
    {
        Node* node = this->head;
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = temp;
    }
    return *this;
}
LinkedList LinkedList::DeleteNode(string data)
{
    Node* before = NULL;
    Node* after = this->head;
    if (this->head == NULL)
    {
        cout << "\t\t\t - Khong co phan tu de xoa" << endl;
    }
    else
    {
        while (after != NULL)
        {
            if (after->data.find(data) < after->data.length())
                break;
            before = after;
            after = after->next;
        }
        if (before == NULL)
        {
            this->head = this->head->next;
        }
        else if (after == NULL)
            cout << "\t\t\t - Khong ton tai! " << data  << endl;
        else
            before->next = after->next;
    }
    return *this;
}


LinkedList LinkedList::getNode() const
{
    return *this;
}

void LinkedList::printList() const
{
    if (this->head != NULL)
    {
        Node* node = this->head;
        while (node != NULL)
        {
            cout << node->data << endl;
            node = node->next;
        }
    }
}


void LinkedList::printListFile(string filename) const
{
    ofstream g;
    g.open(filename);
    if (this->head != NULL)
    {
        Node* node = this->head;
        while (node != NULL)
        {
            g << node->data << endl;
            node = node->next;
        }
    }
    g.close();
}


int LinkedList::sizeofList() const
{
    int count = 0;
    Node* p = this->head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}


bool LinkedList::findData(string data) const
{
    Node* p = this->head;
    while (p != NULL)
    {
        if (p->data.find(data) == 0) {
            return true;
        }
        p = p->next;
    }
    return false;
}


string& LinkedList::findNode(int i) const
{
    Node* p = this->head;
    while (--i)
        p = p->next;
    return p->data;
}
