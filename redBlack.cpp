using namespace std;
#include <iostream>

template <typename k, typename v>

class RedBlackTree
{

    class Node
    {
        k key;
        v value;
        Node left, right, parent; //parent- to get link for parent node(downward se upward(prev node)), left - leftchild, right-rightchild
        boolean isLeftChild, black;

    public:
        Node(k key, v value)
        {
            this.key = key;
            this.value = value;
            left = right = parent = NULL;
            black = false;
            isLeftChild = false;
        }
    } Node root = NULL;
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

    void leftRotate(Node node)
    {
        // Node temp = node.right;
        // node.right = temp.left;
        // temp.left = node;
        // grandParent = temp;
        // return grandParent;

        Node temp = node.right;
        node.right = temp.left; // in this case we also need to update parent pointer and it is no longer a right child it is a left child
         if(node.right!= NULL){ //temp k left node null nahi tha or node.right me temp.left wala node add hua hai 
            node.right.parent = node;
            node.right.isLeftChild = false;
         }
         if(node.parent == null){ // means node is a root node
          // means after rotation it becomes child of temp so temp is now new root
          root = temp;
          temp.parent = null; // because temp has become root

         }else{ // agar node root nahi hai to temp ka new parent node ka parent ho jaayega
                temp.parent = node.parent; // we use parent to get upward link from downward

                if(node.isLeftChild){ // agar node left child hoga to temp bhi node ka prent ka left child hoga
                     temp.isLeftChild = true;
                     temp.parent.left = temp; // hhere we do to get downward link from upward
                }else{
                    temp.isLeftChild = false;
                    temp.parent.child = true;
                }
         }

        temp.left = node;
        node.isLeftChild = true; // because node temp k left me hi aayega
        node.parent = temp;

    }

    void rightRotate(Node node)
    {
        // Node temp = node.left;
        // node.left = temp.right;
        // temp.right = node;
        // grandParent = node;
        // return grandParent;
      
        Node temp = node.left;
        node.left = temp.right;// apne ko temp k right me node ko add karna hai so hamko temp k right me jo pahle node hai uske node k left me add kar dena kyuki ham wahi wala node ka link break kar rahe hai
         if(node.left!= NULL){ //temp k right node null nahi tha or node.left me temp.right wala node add hua hai 
            node.left.parent = node;
            node.left.isLeftChild = true; // since temp k right wala node k left me add hua hai to node.left.isleftchild = true 
         }
         if(node.parent == null){ // means node is a root node
          // means after rotation it becomes child of temp so temp is now new root
          root = temp;
          temp.parent = null; // because temp has become root

         }else{ // agar node root nahi hai to temp ka new parent node ka parent ho jaayega
                temp.parent = node.parent; // we use parent to get upward link from downward

                if(node.isLeftChild){ // agar node left child hoga to temp bhi node ka prent ka left child hoga
                     temp.isLeftChild = true;
                     temp.parent.left = temp; // hhere we do to get downward link from upward
                }else{
                    temp.isLeftChild = false;
                    temp.parent.child = true;
                }
         }

        temp.right = node;
        node.isLeftChild = false; // because node temp k left me hi aayega
        node.parent = temp;

    }

    void leftRightRotate(Node node)
    {

        // node.left = leftRotate(node.left);
        // return rightRotate(node);
        leftRotate(node.left);
        rightRotate(node);
    }

