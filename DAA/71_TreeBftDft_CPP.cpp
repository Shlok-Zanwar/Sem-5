#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class BST {
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insert(Node *head, int value){
        if(head == NULL){
            head = new Node;
            head->data = value;
            head->left = head->right = NULL;
        }
        else if(value < head->data){
            head->left = insert(head->left, value);   
        }
        else if(value > head->data){
            head->right = insert(head->right, value);   
        }
        return head;
    }

    void inorder(Node* head) {
        if(head == NULL){
            return;
        }
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }

    Node* binarySearch(Node* head, int data) {
        if(head == NULL){
            return NULL;
        }
        else if(data < head->data){
            return binarySearch(head->left, data);
        }
        else if(data > head->data){
            return binarySearch(head->right, data);
        }
        else{
            return head;
        }
    }

    void bftraversal(Node* root){
        if(!root){
            return;
        }
        queue<Node *> q;
        Node *temp;
        q.push(root);
        
        while(!q.empty()){
            temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
        cout << "\n";

    }

    void dftraversal(Node* root){
        if(!root){
            return;
        }
        stack<Node *> stk;
        Node *temp;
        stk.push(root);
        
        while(!stk.empty()){
            temp = stk.top();
            stk.pop();
            cout << temp->data << " ";
            if(temp->left){
                stk.push(temp->left);
            }
            if(temp->right){
                stk.push(temp->right);
            }
        }
        
        cout << "\n";

    }

    public:
        BST() {
            root = NULL;
        }

        void insert(int value) {
            root = insert(root, value);
        }

        void display() {
            inorder(root);
            cout << endl;
        }

        void search(int x) {
            Node *searched = binarySearch(root, x);
            if(searched){
                cout  << x << " present in the tree.\n";
            }
            else{
                cout  << x << " not present in the tree.\n";
            }
        }

        void bft(){
            bftraversal(root);
        }

        void dft(){
            dftraversal(root);
        }
        
};


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    cout << "Inorder traversal        : " ;
    t.display();

    cout << "Search 25                : ";
    t.search(25);

    cout << "Search 24                : ";
    t.search(24);

    cout << "Breath first traversal   : " ;
    t.bft();

    cout << "Depth first traversal    : " ;
    t.dft();
}

