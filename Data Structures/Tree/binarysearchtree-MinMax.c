/*
Write an algorithm and program to find
the minimum and maximum value from a binary search tree.
*/
#include <stdio.h>
#include <stdlib.h>
#define INDENT 10
struct nodes{
    int data;
    struct nodes *left_child;
    struct nodes *right_child;
} * root;

void menu();
int find_min_value(struct nodes *tree_root);    // Q1
int find_max_value(struct nodes *tree_root);    // Q2

int main(){
    menu();


}
/* *************************************************************** */
// ASSIGNMENT FUNCTIONS

int find_min_value(struct nodes *tree_root){
        struct nodes *temp;
        temp = tree_root;
        if(temp==NULL){
            printf("\nError: Tree is empty.");
            return -1;
        }
        else
        {
            while(temp->left_child!=NULL)
                temp = temp->left_child;

            printf("\n\nSmallest Data Value: %d", temp->data);
            return temp->data;
        }


}
int find_max_value(struct nodes *tree_root){
        struct nodes *temp;
        temp = tree_root;
        if(temp==NULL){
            printf("\nError: Tree is empty.");
            return -1;
        }
        else
        {
            while(temp->right_child!=NULL)
                temp = temp->right_child;

            printf("\n\nSmallest Data Value: %d", temp->data);
            return temp->data;
        }


}
/* ************************************************************************** */

// Other Tree functions and definitions.


struct nodes *create_tree(){
        struct nodes *new_node;
        new_node = malloc(sizeof(struct nodes));
        new_node->left_child = new_node->right_child = NULL;
        return new_node;
};

struct nodes insert_into_tree(struct nodes * temp, struct nodes * item){
            if(temp==NULL){
                root = item;
            }
            else
            {
                while(temp!=NULL){

                    if(temp->data >= item->data)
                    {
                        if(temp->left_child == NULL)
                        {
                            temp->left_child = item;
                            break;
                        }
                        else temp = temp->left_child;
                    }
                    if(temp->data < item->data)
                    {
                        if(temp->right_child == NULL)
                        {
                            temp->right_child = item;
                            break;
                        }
                        else temp = temp->right_child;
                    }

                }

            }
}


struct nodes input_new_node(){
            struct nodes *item, *temp;
            item = create_tree();
            printf("\nEnter data value of node: ");
            scanf("%d", &item->data);
            temp = root;
            insert_into_tree(temp, item);

};


void printTree(struct nodes *parent, int depth)
{
    if (parent == NULL)
        return;
    depth += INDENT;
    printTree(parent->right_child, depth);
    printf("\n");
    for (int i = INDENT; i < depth; i++)
        printf(" ");
    printf("%d\n", parent->data);

    // Process left child
    printTree(parent->left_child, depth);
}

void menu(){
    int ch;
    printf("\nS Sandeep Pillai - CS3A - 59\n[1]Enter Value \n[2]Pretty Print Tree \n[3]Find Min \n[4]Find Max \n[0]Exit \n");
    while(1){
        printf("\nChoice -> ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                input_new_node();
                break;
            case 2:
                if(root==NULL) printf("\nTree is empty");
                printTree(root, 0);
                break;
            case 3:
                find_min_value(root);
                break;
            case 4:
                find_max_value(root);
                break;
            case 0:
            default:
                exit(0);
        }

    }

}
