#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
struct node {
	char* data;
	struct node* next;
} ;
struct node* head=NULL;
void display(struct node *p);
void AddWord(char *word) ;
void insert_tail(struct node** p,char* x);
void main()
{
     int i , j;
	int c,count=0,cn=1,k=0;char str[100];char str1[100][100];
	char s[MAX][MAX];
	for( i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
		 c=(rand() % (26))+65;
		 s[j][i]=(char)c;
	    }
    }
	for( i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			printf("%c | ",s[i][j]);
		}
		printf("\n");
	}
while(cn){

	printf("Enter the string you want to enter\n");
	scanf("%s",str);
	int l=strlen(str);
	for( j=0;j<MAX;j++){
		for(i=0;i<MAX;i++){
			if(s[j][i]==str[0]){
				int k=0;int h=0;
				while(k<l){
					if(((i%20)==i || i%20==19)&& ((i+1)%20 == 0) && (h!=l))
					  break;
					if(s[j][i]==str[k]){
					  i++;
					  h++;
				}
					if(h==l){
						printf("Word is present");
						count=1;
//						insert_tail(&head,str);
						break;
					}
					k++;
				}
			}
		}
	}
if(count!=1){
for(j=0;j<MAX;j++){
		for(i=0;i<MAX;i++){
			if(s[i][j]==str[0]){
				int k=0;int h=0;
				while(k<l){
					if(((j%20)==j || j%20==19)&& ((j+1)%20 == 0) && (h!=l))
					  break;
					if(s[i][j]==str[k]){
					  i++;
					  h++;
				}
					if(h==l){
						printf("Word is present");
						count=1;
//						insert_tail(&head,str);
						break;
					}
					k++;
				}
			}
		}
	}
}
//printf("%d",h);
strcpy(str1[k],str);
if(count!=1)
 printf("Word is not present");
else if(count==1)
 AddWord(str1[k]);
printf("%s",str1[k]);
printf("\nEnter Zero to exit: ");
scanf("%d",&cn);
count=0;k++;
}
printf("The words you found out are: ");
display(head);
}

//void insert_tail(struct node** p,char* x)
//    {
//      struct node* temp;
//      struct node* q;
//      temp=(struct node*)malloc(sizeof(struct node));
//      temp->data=x;
//      temp->next=NULL;
//      //empty list, first node being inserted
//      if(*p==NULL)
//         *p=temp;//copy the address of the first node into first
//      else
//      {
//        //list present, go to the end of the list
//       q=*p;//copy address of first node into q;
//       while(q->next!=NULL)
//         q=q->next;
//       q->next=temp;
//    }
//}

void AddWord(char *word) // Add a new word to the list MyList
    { struct node *item,*next;
    item = (struct node *) malloc(sizeof(struct node));
    if ( item==0 ) { printf ("Malloc Failed \n");  return ; }
    strcpy(item->data,word); // Copy Word into new Item
    item->next = 0; // Set that next Item is nothing

    if ( head == 0 ) // If List is Empty, make this the first item
        { head = item; return ; }

    if(strcmp(word,head->data) < 0 ) // Check if the new item comes before the first item in old list
        { item->next = head; head = item; return ; }

    // Check to see if an item is inserted before the next item
    for ( next = head ; next ->next != 0 ; next = next ->next )
        {
        if (strcmp (word, next->next->data) < 0 )
            { // Insert Item before the next Item.
            item ->next = next->next;
            next->next = item ; return;
            }
        }

    // There are no more items ! Add to end
    next ->next = item;
    }

void display(struct node *p)
   {
     if(p==NULL)
      printf("Empty List\n");
    else
    { 
        while(p!=NULL)
     {
        printf("%s->",p->data);
        p=p->next;
     }
   }
  }



