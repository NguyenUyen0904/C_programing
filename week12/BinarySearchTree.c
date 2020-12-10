typedef struct Node
{
    int data;
    Node *left;
    Node *right;
} node_t;

void Free(node_t *root) // hàm giải phóng cây
{
    if (root == NULL)
        return;
    Free(root->left);
    Free(root->right);
    Free(root);
}
//Hàm điều hướng của  cây nhị phân tìm kiếm
int LeftOf(const int value, const node_t *root)
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value < root->data;
    //    return value <= root->data;
}

int RightOf(const int value, const node_t *root)
{
    return value > root->data;
}
// thêm giá trị vào
node_t *Insert(node_t *root, const int value)
{
    if (root == NULL)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if (LeftOf(value, root))
        root->left = Insert(root->left, value);
    else if (RightOf(value, root))
        root->right = Insert(root->right, value);
    return root;
}
// Hàm tìm kiếm
bool Search(const node_t *root, int value)
{
    if (root == NULL)
        return false;
    if (root->data == value)
    {
        return true;
    }
    else if (LeftOf(value, root))
    {
        return Search(root->left, value);
    }
    else if (RightOf(value, root))
    {
        return Search(root->right, value);
    }
}
//Hàm lấy giá trị
int LeftMostValue(const node_t *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
node_t *Delete(node_t *root, int value)
{
    if (root == NULL)
        return root;
    if (LeftOf(value, root))
        root->left = Delete(root->left, value);
    else if (RightOf(value, root))
        root->right = Delete(root->right, value);
    else
    {
        // root->data == value, delete this node
        if (root->left == NULL)
        {
            node_t *newRoot = root->right;
            free(root);
            return newRoot;
        }
        if (root->right == NULL)
        {
            node_t *newRoot = root->left;
            free(root);
            return newRoot;
        }
        root->data = LeftMostValue(root->right);
        root->right = Delete(root->right, root->data);
    }
    return root;
}