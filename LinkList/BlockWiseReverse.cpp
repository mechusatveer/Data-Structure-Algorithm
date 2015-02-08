#include<iostream>

using namespace std;

struct Node
{
  int data;
  Node* next;

  public:
  Node(int d) : data(d),next(NULL)
  {

  }
};

void BlockReverse(Node** head)
{
   if(*head == NULL || (*head)->next == NULL)
   {
     return;
   }

   Node* temp = *head;

   Node* currHead = NULL;
   Node* prevHead = NULL;

   while(temp != NULL)
   {
       currHead = temp;
       Node* prev = NULL;
       Node* curr = currHead;
       Node* next = NULL;
       int k = 0;
       while(k++ < 3 && curr != NULL)
       {
           next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
       }
       if(prevHead == NULL)
       {
           *head = prev;
           prevHead = currHead;
       }
       if(prevHead != NULL)
       {
           prevHead->next = prev;
           prevHead = currHead;
       }

       temp = curr;
   }
}

void Insert(Node** head,int data)
{
  if(*head == NULL)
  {
     *head = new Node(data);
     return;
  }
  Node* temp = *head;
  Insert(&(temp->next),data);
}

void Print(Node* head)
{
   while(head != NULL)
   {
      cout<<head->data<<"  ";
      head = head->next;
   }
}
int main()
{
   Node* head = NULL;
   Insert(&head,1);
   Insert(&head,2);
   Insert(&head,3);
   Insert(&head,4);
   Insert(&head,5);
   Insert(&head,6);
   Insert(&head,7);
   Insert(&head,8);

   Print(head);
   cout<<endl;

   BlockReverse(&head);

   Print(head);
   cout<<endl;
   return 0;
}
