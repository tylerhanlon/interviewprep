#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;


//This is trying to make a linked list class from scratch
//BASIC

struct Node
{
    int data;
    Node* next;
};

Node* newNode(int data, Node* next){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = next;
    return newNode;
}




int main() {

Node* hello = newNode(5, NULL);

std::cout << hello->data;
}
