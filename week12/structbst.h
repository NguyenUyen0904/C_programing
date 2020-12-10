#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct name {
  char firstName[20];
  char middleName[20];
  char lastName[20];
};
typedef struct name elmtype;

struct nodeType {
  elmtype element;
  struct nodeType *left, *right;
};
typedef struct nodeType nodetype;



elmtype nameToData( char* input) {
  char *s[3];
  char *tmp;
  int i = 0;
  tmp = strtok(input, " ,.-");
  while( tmp != NULL ) {
    s[i] = tmp;
    tmp = strtok(NULL, " ,.-");
    ++i;
  }
  elmtype newdata;
  strcpy(newdata.firstName, s[0]);
  strcpy(newdata.middleName, s[1]);
  strcpy(newdata.lastName, s[2]);
  return newdata;
}

int compareData(elmtype a, elmtype b) {
  int first = strcmp(a.firstName, b.firstName);
  int middle = strcmp(a.middleName, b.middleName);
  int last = strcmp(a.lastName, b.lastName);
  if( first < 0 ) return -1;
  else if (first  > 0 ) return 1;
  else {
    if( middle < 0 ) return -1;
    else if( middle > 0 ) return 1;
    else {
      if( last < 0 ) return -1;
      else if( last > 0 ) return 1;
      else return 0;
    }
  }
}

int emptyTree(nodetype* T) {
  return T == NULL;
}

nodetype* leftChild(nodetype* n) {
  if( n != NULL ) return n->left;
  else return NULL;
}

nodetype* rightChild(nodetype* n) {
  if( n != NULL ) return n->right;
  else return NULL;
}

nodetype* createNode(elmtype data) {
  nodetype* newnode = (nodetype*)malloc(sizeof(nodetype));
  if( newnode != NULL ) {
    newnode->left = NULL;
    newnode->right = NULL;
    strcpy(newnode->element.firstName, data.firstName);
    strcpy(newnode->element.middleName, data.middleName);
    strcpy(newnode->element.lastName, data.lastName);
  }
  return newnode;
}

int isLeaf( nodetype* n) {
  if( n != NULL ) {
    return (leftChild(n) == NULL ) && (rightChild(n) == NULL );
  }
  else return -1;
}

int nb_nodes(nodetype* T) {
  if( emptyTree(T) ) return 0;
  else return 1 + nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}

nodetype* createFrom2(elmtype v, nodetype* l, nodetype* r) {
  nodetype* tree = (nodetype*)malloc(sizeof(nodetype));
  tree->element = v;
  tree->left = l;
  tree->right = r;
  return tree;
}

nodetype* addLeft(nodetype* tree, elmtype data) {
  nodetype* newnode = createNode(data);
  nodetype* leftNode = tree;
  if( newnode == NULL ) return newnode;
  if( tree == NULL ) return tree = newnode;
  else {
    while( leftNode->left != NULL ) leftNode = leftNode->left;
  }
  leftNode->left = newnode;
  return tree;
}

nodetype* addRight(nodetype* tree, elmtype data) {
  nodetype* newnode = createNode(data);
  nodetype* rightNode = tree;
  if( newnode == NULL ) return newnode;
  if( tree == NULL ) return tree = newnode;
  else {
    while( rightNode->right != NULL ) rightNode = rightNode->right;
  }
  rightNode->right = newnode;
  return tree;
}

void display( nodetype* tree) {
  if( tree != NULL ) {
  display(tree->left);
  printf("%s %s %s\n", tree->element.firstName,tree->element.middleName, tree->element.lastName );
  display(tree->right);
  }
}

nodetype* insertNode(nodetype* tree, elmtype data) {
  if( tree == NULL ) {
    return createNode(data);
  }
  int compare = compareData(tree->element, data);
  if( compare > 0 ) tree->left = insertNode(tree->left, data);
  else if( compare < 0 ) tree->right = insertNode(tree->right, data);
  return tree;
}

nodetype* search(nodetype* tree, char* last) {
  if (tree == NULL) return NULL;
  int compare = strcmp(tree->element.lastName, last);
  if( compare == 0 ) return tree;
  else if( compare > 0 ) return search(tree->right, last);
  else return search(tree->left, last);
}

elmtype deleteMin(nodetype* n) {
  elmtype newnode;
  if( n->left == NULL ) {
    strcpy(newnode.firstName, n->element.firstName);
    strcpy(newnode.middleName, n->element.middleName);
    strcpy(newnode.lastName, n->element.lastName);
    n = n->right;
    return newnode;
  }
  else return deleteMin(n->left);
}

void deleteNode(nodetype* tree, elmtype data ) {
  if (tree != NULL ) {
    int compare = compareData(tree->element, data);
    if( compare > 0 ) {
      deleteNode(tree->left, data);
    }
    else if( compare < 0 ) deleteNode(tree->right, data);
    else if( tree->left == NULL ) {
      tree = tree->right;
    }
    else if(tree->right == NULL ) {
      tree = tree->left;
    }
    else {
      elmtype deletedData = deleteMin(tree->right);
      strcpy(tree->element.firstName, deletedData.firstName);
      strcpy(tree->element.middleName, deletedData.middleName);
      strcpy(tree->element.lastName, deletedData.lastName);
    }
  }
}

void freetree(nodetype* tree) {
  if( tree != NULL ) {
    freetree(tree->left);
    freetree(tree->right);
    free((void*)tree);
  }
}
