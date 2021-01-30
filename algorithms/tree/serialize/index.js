//
//
//              __ 100 __
//             /         \
//         50              150
//       /    \          /     \
//     25      75      125     175
//    /  \
//  15   30
//
//

function BST(v) {
    this.root = this.node(v);
}

BST.prototype = Object.create(null);

BST.prototype.node = function (v) {
    return {
        val: v,
        left: null,
        right: null
    };
};

BST.prototype.insert = function (v) {
    let node = this.root;

    while (node) {
        if (v < node.val) {
            if (!node.left) return node.left = this.node(v);
            else node = node.left;
        } else {
            if (!node.right) return node.right = this.node(v);
            else node = node.right;
        }
    }
};

BST.prototype.inorder = function (node = this.root/*, v = []*/) {
    if (!node) return [];

    const s = [];
    const v = [];
    let curr = node;

    while (curr || s.length) {
        while (curr) {
            s.push(curr);
            curr = curr.left;
        }

        curr = s.pop();
        v.push(curr.val);
        curr = curr.right;
    }

    return v;
};

/* ----------------------------------------------------------- */
/* ----------------------------------------------------------- */

const tree = new BST(100);

tree.insert(150);
tree.insert(50);
tree.insert(25);
tree.insert(75);
tree.insert(125);
tree.insert(175);
tree.insert(15);
tree.insert(30);

console.log('  inorder', tree.inorder());

