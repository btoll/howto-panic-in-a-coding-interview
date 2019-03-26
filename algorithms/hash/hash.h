#define HASHSIZE   100

struct nlist {
    struct nlist *next;
    char *key;
    char *val;
};

static struct nlist *hashtab[HASHSIZE];

struct nlist* add(char *key, char *val);
struct nlist* find(char *s);
unsigned hash(char *s);

