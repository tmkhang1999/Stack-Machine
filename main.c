#include <stdio.h>
#include<stdlib.h>
#include <string.h>

//Linked Data Structure
struct integer {
    int value;
    struct integer* next;
};

//Stack Operations
//Pushes NUMBER on the stack
void lit(struct integer** stack, int value) {
    if (*stack == NULL) {
        (*stack)->value = value;
        (*stack)->next = NULL;
    } else {
        struct integer *Integer = (struct integer *) malloc(sizeof(struct integer));
        Integer->value = value;
        Integer->next = *stack;
        *stack = Integer;
    }
}

//Pops the top element of the stack
void drop(struct integer** stack){
    if(*stack != NULL){
        struct integer* preRoot = *stack;
        *stack = (*stack) -> next;
        free(preRoot);
    }
    else{
        printf("The stack is empty.\n");
    }
}

//Duplicates the top N elements of the stack
void dup( struct integer** stack, int n) {

    struct integer* current = *stack;
    struct integer* newList = NULL;
    struct integer* tail = NULL;

    // Create a new linked list with the pointed tail
    int i = 1;
    while (i<=n) {
        if (newList == NULL){
            newList = (struct integer*)malloc(sizeof(struct integer));
            newList->value = current->value;
            newList->next = NULL;
            tail = newList;
        } else {
            tail->next = (struct integer*)malloc(sizeof(struct integer));
            tail = tail->next;
            tail->value = current->value;
            tail->next = NULL;
        }
        current = current->next;
        i++;
    }

    // Link the new linked list with the the current stack
    tail->next = *stack;
    *stack = newList;
}

//Swaps the top two elements of the stack
void swap(struct integer** stack){
    if((*stack)->next != NULL) {
        int a = (*stack)->value;
        (*stack)->value = ((*stack)->next)->value;
        ((*stack)->next)->value = a;
    } else {
        printf("The stack does not have enough 2 integers to swap");
    }
}

//Integer Operations
void add(struct integer** stack){
    if((*stack)->next != NULL) {
        struct integer *preNext = (*stack)->next;
        (*stack)->value = ((*stack)->value) + (preNext->value);
        (*stack)->next = (preNext)->next;
        free(preNext);
    } else {
        printf("The stack does not have enough 2 integers to add");
    }
}
void sub(struct integer** stack){
    if((*stack)->next != NULL) {
        struct integer *preNext = (*stack)->next;
        (*stack)->value = (((*stack)->value) - (preNext->value));
        (*stack)->next = (preNext)->next;
        free(preNext);
    } else {
        printf("The stack does not have enough 2 integers to subtract");
    }
}
void mul(struct integer** stack){
    if((*stack)->next != NULL) {
        struct integer *preNext = (*stack)->next;
        (*stack)->value = (((*stack)->value) * (preNext->value));
        (*stack)->next = (preNext)->next;
        free(preNext);
    } else {
        printf("The stack does not have enough 2 integers to multiply");
    }
}
void divide(struct integer** stack){
    if((*stack)->next != NULL) {
        struct integer *preNext = (*stack)->next;
        (*stack)->value = (((*stack)->value) / (preNext->value));
        (*stack)->next = (preNext)->next;
        free(preNext);
    } else {
        printf("The stack does not have enough 2 integers to divide");
    }
}
void mod(struct integer** stack){
    if((*stack)->next != NULL) {
        struct integer *preNext = (*stack)->next;
        (*stack)->value = (((*stack)->value) % (preNext->value));
        (*stack)->next = (preNext)->next;
        free(preNext);
    } else {
        printf("The stack does not have enough 2 integers to mod");
    }
}

void and(struct integer** stack){
    if((*stack)->next != NULL) {
        struct integer *preNext = (*stack)->next;
        (*stack)->value = ((*stack)->value) & (preNext->value);
        (*stack)->next = (preNext)->next;
        free(preNext);
    } else {
        printf("The stack does not have enough 2 integers to AND");
    }
}
void or(struct integer** stack){
    if((*stack)->next != NULL) {
        struct integer *preNext = (*stack)->next;
        (*stack)->value = ((*stack)->value) | (preNext->value);
        (*stack)->next = (preNext)->next;
        free(preNext);
    } else {
        printf("The stack does not have enough 2 integers to OR");
    }
}

