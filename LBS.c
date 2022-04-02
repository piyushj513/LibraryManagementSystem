#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node* createnode(struct node*);
void display(struct node*);
void search(struct node*);
void update(struct node*);
int count=0;

struct node
{
int no;
char name[30];
char au[30];
int page;
float price;
struct node* ptr;
};
struct node*createnode(struct node* head)
{
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter Book number :");
scanf("%d",&newnode->no);
printf("Enter the book name :");
scanf("%s",newnode->name);
printf("Enter the book author :");
scanf("%s",newnode->au);
printf("Enter the pages in book :");
scanf("%d",&newnode->page);
printf("Enter the price of the book :");
scanf("%f",&newnode->price);
printf("---------------------------------------------------------------------------\n");
count++;
if(newnode == NULL)
{
printf("\n Enter new book \n");
newnode->ptr=NULL;
 }
else
 {
newnode->ptr=head;
 }
return newnode;
}

void display(struct node* head)
{
if(head==NULL)
 {
printf("\nThe list is empty \n");
 }
else
 {
while(head!=NULL)
  {   
printf("\nBook %d",head->no);  
printf("\nThe name of the book is %s",head->name);
printf("\nThe author of the book is %s",head->au);
printf("\nTotal number of pages is %d",head->page);
printf("\nThe price of the book is %f",head->price);

printf("\n-----------x-----------x----------x----------x----------x-----------x------------\n");
head=head->ptr;
  }
  printf("\nThe total no. of books is %d\n",count);
 }
}

void search_n(struct node* head)
{
char ch[20];
printf("\nEnter the book name:");
scanf("%s",ch);

while(head!=NULL)
 {
if(strcmp(ch,head->name)==0)
  {
printf("\nThe name is matched with Book %d\n",head->no);
printf("\nBook %d\n%s",head->no,head->name);
printf("\nThe name of author is: %s",head->au);
printf("\nThe number of pages is:%d",head->page);
printf("\nThe price of the book is: %f\n",head->price);
 }
else
   {
     printf("");
   }
head=head->ptr;
  }
}
void search_a(struct node* head)
{
char ch[20],a[20];
printf("\nEnter the book name:");
scanf("%s",ch);
printf("\nEnter Author:");
scanf("%s",a);

while(head!=NULL)
 {
if(strcmp(ch,head->name)==0 && strcmp(a,head->au)==0 )
{
printf("\nBOOK MATCHED\n");
printf("\nBook %d\n%s",head->no,head->name);
printf("\nThe name of author is: %s",head->au);
printf("\nThe number of pages is:%d",head->page);
printf("\nThe price of the book is: %f\n",head->price);
}
else
   {
     printf("");
   }
head=head->ptr;
  }
}

void update(struct node* head)
{
char ch1[20];
printf("\nEnter the book name:");
scanf("%s",ch1);
while(head!=NULL)
{
 if(strcmp(ch1,head->name)==0)
 {
    printf("\nBook Found!\n");
    
while (1)
{


 printf("\n################### MENU #######################");
 printf("\n# Please enter the information to be updated ###");
 printf("\n# 1.BOOK NUMBER                              ###");
 printf("\n# 2.BOOK NAME                                ###");
 printf("\n# 3.BOOK PRICE                               ###");
 printf("\n# 4.BOOK PAGES                               ###");
 printf("\n# 5.BOOK AUTHOR                              ###");
 printf("\n# 6.EXIT                                     ###");
 printf("\n################################################\n");
 
 int choose;
 scanf("%d",&choose);
 if(choose==6)
 break;
 if(choose<1||choose>6){
 printf ("No such option, please re-enter!\n"); 
 scanf("%d",&choose);
}
switch(choose)
{
case 1:
printf ("Enter new book number: \n");
scanf("%d",&head->no);
break;
case 2:
printf ("Enter new name: \n");
scanf("%s",&head->name);
break;
case 3:
printf ("Enter new price: \n");
scanf("%lf",&head->price);
break;
case 4:
printf ("Enter new no of pages: \n");
scanf("%d",&head->page);
break;
case 5:
printf ("Enter new Author: \n");
scanf("%s",&head->au);
break;
}
}
}
 head=head->ptr;
 }
}

int main()
{
struct node* head;
int a,i;
head=NULL;
{
    printf("\n\t\t\t                   BATCH 16 MINI PROJECT\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n");
}

while(1)
{
    printf("\n################# MAIN MENU ####################");
    printf("\n# 1.Enter BOOK DETAILS                       ###");
    printf("\n# 2.DISPLAY BOOK DETAILS                     ###");
    printf("\n# 3.SEARCH BOOK BY NAME                      ###");
    printf("\n# 4.SEARCH BOOK BY AUTHOR                    ###");
    printf("\n# 5.UPDATE                                   ###");
    printf("\n# 6.EXIT                                     ###");
    printf("\n################################################\n");
    scanf("%d",&a);
    
switch(a)
 {
case (1): printf("\nEnter the number of books:");
          scanf("%d",&i);
          while(i>0)
         {
          head=createnode(head);
          i--;
         }
          break;
case (2): display(head);
          break;
case (3): search_n(head);
          break; 
case (4): search_a(head);
          break;
case (5): update(head);
          break;
case (6): exit(1);
          break;
default: printf("\nINVALID OPTION");
    }
  }
}