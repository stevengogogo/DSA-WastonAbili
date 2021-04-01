/**
 * @file list.h
 * @author Shao-Ting Chiu
 * @brief Double linked list
 * @version 0.1
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1010
#define MAX_LEN_OPER_STR 100


typedef struct _node{
    int data;
    struct _node* ngb[2]; // neighbor
} node;

typedef struct {
    node* str;
    node* end;
} list;


// Constructor and Descructor
node* init_node(int data);
list init_list(void);
void detach_list(list* line);
void kill_node(node*);
void kill_list(list*);

int PrintList(list*);
int printNode(node* nStr);
int iter_read(node*);

/**
 * @brief Read the linked list from the first node to the last. Which is linked to the NULL
 * 
 * @return int -1 for error report
 */
int iter_read(node*);

/** get the flag point to the node. This function assumes a node is linked to at least one node */
int get_flag2node(node* terminal_node);

int get_flag2null(node* terminal_node);

/* Return the direction to the dst. -1 for missing */
int get_flag2dst(node* src, node* dst);


//Operations

/** Return 1 if one element is pop; -1 for none */
int leave(list*);
int enter(list*, int log);
void migrate(list* src, list* dst);


/** interface */
void interact_scanf(void);

#endif