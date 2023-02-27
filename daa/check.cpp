#include<iostream>
#include<string>
#include<queue>
using namespace std;

// To create a node
struct node{
    char letter;
    int freq;
    struct node *left, *right;
    node(char l, int f){
        letter = l;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct compare{
    bool operator ()(node *left, node *right){
        return left->freq > right->freq;
    }
};

void printcode(struct node *root, string s);

void huffman(char a[], int f[], int n){
    priority_queue<node *,vector<node *>,compare>pq;
    for(int i=0;i<n;i++){
        pq.push(new node(a[i],f[i])); //pushes all the nodes to the array
    }
    struct node *lchild,*rchild;
    while(pq.size()>1){ // use > instead of !=
        lchild = pq.top();
        pq.pop();
        rchild = pq.top();
        pq.pop();
        struct node *temp = new node('*', lchild -> freq + rchild -> freq); // use pointer here
        temp -> left = lchild;
        temp -> right = rchild;
        pq.push(temp);
    }
    printcode(pq.top(),"");
}

void printcode(struct node *root, string s){
    if(root != NULL){
        if(root->letter != '*'){ // use '*' instead of ''
            cout<<root->letter<<"->"<<s<<" ";
        }
        printcode(root->left,s+"0");
        printcode(root->right,s+"1");
    }
}

int main(){
    char arr[] = {'a','b','c','d','e','f'};
    int freq[] = {5,9,12,13,16,45};
    int n = 6;
    huffman(arr,freq,n);
}
