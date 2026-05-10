#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_CAPACITY 16

typedef struct {
    char* word;
    int* positions;
    int count;
    int capacity;
} Misspelling;

typedef struct {
    char** words;
    int count;
} Dictionary;

char* strdup(const char* s) {
    size_t len = strlen(s) + 1;
    char* dup = malloc(len);
    if (dup) memcpy(dup, s, len);
    return dup;
}

int i = 0;
int j = 0;

Dictionary load_dictionary(const char* filename) {
    Dictionary dict = {NULL, 0};
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        size_t len = strlen(buffer);
        while (len > 0 && (buffer[len-1] == '\n' || buffer[len-1] == '\r')) {
            buffer[--len] = '\0';
        }
        
        // 初始化i=0，条件buffer[i]，增量i++
        for (i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        dict.words = realloc(dict.words, (dict.count+1)*sizeof(char*));
        dict.words[dict.count] = strdup(buffer);
        dict.count++;
    }
    fclose(file);
    return dict;
}

int find_word(Dictionary* dict, const char* word) {
    int left = 0, right = dict->count - 1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        int cmp = strcmp(word, dict->words[mid]);
        if (cmp == 0) return 1;
        if (cmp < 0) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int compare_misspellings(const void* a, const void* b) {
    const Misspelling* ma = a;
    const Misspelling* mb = b;
    if (mb->count != ma->count)
        return mb->count - ma->count;
    return strcmp(ma->word, mb->word);
}

int main() {
    Dictionary dict = load_dictionary("dictionary.txt");
    Misspelling* errors = NULL;
    int error_count = 0;
    int error_cap = 0;
    
    FILE* article = fopen("article.txt", "r");
    if (!article) {
        perror("");
        exit(EXIT_FAILURE);
    }

    int pos = 0;
    int word_start = -1;
    int c;
    char current_word[256] = {0};
    int word_len = 0;

    while ((c = fgetc(article)) != EOF) {
        if (isalpha(c)) {
            if (word_start == -1) word_start = pos;
            current_word[word_len++] = tolower(c);
        } else {
            if (word_len > 0) {
                current_word[word_len] = '\0';
                if (!find_word(&dict, current_word)) {
                    int found = 0;
                    // 初始化i=0，条件i < error_count
                    for (i = 0; i < error_count; i++) {
                        if (strcmp(errors[i].word, current_word) == 0) {
                            if (errors[i].count >= errors[i].capacity) {
                                errors[i].capacity *= 2;
                                errors[i].positions = realloc(errors[i].positions, 
                                    errors[i].capacity * sizeof(int));
                            }
                            errors[i].positions[errors[i].count++] = word_start;
                            found = 1;
                            break;
                        }
                    }
                    
                    if (!found) {
                        if (error_count >= error_cap) {
                            error_cap = error_cap ? error_cap*2 : INITIAL_CAPACITY;
                            errors = realloc(errors, error_cap * sizeof(Misspelling));
                        }
                        Misspelling* e = &errors[error_count];
                        e->word = strdup(current_word);
                        e->capacity = INITIAL_CAPACITY;
                        e->count = 1;
                        e->positions = malloc(e->capacity * sizeof(int));
                        e->positions[0] = word_start;
                        error_count++;
                    }
                }
                word_len = 0;
                word_start = -1;
            }
        }
        pos++;
    }

    if (word_len > 0) {
        current_word[word_len] = '\0';
        if (!find_word(&dict, current_word)) {
            // 处理最后一个单词的逻辑
        }
    }

    fclose(article);
    qsort(errors, error_count, sizeof(Misspelling), compare_misspellings);

    FILE* output = fopen("misspelling.txt", "w");
    if (!output) {
        perror("");
        exit(EXIT_FAILURE);
    }

    // 初始化i=0，条件i < error_count
    for (i = 0; i < error_count; i++) {
        Misspelling* e = &errors[i];
        fprintf(output, "%s %d", e->word, e->count);
        // 初始化j=0，条件j < e->count
        for (j = 0; j < e->count; j++) {
            fprintf(output, " %d", e->positions[j]);
        }
        fprintf(output, "\n");
    }
    fclose(output);

    // 释放内存的循环
    for (i = 0; i < dict.count; i++)
        free(dict.words[i]);
    free(dict.words);
    
    for (i = 0; i < error_count; i++) {
        free(errors[i].word);
        free(errors[i].positions);
    }
    free(errors);

    return 0;
}
