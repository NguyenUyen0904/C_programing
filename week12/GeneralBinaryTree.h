typedef  … elmType;
typedef struct nodeType
{
    elmType element;
    struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;

void MakeNullTree(treetype *T)
{
    (*T) = NULL;
}
int EmptyTree(treetype T)
{
    return T == NULL;
}
treetype LeftChild(treetype n)
{
    if (n != NULL)
        return n->left;
    else
        return NULL;
}
treetype RightChild(treetype n)
{
    if (n != NULL)
        return n->right;
    else
        return NULL;
}
node_type *create_node(elmtype NewData)
{
    node_type *N;
    N = (node_type *)malloc(sizeof(node_type));
    if (N != NULL)
    {
        N->left = NULL;
        N->right = NULL;
        N->element = NewData;
    }
    return N;
}

int IsLeaf(treetype n)
{
    if (n != NULL)
        return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
    else
        return -1;
}

int nb_nodes(treetype T)
{
    if (EmptyTree(T))
        return 0;
    else
        return 1 + nb_nodes(LeftChild(T)) +
               nb_nodes(RightChild(T));
}
treetype createfrom2(elmtype v, treetype l, treetype r)
{
    treetype N;
    N = (node_type *)malloc(sizeof(node_type));
    N->element = v;
    N->left = l;
    N->right = r;
    return N;
}
treetype Add_Left(treetype *Tree, elmtype NewData)
{
    node_type *NewNode = Create_Node(NewData);
    if (NewNode == NULL)
        return (NewNode);
    if (*Tree == NULL)
        *Tree = NewNode;
    else
    {
        node_type *Lnode = *Tree;
        while (Lnode->left != NULL)
            Lnode = Lnode->left;
        Lnode->left = NewNode;
    }
    return (NewNode);
}
treetype Add_Right(treetype *Tree, elmtype NewData)
{
    node_type *NewNode = Create_Node(NewData);
    if (NewNode == NULL)
        return (NewNode);
    if (*Tree == NULL)
        *Tree = NewNode;
    else
    {
        node_type *Rnode = *Tree;
        while (Rnode->right != NULL)
            Rnode = Rnode->right;
        Rnode->right = NewNode;
    }
    return (NewNode);
}
