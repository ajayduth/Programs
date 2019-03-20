#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node *lchild,*rchild;
}node;


node * InOrderSuccessor(node *ptr){
  ptr=ptr->rchild;
  while(ptr->lchild!=NULL)
    ptr=ptr->lchild;
  return ptr;
}


void InOrder(node *ptr){
  if(ptr!=NULL){
    InOrder(ptr->lchild);
    printf("%d ",ptr->data);
    InOrder(ptr->rchild);
  }
}


void BSTinsert(node *ptr,int item){
  int k=1;
  node *ptr1;
  while(ptr!=NULL){
    if(ptr->data==item){
      k=0;
      printf("Duplicate Insertion!\n");
      break;
    }
    else{
      ptr1=ptr;
      if(ptr->data<item)
        ptr=ptr->rchild;
      else
        ptr=ptr->lchild;
    }
  }
  if(k!=0){
    node *new=(node *)malloc(sizeof(node));
    new->data=item;
    new->lchild=NULL;
    new->rchild=NULL;
    if(ptr1->data>item)
      ptr1->lchild=new;
    else
      ptr1->rchild=new;
  }
}

void BSTsearch(node *ptr,int item){
  int k=1;
  char ch='m';
  node *ptr1;
  while(ptr!=NULL){
    if(ptr->data==item){
      k=0;
      if(ch=='l')
        printf("Element found at left child of %d\n",ptr1->data);
      else if(ch=='r')
        printf("Element found at right child of %d\n",ptr1->data);
      else
        printf("Element found at root node\n");
      break;
    }
    else{
      ptr1=ptr;
      if(ptr->data<item){
        ch='r';
        ptr=ptr->rchild;
      }
      else{
        ch='l';
        ptr=ptr->lchild;
      }
    }
  }
  if(k!=0){
    printf("Element not found\n");
  }
}

void BSTdelete(node *ptr,int item,node *parent){
  node *root=ptr;
  int flag=0;
  node *ptr1;
  while(ptr!=NULL){
    if(ptr->data==item){
      printf("#");
      flag=1;
      break;
    }
    else{
      parent=ptr;
      if(ptr->data>item)
        ptr=ptr->lchild;
      else
        ptr=ptr->rchild;
    }
  }
  if(flag==0)
    printf("Element not found\n");
  else{
    if(ptr->lchild==NULL && ptr->rchild==NULL){
       if(parent->lchild==ptr)
         parent->lchild=NULL;
       else
         parent->rchild=NULL;
       free(ptr);
    }
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL){
       ptr1=InOrderSuccessor(ptr);
       ptr->data=ptr1->data;
       ptr1->data=item;
       BSTdelete(ptr->rchild,item,ptr);
    }
    else if(ptr->lchild!=NULL){
       if(parent->lchild==ptr)
         parent->lchild=ptr->lchild;
       else
         parent->rchild=ptr->lchild;
       free(ptr);
    }
    else{
       if(parent->lchild==ptr)
         parent->lchild=ptr->rchild;
       else
         parent->rchild=ptr->rchild;
       free(ptr);
    }
    printf("Element has been deleted\n");
  }
}

void PreOrder(node *ptr){
  if(ptr!=NULL){
    printf("%d ",ptr->data);
    PreOrder(ptr->lchild);
    PreOrder(ptr->rchild);
  }
}

void PostOrder(node *ptr){
  if(ptr!=NULL){
    PostOrder(ptr->lchild);
    PostOrder(ptr->rchild);
    printf("%d ",ptr->data);
  }
}

void main(){
  int c,item;
  node *root;
  node *new=(node *)malloc(sizeof(node));
  new->data=10;
  printf("Enter the root node element :");
  scanf("%d",&(new->data));
  root=new;
  root->lchild=NULL;
  root->rchild=NULL;
  char ch;
  do{
        printf("\nEnter the operation \n1.Insertion\n2.deletion\n3.search\n4.Traversal\n");
        scanf("%d",&c);
        switch(c)
        {
        	case 1: 
                        printf("Enter the  element :");
                        scanf("%d",&item);
                        BSTinsert(root,item);
        			break;
        	case 2: printf("Enter the element to be deleted :");
                        scanf("%d",&item);
                        BSTdelete(root,item,NULL);
        			break;
        	case 3: printf("Enter the item \n");
                        scanf("%d",&item);

                        BSTsearch(root,item);
        			break;
        	case 4: printf("\nInorder : \n");
			InOrder(root);
                        printf("Preorder : \n");
                        PreOrder(root);
                        printf("Postorder : \n");
                        PostOrder(root);
			break;


        	default:printf("\nEnter a valid input");
        			break;
       } 
    printf("Do you want to continue(y/n) :");
    scanf(" %c",&ch);
  }while(ch=='y'||ch=='Y');

}
