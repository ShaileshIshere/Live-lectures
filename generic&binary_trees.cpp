#include<iostream>
#include<queue>
#include<map>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Node* create_tree() {
    // cout << "enter your element here :-" << endl;
    // int data;
    // cin >> data;
    // // base case
    // if(data == -1) 
    //     return nullptr;
    // // create 1st node by ourself
    // Node* root = new Node(data);
    // // creation of left node
    // cout << "enter the element you want to insert in left part of the tree :-" << endl;
    // root->left = create_tree();
    // // creation of right node
    // cout << "enter the element you want to insert in right part of the tree :-" << endl;
    // root->right = create_tree();
    // return root;
// }

// void pre_order(Node* root) {
//     if(root == 0) 
//         return;
//     cout << root->data << " -> ";
//     pre_order(root->left);
//     pre_order(root->right);
// }

// void in_order(Node* root) {
//     if(root == 0) 
//         return;
//     in_order(root->left);
//     cout << root->data << " -> ";
//     in_order(root->right); 
// }

// void post_order(Node* root) {
//     if(root == 0)
//         return;
//     post_order(root->left);
//     post_order(root->right);
//     cout << root->data << " -> ";
// }

// fuddu level order traversal
// void level_order_traversal(Node* root) {
//   queue<Node*> q;
//   q.push(root);
//   while(!q.empty()) {
//     Node* front = q.front();
//     q.pop();
//     cout << front->data << " ";
//     if(front->left) 
//       q.push(front->left);
//     if(front->right)
//       q.push(front->right);
//   }
// }

// int max_depth(Node* root) {
//   // brute force
//   if(!root) 
//     return 0;
//   queue<Node*> q;
//   q.push(root);
//   q.push(nullptr);
//   int count = 1;
//   while(q.size() > 1) {
//     Node* front = q.front();
//     q.pop();
//     if(front) {
//       if(front->left) 
//         q.push(front->left);
//       if(front->right)
//         q.push(front->right);
//     }
//     else {
//       count++;
//       q.push(nullptr);
//     }
//   }
//   return count;
//   // optimized method
//   if(!root)
//     return 0;
//   int left_height = max_depth(root->left);
//   int right_height = max_depth(root->right);
//   int height = max(left_height, right_height)+1;
//   return height;
// }

// diameter of a binary tree
// brute force
// int diameter_of_a_binary_tree_1(Node* root) {
//   if(!root)
//     return 0;
//   int option_1 = diameter_of_a_binary_tree_1(root->left);
//   int option_2 = diameter_of_a_binary_tree_1(root->right);
//   int option_3 = max_depth(root->left) + max_depth(root->right);
//   int diameter = max(option_3, max(option_1, option_2));
//   return diameter;
// }
// optimized method
// pair<int, int> diameter_of_a_binary_tree_2(Node* root) {
//   if(!root) {
//     pair<int, int> p = make_pair(0, 0);
//     return p;
//   }
//   pair<int, int> left = diameter_of_a_binary_tree_2(root->left);
//   pair<int, int> right = diameter_of_a_binary_tree_2(root->right);
//   int op_1 = left.first;
//   int op_2 = right.first;
//   int op_3 = (left.second + right.second) +1;
//   pair<int, int> ans;
//   ans.first = max(op_1, max(op_2, op_3));
//   ans.second = max(left.second, right.second)+1;
//   return ans;
// }

// Node* LCA(Node* root, int p, int q) {
//   if(!root)
//     return nullptr;
//   if(root->data == p || root->data == q) 
//     return root;
//   Node* left_ans = LCA(root->left, p, q);
//   Node* right_ans = LCA(root->right, p, q);
//   if(!left_ans && !right_ans)
//     return nullptr;
//   else if(left_ans && !right_ans)
//     return left_ans;
//   else if(!left_ans && right_ans)
//     return right_ans;
//   else 
//     return root;
// }

