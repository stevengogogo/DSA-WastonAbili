#include "list.h"


node* init_node(int data){
    node* init = (node*)malloc(sizeof(node));
    assert(init != NULL);
    init->data = data;
    init->ngb[0] = NULL;
    init->ngb[1] = NULL;

    return init;
}

list init_list(){
    list line = {
        .str = NULL,
        .end = NULL
    };
    return line;
}

void kill_node(node* n){
    free(n);
}

void kill_list(list* line){
    while(line->end != NULL){
        leave(line);
    }
}

int get_flag2node(node* terminal_node){

     node* left =  terminal_node->ngb[0]; 
     node* right = terminal_node->ngb[1];

    assert( ((left == NULL) || (right == NULL) ) ); // one of ends is null

    if (left==NULL && right == NULL)
        return -1;

    if (left != NULL && right == NULL)
        return 0;
    
    if (left == NULL && right != NULL)
        return 1;
}

int get_flag2null(node* terminal_node){
    int flag2node = get_flag2node(terminal_node);

    if (flag2node == -1)
        return 2;
    else 
        return flag2node^1;
    
}

int get_flag2dst(node* src, node* dst){
    if( src->ngb[0] == dst ){
        return 0;
    }
    else if(src->ngb[1] == dst){
        return 1;
    }
    else {
        return -1;
    }
}

//Operations
int leave(list* line){
    int flag;
    int flag_back;

    node* last_n = NULL;
    if(line->end != NULL){
        flag = get_flag2node(line->end);
        
        if (flag==-1){ // Only one element
            assert(line->str == line->end); // Assign to same node
            free(line->end);
            line->str = NULL;
            line->end = NULL;
            return 1;
        }

        last_n = line->end;

        line->end = line->end->ngb[flag];
        // Get to pointer to last node
        flag_back = get_flag2dst(line->end, last_n);
        assert(flag_back != -1); // success link back

        line->end->ngb[flag_back] = NULL;
        
        free(last_n);

        return 1;
    }
    else {
        return -1;
    }
}

void enter(list* line, int log){
    node* new = init_node(log);

    if(line->str == NULL){ //start a new line
        assert(line->end == NULL); //null line
        line->str = new;
        line->end = new;
    }

    else{
        int flag = get_flag2null(line->end);

        if (flag == 2){
            flag = 1;
        }

        // Bridge last to new block
        line->end->ngb[flag] = new;

        // Bridge New block
        new->ngb[flag] = NULL;
        new->ngb[flag^1] = line->end;

        // move terminal to new
        line->end = new;
    }
}