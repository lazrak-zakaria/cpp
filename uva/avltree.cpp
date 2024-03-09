#include <iostream>

using namespace std;

struct node{

    int data;
    node* left;
    node* right;
    
    node () : data (0), left(0), right(0){}
    node (int data) : data(data), left(NULL), right(NULL)
    {}


};


class tree 
{
    private:
        struct node * root ;
    
    public:
        tree ( ) : root (NULL)
        {}


};

void print(node *root)
{
    if (root->left)
        print(root->left);
    
    cout << root->data << "\n";

    if (root->right)
        print(root->right);
    
}

int main()
{
    node *root = new node(1);

    // cout << root->data << "\n";
    root->right = new node(2);
    // cout << root->right->data << "\n";

    root -> right -> right  = new node(3) ;

    node *tmp = root;

    root -> left = new node(-1);
    root -> left -> left = new node(-2);
    root -> left -> right = new node(0);

    // while (tmp)
    // {
    //     cout << tmp->data << ' ' ;
    //     tmp = tmp -> left; 
    // }

    // print(root);
    cout << "\n";

    root


    return 0;
}
