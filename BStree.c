#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node *lchild,*rchild;
}node;

node *root;
node * InOrderSuccessor(node *ptr){
  ptr=ptr->rchild;
  while(ptr->lchild!=NULL)
    ptr=ptr->lchild;
  return ptr;
}


void Binsert(node *ptr,int item){
  int k=1;
  node *ptr1;
if(ptr==NULL)
{       node *temp=(node *)malloc(sizeof(node));
    	temp->data=item;
    	temp->lchild=NULL;
    	temp->rchild=NULL;
    	root=temp;
}
else
{
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
    	node *temp=(node *)malloc(sizeof(node));
    	temp->data=item;
    	temp->lchild=NULL;
    	temp->rchild=NULL;
    if(ptr1->data>item)
      	ptr1->lchild=temp;
    else
      	ptr1->rchild=temp;
 } }
}

void Bsearch(node *ptr,int item){
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

void Bdelete(node *ptr,int item,node *parent){
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
       Bdelete(ptr->rchild,item,ptr);
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

void InOrder(node *ptr){
  if(ptr!=NULL){
        InOrder(ptr->lchild);
        printf("%d ",ptr->data);
        InOrder(ptr->rchild);
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
  int item,a;
  printf("Enter the number of elements :\n");
  scanf("%d",&item);
  printf("Enter the elements :\n");
  for(int i=0;i<item;++i)
 {
    scanf("%d",&a);
    Binsert(root,a);
 }
char ch;
int c;
do{
  printf("Select:\n 1.Insert\n 2.Delete\n 3.Traversal\n 4.Search\n");
 scanf("%d",&c);

  switch(c)
 {
  case 1:   printf("Enter the element :");
            scanf("%d",&item);
            Binsert(root,item);
            break;
  case 2:   printf("Enter the element to be deleted :");
            scanf("%d",&item);
            Bdelete(root,item,NULL);
            InOrder(root);
            break;
  case 3:   printf("\n Inorder: ");
            InOrder(root);
            printf("\n Preorder: ");
            PreOrder(root);
            printf("\n Post order: ");
            PostOrder(root);
            break;
  case 4:   printf("Enter the element to be searched:  ");
            scanf("%d",&a);
            Bsearch(root,a);
            break;
  default:  printf("Enter a valid choice!!!\n");
 }
    printf("\nDo you want to continue(y/n)? :");
    scanf(" %c",&ch);
  }while(ch=='y'||ch=='Y');

  printf("\n");
}

