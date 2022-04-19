#include <stdio.h>
#include "Hashtable.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int64_t hash(char* key) {
    char* c;
    // chose any largePrime
    const int64_t largePrime = 7879;
    int sum = 0;
    int position = 1;
    for (c = key; *c != '\0'; c++) {
        int64_t value = *c * position;
        sum += value;
        position += 13;   // any value
    }
    return sum * largePrime;
}



Hashtable CreateHashtable(int num_buckets) {
    Hashtable ht = (Hashtable)malloc(sizeof(struct hashtableInfo));
    if (ht == NULL) {
        return NULL;
    } else {
        ht->num_buckets = num_buckets;
        ht->num_elements = 0;
        ht->buckets = (LinkedList*)malloc(sizeof(LinkedList) * num_buckets);
        int i;
        for (i = 0; i < num_buckets; i++) {
            ht->buckets[i] = NULL;
        }
        return ht;
  }
}



int NumElemsInHashtable(Hashtable ht) {
    return ht->num_elements;
}


void DestroyHashtable(Hashtable ht) {
    int i;
    for (i = 0; i < ht->num_buckets; i++) {
        if (ht->buckets[i] != NULL) {
            // iterate the data in buckets
            LinkedListNodePtr curr = ht->buckets[i]->head;
            while (curr != NULL) {
                HTKeyValuePtr anagram_data = (HTKeyValuePtr)curr->data;
                LinkedList anagrams_list = anagram_data->value;
                // free key and value
                DestroyLinkedList(anagrams_list);
                free(anagram_data->key);
                curr = curr->next;
           }
           DestroyLinkedList(ht->buckets[i]);
        }
    }
    free(ht->buckets);
    free(ht);
}


// helper function thant check whether the key in the hashtable(sorted_word)
// bucket_number is the hash location in buckets
int ContainsKey(Hashtable ht, int64_t bucket_number, char* sorted_word) {
    if (ht->buckets[bucket_number] != NULL) {
        // iterate the linked list
        LinkedListNodePtr curr = ht->buckets[bucket_number]->head;
        while (curr != NULL) {
            // get the data
            HTKeyValuePtr anagram_data = (HTKeyValuePtr)curr->data;
            // if the key equals to the given sorted word
            if (strcmp(anagram_data->key, sorted_word) == 0) {
                return 1;
            }
            curr = curr->next;
        }
    }
  return 0;  // otherwise return 0
}


// helper function check whether the given word in the linked list
int InList(LinkedList anagram_list, char* word) {
    // iterate the linked list
    LinkedListNodePtr curr = anagram_list->head;
    while (curr != NULL) {
        // detected the same data in the linked list
        if (strcmp((char*)curr->data, word) == 0) {
      return 1;
    }
    curr = curr->next;
  }
  return 0;
}


void PutInHashtable(Hashtable ht, char* sorted_word, char* word) {
    // calculate the hash location
    int64_t bucket_number = hash(sorted_word) % ht->num_buckets;
    // if we have the key in the hash table
    if (ContainsKey(ht, bucket_number, sorted_word)) {
        // iterate the linkedlist buckets
        LinkedListNodePtr curr = ht->buckets[bucket_number]->head;
        while (curr != NULL) {
            HTKeyValuePtr anagram_data = (HTKeyValuePtr)curr->data;
            LinkedList anagrams = anagram_data->value;
            // if the anagram_data has the correct key
            // and do not have this word, put into the linked list
            if ((strcmp(anagram_data->key, sorted_word) == 0)
                && !(InList(anagrams, word))) {
                char* anagram =
                (char*)malloc(sizeof(*word) * (strlen(word) + 1));
                strncpy(anagram, word, strlen(word) + 1);
                InsertLinkedList(anagrams, anagram);
            }
            curr = curr->next;
        }
    } else {   // if hash table doesnt have the given sorted_word as key
               // or NULL at the given bucket
        if (ht->buckets[bucket_number] == NULL) {
            ht->buckets[bucket_number] = CreateLinkedList();
        }
        // create the key
        HTKeyValuePtr anagram_data = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));
        char* anagram_key =
        (char*)malloc(sizeof(*sorted_word) * (strlen(sorted_word) + 1));
        strncpy(anagram_key, sorted_word, strlen(sorted_word) + 1);
        anagram_data->key = anagram_key;
        // create the value
        LinkedList anagrams = CreateLinkedList();
        anagram_data->value = anagrams;
        char* anagram = (char*)malloc(sizeof(*word) * (strlen(word) + 1));
        strncpy(anagram, word, strlen(word) + 1);
        InsertLinkedList(anagrams, anagram);
        ht->num_elements += 1;
        InsertLinkedList(ht->buckets[bucket_number], anagram_data);
    }
}


LinkedList LookupInHashtable(Hashtable ht, char* key) {
    // get the location based on hash
    int bucket_number = hash(key) % ht->num_buckets;
    if (ht->buckets[bucket_number] != NULL) {
        // iterate the buckets
        LinkedListNodePtr curr = ht->buckets[bucket_number]->head;
        while (curr != NULL) {
        HTKeyValuePtr anagram_data = (HTKeyValuePtr)curr->data;
        if (strcmp(anagram_data->key, key) == 0) {
            // detect the same key, return value
            return anagram_data->value;
        }
        curr = curr->next;
        }
    }
    return NULL;
}


void PrintHashtable(Hashtable ht) {
    int i;
    for (i = 0; i < ht->num_buckets; i++) {  // iterate all the buckets
        printf("Bucket %d: ", i);
        if (ht->buckets[i] != NULL) {
        // iterate the specific bucket
            LinkedListNodePtr curr = ht->buckets[i]->head;
            printf("\n");
            while (curr != NULL) {
                HTKeyValuePtr anagram_data = (HTKeyValuePtr)curr->data;
                printf("\tkey: %s\tvalue: [", anagram_data->key);
                // iterate the value list
                LinkedListNodePtr value_curr = anagram_data->value->head;
                while (value_curr->next != NULL) {
                    char* anagram = (char*)value_curr->data;
                    printf("%s,", anagram);
                    value_curr = value_curr->next;
                }
            printf("%s],\n", (char*)value_curr->data);
            curr = curr->next;
            }
        } else {
            printf("NULL\n");
        }
    }
    printf("\n");
}

