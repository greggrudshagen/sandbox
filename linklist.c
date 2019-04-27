#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

typedef struct node
{
    struct node* next;
    int data;
} node;

typedef void (*callback)(node* data);


/*
 * return the number of elements in the list
 */
int count(node * const head)
{
    int c = 0;
    for (node *itr = head; NULL != itr; itr = itr->next)
    {
        c++;
    }

    return c;
}

/*
 * create a new node
 * initialize the data and next field
 *
 * return the newly created node
 */
node* create(int const data, node* const next)
{
    node* const new_node = (node*)malloc(sizeof(node));
    if (NULL == new_node)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

/*
 * add a new node at the beginning of the list
 */
node* prepend(node* head, int data)
{
    return create(data, head);
}

/*
 *  add a new node at the end of the list
 */
node* append(node* const head, int data)
{
    if (NULL == head)
    {
        return prepend(head, data);
    }

    { /* iterate to the last and then create a new node */
        for (node *itr = head; NULL != itr; itr = itr->next)
        {
            if (NULL == itr->next)
            { // found
                itr->next = create(data, NULL);
                break;
            }
        }
    }

    return head; // return head; the previous head is still the head
}

/*
 * insert a new node after the prev node
 */
node* insert_after(node * const head, int const data, node* const prev)
{
    if (NULL == head || NULL == prev)
    {
        return head;
    }

    { /* iterate to the prev node and then create a new node */
        for (node *itr = head; NULL != itr; itr = itr->next)
        {
            if (prev == itr)
            { // found
                itr->next = create(data, itr->next);
            }
        }
    }

    return head; // return head; the previous head is still the head
}

/*
 * insert a new node before the nxt node
 */
node* insert_before(node * const head, int const data, node* const nxt)
{
    if (NULL == head || NULL == nxt)
    {
        return head;
    }

    if (head == nxt)
    { // This new node is to become the new head of the linked list
        return prepend(head, data);
    }

    { /* iterate to the nxt node and then create a new node */
        for (node *itr = head; NULL != itr; itr = itr->next)
        {
            if (nxt == itr->next)
            { // found
                itr->next = create(data, itr->next);
                break;
            }
        }
    }

    return head; // return head; the previous head is still the head
}

/*
 * traverse the linked list
 */
void traverse(node* const head, callback const f)
{
    for (node *itr = head; NULL != itr; itr = itr->next)
    {
        f(itr);
    }
}

/*
 * remove node from the front of list
 * release the memory
 */
node* remove_front(node* head)
{
    if (head == NULL)
    {
        return head;
    }

    node *front = head;
    head = head->next;
    front->next = NULL;
    /* is this the last node in the list */
    if (front == head)
    {
        head = NULL;
    }
    free(front);
    return head;
}

/*
 * remove node from the back of the list
 */
node* remove_back(node* head)
{
    if(head == NULL)
    {
        return head;
    }

    node *cursor = head;
    node *back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }

    if(back != NULL)
    {
        back->next = NULL;
    }

    /* if this is the last node in the list*/
    if(cursor == head)
    {
        head = NULL;
    }
    free(cursor);

    return head;
}

/*
 * remove a node from the list
 */
