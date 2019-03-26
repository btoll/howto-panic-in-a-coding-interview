struct queue {
    struct queue_node *head;
    struct queue_node *tail;
};

struct queue_node {
    struct tree_node *node;
    struct queue_node *next;
};


struct queue* create_queue();
struct queue_node* create_queue_node(struct tree_node *n);
struct tree_node* dequeue(struct queue *q);
struct queue* enqueue(struct queue *q, struct tree_node *n);

