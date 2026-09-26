#include<iostream>
using namespace std;

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
        
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while( originalNode != NULL ) {
            Node* originalNext = originalNode -> next;
            Node* cloneNext = cloneNode -> next;

            originalNode -> next = cloneNode;
            originalNode = originalNext;
            
            cloneNode-> next = originalNode;
            cloneNode = cloneNext;
        }
        
        // random pointers
        originalNode = head;
        while ( originalNode != NULL ) {
            if( originalNode -> next != NULL ) {
                if( originalNode -> random != NULL ) {
                    originalNode -> next -> random = originalNode -> random -> next;
                    
                } else {
                    originalNode -> next -> random = NULL;
                }
            }
            
            originalNode = originalNode -> next -> next;
        }
        
        
        // rever back changes
        cloneNode = cloneHead;
        originalNode = head;
        
        
        while (originalNode != NULL) {
            originalNode->next = originalNode->next->next;

            if (cloneNode->next != NULL) {
                cloneNode->next = cloneNode->next->next;
            }

            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        
        return cloneHead;
    }
};
