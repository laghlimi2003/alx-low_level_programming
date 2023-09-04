#include <stdlib.h>
#include <stdio.h>

static int count_words(char *str) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            count++;
        }
        str++;
    }

    return count;
}

static char *strdup_word(char *start, char *end) {
    int len = end - start;
    char *word = (char *)malloc(len + 1);
    
    if (word == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        word[i] = start[i];
    }

    word[len] = '\0';
    return word;
}

char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    int num_words = count_words(str);
    char **word_array = (char **)malloc((num_words + 1) * sizeof(char *));

    if (word_array == NULL) {
        return NULL;
    }

    int in_word = 0;
    char *word_start = NULL;
    int word_index = 0;

    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            if (in_word) {
                word_array[word_index] = strdup_word(word_start, str);
                if (word_array[word_index] == NULL) {
                    // Memory allocation failed
                    for (int i = 0; i < word_index; i++) {
                        free(word_array[i]);
                    }
                    free(word_array);
                    return NULL;
                }
                word_index++;
                in_word = 0;
            }
        } else if (in_word == 0) {
            in_word = 1;
            word_start = str;
        }
        str++;
    }

    if (in_word) {
        word_array[word_index] = strdup_word(word_start, str);
        if (word_array[word_index] == NULL) {
            // Memory allocation failed
            for (int i = 0; i <= word_index; i++) {
                free(word_array[i]);
            }
            free(word_array);
            return NULL;
        }
        word_index++;
    }

    word_array[word_index] = NULL;
    return word_array;
}

int main(void) {
    char **tab;

    tab = strtow("      ALX School         #cisfun      ");
    if (tab == NULL) {
        printf("Failed\n");
        return 1;
    }

    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s$\n", tab[i]);
        free(tab[i]); // Free the allocated words
    }

    free(tab); // Free the array of pointers
    return 0;

