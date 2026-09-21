#include <stdio.h>
#include <string.h>

#define MAX 100

char history[MAX][100];
int top = -1;

/* Check whether stack is empty */
int isEmpty()
{
    return top == -1;
}

/* Add a website to the stack */
void push(char url[])
{
    if (top == MAX - 1)
    {
        printf("History is full. better luck next time, or approach fiza \n");
        return;
    }

    top++;
    strcpy(history[top], url);

    printf("Website visited successfully.\n");
}

/* Remove the current website */
void pop()
{
    if (isEmpty())
    {
        printf("No history to go back.bad luck\n");
        return;
    }

    printf("Going back from: %s\n . bye byeee", history[top]);
    top--;
}

/* Show the current page */
void peek()
{
    if (isEmpty())
    {
        printf("No current page .bad movee\n");
        return;
    }

    printf("Current Page: %s\n", history[top]);
}

/* Display all browsing history */
void showHistory()
{
    int i;

    if (isEmpty())
    {
        printf("History is empty.better luck next time\n");
        return;
    }

    printf("\n===== Browser History =====\n");

    for (i = top; i >= 0; i--)
    {
        printf("%s\n", history[i]);
    }
}

int main()
{
    int choice;
    char url[100];

    while (1)
    {
        printf("\n===== Browser History =====\n");
        printf("1. Visit Website\n");
        printf("2. Go Back\n");
        printf("3. Show Current Page\n");
        printf("4. Show History\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter website URL: ");
                scanf("%s", url);
                push(url);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                showHistory();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
