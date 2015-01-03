//Complexity Non sorted O(m+n)
//SOrt O(m+n)

#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Insert(Node** head, int d)
{
    if(*head == NULL)
    {
        *head = new Node();
        (*head)->data = d;
        (*head)->next = NULL;
        return *head;
    }

    Node* temp = *head;
    return Insert(&(temp->next),d);
}


//Complexity  m,n where m < n
//m + n-m + m = O(m+n)
Node* MergePoint(Node* head1,Node* head2)
{
    //m,n is size of lists  m<n

    if(head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    Node* list1 = head1;
    Node* list2 = head2;

    //m
    while(list1 && list2)
    {
        list1 = list1->next;
        list2 = list2->next;
    }

    if(list1 == NULL)//list2 is large
    {
        list1 = head2;
        //n-m
        while(list2)
        {
            list1 = list1->next;
            list2 = list2->next;
        }
        list2 = head1;
    }
    else
    {
        list2 = head1;
        //n-m
        while(list1)
        {
            list1 = list1->next;
            list2 = list2->next;
        }
        list1 = head2;
    }

    //we are here mean both list now same size
    //m time
    while(list1)
    {
        if(list1 == list2) return list1;
        list1 = list1->next;
        list2 = list2->next;
    }

    //we came here it mean no merge point
    return NULL;
}

void Print(Node* head)
{
    if(head == NULL) return;

    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//Complexity O(m+n)
Node* sorted_merge(Node* head1,Node* head2)
{
    if(head1 == NULL || head2 == NULL) return NULL;

    while(head1 && head2)
    {
        if(head1 == head2)
        {
            return head1;
        }
        if(head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }
    return NULL;
}
int main()
{
   Node *head1 = NULL;
   Node *head2 = NULL;
   /*
   Insert(&head1,1);
   Insert(&head1,2);
   Insert(&head1,3);
   Insert(&head1,4);
   Insert(&head1,5);
   Node* mPoint = Insert(&head1,6);
   Insert(&head1,7);
   Insert(&head1,8);
   Insert(&head1,9);
   Insert(&head1,10);
   Insert(&head2,0);
   Insert(&head2,1);
   Node* e2 = Insert(&head2,-2);
   e2->next = mPoint;
   Print(head1);
   Print(head2);

   Node *temp = MergePoint(head1,head2);

   if(temp != NULL)
   {
       cout<<"Merge Point ="<<temp->data<<endl;
   }
   */

   Insert(&head1,1);
   Insert(&head1,3);
   Insert(&head1,5);
   Insert(&head1,7);
   Insert(&head1,9);
   Node* mPoint = Insert(&head1,10);
   Insert(&head1,11);
   Insert(&head1,12);
   Insert(&head1,13);
   Insert(&head1,14);
   Insert(&head2,2);
   Insert(&head2,4);
   Insert(&head2,6);
   Node* e2 = Insert(&head2,8);
   e2->next = mPoint;

   Print(head1);
   Print(head2);

   Node *temp_sort = MergePoint(head1,head2);

   if(temp_sort != NULL)
   {
       cout<<"Merge Point Sorted ="<<temp_sort->data<<endl;
   }

   return 0;
}
