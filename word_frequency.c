#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Word
{
    char word[50];
    int count;
};

int main()
{
    char sentence[500];
    char temp[50];

    struct Word words[100];

    int wordCount = 0;
    int i = 0;
    int j = 0;

    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);

    while (sentence[i] != '\0')
    {
        if (isalnum(sentence[i]))
        {
            temp[j] = tolower(sentence[i]);
            j++;
        }
        else
        {
            if (j > 0)
            {
                temp[j] = '\0';

                int found = 0;

                for (int k = 0; k < wordCount; k++)
                {
                    if (strcmp(words[k].word, temp) == 0)
                    {
                        words[k].count++;
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    strcpy(words[wordCount].word, temp);
                    words[wordCount].count = 1;
                    wordCount++;
                }

                j = 0;
            }
        }

        i++;
    }

    /* Handle the last word */
    if (j > 0)
    {
        temp[j] = '\0';

        int found = 0;

        for (int k = 0; k < wordCount; k++)
        {
            if (strcmp(words[k].word, temp) == 0)
            {
                words[k].count++;
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            strcpy(words[wordCount].word, temp);
            words[wordCount].count = 1;
            wordCount++;
        }
    }

    printf("\n===== Word Frequencies =====\n");

    for (i = 0; i < wordCount; i++)
    {
        printf("%-15s %d\n", words[i].word, words[i].count);
    }

    /* Find most frequent word */
    int max = 0;
    int maxIndex = 0;

    for (i = 0; i < wordCount; i++)
    {
        if (words[i].count > max)
        {
            max = words[i].count;
            maxIndex = i;
        }
    }

    printf("\nMost frequent word: %s\n", words[maxIndex].word);
    printf("Count: %d\n", words[maxIndex].count);
    printf("\nRepeated words:\n");

    int repeatedFound = 0;

    for (i = 0; i < wordCount; i++)
    {
        if (words[i].count > 1)
        {
            printf("%s -> %d\n", words[i].word, words[i].count);
            repeatedFound = 1;
        }
    }

    if (repeatedFound == 0)
    {
        printf("No repeated words found.\n");
    }
    return 0;
}