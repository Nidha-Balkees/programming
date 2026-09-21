#include <stdio.h>
#include <string.h>

#define MAX 100

char history[MAX][100];
int top = -1;


// Check whether history is empty
int isEmpty()
{
    return top == -1;
}


// Visit a website
void push(char url[])
{
    if (top == MAX - 1)
    {
        printf("History is full.\n");
        return;
    }

    top++;
    strcpy(history[top], url);

    printf("Website visited successfully.\n");
}


// Go back to previous page
void pop()
{
    if (isEmpty())
    {
        printf("No history to go back.\n");
        return;
    }

    printf("Going back from: %s\n", history[top]);
    top--;
}


// Show current page
void peek()
{
    if (isEmpty())
    {
        printf("No current page.\n");
        return;
    }

    printf("Current Page: %s\n", history[top]);
}


// Show all browser history
void showHistory()
{
    int i;

    if (isEmpty())
    {
        printf("History is empty.\n");
        return;
    }

    printf("\n===== Browser History =====\n");

    for (i = top; i >= 0; i--)
    {
        printf("%s\n", history[i]);
    }
}


// Search for a URL in browser history
void searchHistory()
{
    char searchURL[100];
    int i;
    int count = 0;

    printf("Enter URL to search: ");
    scanf("%s", searchURL);

    for (i = 0; i <= top; i++)
    {
        if (strcmp(history[i], searchURL) == 0)
        {
            count++;
        }
    }

    if (count > 0)
    {
        printf("%s was visited %d time(s).\n", searchURL, count);
    }
    else
    {
        printf("%s was not found in history.\n", searchURL);
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
        printf("5. Search History\n");
        printf("6. Exit\n");

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
                searchHistory();
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}