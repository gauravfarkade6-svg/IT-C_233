#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create() {
    int val;
    struct node *newnode;

    printf("Enter data for node: ");
    scanf("%d", &val);

    if (val <= 0)
        return NULL;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    printf("Enter data for left node of %d: ", val);
    newnode->left = create();

    printf("Enter data for right node of %d: ", val);
    newnode->right = create();

    return newnode;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct node *root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (search(root->left, key) || search(root->right, key))
        return 1;

    return 0;
}

int main() {
    int key;
    struct node *root;

    root = create();

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\nPostorder Traversal:\n");
    postorder(root);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Found!");
    else
        printf("Not Found!");

    return 0;
}

