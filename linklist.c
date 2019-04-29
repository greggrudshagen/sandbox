#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

typedef struct node
{
    struct node* next;
    int data;
} node;

typedef void (*callback)(node* nd);


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
        exit(0); // Since we exit, we are not checking for NULL in the caller.
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
        return head; // do not return a hard NULL.
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
        return head; // do not return a hard NULL.
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
node* remove_front(node *const head)
{
    if (NULL == head)
    {
        return head;
    }

    // will become the new head of the link list
    node *const new_head = head->next;

    // clean up the current head node for freeing
    head->next = NULL;
    free(head);

    return new_head;
}

/*
 * remove node from the back of the list
 */
node* remove_back(node* head)
{
    if (NULL == head)
    {
        return head;
    }

    node *new_tail = NULL;
    node *itr = NULL;
    for (itr = head; NULL != itr; itr = itr->next)
    {
        if (NULL == itr->next)
        { // found
            break;
        }
        new_tail = itr;
    }

    if (NULL != new_tail)
    { // mark as tail node in the link list
        new_tail->next = NULL;
    }
    else
    { // head is the only node in link list
        // clean up the current head node for freeing
        head = NULL;
    }

    free(itr);
    return head;
}

/*
 * remove a node from the list
 */
node* remove_any(node* const head, node* const nd)
{
    if (NULL == head || NULL == nd)
    {
        return head; // do not return a hard NULL.
    }

    { // special cases
        /* if the node is the first node */
        if (nd == head)
        {
            return remove_front(head);
        }

#if 0 // the below for loop will do the work
        /* if the node is the last node */
        if (nd->next == NULL)
        {
            return remove_back(head);
        }
#endif
    }

    node *itr = NULL;
    for (itr = head; NULL != itr; itr = itr->next)
    {
        if (nd == itr->next)
        { // found
            break;
        }
    }
    if (NULL != itr)
    {
        node* const tmp = itr->next;
        itr->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }

    return head;
}

/*
 * remove all nodes from the list
 */
node* remove_all(node* head)
{
    node *itr = NULL;
    for (itr = head; NULL != itr; itr = remove_front(itr))
    {
        ; // do nothing
    }
    // printf("size = %d\n", count(head));
    return itr;
}

/*
 * display a node
 */
void display_node_data(node* const n)
{
    if (NULL != n)
    {
        printf("%d ", n->data);
    }
}

/*
 * display a node's parameters
 */
void display_node_parameters(node* const nd)
{
    if (NULL != nd)
    {
        printf("node @ %p, node->data %d, node->next %p\n", nd, nd->data, nd->next);
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
 * clean up routine before exiting.
 */
void dispose(node *head)
{
    node * const nd = remove_all(head);
    if (NULL != nd)
    {
        printf("%s: Still have node(s): %d.\n", __FUNCTION__, count(nd));
    }
    // no return
}

/*
 * sort the linked list using insertion sort
 */
node* insertion_sort(node* head)
{
#if 0
    node *x = head; //, *y;//, *e;

    //x = head;
    head = NULL;

    while(x != NULL)
    {
        node *e = x;
        x = x->next;
        if (head != NULL)
        {
            if(e->data > head->data)
            {
                node *y = head;
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
#else
    node * const x = head;
    head = NULL;

    for (node* itr = x; NULL != itr; /* look inside loop */ )
    {
        node *e = itr;
        itr = itr->next; // needs to be here

        if (NULL != head)
        {
            if (e->data > head->data)
            {
                node *y = NULL;
                for (y = head; NULL != y->next; y = y->next)
                {
                    if (e->data > y->next->data)
                    {
                        continue;
                    }
                    break;
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
#endif
    return head;
}

/*
 * reverse the linked list
 */
node* reverse(node* const head)
{
    node* prev = NULL;
    node* next = NULL;
    for (node* itr = head; NULL != itr; itr = next)
    {
        next  = itr->next;
        itr->next = prev;
        prev = itr;
    }
    // prev is now the new head
    return prev;
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
    printf("9.remove all nodes\n");
    printf("10.sort the list\n");
    printf("11.reverse the list\n");
    printf("12.display the list\n");
    printf("13.count nodes in the list\n");
    printf("14.display the node's parameters\n");
    printf("-1.quit\n");
}

int ll_main()
{
    int command = 0;
    int data;

    node* head = NULL;
    node* nd   = NULL;
    callback const display_default = display_node_data;
    callback disp = display_default;


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
                if (NULL != head)
                {
                    traverse(head, disp);
                }
                break;
            case 7:
                head = remove_back(head);
                if (NULL != head)
                {
                    traverse(head, disp);
                }
                break;
            case 8:
                printf("Enter the element value to remove:");
                scanf("%d", &data);
                nd = search(head, data);
                if (NULL != nd)
                {
                    head = remove_any(head, nd);
                    if (NULL != head)
                    {
                        traverse(head, disp);
                    }
                }
                else
                {
                    printf("Element with value %d not found.", data);
                }
                break;
            case 9:
                head = remove_all(head);
                break;
            case 10:
                head = insertion_sort(head);
                if (NULL != head)
                {
                    traverse(head, disp);
                }
                break;
            case 11:
                head = reverse(head);
                if (NULL != head)
                {
                    traverse(head, disp);
                }
                break;
            case 12:
                traverse(head, disp);
                break;
            case 13:
                printf("Total nodes: %d.", count(head));
                break;
            case 14:
                // display the node's parameters
                disp = display_node_parameters;
                traverse(head, disp);
                disp = display_default;
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
