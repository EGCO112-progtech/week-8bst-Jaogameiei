// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );

/*void insertNode_R(TreeNodePtr * t,int value){
  if(t==NULL){
   t=new TreeNode;
	 if(t){
		t->leftPtr=NULL;
		t->rightPtr=NULL;
		t->data=value;
   }
  }
  else{
     if(t->data>=value) //left
     insertNode_R(&((*t)->leftPtr), value);   
     else //right
     insertNode_R(&((*t)->rightPtr), value); 
   }
}*/

void insertNode(BST *b, int value) {
   TreeNodePtr t = b->root, new_node;
   int inserted = 0;
   
   new_node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
   if (new_node) {
       new_node->leftPtr = NULL;
       new_node->rightPtr = NULL;
       new_node->data = value;
       
       /* First Node */
       if (!b->root) {
           b->root = new_node;
       }
       else {
           while (!inserted) {
               if (t->data >= value) {
                   if (t->leftPtr == NULL) {
                       t->leftPtr = new_node;
                       inserted = 1;
                   }
                   else {
                       t = t->leftPtr;
                   }
               }
               else {
                   if (t->rightPtr == NULL) {
                       t->rightPtr = new_node;
                       inserted = 1;
                   }
                   else {
                       t = t->rightPtr;
                   }
               }
           }  // end while
       }  // end else
       b->size++;
   }  // end if(new_node)
}  // end insertNode

void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void preOrder(TreeNodePtr treePtr) {
   if (treePtr != NULL) {
       printf("%3d", treePtr->data);  // print the value first
       preOrder(treePtr->leftPtr);    // then go left
       preOrder(treePtr->rightPtr);   // then go right
   }
}

void postOrder(TreeNodePtr treePtr) {
   if (treePtr != NULL) {
       postOrder(treePtr->leftPtr);    // traverse left subtree
       postOrder(treePtr->rightPtr);   // traverse right subtree
       printf("%3d", treePtr->data);   // print the value last
   }
}

void printTree(TreeNodePtr treePtr, int level) {
   if (treePtr != NULL) {
       // Traverse the right subtree first (reverse order)
       printTree(treePtr->rightPtr, level + 1);

       // Print the current node with indentation
       for (int i = 0; i < level; i++) {
           printf("   ");  // 4 spaces per level of indentation
       }
       printf("%d\n", treePtr->data);

       // Traverse the left subtree
       printTree(treePtr->leftPtr, level + 1);
   }
}
