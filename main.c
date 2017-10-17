///\file main.c
///\brief Our main file where we can find our menu and the decisions.
///

#include "header.h"


/*! \fn void main
	\brief This is our main function where we can find the menu and the loop that forces the user to choose an option along with the function calling for the option selected.
*/

int main() {


    struct activity *activity = malloc (sizeof (struct activity));
    activity->next = NULL;
    unsigned int decision;
    float decision_1;
    char decision_2[100];

    while (1) {
        printf ("\n\n\t Menu");
        printf ("\n1.Add an activity.");
        printf ("\n2.Delete an activity.");
        printf ("\n3.Calculate activities in order to have 0 intake.");
        printf ("\n4.Print all activities.");
        printf ("\n5.Load activities from file.");
        printf ("\n6.Save current activities to activities file.");
        printf ("\n7.Exit.");
        printf ("\n\nChose your option: ");
        scanf ("%d", &decision);

        switch (decision) {

            case 1:
                printf ("\nEnter the name of the activity: ");
                scanf (" %100[^\n]", decision_2);
                printf ("\nEnter the intake calories of the activity: ");
                scanf ("%f", &decision_1);
                add_activity (activity, decision_2, decision_1);
                break;
            case 2:
                printf ("\nEnter the name of the activity you want to delete: ");
                scanf (" %100[^\n]", decision_2);
                delete_activity (activity, decision_2);
                break;
            case 3:
                calculate_intake_zero (activity);
                break;
            case 4:
                print_all (activity);
                break;
            case 5:
                load_activities (activity);
                break;
            case 6:
                save_to_file (activity);
                break;
            case 7:
                return 0;
                break;
        }
    }


}
