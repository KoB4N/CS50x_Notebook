// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

unsigned int word_cnt = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word); // Get bucket index for word
    node *ptr = table[index];        // Set ptr to head of linked list

    while (ptr != NULL) // Traverse linked list
    {
        // Compare ptr->word with word
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true; // word found in dictionary
        }
        ptr = ptr->next; // Move ptr to next node
    }
    return false; // word not found
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash_value = 5381; // Accumulator initialized to a prime starting seed

    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = toupper(word[i]); // Force letter to uppercase for case-sensitivity
        hash_value = ((hash_value << 5) + hash_value) +
                     c; // Hash bit-shift formula: (hash_value * 33) + char
    }

    return hash_value % N; // Keep the returned index strictly within range [0, N - 1]
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *source = fopen(dictionary, "r"); // Open the dictionary file
    if (source == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1]; // Temporary buffer to store each word

    // Read each word in the file
    while (fscanf(source, "%s", buffer) != EOF)
    {
        // Add each word to the hash table
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(source);
            return false;
        }

        // Copy word into node and hash it
        strcpy(n->word, buffer);
        unsigned int index = hash(buffer);

        // Prepare node to head of target list
        n->next = table[index];
        table[index] = n;

        word_cnt++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_cnt;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Iterate over each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        // Set ptr to head of list at bucket i
        node *ptr = table[i];

        // Traverse linked list and free each node
        while (ptr != NULL)
        {
            node *tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }

    return true;
}