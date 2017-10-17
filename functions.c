///\file functions.c
///\brief File where we find all functions that are used in the main file.
///

#include "header.h"

/*! \fn void add_activity (struct activity *activity, char name[100], float intake)
    \brief Adds an activity to our linked list.
    \param activity is the linked list where we store our activities.
	\param name is the name of our activity.
	\param intake is the intake of calories from doing the activity.
*/

void add_activity (struct activity *activity, char name[100], float intake) {

    struct activity *iterator = activity;
    struct activity *newActivity = malloc (sizeof (struct activity));

    while (iterator->next != NULL)
        iterator = iterator->next;

    iterator->next = newActivity;
    newActivity->next = NULL;
    newActivity->intake = intake;
    strcpy(newActivity->name, name);
    if (intake > 0)
        G_TOTAL_INTAKE += intake;
    printf ("\nYour activity \"%s\" has been added to the list and total intake has been updated.", newActivity->name);
}

/*! \fn void delete_activity (struct activity *activity, char name[100])
    \brief Deletes an activity to our linked list.
    \param activity is the linked list from where we will delete the given activitiy.
	\param name is the name of our activity that will be deleted.
*/

void delete_activity (struct activity *activity, char name[100]) {

    struct activity *iterator = activity;
    struct activity *deleteActivity = malloc (sizeof (struct activity));

    while (iterator->next != NULL) {
        if (strcmp (iterator->next->name, name) == 0) {
            deleteActivity = iterator->next;
            iterator->next = iterator->next->next;
            free(deleteActivity);
            printf ("\nActivity \"%s\" successfully deleted.", name);
            return;
        }
        iterator = iterator->next;
    }
    printf ("\nGiven activity does not exists in activity.");


}

/*! \fn void print_all (struct activity *activity)
    \brief Prints all activites and their caloric intake to the console.
    \param activity is the linked list from where we take our data.
*/

void print_all (struct activity *activity) {

    unsigned int counter = 1;
    struct activity *iterator = activity;

    G_TOTAL_INTAKE = 0;
    printf ("\n\tActivities");

    while (iterator->next != NULL) {
        printf ("\n\nActivity %d", counter);
        printf ("\nName: %s", iterator->next->name);
        printf ("\nIntake: %.3f", iterator->next->intake);
        ++counter;
        if (iterator->next->intake > 0)
            G_TOTAL_INTAKE += iterator->next->intake;
        iterator = iterator->next;
    }

    printf ("\n\t You must burn %.3f calories if you want to have the intake 0.", G_TOTAL_INTAKE);



}

/*! \fn void calculate_intake_zero (struct activity *activity)
    \brief Prints all activites and their caloric and how many times user need to perform them in order to have 0 intake.
    \param activity is the linked list from where we take our data.
*/

void calculate_intake_zero (struct activity *activity) {

    float current_intake = 0;
    int counter;
    struct activity *iterator = activity;

    printf ("\nIn order for your intake to be approximately 0 you need to burn %.3f calories", G_TOTAL_INTAKE);

    while (iterator->next != NULL) {
        if (iterator->next->intake < 0) {
            current_intake = 0;
            counter = 0;
            while ( G_TOTAL_INTAKE - (- iterator->next->intake) >= current_intake ) {
                current_intake += -iterator->next->intake;
                counter++;
            }
            if (current_intake != G_TOTAL_INTAKE)
                printf ("\nYou can do \"%s\" activity which will burn %.3f calories so you need to do this activity %d times which will burn ~%.3f calories from a total of %.3f", iterator->next->name, -iterator->next->intake,counter, current_intake, G_TOTAL_INTAKE);
            else
                printf ("\nOne perfect activity for you is \"%s\" you need to do it %d times (%.3f calories burned per repetition) and you will burn all of your intake (%3.f).", iterator->next->name, counter, -iterator->next->intake, G_TOTAL_INTAKE);

        }
        iterator = iterator->next;
    }


}


/*! \fn void load_activities (struct activity *activity)
    \brief Loads activites from the activity file.
    \param activity is the linked list where we will save our data.
*/


void load_activities (struct activity *activity) {

    double intake;
    unsigned int counter = 0;
    char name[100];

    FILE *f = fopen ("load_activities.txt", "r");

    if (f == NULL) {
        printf ("\nError opening file!");
		return;
    }

    while (fscanf(f, "%100[^=]=%lf;\n", name, &intake) != EOF) {
        add_activity (activity, name, intake);
        ++counter;
    }

    fclose (f);

	if(counter > 0){
		printf ("\nLoaded %d activities successfully.", counter);
	} else {
		printf ("\nNo activity loaded from file.");
	}

}

/*! \fn void save_to_file (struct activity *activity)
    \brief Saves our activites and their intake to the activity file.
    \param activity is the linked list from where we will take our data to be saved.
*/


void save_to_file (struct activity *activity) {


    int counter = 0;
    struct activity *iterator = activity;

    FILE *f = fopen ("activities.txt", "w+");
    FILE *f2 = fopen ("load_activities.txt", "w+");

    if (f == NULL) {
        printf ("\nError saving to file!");
        return;
    }

    fprintf (f, "\tActivities");

    while (iterator->next != NULL) {
        ++counter;
        fprintf (f, "\n|\tActivity %d\t|", counter);
        fprintf (f, "\n|\tName: %s\t|", iterator->next->name);
        fprintf (f, "\n|\tIntake: %.3f calories\t|", iterator->next->intake);
        fprintf (f, "\n|||||||||||||||||||||||||||||||||");
        fprintf (f2, "%s=%f;\n", iterator->next->name, iterator->next->intake);
        iterator = iterator->next;
    }

    fclose (f);
    fclose (f2);

    printf ("\nYour activities has been saved to file \"activities.txt\".");

}
