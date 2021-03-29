/**
 * @file main.c
 * @author Shao-Ting Chiu (r07945001@ntu.edu.tw)
 * @brief This project is for the DSA course 2021 at National Taiwan Unviersity. Homework 1 Problem 5.
 * @version 0.1
 * @date 2021-03-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "list.h"

int main()
{

    list l = init_list();

    enter(&l, 3);
    enter(&l, 4);

    kill_list(&l);
    //TEST_ASSERT( l.end == NULL );
    //TEST_ASSERT( l.str == NULL );

    //TEST_ASSERT(leave(&l) == -1); //release null line


    return 0;
}