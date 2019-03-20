#include<stdio.h>
typedef struct binary
{
	int data;
	struct binary *left;
	struct binary *right;

}node;

void create();
void insert();
//void delete(node *);
//void search(node *);
void inorder();
void preorder();
void postorder();
int main()
{
    int c;
    char ch;
    node *root=NULL,*temp;
    
    do
    {
    	printf("\nEnter the operation \n1.Insertion\n2.deletion\n3.search\n4.Inoreder treversal\n5.preorder traversal\n6.postoredr traversal\n");
        scanf("%d",&c);
        switch(c)
        {
        	case 1: insert();
        			break;
        	case 2: delete();
        			break;
        	case 3: search();
        			break;
        	case 4: search();
        			break;
        	case 5: inorder();
        			break;
        	case 6: preorder();
        			break;
        	case 7: postorder();
        			break;
        	default:print("\nEnter a valid input");
        			break;
        }
        printf("nDo you want to enter more(y/n)?");
        getchar();
        scanf("%c",&ch);
    }while(ch=='y'|ch=='Y');

    
    printf("nPreorder Traversal: ");
    preorder(root);
    return 0;
}
 
void insert()

{

    create();

    if (root == NULL) 

        root = temp;

    else    

        search(root);    

}



void create()

{

    int data;

 

    printf("Enter data of node to be inserted : ");

    scanf("%d", &data);

    temp = (struct btnode *)malloc(1*sizeof(struct btnode));

    temp->value = data;

    temp->l = temp->r = NULL;

}


void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}