node* remove_any(node* head, node* nd)
{
    if(nd == NULL)
    {
        return NULL;
    }

    /* if the node is the first node */
    if(nd == head)
    {
        return remove_front(head);
    }

    /* if the node is the last node */
    if(nd->next == NULL)
    {
        return remove_back(head);
    }

    /* if the node is in the middle */
    node* cursor = head;
    while(cursor != NULL)
    {
        if(cursor->next == nd)
            break;
        cursor = cursor->next;
    }

    if(cursor != NULL)
    {
        node* tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;

}

/*
 * display a node
 */
void display(node* const n)
{
    if (NULL != n)
    {
        printf("%d ", n->data);
    }
}

/*
 * Search for a specific node with input data
 *
 * return the first matched node that stores the input data,
 * otherwise return NULL
 */
node* search(node* const head, int const data)
{
    for (node *itr = head; NULL != itr; itr = itr->next)
    {
        if (data == itr->data)
        {
            return itr;
        }
    }

    return NULL;
}

/*
 * remove all element of the list
 */
void dispose(node *head)
{
    while (NULL != head)
    {
        head = remove_front(head);
    }
    // printf("size = %d\n", count(head));
}

/*
 * sort the linked list using insertion sort
 */
node* insertion_sort(node* head)
{
    node *x, *y;//, *e;

    x = head;
    head = NULL;

    while(x != NULL)
    {
        node *e = x;
        x = x->next;
        if (head != NULL)
        {
            if(e->data > head->data)
            {
                y = head;
                while ((y->next != NULL) && (e->data > y->next->data))
                {
                    y = y->next;
                }
                e->next = y->next;
                y->next = e;
            }
            else
            {
                e->next = head;
                head = e ;
            }
        }
        else
        {
            e->next = NULL;
            head = e ;
        }
    }
    return head;
}

/*
 * reverse the linked list
 */
node* reverse(node* head)
{
    node* prev    = NULL;
    node* current = head;
    node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

/*
 * display the menu
 */
void menu()
{
    printf("--- C Linked List Demonstration --- \n\n");
    printf("0.menu\n");
    printf("1.prepend an element\n");
    printf("2.append an element\n");
    printf("3.search for an element\n");
    printf("4.insert after an element\n");
    printf("5.insert before an element\n");
    printf("6.remove front node\n");
    printf("7.remove back node\n");
    printf("8.remove any node\n");
    printf("9.sort the list\n");
    printf("10.Reverse the linked list\n");
    printf("-1.quit\n");

}


int ll_main()
{
    int command = 0;
    int data;

    node* head = NULL;
    node* nd   = NULL;
    callback disp = display;


    menu();
    while(1)
    {
        printf("\nEnter a command(0-10,-1 to quit):");
        scanf("%d", &command);

        if (command == -1)
        {
            break;
        }

        switch(command)
        {
            case 0:
                menu();
                break;
            case 1:
                printf("Please enter a number to prepend:");
                scanf("%d", &data);
                head = prepend(head, data);
                traverse(head, disp);
                break;
            case 2:
                printf("Please enter a number to append:");
                scanf("%d", &data);
                head = append(head, data);
                traverse(head, disp);
                break;
            case 3:
                printf("Please enter a number to search:");
                scanf("%d", &data);
                nd = search(head, data);
                if(nd != NULL)
                {
                    printf("Element with value %d found.", data);
                }
                else
                {
                    printf("Element with value %d not found.", data);
                }
                break;
            case 4:
                printf("Enter the element value where you want to insert after:");
                scanf("%d", &data);
                nd = search(head, data);
                if(nd != NULL)
                {
                    printf("Enter the element value to insert after:");
                    scanf("%d", &data);
                    head = insert_after(head, data, nd);
                    if(head != NULL)
                        traverse(head, disp);
                }
                else
                {
                    printf("Element with value %d not found.", data);
                }
                break;
            case 5:
                printf("Enter the element value where you want to insert before:");
                scanf("%d", &data);
                nd = search(head, data);
                if(nd != NULL)
                {
                    printf("Enter the element value to insert before:");
                    scanf("%d", &data);
                    head = insert_before(head, data, nd);

                    if(head != NULL)
                        traverse(head, disp);
                }
                else
                {
                    printf("Element with value %d not found.", data);
                }
                break;
            case 6:
                head = remove_front(head);
                if(head != NULL)
                    traverse(head, disp);
                break;
            case 7:
                head = remove_back(head);
                if(head != NULL)
                    traverse(head, disp);
                break;
            case 8:
                printf("Enter the element value to remove:");
                scanf("%d", &data);
                nd = search(head, data);
                if(nd != NULL)
                {
                    remove_any(head, nd);
                    if(head != NULL)
                        traverse(head, disp);
                }
                else
                {
                    printf("Element with value %d not found.", data);
                }
                break;
            case 9:
                head = insertion_sort(head);
                if(head != NULL)
                    traverse(head, disp);
                break;
            case 10:
                head = reverse(head);
                if(head != NULL)
                    traverse(head, disp);
                break;
        }
    }
    dispose(head);
    return 0;
}



int linklist_main()
{
    int rc = 0;
    printf("%s\n", __FUNCTION__);

#if 1
    rc = ll_main();
#elif 0

#else

#endif
    return rc;
}

// EOF