//Branching
int ifeq(struct integer** stack){
    if((*stack)->next != NULL) {
        struct integer *preRoot = *stack;
        struct integer *preNext = (*stack)->next;
        if (preRoot->value == preNext->value) {
            *stack = (preNext)->next;
            free(preRoot);
            free(preNext);
            return 1;
        } else {
            *stack = (preNext)->next;
            free(preRoot);
            free(preNext);
            return 0;
        }
    } else {
        printf("The stack does not have enough 2 integers to compare");
    }
    return 0;
}
int iflt(struct integer** stack) {
    if((*stack)->next != NULL) {
        struct integer *preRoot = *stack;
        struct integer *preNext = (*stack)->next;
        if (preRoot->value < preNext->value) {
            *stack = (preNext)->next;
            free(preRoot);
            free(preNext);
            return 1;
        } else {
            *stack = (preNext)->next;
            free(preRoot);
            free(preNext);
            return 0;
        }
    } else {
        printf("The stack does not have enough 2 integers to compare");
    }
    return 0;
}

//Input / Output
void in(struct integer** stack){
    int a;
    printf("What is the integer you would like to put into the stack?\n");
    scanf("%d", &a);
    if(*stack == NULL){
        (*stack)->value = a;
    } else {
        lit(stack,a);
    }
}
void out(struct integer** stack){
    if(*stack == NULL){
        printf("The stack is empty.\n");
    } else {
        printf("%d\n",(*stack)->value);
        drop(stack);
    }
}

// Extra credits
void store(struct integer** stack, int* array, int index){
    if(*stack != NULL){
        array[index] = (*stack)->value;
        drop(stack);
    }
    else{
        printf("The stack is empty.\n");
    }
}
void load(struct integer** stack, int* array, int index){
    lit(stack, array[index]);
}

int main() {

    char *filename = NULL;
    int numOfIns;
    int i = 0;
    int ints[0xFF];
    ints[100] = 1234;

    //get the file of instructions
    printf("What is the file of instructions you want to open?\n");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("This file doesn't exit");
    }

    //Create a root for the stack
    struct integer *top = (struct integer *) malloc(sizeof(struct integer));

    //Create an array for instructions
    fscanf(file, "%d", &numOfIns);
    char lines[numOfIns][100];
    while (fgets(lines[i], 20, file)) {
        if (i < numOfIns) {
            lines[i][strlen(lines[i]) - 1] = '\0';
        }
        i++;
    }

    //Operation
    int x = 1;
    char a[100];
    int b;

    while (x <= numOfIns) {
        sscanf(lines[x], "%s%*[^0-9]%d", a, &b);
        if (strcmp(a,"IN") == 0){
            in(&top);
            x++;
        } else if(strcmp(a,"OUT") == 0){
            out(&top);
            x++;
        } else if(strcmp(a, "LIT") == 0){
            lit(&top, b);
            x++;
        } else if (strcmp(a, "DROP") == 0){
            drop(&top);
            x++;
        } else if (strcmp(a, "DUP") == 0){
            dup(&top, b);
            x++;
        } else if (strcmp(a, "SWAP") == 0){
            swap(&top);
            x++;
        } else if (strcmp(a, "ADD") == 0){
            add(&top);
            x++;
        } else if (strcmp(a, "SUB") == 0){
            sub(&top);
            x++;
        } else if (strcmp(a, "MUL") == 0){
            mul(&top);
            x++;
        } else if (strcmp(a, "DIV") == 0){
            divide(&top);
            x++;
        } else if (strcmp(a, "MOD") == 0){
            mod(&top);
            x++;
        } else if (strcmp(a, "AND") == 0){
            and(&top);
            x++;
        } else if (strcmp(a, "OR") == 0){
            or(&top);
            x++;
        }else if (strcmp(a, "IFEQ") == 0){
            if (ifeq(&top) == 1){
                x = b;
            } else {
                x++;
            }
        } else if (strcmp(a, "IFLT") == 0){
            if (iflt(&top) == 1){
                x = b;
            } else {
                x++;
            }
        } else if (strcmp(a, "JUMP") == 0){
            x = b;
        } else if (strcmp(a,"STOR") == 0){
            store(&top, ints, b);
            x++;
        } else if (strcmp(a,"LOAD") == 0){
            load(&top, ints, b);
            x++;
        }
    }
    printf("%d",ints[2]);
    printf("%d",top->value);
    return 0;
}

