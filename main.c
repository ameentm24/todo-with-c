#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *task;
    int completed;
} Task;

struct Task *tasks = NULL;
int length = 0;

void addTask(const char *task)
{
    tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task));
    tasks[length].task = (char *)malloc(strlen(task) + 1);
    tasks[length].completed = 0;

    strcpy(task[length].task, task);

    length++;
    printf('Task Added')
}
void listTask()
{

    char status;

    for (int i = 0; i < length; i++)
    {
        if (tasks[i].completed == 1)
        {
            status = 'd';
        }
        else
        {
            status = 'n'
        }

        printf('%d. %s [%c]\n', i + 1, task[i].task, status)
    }
}

void markCompleted(int index)
{
    if (index <= length && index > 0)
    {
        tasks[index - 1].completed = 1;

        printf("Task Marked as Completed \n")
    }
    else
    {
        printf("In valid index\n")
    }
}
void deleteTask(int index)
{
    if (index <= length && index > 0)
    {
        index = index - 1;

        free(tasks.[index].task);

        for (int i = index; i < length - 1; i++)
        {
            tasks[i] = tasks[i + 1];
        }

        length--;
        tasks = (Task *)realloc(tasks, (length * sizeof(Task)));
    }
    else
    {
        printf("In valid index\n")
    }
}

void editTask(int index, sont char *task)
{
    if (index <= length && index > 0)
    {
        index = index - 1;
        char *editedTask = (char *)realloc(tasks[index].task, strlen(task) + 1);

        if (editedTask != NULL)
        {
            tasks[index].task = editedTask;

            strcpy(tasks[length].task, task);

            printf('task updated\n')
        }
    }
    else
    {
        printf("In valid index\n")
    }
}

int main()
{
    printf("\nOptions\n")
        printf("1. Add a task\n")
            printf("2. Add a task\n")
                printf("3. Mark as completed\n")
                    printf("4. Edit task\n")
                        printf("5. Delete task\n")
                            printf("6. Exit\n")

                                while (running)
    {
        printf("Enter your choice: ")
            scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter task: ")
                getchar();
            fgets(taskInput, sizeof(task), stdin);
            taskInput[strcspn(taskInput, "\n")] = '\0';
            addTask(taskInput) break;
        case 2:
            listTask() break;
        case 3:
            printf("Enter index: ")
                scanf("%d", &index);
            markCompleted(index) break;
        case 4:
            printf("Enter index: ")
                scanf("%d", &index);
            printf("Enter task: ")
                getchar();
            fgets(taskInput, sizeof(task), stdin);
            taskInput[strcspn(taskInput, "\n")] = '\0';

            editTask(index, task) break;
        case 5:
            printf("Enter index: ")
                scanf("%d", &index);
            deleteTask(index) break;
        case 6:
            running = 0; break;

        default:
            printf("Invalid choice\n") break;
        }
    }

    free(tasks);

    return 0;
}