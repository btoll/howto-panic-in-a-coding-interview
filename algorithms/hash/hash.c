#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

// Mostly taken from K&R, Chapter 6, page 145.

struct nlist* add(char *key, char *val) {
    unsigned hashval;
    struct nlist *n;

    if ((n = find(key)) == NULL) {
        n = (struct nlist *) malloc(sizeof(*n));

        if (n == NULL || (n->key = strdup(key)) == NULL)
            return NULL;

        hashval = hash(key);
        n->next = hashtab[hashval];
        hashtab[hashval] = n;
    } else
        free((void *) n->val);

    if ((n->val = strdup(val)) == NULL)
        return NULL;

    return n;
}

struct nlist* find(char *s) {
    for (struct nlist *n = hashtab[hash(s)]; n != NULL; n = n->next)
        if (strncmp(s, n->key, sizeof(*s) / sizeof(s[0])) == 0)
            return n;

    return NULL;
}

unsigned hash(char *s) {
    unsigned hashval = 0;

    while (*s)
        hashval += *s++ + 31 * hashval;

    return hashval % HASHSIZE;
}

int main(int argc, char **argv) {
    struct {
        char *key;
        char *val;
    } k[] = {
        "derp",
        "hello world",

        "herp",
        "goodbye cruel world",

        "weeeeeee",
        "pfffffft",

        "foo",
        "bar"
    };

    for (int i = 0; i < sizeof(k) / sizeof(k[0]); ++i)
        add(k[i].key, k[i].val);

    printf("%s\n", find("herp")->val);
}

