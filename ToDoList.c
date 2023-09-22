#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

struct Date {
    int year;
    int month;
    int day;
};

struct Task {
    char name[MAX_TITLE_LENGTH];
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct Date deadline;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

struct Date enterDate() {
    struct Date date;
    printf("Entrez l'année : ");
    scanf("%d", &date.year);
    printf("Entrez le mois : ");
    scanf("%d", &date.month);
    printf("Entrez le jour : ");
    scanf("%d", &date.day);
    return date;
}

void addTask() {
    if (taskCount < MAX_TASKS) {
        struct Task newTask;

        printf("Entrez le nom de la tâche : ");
        scanf("%s", newTask.name);
        printf("Entrez le titre de la tâche : ");
        scanf("%s", newTask.title);
        printf("Entrez la description de la tâche : ");
        scanf("%s", newTask.description);

        printf("Entrez la date limite de la tâche :\n");
        newTask.deadline = enterDate();

        tasks[taskCount] = newTask;
        taskCount++;
    } else {
        printf("Le nombre maximum de tâches a été atteint.\n");
    }
}

void displayDate(struct Date date) {
    printf("%d-%02d-%02d", date.year, date.month, date.day);
}

void displayAllTasks() {
    if (taskCount == 0) {
        printf("Aucune tâche à afficher.\n");
    } else {
        printf("\n--- Liste des tâches ---\n");
        for (int i = 0; i < taskCount; i++) {
            printf("Tâche %d :\n", i + 1);
            printf("Nom : %s\n", tasks[i].name);
            printf("Titre : %s\n", tasks[i].title);
            printf("Description : %s\n", tasks[i].description);
            printf("Date limite : ");
            displayDate(tasks[i].deadline);
            printf("\n-------------------------\n");
        }
    }
}

void deleteTask(int index) {
    if (index >= 0 && index < taskCount) {
        for (int i = index; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        printf("Tâche supprimée avec succès.\n");
    } else {
        printf("Index de tâche invalide.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n-- Menu --\n");
        printf("1. Ajouter une tâche\n");
        printf("2. Afficher toutes les tâches\n");
        printf("3. Supprimer une tâche\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayAllTasks();
                break;
            case 3:
                if (taskCount > 0) {
                    int index;
                    printf("Entrez l'indice de la tâche à supprimer : ");
                    scanf("%d", &index);
                    deleteTask(index - 1);
                } else {
                    printf("Aucune tâche à supprimer.\n");
                }
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 4);

    return 0;
}