// path sum 1
// bool path_sum_1(Node* root, int target_sum, int sum) {
//   if(!root)
//     return false;
//   sum += root->data;
//   if(!root->left && !root->right) {
//     if(sum == target_sum)
//       return true;
//     else    
//       return false;
//   }
//   bool left_ans = path_sum_1(root->left, target_sum, sum);
//   bool right_ans = path_sum_1(root->right, target_sum, sum);
//   return left_ans || right_ans;
// }

// path sum 2
// vector<vector<int>> path_sum_2(Node* root, int target_sum, vector<vector<int>> &ans, vector<int> temp, int sum) {
//   if(!root)
//     return ans;
//   sum += root->data;
//   temp.push_back(root->data);
//   if(!root->left && !root->right) {
//     if(sum == target_sum)
//       ans.push_back(temp);
//     else 
//       return ans;
//   }
//   path_sum_2(root->left, target_sum, ans, temp, sum);
//   path_sum_2(root->right, target_sum, ans, temp, sum);
//   return ans;
// }

// int kth_ancestor(Node* root, int &k, int node, int &ans) {
//   if(!root)
//     return 0;
//   if(root->data == node)
//     return root->data;
//   if(ans != 1)
//     return root->data;
//   int left = kth_ancestor(root->left, k, node, ans);
//   int right = kth_ancestor(root->right, k, node, ans);
//   if(!left && !right)
//     return 0;
//   k--;
//   if(k == 0) {
//     ans = root->data;
//     return ans;
//   }
//   return ans;
// }

// mast wala level order traversal
// void level_order_traversal(Node* root) {
//   queue<Node*> q;
//   q.push(root);
//   q.push(nullptr);
//   while(q.size() > 1) {
//     Node* front = q.front();
//     q.pop();
//     if(!front) {
//       cout << endl;
//       q.push(nullptr);
//     }
//     else {
//       cout << front->data << " ";
//       if(front->left)
//         q.push(front->left);
//       if(front->right) 
//         q.push(front->right);
//     }
//   }
// }

// this is the method to find the element in O(n) time
// int searchInorder(int inorder[], int size, int target){
//   for(int i=0; i<size; i++) {
//     if(inorder[i] == target) {
//       return i;
//     }
//   }
//   return -1;
// }

// this is the method to find the element in O(1) time
// void createMapping(int inorder[], int size, map<int,int> &valueToIndexMap) {
//     for(int i=0; i<size; i++) {
//       int element = inorder[i];
//       int index = i;
//       valueToIndexMap[element] = index;
//     }
// }

// Node* constructTreeFromPreAndInorderTraversal( map<int,int> &valueToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size) {
//   //base case
//   if(preIndex >= size || inOrderStart > inOrderEnd) {
//     return NULL;
//   }
//   //1 case main solve krta hu
//   int element = preOrder[preIndex++];
//   Node* root = new Node(element);
//   //element search krna padega  inorder me 
//   //int position = searchInorder(inOrder, size, element);
//   int position = valueToIndexMap[element];
//   //baaaki recursion sambhal lega
//   root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position-1, size);
//   root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, position+1, inOrderEnd, size);
//   return root;
// }

// Node* constructTreeFromPostAndInorderTraversal( map<int,int> &valueToIndexMap, int postorder[], int inorder[], int &postIndex, int inorderStart, int inorderEnd, int size) {
//   if(postIndex < 0 || inorderStart > inorderEnd) {
//     return NULL;
//   }
//   //1 case main solve krunga
//   int element = postorder[postIndex--];
//   Node* root = new Node(element);
//   //search karo inorder me 
//   int position = valueToIndexMap[element];
//   //baaki recursion sambhal lega
//   //right ki call pehle lagegi
//   root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, position+1, inorderEnd, size);
//   root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, inorderStart, position-1, size);
//   return root;
// }

// void print_left_view(Node* root, int level, vector<int> &left_view) {
//     if(!root)
//       return;
//     if(level == left_view.size())
//       left_view.push_back(root->data);
//     print_left_view(root->left, level+1, left_view);
//     print_left_view(root->right, level+1, left_view);
// }

// void print_right_view(Node* root, int level, vector<int> &right_view) {
//     if(!root)
//       return;
//     if(level == right_view.size())
//       right_view.push_back(root->data);
//     print_right_view(root->right, level+1, right_view);
//     print_right_view(root->left, level+1, right_view);
// }

