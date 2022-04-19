#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct Tree {
    int* value;
    struct Tree* left;
    struct Tree* right;
    int size;
}Tree;

void printAllValues(Tree* t) {
    if(t == NULL) return;

    printf("value is %d\n", *(t->value));
    printAllValues(t->left);
    printAllValues(t->right);
}

Tree* construct(int i) {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    int* v = (int*)malloc(sizeof(int));
    *v = i;
    t->value = v;
    t->left = NULL;
    t->right = NULL;
    t->size = 0;
    return t;
}

int preOrder(Tree* t, int i) {
    if(t == NULL) return 0;

    int ret = *(t->value) == i;
    int left = preOrder(t->left, i);
    int right = preOrder(t->right, i);

    return ret || left || right;
}

void add(Tree* t, int i){
    int* val = (int*)malloc(sizeof(int));
    *val = i;

    if(t->left == NULL && t->right == NULL) {
        Tree* nt = construct(i);    
        if(i <= *(t->value)) {
            t->left = nt;
        } else {
            t->right = nt;
        }

        return;
    }

    t->size++;
    
    /*
    if(t->left == NULL) {
        //add to left
        Tree* nt = construct(i);    
        t->left = nt;
        return;       
    } else if(t->right == NULL) {
        Tree* nt = construct(i);    
        t->right = nt;
        return;
    }
    Tree* next;
    if(t->left->size < t->right->size) {
        next = t->left;
    } else {
        next = t->right;
    }
    */


    if(i <= *(t->value)) {
        if(t->left == NULL) {
            Tree* nt = construct(i);
            t->left = nt;
            return;
        } else {
            add(t->left, i);
        }
    } else {
        if(t->right == NULL){
            Tree* nt = construct(i);
            t->right = nt;
            return;
        } else {
            add(t->right, i);
        }
    }
    /*
    if(t->left != NULL && i <= t->value) {
        add(t->left, i);
    } else if(t->right != NULL
    add(next, i);*/
}

int getSize(Tree* t) {
    return t -> size;
}

bool helper(Tree* root, long low, long high) {
    //empty tree is BST
    if (!root) {
        return true;
    }
    // if not in the range, return false
    if (!(low < *(root->value) && *(root->value) < high)) {
        return false;
    }
    // recursion
    return helper(root->left, low, *(root->value)) && 
           helper(root->right, *(root->value), high);
    }




bool isBST(Tree* root) {
    if (!root){
        return true;
    }
    return helper(root->left, LONG_MIN, *(root->value)) && helper(root->right,*(root->value), LONG_MAX);
}



int main() {
    Tree* t1 = construct(1);
    add(t1, 2);
    add(t1, 3);
    add(t1, 4);
    add(t1, 5);
    printAllValues(t1);
    printf("Tree has size %d\n", getSize(t1));
    printf("Is tree a BST? %d\n",isBST(t1));
   // printf("has value is %d\n", preOrder(t1, 2));
}

