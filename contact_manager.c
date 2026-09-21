#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact
{
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact contacts[MAX];
int count = 0;

/* Add Contact */
void addContact()
{
    if (count >= MAX)
    {
        printf("\nContact list is full!\n");
        return;
    }

    printf("\nEnter name: ");
    scanf(" %[^\n]", contacts[count].name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", contacts[count].phone);

    printf("Enter email: ");
    scanf(" %[^\n]", contacts[count].email);

    count++;

    printf("\nContact added successfully!\n");
}

/* List Contacts */
void listContacts()
{
    if (count == 0)
    {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\n===== Contact List =====\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nContact %d\n", i + 1);
        printf("Name  : %s\n", contacts[i].name);
        printf("Phone : %s\n", contacts[i].phone);
        printf("Email : %s\n", contacts[i].email);
    }
}

/* Search Contact */
void searchContact()
{
    char searchName[50];
    int found = 0;

    printf("\nEnter name to search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].name, searchName) == 0)
        {
            printf("\nContact Found!\n");
            printf("Name  : %s\n", contacts[i].name);
            printf("Phone : %s\n", contacts[i].phone);
            printf("Email : %s\n", contacts[i].email);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nContact not found.\n");
    }
}

/* Delete Contact */
void deleteContact()
{
    char deleteName[50];
    int found = 0;

    printf("\nEnter name to delete: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].name, deleteName) == 0)
        {
            for (int j = i; j < count - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }

            count--;
            found = 1;

            printf("\nContact deleted successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("\nContact not found.\n");
    }
}

/* Sort Contacts */
void sortContacts()
{
    int choice;

    if (count == 0)
    {
        printf("\nNo contacts available to sort.\n");
        return;
    }

    printf("\n===== Sort Contacts =====\n");
    printf("1. Sort by Name\n");
    printf("2. Sort by Phone Number\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            int shouldSwap = 0;

            if (choice == 1)
            {
                if (strcmp(contacts[j].name, contacts[j + 1].name) > 0)
                {
                    shouldSwap = 1;
                }
            }
            else if (choice == 2)
            {
                if (strcmp(contacts[j].phone, contacts[j + 1].phone) > 0)
                {
                    shouldSwap = 1;
                }
            }
            else
            {
                printf("\nInvalid sorting choice!\n");
                return;
            }

            if (shouldSwap)
            {
                struct Contact temp;

                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }

    printf("\nContacts sorted successfully!\n");

    if (choice == 1)
    {
        printf("Sorted by Name.\n");
    }
    else
    {
        printf("Sorted by Phone Number.\n");
    }
}

/* Main */
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== Contact Manager =====\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Sort Contacts\n");
        printf("6. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                listContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                sortContacts();
                break;

            case 6:
                printf("\nExiting Contact Manager\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}