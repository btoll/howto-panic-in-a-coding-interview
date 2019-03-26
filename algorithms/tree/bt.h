struct tree {
    struct tree_node *root;
    size_t count;
};

struct tree_node {
    int val;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree *make_tree(int nodes[]);
struct tree_node* create_tree_node(int v);
struct tree_node* add(struct tree_node *root, int v);
void preorder(struct tree_node* n);
void inorder(struct tree_node* n);
void postorder(struct tree_node* n);

