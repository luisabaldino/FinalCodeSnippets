class TreeNode{
public:
  TreeNode();
  TreeNode(int k);
  //TreeNode(int k, <type> v);
  ~TreeNode();
  //Virtual ~Treenode(); - when working w a template class (look this up)

  int key;
  TreeNode *left;
  TreeNode *right;
};

//TreeNode Implementation
TreeNode::TreNode(){
  key = 0;
  left = NULL;
  right = NULL;
}
TreeNode::TreeNode(intk k){
  key = k;
  left = NULL;
  right = NULL;
}
TreeNode::~TreeNode(){
  //look this up
}