// void print_top_view(Node* root) {
//     map<int,int> lvl_to_nodemap;
//     queue< pair<Node* , int> > q;
//     q.push(make_pair(root, 0));
//     while(!q.empty()) {
//         pair<Node* ,int> temp = q.front();
//         q.pop();
//         Node* frontNode = temp.first;
//         int lvl = temp.second;
//         //if there is no entry for lvl in map, then create a new entry
//         if(lvl_to_nodemap.find(lvl) == lvl_to_nodemap.end()) {
//           lvl_to_nodemap[lvl] = frontNode->data;
//         }
//         //child ko dekhna h 
//         if(frontNode->left) {
//           q.push(make_pair(frontNode->left, lvl-1));
//         }
//         if(frontNode->right) {
//           q.push(make_pair(frontNode->right, lvl+1));
//         }
//     }
//     cout << "printing top view: " << endl;
//     for(auto i: lvl_to_nodemap) {
//       cout << i.second << " ";
//     }
// }

// void print_bottom_view(Node* root) {
//     map<int,int> lvl_to_nodemap;
//     queue< pair<Node* , int> > q;
//     q.push(make_pair(root, 0));
//     while(!q.empty()) {
//         pair<Node* ,int> temp = q.front();
//         q.pop();
//         Node* frontNode = temp.first;
//         int lvl = temp.second;
//         //bas yaha if condition nhi rhegi baki entire code same
//           lvl_to_nodemap[lvl] = frontNode->data;
//         //child ko dekhna h 
//         if(frontNode->left) {
//           q.push(make_pair(frontNode->left, lvl-1));
//         }
//         if(frontNode->right) {
//           q.push(make_pair(frontNode->right, lvl+1));
//         }
//     }
//     cout << "printing bottom view: " << endl;
//     for(auto i: lvl_to_nodemap) {
//       cout << i.second << " ";
//     }
// }

// boundary traversal
// void left_part(Node* root) {
// 	if(!root) {
// 		return;
// 	}
// 	if(!root->left && !root->right) {
// 		return;
// 	}
// 	cout << root->data << " ";
// 	if(root->left) {
// 		left_part(root->left);
// 	}
// 	else {
// 		left_part(root->right);
// 	}
// }
// void right_part(Node* root) {
// 	if(!root) {
// 		return;
// 	}
// 	if(!root->left && !root->right) {
// 		return;
// 	}
	
// 	if(root->right) {
// 			right_part(root->right);
// 	}
// 	else {
// 			right_part(root->left);
// 	}
// 	cout << root->data << " ";
// }
// void leaf_part(Node* root) {
// 	if(!root )
// 		return;
// 	if(!root->left && !root->right) {
// 		cout << root->data <<" ";
// 	}
// 	leaf_part(root->left);
// 	leaf_part(root->right);
// }

// more optimal way
// void boundary_traversal(Node* root ) {
// 	if(!root)
// 		return;
// 	cout << root->data << " ";
// 	left_part(root->left);
// 	leaf_part(root->left);
// 	leaf_part(root->right);
// 	right_part(root->right);
// }

// theek thaak way
// void boundary_traversal(Node* root ) {
// 	if(!root)
// 		return;
// 	left_part(root);
// 	leaf_part(root);
//   if(root->right) 
// 	  right_part(root->right);
// 	else 
//     right_part(root->left);
// }

