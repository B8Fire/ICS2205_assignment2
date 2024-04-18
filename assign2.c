/*
BONFACE GEKARA MORARA SCT221-0282/2022
SHADRACK KEBASO       SCT221-0205/2022
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int bst_construct(int post_order[], int in_order[], int in_start, int in_end, int *post_index);
void depthFirstSearch(struct Node *root);

int main() {
    int post_order[] = {5, 15, 10, 25, 45, 30, 20};
    int in_order[] = {5, 10, 15, 20, 25, 30, 45};
    int n = sizeof(in_order) / sizeof(in_order[0]);

    int post_index = n - 1;
    int root_address = bst_construct(post_order, in_order, 0, n - 1, &post_index);
    printf("\nRoot address = %d\n\n",root_address);

    depthFirstSearch((struct Node *)root_address);

    return 0;
}

int bst_construct(int post_order[], int in_order[], int in_start, int in_end, int *post_index) {
    if (in_start > in_end)
        return -1;

    struct Node *root = newNode(post_order[*post_index]);
    (*post_index)--;

    if (in_start == in_end)
        return (int)root;

    int in_index;
    for (int i = in_start; i <= in_end; i++) {
        if (in_order[i] == root->data) {
            in_index = i;
            break;
        }
    }

    root->right = (struct Node *)bst_construct(post_order, in_order, in_index + 1, in_end, post_index);
    root->left = (struct Node *)bst_construct(post_order, in_order, in_start, in_index - 1, post_index);

    return (int)root;
}

void depthFirstSearch(struct Node *root) { //recursive implementation of function
    if (root == NULL)
        return;

    printf("%d ", root->data);
    depthFirstSearch(root->left);
    depthFirstSearch(root->right);
}
