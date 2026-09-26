#include<iostream>
#include<unordered_map>
using namespace std;

// Structure of Linked List Node

class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};

class Solution {
    private:
        void insert( Node* &head, Node* &tail, int data ) {
            
            Node* temp = new Node( data );
            
            if( head == NULL ) {
                head = tail = temp;
                return;
                
            }
            
            tail -> next = temp;
            tail = temp;
        }
    
    
    
    
  public:
    Node* cloneLinkedList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while( temp != NULL ) {
            insert( cloneHead, cloneTail, temp-> data);
            temp = temp-> next;
        }
        
        
        // craeting a map
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        unordered_map<Node*, Node*> mapping;
        while( temp != NULL ) {
            mapping[originalNode] = cloneNode;
            originalNode = originalNode-> next;
            cloneNode = cloneNode-> next;
            
        }
        
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while( originalNode != NULL ) {
            cloneNode -> random = mapping[ originalNode-> random ];
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        return cloneNode;
    }
};
