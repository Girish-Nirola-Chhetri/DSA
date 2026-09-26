#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};


class Solution {
    
  private:
    Node* merge( Node* a, Node* b ) {
        if( a == NULL ) return b;
        if( b == NULL ) return a;
        
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while ( a != NULL && b != NULL ) {
            if( a-> data <= b-> data ) {
                temp ->bottom = a;
                temp = a;
                a = a-> bottom;
            }else {
                temp-> bottom = b;
                temp = b;
                b = b-> bottom;;
            }
        }
        
        while ( a!= NULL ) {
            temp ->bottom = a;
            temp = a;
            a = a-> bottom;
        }
        
        while ( b!= NULL ) {
            temp ->bottom = b;
            temp = b;
            b = b-> bottom;
        }
        
        return dummy-> bottom;
    }
    
     
    
  public:
    Node* flatten(Node* head) {
        
        if( head == NULL || head -> next == NULL) return head;
        
        Node* right = flatten( head-> next);
        head->next = NULL;
        
        head = merge(head, right);
        
        return head;
        
                
    }
};