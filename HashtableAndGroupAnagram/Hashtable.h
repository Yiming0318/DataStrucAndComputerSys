/*
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  See <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#include "LinkedList.h"


#ifndef HASHTABLE_H
#define HASHTABLE_H


struct hashtableInfo {
	int num_buckets;
	int num_elements;
	LinkedList* buckets;
};

typedef struct hashtableInfo* Hashtable;





// Hashtables store key/value pairs.  We'll define a key to be an
// unsigned 64-bit integer; it's up to the customer to figure out how
// to produce an appropriate hash key, but below we provide an
// implementation of FNV hashing to help them out.  We'll define
// a value to be a (void *), so that customers can pass in pointers to
// arbitrary structs as values, but of course we have to worry about
// memory management as a side-effect.
typedef struct {
  char*   key;    // the key in the key/value pair
  LinkedList value;  // the value in the key/value pair
} HTKeyValue, *HTKeyValuePtr;


void PrintHashtable(Hashtable ht);

// Allocates and returns a new Hashtable.
//
// INPUT:
//   numBuckets: The number of buckets this hashtable will start with.
//
// Returns NULL if the hashtable was unable to be malloc'd, or
// the hashtable.
Hashtable CreateHashtable(int num_buckets);

// Destroys and Frees the hashtable.
//
// Input:
//   ht: the table to be free'd. It is unsafe to use the
//    hashtable after this is called.
void DestroyHashtable(Hashtable ht);

// Puts the given key value pair int the hashtable.
//
// INPUT:
//   ht: the hashtable to insert into
//   sorted_word: sorted word
//   word: original word
void PutInHashtable(Hashtable ht, char* sorted_word, char* word);

// Looks up the given key in the hashtable.
// Returns the value store original word, linkedlist.
//
// INPUT:
//   ht: the hashtable to lookup in
//   key: the key to lookup, sorted word
LinkedList LookupInHashtable(Hashtable ht, char* key);


// Gets the number of elements in the hashtable.
//
// INPUT:
//   ht: the Hashtable
//
// Returns the number of elements in the hashtable.
int NumElemsInHashtable(Hashtable ht);



// Computes an int from a string, to be used for a key in a HTKeyValue.
int64_t hash(char* key);

#endif  // HASHTABLE_H

