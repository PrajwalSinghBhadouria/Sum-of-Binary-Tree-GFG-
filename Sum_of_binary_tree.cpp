//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* make_tree()
{
	int n;
	cin>>n;
    
	Node* head=NULL;
	queue <Node*> q;

	for( ; n>0 ; n-=2 )
	{
		int a,b;
		char c;
		cin>> a >> b >> c;

        if(!head)
		{
			head = new Node(a);
			q.push(head);
		}

        Node* pick = q.front();
		q.pop();

		if(c == 'L')
		{
			pick->left = new Node(b);
			q.push( pick->left );
		}
		
		
		cin>> a >> b >> c;
		
		if(c == 'R')
		{
			pick->right = new Node(b);
			q.push( pick->right );
		}
	}
	return head;
}

long int sumBT(Node* root);


int main()
{
    int t;cin>>t;while(t--){
    	
    	Node* head = make_tree();
    
        cout<<sumBT(head)<<endl;
    
cout << "~" << "\n";
}
	return 1;
}

// } Driver Code Ends


/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/
// Function should return the sum of all the elements
// of the binary tree
void solve(Node* root,vector<int> &ans){
    if(root == NULL){
        return ;
    }
    solve(root->left,ans);
    ans.push_back(root->key);
    solve(root->right,ans);
     
}

long int sumBT(Node* root)
{
    // Code here
    vector<int> v;
    solve(root,v);
    long ans = 0;
    for(int i=0; i<v.size(); i++){
        ans = ans + v[i];
    }
    return ans;
}
