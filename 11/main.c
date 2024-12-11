#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 100

typedef struct {
    unsigned long key;
    unsigned long count;
} HashMapEntry;

typedef struct {
    HashMapEntry *entries;
    int size;
    int capacity;
} HashMap;

HashMap *create_hash_map() {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    if (map == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    map->entries = (HashMapEntry *)malloc(INITIAL_CAPACITY * sizeof(HashMapEntry));
    if (map->entries == NULL) {
        printf("Memory allocation failed\n");
        free(map);
        exit(EXIT_FAILURE);
    }
    map->size = 0;
    map->capacity = INITIAL_CAPACITY;
    return map;
}

void free_hash_map(HashMap *map) {
    if (map) {
        free(map->entries);
        free(map);
    }
}

int find_entry(HashMap *map, unsigned long key) {
    for (int i = 0; i < map->size; ++i) {
        if (map->entries[i].key == key) {
            return i;
        }
    }
    return -1;
}

void increment_or_set_default(HashMap *map, unsigned long key, unsigned long default_increment) {
    int index = find_entry(map, key);
    if (index != -1) {
        map->entries[index].count += default_increment;
    } else {
        if (map->size == map->capacity) {
            map->capacity *= 2;
            map->entries = (HashMapEntry *)realloc(map->entries, map->capacity * sizeof(HashMapEntry));
            if (map->entries == NULL) {
                printf("Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
        map->entries[map->size].key = key;
        map->entries[map->size].count = default_increment;
        map->size++;
    }
}

int even_digits(unsigned long number) {
    char buffer[20];
    sprintf(buffer, "%lu", number);
    size_t digit_count = strlen(buffer);
    return (digit_count % 2 == 0);
}

unsigned long* split(unsigned long number) {
    char buffer[20];
    sprintf(buffer, "%lu", number);
    size_t digit_count = strlen(buffer);

    unsigned long *result = malloc(2 * sizeof(unsigned long));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    size_t mid = digit_count / 2;
    char left[10], right[10];

    strncpy(left, buffer, mid);
    left[mid] = '\0';
    strncpy(right, buffer + mid, digit_count - mid);
    right[digit_count - mid] = '\0';

    result[0] = strtoul(left, NULL, 10);
    result[1] = strtoul(right, NULL, 10);
    return result;
}

HashMap* step(HashMap *map) {
    HashMap *new_map = create_hash_map();
    for (int i = 0; i < map->size; ++i) {
        if (map->entries[i].key == 0) {
            increment_or_set_default(new_map, 1, map->entries[i].count);
        } else if (even_digits(map->entries[i].key)) {
            unsigned long *res = split(map->entries[i].key);
            if (res != NULL) {
                increment_or_set_default(new_map, res[0], map->entries[i].count);
                increment_or_set_default(new_map, res[1], map->entries[i].count);
                free(res);
            }
        } else {
            increment_or_set_default(new_map, map->entries[i].key * 2024, map->entries[i].count);
        }
    }
    return new_map;
}

unsigned long sum(HashMap *map) {
    unsigned long total = 0;
    for (int i = 0; i < map->size; ++i) {
        total += map->entries[i].count;
    }
    return total;
}

int main() {
    HashMap *map = create_hash_map();

    unsigned long capacity = 10;
    unsigned long *list = malloc(sizeof(unsigned long) * capacity);
    if (list == NULL) {
        printf("Memory allocation failed\n");
        free_hash_map(map);
        exit(EXIT_FAILURE);
    }

    for (unsigned long i = 0; i < capacity; i++) {
        if (scanf("%lu", &list[i]) != 1) {
            break;
        }
        increment_or_set_default(map, list[i], 1);
    }

    HashMap *current_map = map;
    for (int i = 0; i < 75; ++i) {
        HashMap *new_map = step(current_map);
        if (i != 0) {
            free_hash_map(current_map);
        }
        
        current_map = new_map;
        if(i == 24){
            unsigned long total = sum(new_map);
            printf("Total after 25 steps: %lu\n", total);
        }
    }

    unsigned long total = sum(current_map);
    printf("Total after 75 steps: %lu\n", total);

    free_hash_map(current_map);
    free(list);

    return 0;
}
