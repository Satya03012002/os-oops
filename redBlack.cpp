using namespace std;
#include <iostream>

class RedBlackTree{
     
     Node grandParent;
    // Node leftRoatation(Node grandParent){
    //     Node temp = grandParent.right;
    //     grandParent.right = temp.left;
    //     temp.left = grandParent;
    //     grandParent = temp;
    //     return grandParent;
    // }

    Node leftRoatation(Node node){
        Node temp = node.right;
        node.right = temp.left;
        temp.left = node;
        grandParent = temp;
        return grandParent;
    }

    Node rightRoatation()
};