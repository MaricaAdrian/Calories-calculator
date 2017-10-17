///\file header.h
///\brief Header file where we can find the head declaration of our functions.
///
#ifndef _HEADER_H_
#define _HEADER_H_


#include <stdio.h>
 /** A Linked list. 
     *  Where we will store the name and the intake of every activity.
     */
struct activity {

    char name[100]; /**< Name of the activity. */  
    float intake; /**< Intake of calories after doing the activity. */  
    struct activity *next; /**< Next activity from our linked list. */  


}activity; /**< Name of our main linked list. */  


float G_TOTAL_INTAKE = 0; /**< Global variable that stores the intake calories from food. */  

void add_activity (struct activity *activity, char name[100], float intake); /**< Head declaration of our function that adds an activity to the linked list. */  
void delete_activity (struct activity *activity, char name[100]); /**< Head declaration of our function that deletes an activity from the linked list. */  
void print_all (struct activity *activity); /**< Head declaration of our function that prints all activites to the console. */  
void calculate_intake_zero (struct activity *activity); /**< Head declaration of our function that prints to the console if an activity is perfect for you to have 0 intake. */  
void load_activities (struct activity *activity); /**< Head declaration of our function that loads the activities from the activity file. */  
void save_to_file(struct activity *activity); /**< Head declaration of our function that saves our current activites to the activity file. */  

#endif