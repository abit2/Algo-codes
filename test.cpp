        #include <iostream>
        using namespace std;
     
        struct node
        {
        int value;
        node *left,*right;
        };
     
         int height(node *root)		//used recursive operation to find heightof BST
        {
        	if(root==NULL)
        	return 0;
        	int lh=0,rh=0;
        	lh=height(root->left);
        	rh=height(root->right);
     
        	if(lh>rh)
        	return (lh+1);
        	else
        	return(rh+1);
        	if(lh==rh)
        	return (rh+1);
     
        }
        void inorder(node *root)		//used the defined inorder traversal
        {
        if (root != NULL)
        {
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
        }
        }
     
         void preorder(node *root)		//used the defined preorder traversal
        {
        	if(root != NULL)
        	{
        		cout<<root->value<<" ";
    		preorder(root->left);
           		preorder(root->right);
        	}
        }
     
         node *leftrotate(node *root)	
        {
        	node *x,*y;			//initialised x to root
        	x=root;
        	if(x->right!=NULL)		
        	{
        	y=x->right;			//y is x's right now i.e if x's right !=0
        	x->right=y->left;
        	y->left=x;
		return y;		
		}
    	return x;
        }
     
         node *rightrotate(node *root)	
        {
        	node *k,*l;			//initialised l to root
        	l=root;
        	if(l->left!=NULL)		//k is l's left now i.e if l's left !=0
        	{
        	k=l->left;
        	l->left=k->right;
        	k->right=l;
		return k;
        	}
		return l;
        	
        }
     
        node *insert( node *root,int key)
        {
        node*temp=new node;
        temp->value=key;			
        temp->right=NULL;
        temp->left=NULL;
        if(root==NULL)			//inserting values if root is NULL
        {
        root=temp;
        }
        else
        if(key>root->value)			//else checking value is greater or smaller than root's value
        {
        root->right=insert(root->right,key);
        }
        else
        if(key<root->value)
        {
        root->left=insert(root->left,key);
        }
        return root;
        }
     
        node *makeskew(node *root)		
        {
            node *p=root;
        	//while(p->right!=NULL)	//continuing until root's right is not equal to 0	
        	
        		while(p->left!=NULL)		//till root's left is not equal to 0
        		{
        			p=rightrotate(p);		//rotating
        		}
        		p=p->right;		//changing roots value
        		p=makeskew(p);		//recursively continuing
        	
        	return root;
        }
     
        int main()
        {
        node *root = NULL;
        int h,i,n,val;
        cout<<"enter no. ";
        cin>>n;
        for(i=0;i<n;i++)
        {
        	cin>>val;
        	if(i==0)
        	{
        		root=insert(root,val);
        	}
        	else
        	insert(root,val);
        }
        cout<<"preorder : ";
        preorder(root);
        cout<<endl;
        cout<<"inorder : ";
        inorder(root);
        cout<<endl;
        h=height(root);
        h=h-1;
        cout<<h<<endl;
       // cout<<root->value<<endl;
       // root=leftrotate(root);
        root=rightrotate(root);
       // cout<<root->value<<endl;
       // cout<<"preorder : ";
       // preorder(root);
        root=makeskew(root);
        cout<<endl;
        cout<<"preorder : ";
        preorder(root);
        return 0;
        }
