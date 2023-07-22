/*Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.*/
//TC:O(N log N)
//SC:O(N)
class Node{
    public:
       int data;
       Node* left;
       Node* right;
       
       Node(int d){
           data = d;
           left = NULL;
           right = NULL;
       }
};
class comp{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};
void preorder(Node* root, string temp, vector<string>& ans){
    if(!root->right and !root->left){
        ans.push_back(temp);
        return;
    }
   
    preorder(root->left, temp+'0', ans);
    preorder(root->right, temp+'1', ans);
}

class Solution
{
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, comp> pq;
		    
		    for(int i=0; i<N; i++){
		        Node* node = new Node(f[i]);
		        pq.push(node);
		    }
		    
		    while(pq.size()>1){
		        auto first = pq.top();
		        pq.pop();
		        
		        auto second = pq.top();
		        pq.pop();
		        
		        
		        Node* sum = new Node(first->data + second->data);
		        sum->left = first;
		        sum->right = second;
		        
		        pq.push(sum);
		    }
		    
		    Node* root = pq.top();
		    
		    vector<string> ans;
		    preorder(root, "", ans);
		    
		    return ans;
		}
};
