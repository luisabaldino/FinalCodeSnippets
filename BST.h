class BST{
public:
  BST();
  ~BST();
  //virtual ~BST()

  void insert (int value);
  bool search(int value);
  bool deleteNode(int k);

  bool isEmpty();
  TreeNode *getMin();
  TreeNode *getMax();

  TreeNode* getSuccessor(TreeNode *d);
  void printTree(TreeNode *d);

private:
  TreeNode *root;
};

BST::BST(){
  root = NULL; //empty tree
}

BST::~BST(){
  //diy
}

void BST::printTree(TreeNode *node){
  if(node == NULL) return;

  printTree(node->left);
  cout<< node->key << endl;
  printTree(node->right);
}

TreeNode* BST::getMax(){
  TreeNode *curr = root;

  if(root = NULL) return NULL;

  while (curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}

TreeNode* BST::getMin(){
  TreeNode *curr = root;

  if(root = NULL) return NULL;

  while (curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

bool BST::isEmpty(){
  return (root = NULL);
}

void BST::insert(int value){
  TreeNode *node = new TreeNode(value);

  if (isEmpty()){
    //empty tree
    root = node;
  } else{
    //not empty
    TreeNode *curr = root;
    TreeNode *parent;

    while (true){
      parent = curr;
      if(value < curr->key){
        curr = curr->left;
        if(curr == NULL){
          //leaf node = insertion point
          parent->left = node;
          break;
        }
      } else{
        curr = curr->right;
        if(curr == NULL){
          //insertion point
          parent->right = node;
          break;
        }
      }
    }
  }
}

bool BST::search(int value){
  if(isEmpty()) return false;
  else {
    //not an empty Tree
    TreeNode *current = root;
    while(current->key != value){
      if(value < current->key)
        current = current->left;
      else
        curent = current->right;

      if(current == NULL) return false;
    }
  }
  return true;
}

bool BST::deleteNode(int k){
  if (isEmpty()) return false;

  TreeNode *parent = root;
  TreeNode *curr = root;
  bool isLeft = true;

  //Find node
  while(curr->key != k){
    parent = curr;
    if (k < curr->key){
      isLeft = true;
      curr = curr->left;
    } else{
      isLeft = false;
      curr = curr->right;
    }
    if (curr == NULL) return false;
  }
  //Found value, proceed to delete

  if (curr->left == NULL && curr->right == NULL){
    //Then we have a leaf Treenode
    if (curr == root) root == NULL;
    else if (isLeft) parent->left = NULL;
    else parent->right = NULL;
  }

  else if (curr->right == NULL){
    //No right child, must have left child
    if (curr == root) {
      //Root with left child
      root = curr->left;
    } else if (isLeft){
      //Left node with left child
      parent->left = curr->left;
    } else {
      //Right node with left child
      parent->right = curr->left;
    }
  }

  else if (curr->left == NULL){
    //No left child, must have right child
    if (curr == root) {
      //Root with right child
      root = curr->right;
    } else if (isLeft){
      //Left node with right child
      parent->left = curr->right;
    } else {
      //Right node with right child
      parent->right = curr->right;
    }
  }

  else{
    //Two children
    TreeNode *successor = getSuccessor(current);

    if(curr==root) root = successor;
    else if (isLeft) parent->left = successor;
    else parent->right = successor;

    //connect/link successor to curent's (d) left children
    successor->left = curr->left;

  }

}

TreeNode* BST::getSuccessor(TreeNode *d){
  //d represents the node to be deleted

  TreeNode *curr = d->right;
  TreeNode *sp = d; //successor's parent
  TreeNode *successor = d;

  while (curr!=NULL){
    sp = successor;
    successor = curr;
    curr = curr->left;
  } 

  if(successor != d->right){
    sp->left = successor->right; //Point to null
    successor->right = d->right;
  }
  return successor;
}
