#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    ~LinkedList() {
        Node<T>* current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
        get(length-1)->next = NULL;
    }

    Node<T>* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (index < 0 || index >= length) {
            cout<<"Invalid index"<<endl;
            return;
        }
        if (index == 0) {
            delfirst();
        }
        if (index == length-1) {
            dellast();
        }
        else {
            Node<T>* temp = get(index-1);
            Node<T>* temp2 = get(index);
            temp->next = get(index+1);
            delete temp2;
            length--;

        }
    }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
        if (index < 0 ||  index >= length) {
            cout<<"Index is invalid"<<endl;
            return;
        }
        if (index == 0) {
            addhead(value);
        }
        if (index == length-1) {
            add(value);
        }
        else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* temp = get(index-1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T>* prev = new Node<T>(nullptr);
        Node<T>* curr = new Node<T>(nullptr);
        Node<T>* nextNode = new Node<T>(nullptr);
        prev = NULL;
        curr = head;
        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    //ll->delfirst();
    //ll->print();
    //ll->dellast();
    //ll->print();
    //ll->deleteNode(1);
    //ll->print();
    ll->reverselist();
    ll->print();
}