int main() {

    // Node* root = create_tree();
    // cout << "pre order traversal :-" << endl;
    // pre_order(root);
    // cout << endl;
    // cout << "in order traversal :-" << endl;
    // in_order(root);
    // cout << endl;
    // cout << "post order traversal :-" << endl;
    // post_order(root);
    // cout << endl;
    // cout << "level order traversal :-" << endl;
    // level_order_traversal(root);
    // cout << endl;
    // cout << "height of tree : " << max_depth(root) << endl;

    // cout << "diameter of a binary tree in terms of slides : " << diameter_of_a_binary_tree_1(root) << endl;
    // cout << "diameter of a binary tree in terms of nodes : " << diameter_of_a_binary_tree_2(root).first << endl;
    
    // int test_case;
    // cout << "enter the amount of test cases : ";
    // cin >> test_case;

    // while(test_case) {
    //   test_case--;
    //   int p,q;
    //   cout << "enter the first node : ";
    //   cin >> p;
    //   cout << "enter the second node : ";
    //   cin >> q;
    //   Node* key = LCA(root, p, q);
    //   cout << "lowest common ancestor : " << key->data << endl;
    // }

    // while(test_case) {
    //   test_case--;
    //   int kth_node, node, ans;
    //   cout << "how much times you wanna go upwards : ";
    //   cin >> kth_node;
    //   cout << "enter the base node you want to start from : ";
    //   cin >> node;
    //   cout << "your node has been found at [" << kth_ancestor(root, kth_node, node, ans) << "] node" << endl;
    // }

    // int test_case, target_sum, n, sum=0;
    // cin >> test_case;
    // while(test_case) {
    //   test_case--;
    //   cout << "if you need to calculate path sum 1 then type '1'" << endl;
    //   cout << "or if you want to calculate path sum 2 then type '2'" << endl;
    //   cin >> n;
    //   if(n == 1) {
    //     test_case--;
    //     cout << "enter the sum you're targeting from this tree : ";
    //     cin >> target_sum;
    //     if(path_sum_1(root, target_sum, sum))
    //       cout << "your target sum has found in the given tree :)" << endl;
    //     else 
    //       cout << "we're sorry to inform you that your desired targeted sum has not been found in the tree :(" << endl;
    //   }
    //   else if(n == 2) {
    //     cout << "enter the sum you're targeting from this tree : ";
    //     cin >> target_sum;
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     vector<vector<int>> fianl_ans = path_sum_2(root, target_sum, ans, temp, sum);
    //     cout << "your path sum lies in these nodes : " << endl;
    //     // for (const auto& path : ans) {
    //     //     cout << "Path: ";
    //     //     for (int nodeValue : path) {
    //     //         cout << nodeValue << " ";
    //     //     }
    //     //     cout << endl;
    //     // }
    //     for(vector<int> vect1D : ans) {
    //       cout << "[" << " ";
    //       for(int x : vect1D) {
    //         cout << x << " ";
    //       }
    //       cout << "]" << " ";
    //     }
    //     cout << endl;
    //   }
    // }
     
    // int inorder[] = {10,8,6,2,4,12};
    // int preOrder[] = {2,8,10,6,4,12};
    // int size = 6;
    // int preOrderIndex = 0;
    // int inorderStart = 0;
    // int inorderEnd = size-1;
    // map<int,int> valueToIndexMap;
    // createMapping(inorder, size, valueToIndexMap);
    // Node* root = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder, inorder, preOrderIndex, inorderStart,inorderEnd, size);

    // int inorder[] = {8,12,6,2,10,4};
    // int postorder[] = {8,6,12,4,10,2};
    // int size = 6;
    // int postIndex = size-1;
    // int inorderStart = 0;
    // int inorderEnd = size-1; 
    // map<int,int> valueToIndexMap;
    // createMapping(inorder, size, valueToIndexMap);
    // Node* root = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postorder, inorder, postIndex, inorderStart,inorderEnd, size);
    // cout << "Printing the entire tree: " << endl;
    // level_order_traversal(root);

    // cout << "printing level order traversal :-" << endl;
    // level_order_traversal(root);

    // vector<int> left_view;
    // cout << "printing left view :-" << endl;
    // print_left_view(root, 0, left_view);
    // for(int i=0; i<left_view.size(); ++i) {
    //   cout << left_view[i] << " ";
    // }
    // cout << endl;
    
    // vector<int> right_view;
    // cout << "printing right view :-" << endl;
    // print_right_view(root, 0, right_view);
    // for(int i=0; i<right_view.size(); ++i) {
    //   cout << right_view[i] << " ";
    // }
    // cout << endl;

    // print_top_view(root);

    // print_bottom_view(root);

    // boundary_traversal(root);

    return 0;
}