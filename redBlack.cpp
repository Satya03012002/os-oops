using namespace std;
#include <iostream>

template <typename k,typename v>

class RedBlackTree{
    

    class Node{
        k key;
        v value;
        Node left,right,parent;
        boolean isLeftChild, black;
        public:
        Node(k key, v value){
            this.key = key;
            this.value = value;
            left = right = parent = NULL;
            black = false;
            isLeftChild = false;

        }
    }
    Node root = NULL;
    int size;

    
     
    public:
     Node grandParent;
    // Node leftRoatation(Node grandParent){
    //     Node temp = grandParent.right;
    //     grandParent.right = temp.left;
    //     temp.left = grandParent;
    //     grandParent = temp;
    //     return grandParent;
    // }

    Node leftRotate(Node node){
        Node temp = node.right;
        node.right = temp.left;
        temp.left = node;
        grandParent = temp;
        return grandParent;
    }

    Node rightRotate(Node node){
        Node temp = node.left;
        node.left = temp.right;
        temp.right = node;
        grandParent = node;
        return grandParent;
        
    }

    Node leftRightRotate(Node node){

        node.left = leftRotate(node.left);
        return rightRotate(node);

    }

    Node RightLeftRotate(Node node){

        node.right = rightRotate(node.right);
        return leftRotate(node);

        

    }
     void recAdd(Node root, Node newNode){
        if( root== NULL){
            
            root = node;
            root.black = false;
            
            return root;
        }else if(root.key == newNode.key){
            cout<<"already this key is present"<< endl;
            return root;
        }
        else if(root.key < newNode.key){
            newNode.parent = root;
            root.right = recAdd(root.right, newNode);
            root.right.isLeftChild = false;
            

        }else{
            newNode.parent = root;
            root.left = recAdd(root.left,newNode);
            root.left.isLeftChild = true;
        }
        return root;

     }

     void correctTree(Node node){
        
        if(node.parent.isLeftChild ){ // aunt is grandparent right child
         if(node.parent.parent.right == NULL || node.parent.parent.right.black == true ) {// ham null ko black hi consider karte hai or agar aunt black hoga to we do rotation
            return rotate(node);
         }
         if(node.parent.parent.right != NULL && node.parent.parent.right.black == false ) { // aunt is red means we do color flip
          
          node.parent.parent.black = false;
          node.parent.parent.right.black = true;
          node.parent.parent.black = true;

         }
         

        }else{
            if(node.parent.parent.left == NULL || node.parent.parent.left.black == true ) {// ham null ko black hi consider karte hai or agar aunt black hoga to we do rotation
            return rotate(node);
         }
         if(node.parent.parent.left != NULL && node.parent.parent.left.black == false ) { // aunt is red means we do color flip
          
          node.parent.parent.black = false;
          node.parent.parent.left.black = true;
          node.parent.parent.black = true;

         }
         
        }

     }


     void checkVoilation(Node node){
        if(node == root){
            return;
        }
        if(!node.black && !node.parent.black ){
            correctTree(node);
            checkVoilation(node.parent);
        }
     }

    void insert(k key, v value){
        Node node(key,value);
        if(root == NULL){
            root = node;
            root.black = true;
            size++;
        }else{
            recAdd(root,node);
            size++;
            checkVoilation(node);
        }
    }

};