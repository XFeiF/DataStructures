#include<stdlib.h>
#include<stdio.h>

struct tree_el {
   int val;
   struct tree_el * right, * left;
};

typedef struct tree_el node;
node * curr, * root;
int size = 0;
int left_depth = 0;
int right_depth = 0;
int path[1000];
int ancestorPath[1000];

// Finds the size of the binary tree
int find_size(node * tree){
    if(tree->left){
        size++;
        find_size(tree->left);
    }
    if(tree->right){
        size++;
        find_size(tree->right);
    }
    return size + 1;
}

// Finds the maximum depth of the binary tree
int find_max_depth(node * tree){
	if(tree->left){
		left_depth++;
		find_max_depth(tree->left);
	}

	if(tree->right){
		right_depth++;
		find_max_depth(tree->right);
	}

	return ((left_depth > right_depth) ? left_depth : right_depth);
}

// In Order traversal
void print_inorder_traversal(node * tree) {
   if(tree->left) print_inorder_traversal(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) print_inorder_traversal(tree->right);
}

// Pre Order traversal
void print_preorder_traversal(node * tree) {
   printf("%d\n",tree->val);
   if(tree->left) {
	print_preorder_traversal(tree->left);
   }

   if(tree->right) {
    print_preorder_traversal(tree->right);
   }
}

// Post Order traversal
void print_postorder_traversal(node * tree) {
   if(tree->left) {
	print_postorder_traversal(tree->left);
   }

   if(tree->right) {
	print_postorder_traversal(tree->right);
   }

   printf("%d\n",tree->val);
}

// Finds the maximum element in the binary tree
int find_max(node *root)
{
	int leftVal, rightVal, rootVal, MAX = 0;
	if(root != NULL)
	{
		rootVal = root->val;
		leftVal = find_max(root->left);
		rightVal = find_max(root->right);
		if(leftVal > rightVal) MAX = leftVal;
		else MAX = rightVal;
		if(rootVal > MAX)
		MAX = rootVal;
	}
	return MAX;
}

// Recursively inserts elements into binary search tree
int insert(node ** tree, node * item) {
	if(!(*tree)) {
	  *tree = item;
	  return 0;
	}
	if(item->val<(*tree)->val){
		insert(&(*tree)->left, item);
	}
	else if(item->val>(*tree)->val){
		insert(&(*tree)->right, item);
	}
	return 0;
}

// Creates a binary search tree
void create_binary_search_tree(){
	int number = 0, counter = 0, how_many_elements = 0;
	printf("Enter how many elements: \n");
	scanf("%d", &how_many_elements);
	for(counter = 1; counter <= how_many_elements; counter++) {
		curr = (node *)malloc(sizeof(node));
		curr->left = curr->right = NULL;
		scanf("%d", &number);
		curr->val = number;
		insert(&root, curr);
	}
	printf("\nThe binary search tree is: \n");
	print_inorder_traversal(root);
}

// Finds an element in the binary tree
void find_element(node * tree, int value){
	if(tree->val == value)
    {
        printf("\nMatch found \n");
    }
    else if(tree->val < value)
    {
        if(tree->right)
        {
            find_element(tree->right, value);
        }
        else
        {
            printf("Match not found \n");
        }
    }
    else if(tree->val > value)
    {
        if(tree->left)
        {
            find_element(tree->left, value);
        }
        else
        {
            printf("Match not found \n");
        }
    }
}

// Utility that prints node's Ancestors
void printAncestors(int ancestorArray[], int length) {
  int i;
  for (i=length-1; i>=0; i--) {
    printf("%d ", ancestorArray[i]);
  }
  printf("\n");
}

// Utility that prints out a path on a line.
void printArray(int ints[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
}

//gets all the paths from root to leaf
void printPathsRecur(node * tree, int path[], int pathLen) {
  if (tree==NULL) return;

  // append this node to the path array
  path[pathLen] = tree->val;
  pathLen++;

  // it's a leaf, so print the path that led to here
  if (tree->left==NULL && tree->right==NULL) {
    printArray(path, pathLen);
  }
  else {
  // otherwise try both subtrees
    printPathsRecur(tree->left, path, pathLen);
    printPathsRecur(tree->right, path, pathLen);
  }
}

// Gets ancestors
void getNodeAncestors(node * tree, int ancestorPath[], int pathLength)
{
    if (tree==NULL) return;

    ancestorPath[pathLength] = tree->val;
    pathLength++;
    if(pathLength > 1)
    {
        printf("Ancestors:\n");
        printAncestors(ancestorPath, pathLength);
    }
    getNodeAncestors(tree->left, ancestorPath, pathLength);
    getNodeAncestors(tree->right, ancestorPath, pathLength);
}


int main(){
   int action_key = 0, search_element;
   do{
    printf("\n1: Create tree\n2: Find max\n3: Pre Order Traversal\n4: Post Order Traversal\n5: Get Size\n6: Get Maximum Depth\n7: Search Element\n8: Print all the paths\n9: Get Ancestors\n10: Get root\n\n");
    scanf("%d", &action_key);
	switch(action_key){
		case 1:
		    // creates binary search tree
			create_binary_search_tree();
			break;
		case 2:
			printf("\nThe maximum value in the tree is:");
			printf("%d\n", find_max(root));
			break;
		case 3:
		    printf("\nPre Order Traversal of the binary tree\n");
			print_preorder_traversal(root);
			break;
		case 4:
			printf("\nPost Order Traversal of the binary tree\n");
			print_postorder_traversal(root);
			break;
		case 5:
			printf("\nThe size of the binary tree is: ");
			printf("%d\n", find_size(root));
			break;
		case 6:
			printf("\nThe depth of the binary tree is: ");
			printf("%d\n", find_max_depth(root));
			break;
		case 7:
		    printf("\nEnter the element to be searched: ");
			scanf("%d", &search_element);
			find_element(root, search_element);
			break;
		case 8:
		    printf("\nGets all the paths from root to leaves: \n");
			printPathsRecur(root, path, 0);
			break;
		case 9:
		    printf("\nGets all the ancestors: \n");
			getNodeAncestors(root, ancestorPath, 0);
			break;
		case 10:
		    printf("\nGet the root of the binary tree: \n");
			printf("%d", root->val);
		default:
			break;
	}
   } while(action_key <= 15);
   getchar();
}
