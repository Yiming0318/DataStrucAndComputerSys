#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
    int* value;
    struct Tree* left;
    struct Tree* right;
    int size;
}Tree;



void printAllvalues(Tree* t) {
    if(t = NULL) return;
    printf("value is %d\n", *(t->value))
}

Tree* construct(int i) {
    Tree* t =(Tree*)malloc(sizeof(Tree));
    int* v = (int*)malloc(sizeof(int));
    *v = i;
    t->value = v;
    t->left = NULL;
    t->right = NULL;
    t->size = 0;
    return t;
}

void add(Tree* t, int i) {
    int* val = (int*)malloc(sizeof(int));
    *val = i;
    if (t->left==NULL && t->right==NULL) {
        Tree* nt = construct(i);
        t->left = nt;
        return;
    }
    t->size++;
    if (t->left == NULL) {
        //add to left
        Tree* nt = construct(i);
        t->left = nt;
        return;
    } else if(t->right == NULL) {
        //add to right
        Tree* nt = construct(i);
        t->right = nt;
        return;
    }
    Tree* next;
    if(t->left->size < t->right->size){
        next = t->left;
    }else{
        next = t->right;
    }
    add(next,i);
    }
}

int main() {
    Tree* t = constrcut();
}
