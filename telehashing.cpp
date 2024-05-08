/*conside telephone book database of N clients. Make use of a hash table implementations to quickly look up client's telephone no. Make use of two collision handelling techniques and compare them using no of comparisons required to find set of telephone nos.*/

#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    int value;
    node* next; 

}*HashTable[10];
class hashing   
{
    public:
        hashing()
        {
            for (int i = 0; i < 10; i++)
            {
                HashTable[i]=NULL;

            }
        }
        int HashFunction(int value)
        {
            return(value%10);
        }
        node* create_node(int x)
        {
            node* temp=new node;
            temp->next=NULL;
            temp->value=x;
            return temp;
        }
        void display()
        {
            for (int i = 0; i < 10; i++)
            {
                node* temp = new node;
                temp=HashTable[i];
                cout<<"a["<<i<<"] : ";
                while (temp!=NULL)
                {
                    cout<<"->"<<temp->value;
                    temp=temp->next;
                }
                cout<<"\n";
                
            }
            
        }
        int searchElement(int value)
        {
            bool flag=false;
            int hashVal = HashFunction(value);
            node* entry = HashTable[hashVal];
            cout<<"\n ELEMENT FOUND AT :";
            while (entry!=NULL)
            {
                if (entry->value==value)
                {
                    cout<<hashVal<<" : "<<entry->value<<endl;
                    flag = true;
                }
                entry = entry->next;
                
            }
            if (!flag)
            {
                return -1;
            }
        }
        void insertElement(int value)
        {
            int hashVal = HashFunction(value);
            node* temp=new node;
            node* head=new node;
            head = create_node(value);
            temp=HashTable[hashVal];
            if (temp==NULL)
            {
                HashTable[hashVal]=head;
            }
            else
            {
                while (temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=head;
            }
        }
        void deleteElement(int value)
        {
            int hashVal=HashFunction(value);
            node *entry=HashTable[hashVal];
            if (entry==NULL)
            {
                cout<<"NO ELEMENT FOUND";
                return;
            }
            
            if (entry->value==value)
            {
                HashTable[hashVal]=entry->next;
                return;
            }
            while ((entry->next)->value!=value)
            {
                entry=entry->next;
            }
            entry->next=(entry->next)->next;
            
        }
        
};
int main()
{
    int ch;
    int data,search,del;
    hashing h;
    do
    {
        cout<<"\n TELEPHONE :\n1.INSERT \n2.DISPLAY\n3.SEARCH\n4.DELETE";
        cout<<"\n ENTER YOUR CHOICE :";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\n ENTER PHONE NO. TO BE INSERTED :";
            cin>>data;
            h.insertElement(data);
            break;
        case 2:
            h.display();
            break;
        case 3:
            cout<<"\n ENTER NO. TO BE SEARCHED :";
            cin>>search;
            if (h.searchElement(search)== -1)
            {
                cout<<" NO ELEMENT FOUND AT KEY ";
                continue;
            }
            break;
        case 4:
            cout<<"\n ENTER PHONE NO. TO BE DELETED:";
            cin>>del;
            h.deleteElement(del);
            cout<<"PHONE NO. DELETED "<<endl;
            break;
        }
    } while (ch!=5);
    return 0;
    
}

