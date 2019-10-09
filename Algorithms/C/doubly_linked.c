#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
}node;

int option();
struct node * InsertAtBeg(int, struct node *);
struct node * InsertAtEnd(int, struct node *);
struct node * InsertAfter(int, int, struct node *);
struct node * delStart(struct node *);
struct node * delEnd(struct node*);
struct node * delNum(int, struct node*);
void display(struct node *);

int main()
{
  struct node *head = NULL;
  int opt, num, reqnum;
  opt = option();
  while(opt <= 9)
  {
    switch(opt)
    {
      case 1:
        printf("Enter the number\n");
        scanf("%d", &num);
        head = InsertAtBeg(num, head);
        break;

      case 2:
        printf("Enter the number\n");
        scanf("%d", &num);
        head = InsertAtEnd(num, head);
        break;
      
      case 3:
        printf("Enter the number\n");
	scanf("%d", &num);
        printf("Enter the number after which the above number will be inserted\n");
        scanf("%d", &reqnum);
        head = InsertAfter(num, reqnum, head);
        break;
      case 4:
	head = delStart(head);
	break;
      case 5:
	head = delEnd(head);
	break;
      case 6:
        printf("Enter the number\n");
        scanf("%d", &num);
        head = delNum(num, head);
        break;

      case 7:
	display(head);
        break;
      case 8:
        exit(0);	
    }
    opt = option();
  }
}

int option()
{
  int op;
  printf("1.Insert an element in the beginning of the list\n");
  printf("2.Insert at the end of the list\n");
  printf("3.Insert after an number in the list\n");
  printf("4.Delete beginning number from the list \n5.Delete last number \n6.Delete number \n");
  printf("7.Display\n8.Exit\n");
  scanf("%d", &op);
  
  return op;
}

struct node * InsertAtBeg(int num, struct node *head)
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num;

  if(head == NULL)
  {
    head = temp;
    head->left = NULL;
    head->right = NULL;
    return head;
  }
  else
  {
    temp->right = head;
    temp->left = NULL;
    head = temp;
    return head;
  }
}

struct node * InsertAtEnd(int num, struct node *head)
{
  struct node *temp1, *temp2;
  temp1 = (struct node *)malloc(sizeof(struct node));
  temp1->data = num;

  temp2 = head;
  if(head == NULL)
  {
    head = temp1;
    head->right = NULL;
    head->left = NULL;
    return head;
  }
  else
  {
    while(temp2->right != NULL)
      temp2 = temp2->right;

    temp1->right = NULL;
    temp1->left = temp2;
    temp2->right = temp1;
    return head;
  }
}

struct node * InsertAfter(int num, int reqnum, struct node *head)
{
  if(head == NULL)
  {
    printf("The list is empty\n");
    return head;
  }
  else
  {
    struct node *temp1, *temp2;
    temp2 = head;
    do
    {
      if(temp2->data == reqnum)
      {
        temp1 = (struct node *)malloc(sizeof(struct node));
        temp1->data = num;
        temp1->right = temp2->right;
	temp2->right->left = temp1;
	temp1->left = temp2;
        temp2->right = temp1;
        return head;
      }
      temp2 = temp2->right;
    }while(temp2 != NULL);

    if(temp2 == NULL)
    {
      printf("The number given not found\n");
      return head;
    }
  }
  return head;
}
struct node * delStart(struct node *head){
 if (head == NULL){
  printf("List empty\n");
  return head;
 }
 if (head ->right == NULL){
  struct node *temp = head;
  printf("Element %d deleted\n", temp->data);
  head = NULL;
  free(temp);
  return head;
 }
 struct node *temp = head;
 head = head->right;
 head->left = NULL;
 printf("Element %d deleted\n", temp->data);
 free(temp);
 return head;
}
struct node * delEnd(struct node *head){
 if(head == NULL)
  {
    printf("The list is empty\n");
    return head;
  }
  if (head ->right == NULL){
   struct node *temp = head;
   printf("Element %d deleted\n", temp->data);
   head = NULL;
   free(temp);
   return head;
 }
 struct node *temp;
 temp = head;
 while(temp->right != NULL){
  temp = temp->right;
 }
 temp->left->right = NULL;
 printf("Element %d deleted \n", temp->data);
 free(temp);
 return head;
}
struct node * delNum(int num, struct node *head)
{
  if(head == NULL)
  {
    printf("The list is empty\n");
    return head;
  }
  if(head->right == NULL)
  {
   if(head->data == num){
    struct node *temp = head;
    head = NULL;
    printf("The element is deleted from the list %d\n", head->data);
    free(temp);
    return head;
  }
  else{
   printf("The given element not found \n");
   return head;
  }
  }
  struct node *temp;
  temp = head;
  while(temp != NULL)
  {
    if (temp->right == NULL){
     temp->left->right = NULL;
     free(temp);
     return head;
    }
    if(temp->data == num)
    {
      temp->right->left = temp->left;
      temp->left->right = temp->right;
      free(temp);
      printf("The element is deleted from the list \n");
      return head;
    }
    temp = temp->right;
  }

  if(temp == NULL)
  {
    printf("The given element not found\n");
    return head;
  }
  return head;
}

void display(struct node *head)
{
  if(head == NULL)
  {
    printf("The list is empty\n");
    return;
  }
  struct node *temp;
  temp = head;
  printf("Elements are \n%d\n", temp->data);
  temp = temp->right;
  while(temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->right;
  }
  printf("\n");
}
