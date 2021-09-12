
#include <iostream>
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    T dat;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} Stack;

void init(Stack* stack) {
    stack->head = NULL;
    stack->size = 0;
}

boolean push(Stack* stack, T value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp==NULL)
    {
        std::cout << "Stack overflow" << std::endl;
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}
T pop(Stack* stack) {
    if (stack->size==0)
    {
        //std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    Node* tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

void printOneLinkCharNode(Node* n) {
    if (n==NULL)
    {
        std::cout << "*";
        return;
    }
    std::cout << n->dat;
}

void printOneLinkCharStack(Stack* stack) {
    Node* current = stack->head;
    if (current==NULL)
    {
        printOneLinkCharNode(current);
    }
    else {
        do
        {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current!=NULL);
    }
    std::cout << std::endl;
}

typedef struct Node2 {
    int dat;
    struct Node2* next;
} Node2;

typedef struct {
    Node2* head;
    int size;
} List;

void init2(List* lst) {
    lst->head = NULL;
    lst->size = 0;
}

void ins(List* lst, int data) {
    Node2* neww = (Node2*)malloc(sizeof(Node2));
    neww->dat = data;
    neww->next = NULL;

    Node2* current = lst->head;
    if (current == NULL)
    {
        lst->head = neww;
        lst->size++;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = neww;
        lst->size++;
    }
}

Node2* rm(List* lst, int data) {
    Node2* current = lst->head;
    Node2* parent = NULL;
    if (current == NULL)
    {
        return NULL;
    }

    while (current->next != NULL && current->dat != data)
    {
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
    {
        return NULL;
    }
    if (current == lst->head)
    {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printNode(Node2* n) {
    if (n == NULL)
    {
        std::cout << "[]";
        return;
    }
    std::cout << '[' << n->dat << ']';
}

void printList(List* lst) {
    Node2* current = lst->head;
    if (current == NULL)
    {
        printNode(current);
    }
    else {
        do
        {
            printNode(current);
            current = current->next;
        } while (current != NULL);
    }
    std::cout << "Size: " << lst->size << std::endl;
}

void ListCopy(List* lst, List* lst1) {
    lst1->size = 0;
    Node2* current = lst->head;
    Node2* current1 = lst1->head;
    if (current == NULL)
    {
        std::cout << "List is empty.";
        return;
    }
    else {
        lst1->head = lst->head;
    }
    for (size_t i = 0; i < lst->size; i++)
    {
        current1 = current;
        current = current->next;
        current1 = current1->next;
        lst1->size++;
    }
}

void SortList(List* lst) {
    Node2* current = lst->head;
    if (current == NULL)
    {
        std::cout << "List is empty.";
        return;
    }
    int q = 0;
    for (size_t i = 0; i < lst->size - 1; i++)
    {
        if (current->next->dat > current->dat)
        {
            current = current->next;
        }
        else {
            q = 1;
            break;
        }
    }
    if (q == 0)
    {
        std::cout << "Sorted" << std::endl;
    }
    else
    {
        std::cout << "Unsorted" << std::endl;
    }
}




int main()
{

    /////// exercise 1

    Stack* st = (Stack*)malloc(sizeof(Stack));
    init(st);

    char a[] = {'(',')','{','}','{',')' };

    for (size_t i = 0; i < sizeof(a); i++)
    {
        if (a[i] == '(')
        {
            push(st, a[i]);
        }
        else if (a[i] == ')' && st->size > 0)
        {
            pop(st);
        }
    }
    for (size_t i = 0; i < sizeof(a); i++)
    {
        if ( a[i] == '[')
        {
            push(st, a[i]);
        }
        else if (a[i] == ']' && st->size > 0)
        {
            pop(st);
        }
    }
    for (size_t i = 0; i < sizeof(a); i++)
    {
        if (a[i] == '{')
        {
            push(st, a[i]);
        }
        else if ( a[i] == '}' && st->size > 0)
        {
            pop(st);
        }
    }


    if (st->size == 0)
    {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    ////////
    /////exercise 2,3

    List* lst = (List*)malloc(sizeof(List));
    List* lst1 = (List*)malloc(sizeof(List));
    init2(lst);

    ins(lst, 1);
    ins(lst, 2);
    ins(lst, 3);
    ins(lst, 4);
    ins(lst, 5);
    ins(lst, 6);
    printList(lst);
    ListCopy(lst, lst1);
    printList(lst1);
    SortList(lst);



    //////

    system("pause");
    return 0;
}