    void RightLeftRotate(Node node)
    {

        // node.right = rightRotate(node.right);
        // return leftRotate(node);
        rightRotate(node.right);
        leftRotate(node);
    }
    void recAdd(Node root, Node newNode)
    {
        if (root == NULL)
        {

            root = node;
            root.black = false;

            return root;
        }
        else if (root.key == newNode.key)
        {
            cout << "already this key is present" << endl;
            return root;
        }
        else if (root.key < newNode.key)
        {
            newNode.parent = root;
            root.right = recAdd(root.right, newNode);
            root.right.isLeftChild = false;
        }
        else
        {
            newNode.parent = root;
            root.left = recAdd(root.left, newNode);
            root.left.isLeftChild = true;
        }
        return root;
    }
    void rotate(Node node)
    {
        if (node.isLeftChild)
        {
            if (node.parent.isLeftChild)
            {
                rightRotate(node.parent.parent);
                node.black = false;
                node.parent.black = true;
                if (node.parent.right != NULL)
                {
                    node.parent.right.black = false;
                }
                return;
            }
            else
            {
                if (!node.parent.isLeftChild)
                {
                    rightLeftRotate(node.parent.parent);
                    node.black = true;
                    node.right.black = false;
                    node.left.black = false;
                    if (node.parent.right != NULL)
                    {
                        node.parent.right.black = false;
                    }
                }
            }
        }else{
            if (!node.parent.isLeftChild)
            {
                leftRotate(node.parent.parent);
                node.black = false;
                node.parent.black = true;
                if (node.parent.right != NULL)
                {
                    node.parent.right.black = false;
                }
                return;
            }
            else
            {
                if (node.parent.isLeftChild)
                {
                    rightLeftRotate(node.parent.parent);
                    node.black = true;
                    node.right.black = false;
                    node.left.black = false;
                    if (node.parent.right != NULL)
                    {
                        node.parent.right.black = false;
                    }
                }
            }
        }
    }

        int blackNode(Node node){
            if(node == null){ // we also conider null as a black node
                return 1;
            }
             int rightBlackNode = blackNode(node.right);
             int leftBlackNode = blackNode(node.left);

             if(leftBlackNode != rightBlackNode){
                cout << "error check tree"<<endl;// ek rule ye bhi hai root se har path par black node same hona chahiye
             }

             if(node.black){ // check jo node hai kahi wo balck to nahi hai
                  leftBlackNode +1 ;// since leftBlacknode and rightBlackNode dono same hona chahiye correct tree k lea so lefyblacknode me plus kre or rightblacknode me plus kre baat same hi hai
             }
             return leftBlackNode;
        }

       int recHeight(Node node){
        if(node == null){
            return 0;
        }
        int leftHeight = recHeight(node.left)+1;
        int rightHeight = recHeight(node.right)+1;

        if(leftHeight > rightHeight){
            return leftHeight;
        }else{
            return rightHeight;
        }
       }

       int height(){
        if(node == NULL){
            return -1;

        }
        else{
            return recHeight(root) -1;
        }
       }

        void correctTree(Node node)
        {

            if (node.parent.isLeftChild)
            { // aunt is grandparent right child
                if (node.parent.parent.right == NULL || node.parent.parent.right.black == true)
                { // ham null ko black hi consider karte hai or agar aunt black hoga to we do rotation and then parent  become grand parent become red and parent become black
                    return rotate(node);
                }
                if (node.parent.parent.right != NULL && node.parent.parent.right.black == false)
                { // aunt is red means we do color flip in this case grand parent red hoga and parent and child black hoga

                    node.parent.parent.black = false;
                    node.parent.parent.right.black = true;
                    node.parent.parent.black = true;
                }
            }
            else
            {
                if (node.parent.parent.left == NULL || node.parent.parent.left.black == true)
                { // ham null ko black hi consider karte hai or agar aunt black hoga to we do rotation
                    return rotate(node);
                }
                if (node.parent.parent.left != NULL && node.parent.parent.left.black == false)
                { // aunt is red means we do color flip

                    node.parent.parent.black = false;
                    node.parent.parent.left.black = true;
                    node.parent.parent.black = true;
                }
            }
        }

        void checkVoilation(Node node)
        {
            if (node == root)
            {
                return;
            }
            if (!node.black && !node.parent.black)
            {
                correctTree(node);
                checkVoilation(node.parent);
            }
        }

        void insert(k key, v value)
        {
            Node node(key, value);
            if (root == NULL)
            {
                root = node;
                root.black = true;
                size++;
            }
            else
            {
                recAdd(root, node);
                size++;
                checkVoilation(node);
            }
        }
    

};