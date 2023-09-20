#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

// Arrays to strore data
char TaskName[MAX_TASKS][50];
char TitelTask[MAX_TITLE_LENGTH][50];
char Description[MAX_DESCRIPTION_LENGTH][100];
int Deadline[MAX_TASKS][3];

int TaskNumbre = 0;

//Function to add Task
void	addTask(){
	if(TaskNumbre < MAX_TASKS && TaskNumbre < MAX_TITLE_LENGTH && TaskNumbre  < MAX_DESCRIPTION_LENGTH){

		printf("	Entrez le nom du task : ");
		scanf("%s" , TaskName[TaskNumbre]);
		printf("	Entrez le titre du task : ");
		scanf("%s" , TitelTask[TaskNumbre]);
		printf("	Entrez une discription du task : ");
		scanf("%s" , Description[TaskNumbre]);


		// Prompt for the deadline
		printf("	Enter the year for the deadline: ");
		scanf("%d", &Deadline[TaskNumbre][0]);
		printf("	Enter the month for the deadline: ");
		scanf("%d", &Deadline[TaskNumbre][1]);
		printf("	Enter the day for the deadline: ");
		scanf("%d", &Deadline[TaskNumbre][2]);

		TaskNumbre++;

	}else {
		printf("le nombre maximum de données a été atteint. \n");
	}
}
//Display Function

void displayAllTasks() {
    if (TaskNumbre == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\n------------------ Task List ------------------\n");
    for (int i = 0; i < TaskNumbre; i++) {
        printf("Task %d:\n", i + 1);
        printf("Name: %s\n", TaskName[i]);
        printf("Title: %s\n", TitelTask[i]);
        printf("Description: %s\n", Description[i]);
        printf("Deadline: %d-%02d-%02d\n", Deadline[i][0], Deadline[i][1], Deadline[i][2]);
        printf("----------------------------------------------\n");
    }
}




int main() {
    int choice;
    
    do {
        printf("\n	--------------------------------Menu--------------------------- :\n");
        printf("	1. Ajouter une nouvelle tâche\n");
        printf("	2. Afficher la liste de toutes les tâches\n");
        printf("	3. Trier les tâches par titre\n");
        printf("	4. Trier les tâches par deadline\n");
        printf("	5. Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
        printf("	6. Quitter\n");
        printf("	_____Entrez votre choix_____ : ");
        scanf("%d", &choice);
      
        
        switch (choice) {
            case 1:
              addTask();
                break;
            case 2:
                displayAllTasks();
                break;
            case 3:
               // sortByTitle();
                break;
            case 4:
              //  sortByDeadline();
                break;
            case 5:
               // displayTasksWithinThreeDays();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 6);

    return 0;
}

