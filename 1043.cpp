#include <bits/stdc++.h>
using namespace std;
typedef struct NODE *Node;
struct NODE{
    Node left;
    Node right;
    int data;
};
std::vector<int> pre,pre1,pre2;
void preOrder(Node root){
    if(root==NULL) return;
    pre1.push_back(root->data);
    //printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void preOrderM(Node root){
    if(root==NULL) return;
    pre2.push_back(root->data);
    //cout<<root->data<<" ";
    preOrderM(root->right);
    preOrderM(root->left);
}
int k=0;
void postOrder(Node root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    if (k==0) printf("%d",root->data );
    else printf(" %d",root->data );
    k++;

}

void postOrderM(Node root){
    if(root==NULL) return;
    postOrderM(root->right);
    postOrderM(root->left);
    if (k==0) printf("%d",root->data );
    else printf(" %d",root->data );
    k++;

}
void insert(Node &node,int data){
    if(node==NULL){
        node = new NODE;
        node->data = data;
        node->left = node->right = NULL;
        return ;
    }
    if(data>=node->data){
        insert(node->right,data);
    }else{
        insert(node->left,data);
    }
}
int main(int argc, char const *argv[])
{
    int n,data;
    Node tree=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        pre.push_back(data);
        insert(tree,data);
    }
    //postOrder(tree);
    //printf("\n");
    preOrder(tree);
    //printf("\n");
    preOrderM(tree);
    //printf("%d\n",pre1.size());
    if(pre==pre1){
        printf("YES\n");
        postOrder(tree);
    }else if(pre==pre2){
        printf("YES\n");
        postOrderM(tree);
    }else{
        printf("NO\n");
    }
    return 0;
}
