#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<iomanip>

using namespace std;



//-------------------------------------------------------Array Functions-------------------------------------------------------------//


int a[100], arrayPos, elem;
int n = 0;


void arrayCreate();
void arrayDisplay();
void arrayInsert();
void arraydDelete();


void arrayDisplay()
{
    if(!n)
    {
      cout<<"\n Array is Empty....\n\n";
      return;
    }

    clock_t tStart = clock();
    
    cout<<"\n Current Array is : \n";
    cout<<"\n\n\t--------------------------------------------------------------";
    cout<<"\n\n\t  ";
    
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cout<<"［"<<a[i]<<"］--";
    }
    
    cout<<"［"<<a[n-1]<<"］";
    
    cout<<"\n\n\t--------------------------------------------------------------";
    cout<<"\n\n\n\n";

    printf(" Time taken for Traversal : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
}



void arrayCreate()
{
    
    cout<<"\n Enter the number of elements in array : ";
    cin>>n;
    cout<<"\n Enter the elements : \n\n";
    
    clock_t tStart = clock();
            
    for(int i=0; i<n; i++)
     {
        cout<<"\n Enter element "<< i + 1 <<" : ";
        cin>>a[i];
     }
     
    cout<<"\n\n";
    
    printf(" Time taken in Creation of Array : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
    cout<<"\n";
    arrayDisplay();

}



void arrayInsert()
{
    if(n == 100)
    {
        cout<<"\n Size Allocated to array is Array is Full ....\n\n";
        return;
    }

    cout<<"\n Enter position where you want to insert element : ";
    cin>>arrayPos;

    if(arrayPos > n)
    {
        cout<<"In Invalid Position....";
        return;
    }

    cout<<"\n\n Enter the value to be inserted : ";
    cin>>elem;
    
    clock_t tStart = clock();

     for(int i=n-1; i>=arrayPos ; i--)
     {
        a[i+1] = a[i];
     }

    a[arrayPos] = elem;
    n = n+1;
    
    cout<<"\n Element Inserted Successfully !!!";
    cout<<"\n\n";
    printf(" Time taken in Insertion : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  
  
    cout<<"\n";
    arrayDisplay();

}



void arrayDelete()
{
   if(n == 0)
   {
       cout<<"\n Array is Empty.... Element can not be Deleted.\n\n";
       return;
   }
  
     cout<<"\n Enter a valid position to delete an Element from Array : ";
     cin>>arrayPos;

     if(arrayPos>n)
     {
         cout<<"\n Given Position is Invalid...Element can not be deleted. ";
         return;
     }
     
     cout<<"\n Element Deleted Successfully !!!";
     cout<<"\n Deleted Element is : "<<a[arrayPos];

     clock_t tStart = clock();

     for( int i = arrayPos; i< n-1; i++)
     {
        a[i] = a[i + 1];
     }

     n = n-1;
     
     cout<<"\n\n";
     printf(" Time taken in Deleting : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
     cout<<"\n";

     arrayDisplay();
   

} 

//----------------------------------------------------Linked List Functions----------------------------------------------------------//


//Linked List Structure;


struct node
{
  int d;
  node*next;
};

node* head;
node* temp;



//Linked List Traversal/ Display;



void traversal(struct node*ptr)
{   
    bool flag = true;
    
    clock_t tStart = clock();
    
    if(!ptr)
    {
        cout<<"\n Linked list is Empty.....";
    }
    else
    {
    cout<<"\n\n │ Current Linked List │\n\n\n";
    
    cout<<"\n    ";
    
    while(ptr!=NULL)
    {
        if(ptr->next)
        {
            if(flag)
            {
             
              cout<<"Head --->〔 "<<ptr->d<<"|● 〕"<<"--->";
            }
            else
            {
              cout<<"〔 "<<ptr->d<<"|● 〕"<<"--->";
            }
        }
        else
        {
            cout<<"〔 "<<ptr->d<<"|● 〕---> NULL";
        }
        
        flag = false;
        ptr=ptr->next;
    }
    
    
    cout<<"\n\n\n\n\n";
    
    printf(" Time taken for Traversal : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    }
}




//Linked List Insertion;


void insertion(int i)
{   
    clock_t tStart = clock();
    
    node* newnode;
    newnode=new node();
    cout<<"\n Enter Node Element "<<i<<" : ";
    cin>>newnode->d;
    newnode->next=NULL;
    if(head==NULL)
    head=temp=newnode;
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    
    cout<<"\n";
    printf(" Time taken for Insertion : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
    
}


//Delete Element From Linked List;

void deletion()
{
       clock_t tStart = clock();
       
       if(head==NULL)
       {
         cout<<"\n List is empty....";
       }
       else
       {
         temp=head;
         head=head->next;
         cout<<"\n Node "<<temp->d<<" deleted from list...";
         free(temp);
       
       cout<<"\n";
       printf(" Time taken for Deletion : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
       
       }
       
       cout<<"\n";
       
       traversal(head);
       
}



//Search an Element in Linked list;



int  search()
{       
        clock_t tStart = clock();
        
        int element;
        cout<<"\n Enter Node to be searched in List : ";
        cin>>element;
        temp=head;
        int count=0;
        while(temp!=0)
        {
                count++;
                
                if(temp->d==element)
                {
                   cout<<"\n Entered Node is Found at position | "<<count<<" |";
                   printf(" \n\n Time taken in Seaching: %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                   return count;
                }
                
                temp=temp->next;
        }
        return -1;
        
        cout<<"\n";

}


//---------------------------------------------------------Stack Functions---------------------------------------------------------//


//Stack Structure ::

struct lobe 
{
   int g;
   lobe *link;
};


lobe* top = NULL;


//Traversal of Stack : Warning : Do not play with this function.......


void display() 
{
   clock_t tStart = clock();  
   
   bool flag = true;
    
   lobe* ptr;
   
   if(top==NULL)
   {
     cout<<"\n Current Stack is empty....";
   }
   else 
   {
      ptr = top;
      cout<<"\n | : Current Stack : |  \n\n\n";
      
      
      while (ptr != NULL) 
      {
         
         if(flag)
         {
            cout<<"\tTop ----> |-----|\n";
            cout<<"\t\t  |  "<< ptr->g <<"  |\n"; 
         }
         else
         {
           cout<<"\t\t  |  "<< ptr->g <<"  |\n";
         }
         
         if(ptr->link)
         {
             cout<<"\t\t  |-----|\n";
         }
         else
         {
             cout<<"\t\t  |-----| ----> Next Null \n";
         }

         ptr = ptr->link;
         flag = false;
      }
      
      
   }
   
   cout<<"\n\n\n";
   printf(" Time Taken in Traversal : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
   
}



//Push To stack;


void push(int val)
{  
   clock_t tStart = clock();

   lobe* newnode;
   newnode=new lobe();
   newnode->g = val;
   newnode->link = top;
   top = newnode;
   
   cout<<"\n";
   
   printf(" Time taken in Inserting : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
   
   cout<<"\n";
}



//Delete Element from Stack;


void pop() 
{
   clock_t tStart = clock();    
    
   if(top==NULL)
   {
      cout<<"\n Stack Underflow : No Element is Present in Stack...."<<endl;
   } 
   else 
   {
      cout<<"\n Popped element is : ";
      cout<<"\t|-----|\n";
      cout<<"\t\t\t|  "<<top->g<<"  |\n";
      cout<<"\t\t\t|-----|";
      cout<<"\n\n";
      top = top->link;
      
      printf("\n Time taken in Deleting : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
   }
   
  
   cout<<"\n\n";
   
   display();
   
}

//--------------------------------------------------------Tree Functions-------------------------------------------------------//


struct Tnode
{
    int info;
    struct Tnode *left;
    struct Tnode *right;
    
}*root;

Tnode *Ttemp;

void find(int, Tnode **, Tnode **);    
void insert(Tnode *, Tnode *);
void del(int);
void case_a(Tnode *,Tnode *);
void case_b(Tnode *,Tnode *);
void case_c(Tnode *,Tnode *);
void preorder(Tnode *);
void inorder(Tnode *);
void postorder(Tnode *);
void display(Tnode *, int);



//Find Function : Utility for Delete



void find(int item, Tnode **par, Tnode **loc)
{
    Tnode *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->left;
	else
	    ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}


//Delete Function


void del(int item)
{
    Tnode *parent, *location;
    if (root == NULL)
    {
        cout<<"\n Tree is currently empty ."<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"\n Entered Item is not present in the Tree ."<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
    
    cout<<"\n Entered Item is Deleted from the Tree.";
    
    cout<<"\n\n | Current BST | \n\n ";
    display(root, 1);
}



void case_a(Tnode *par, Tnode *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}




void case_b(Tnode *par, Tnode *loc)
{
    Tnode *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}


void case_c(Tnode *par, Tnode *loc)
{
    Tnode *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}
 


void insert(Tnode *tree, Tnode *newnode)
{
    
    if (root == NULL)
    {
        root = new Tnode;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"\n Root Node is Added in the BST ."<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"\n Entered Element is already in the tree ."<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);	
	}
	else
	{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"\n Node is Added To Left <----."<<endl;
            cout<<"\n | Current Tree | \n\n";
            display(root,1);
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"\n Node Added To Right ----> ."<<endl;
            cout<<"\n\n | Current Tree | \n\n ";
            display(root, 1);
            return;
        }	
    }
    
}





void preorder(Tnode *ptr)
{
    if (root == NULL)
    {
        cout<<"\n Tree is empty"<<endl;
        return;
    }
    
    
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
    
}




void inorder(Tnode *ptr)
{
    
    if (root == NULL)
    {
        cout<<"\n Current Tree is | EMPTY |"<<endl;
        return;
    }
    
    
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
    
}
 



void postorder(Tnode *ptr)
{
    
    if (root == NULL)
    {
        cout<<"\n Current Tree is | EMPTY |"<<endl;
        return;
    }
    
    
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
    
}


//Tree Display Function -----------------------------------------------------------------------------------------//


void display(Tnode *ptr, int level)
{
    int i;
    
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        
        if (ptr == root)
            cout<<" ●--> ";
        else
        {
            for (i = 0 ; i < level ; i++)
                cout<<"          ";
	    }
	    
        cout<<"|"<<ptr->info<<"|--［";
        
        display(ptr->left, level+1);
    }
    
    cout<<"\n";
    return;
    
}



//---------------------------------------------------------Queue Functions------------------------------------------------------//



#define MAX 50

void Qinsert();
void Qdelete();
void Qdisplay();
int queue_array[50];
int rear = - 1;
int front = - 1;



void Qinsert()
{
    int add_item;
    
    clock_t tStart = clock();
    
    if (rear == MAX - 1)
    cout<<"\n Queue Overflow !!! Allocated Space in full...... \n";
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        cout<<"\n Enter the element you want to insert in queue : ";
        cin>>add_item;
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
    
    printf("\n\n Time Taken in Insertion : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
    cout<<"\n\n";
    Qdisplay();
} 



void Qdelete()
{
    clock_t tStart = clock();
    
    if (front == - 1 || front > rear)
    {
        cout<<"\n Queue Underflow \n";
        return ;
    }
    else
    {
        cout<<"\n Element deleted from queue is : | "<< queue_array[front]<<" |";
        front = front + 1;
    }
    
    
    printf("\n\n Time Taken in Deleting Element : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
    cout<<"\n\n";
    Qdisplay();
    
}



void Qdisplay()
{
    clock_t tStart = clock();
    
    int i;
    if (front == - 1)
        cout<<"\n Queue is empty ";
    else
    {
        cout<<"\n| Current Queue | \n\n\n\t";
        for (i = front; i <= rear; i++)
             cout<<"| "<<queue_array[i]<<" | <-- ";
        cout<<"\n";
    }
    
    printf("\n\n Time Taken in Traversal of Queue : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
} 


//---------------------------------------------------------Main Function--------------------------------------------------------//





int main()
{  
    
    int choice,ch,a,c,num;
    head = NULL;
    
    
do
{
    cout<<"\n ||-----------------------------------------------||";
    cout<<"\n ||      Welcome To Data Structure Visualizer     ||";
    cout<<"\n ||-----------------------------------------------||";
    
    cout<<"\n\n\n\n Choose a Data Structure To perform Operations :";
    cout<<"\n\n 1. Stack  \n 2. Linked List \n 3. Array \n 4. Tree (BST) \n 5. Queue  \n 6. Exit";
    cout<<"\n\n Enter your choice : ";
    
    cin>>choice;

 switch(choice)
 {
     //Stack
     
      case 1: cout << "\033[2J\033[1;1H";
          
          do 
           { cout << "\033[2J\033[1;1H";
           
             cout<<"\n ||-----------------------------------------------||";
             cout<<"\n ||           Stack Data Structure Menu           ||";
             cout<<"\n ||-----------------------------------------------||";
             
             cout<<"\n\n\n Operations ::\n";
             cout<<"\n 1 : Push \n 2 : Pop \n 3 : Visualise \n 4 : Go to Main Menu \n"<<endl;
             cout<<"\n Enter your choice of Operation : ";
             
             cin>>ch;
             
             if(ch == 4)
               break;
             
                 switch(ch) 
                 {
                 case 1:
                        cout << "\033[2J\033[1;1H";
                        int val,m;
                        cout<<"\n Enter no of values to be pushed into Stack : ";
                        cin>>m;
                        for(int i=0;i<m;i++)
                        { 
                          cout<<"\n Enter value "<<i + 1<<" : ";
                          cin>>val;
                          push(val);
                          cout<<"\n";
                        }
                        cout<<"\n\n";
                        display();
                        break;
         
                 case 2:
                        cout << "\033[2J\033[1;1H";
                        pop();
                        break;
         
                 case 3: 
                        cout << "\033[2J\033[1;1H";
                        display();
                        break;
         
                 default: cout<<"\nInvalid Choice of Operation.....";
                 }
             
             cout<<"\n\n\n|------------------------------------------------------------------|";
             cout<<"\n\n 1 : To Go To Stack Menu";
             cout<<"\n 2 : Go Back To Main Menu ";
             cout<<"\n\n Enter your Choice : ";
             cin>>c;
        
            }while(c==1);
                 
       cout << "\033[2J\033[1;1H";     
       break;
       
       
       
       //Linked List
       
       case 2: cout << "\033[2J\033[1;1H";
       
             do
            {
              cout << "\033[2J\033[1;1H";
             cout<<"\n ||-----------------------------------------------||";
             cout<<"\n ||        Linked List  Data Structure Menu       ||";
             cout<<"\n ||-----------------------------------------------||";
              
              cout<<"\n\n\n Operations ::\n";
              cout<<"\n 1. Visualise \n 2. Insert \n 3. Delete \n 4. Search\n 5. Go to Main Menu \n";
              cout<<"\n\n Enter your choice of Operation : ";
              cin>>ch;
              
              if(ch == 5)
               break;
               
              switch(ch)
              {
                case 1: 
                        cout << "\033[2J\033[1;1H";
                        traversal(head);
                        break;
                case 2: 
                        cout << "\033[2J\033[1;1H";
                        cout<<"\n Enter no. of elements to be inserted in the list : ";
                        cin>>a;   
                        for(int i = 0; i < a; i++)
                        insertion(i + 1);
                        traversal(head);
                        break;
                case 3: 
                        cout << "\033[2J\033[1;1H";
                        deletion();
                        break;
                case 4: 
                        cout << "\033[2J\033[1;1H";
                        int pos;
                        pos = search();
                        if(pos==-1)
                        cout<<"\n Entered Node not found in Current Linked List...";
                        break;
                default: cout<<" Invalid choice.......";
                }
                
         cout<<"\n\n\n|------------------------------------------------------------------|";
         cout<<"\n\n 1 : To Go To Linked List Menu";
         cout<<"\n 2 : Go Back To Main Menu ";
         cout<<"\n\n Enter your Choice : ";
         cin>>c;
         
         }while(c==1);
         
    cout << "\033[2J\033[1;1H";      
    break;
    
    
    //Array
    
    case 3: cout << "\033[2J\033[1;1H";
           
            do
            {
              cout << "\033[2J\033[1;1H";
             cout<<"\n ||-----------------------------------------------||";
             cout<<"\n ||           Array Data Structure Menu           ||";
             cout<<"\n ||-----------------------------------------------||";
              
              cout<<"\n\n\n Operations ::\n";
              cout<<"\n 1. Create new Array \n 2. Visualise \n 3. Insert \n 4. Delete \n 5. Go to Main Menu \n";
              cout<<"\n\n Enter your choice of Operation : ";
              cin>>ch;
              
              if(ch == 5)
               break;
              
              switch(ch)
              {
                case 1: 
                        cout << "\033[2J\033[1;1H";
                        arrayCreate();
                        break;
                        
                case 2:
                        cout << "\033[2J\033[1;1H";
                        arrayDisplay();
                        break;
                
                case 3:
                        cout << "\033[2J\033[1;1H";
                        arrayInsert();
                        break;
                
                case 4:
                        cout << "\033[2J\033[1;1H";
                        arrayDelete();
                        break;
                
                default: cout<<"\n Wrong Choice !!!";
                
              }
              
             
            cout<<"\n\n\n|------------------------------------------------------------------|";
            cout<<"\n\n 1 : To Do To Array Menu";
            cout<<"\n 2 : To Go Back To Main Menu ";
            cout<<"\n\n Enter your Choice : ";
            cin>>c;
              
            }while(c==1);
            
        cout << "\033[2J\033[1;1H";      
        break;
        
        
    //Tree
        
    case 4: cout << "\033[2J\033[1;1H"; 
            
            
            do
            {
              cout << "\033[2J\033[1;1H";
             cout<<"\n ||-----------------------------------------------||";
             cout<<"\n ||           Tree Data Structure Menu            ||";
             cout<<"\n ||-----------------------------------------------||";
              
              cout<<"\n\n\n Operations ::\n";
              cout<<"\n 1. Insert \n 2. Delete  \n 3. Inorder \n 4. Preorder \n 5. Postorder \n 6. Visualise \n 7. Go to Main Menu";
              cout<<"\n\n Enter your choice of Operation : ";
              cin>>ch;
              
              if(ch == 7)
               break;
               
              switch(ch)
              {
                  case 1: cout << "\033[2J\033[1;1H";
                          Ttemp = new Tnode;
                          cout<<"\n Enter the number to be inserted : ";
	                      cin>>Ttemp->info;
                          insert(root, Ttemp);
                          break;
                          
                  case 2: cout << "\033[2J\033[1;1H";
                  
                          if (root == NULL)
                          {
                            cout<<"\n Tree is empty, nothing to delete ."<<endl;
                            continue;
                          }
                          
                          
                          cout<<"\n Enter the number to be deleted : ";
                          cin>>num;
                          del(num);
                          break;
                   
                   case 3: cout << "\033[2J\033[1;1H";
                           cout<<"\n Inorder Traversal of BST : ";
                           inorder(root);
                           break;
                    
                    
                   case 4: cout << "\033[2J\033[1;1H";
                           cout<<"\n Preorder Traversal of BST : ";
                           preorder(root);
                           break;
                   
                   case 5: cout << "\033[2J\033[1;1H";
                           cout<<"\n Postorder Trversal of BST : ";
                           postorder(root);
                           break;
                    
                   case 6: cout << "\033[2J\033[1;1H";
                           cout << "\033[2J\033[1;1H";
                           cout<<"\n\n\n | Current BST | \n\n\n ";
                           display(root,1);
                           cout<<"\n\n";
                           
                           break;
                
                   case 7: exit(1);
                   
                   default: cout<<"\nWrong Choice!!!";
                  
              }
            
            cout<<"\n\n\n|------------------------------------------------------------------|";
            cout<<"\n\n 1 : To Go To Tree Menu";
            cout<<"\n 2 : To Go Back To Main Menu ";
            cout<<"\n\n Enter your Choice : ";
            cin>>c;
              
            }while(c==1);
            
        cout << "\033[2J\033[1;1H";      
        break;
              
    
    //Queue         
              
        
    case 5: cout << "\033[2J\033[1;1H"; 
            
            
            do
            {
              cout << "\033[2J\033[1;1H";
             cout<<"\n ||-----------------------------------------------||";
             cout<<"\n ||           Queue Data Structure Menu           ||";
             cout<<"\n ||-----------------------------------------------||";
              
              cout<<"\n\n\n Operations ::\n";
              cout<<"\n 1. Insert \n 2. Delete  \n 3. Visualise \n 4. Go to Main Menu";
              cout<<"\n\n Enter your choice of Operation : ";
              cin>>ch;
              
              if(ch == 4)
               break;
               
              switch(ch)
              {
                case 1: cout << "\033[2J\033[1;1H";
                        Qinsert();
                        break;
                        
                case 2: cout << "\033[2J\033[1;1H";
                        Qdelete();
                        break;
                        
                case 3: cout << "\033[2J\033[1;1H";
                        Qdisplay();
                        break;
                        
                default: cout<<"\nWrong Choice";
              }
             cout<<"\n\n\n|------------------------------------------------------------------|";
             cout<<"\n\n 1 : To Go To Queue Menu";
             cout<<"\n 2 : Go Back To Main Menu ";
             cout<<"\n\n Enter your Choice : ";
             cin>>c;
        
            }while(c==1);
                 
       cout << "\033[2J\033[1;1H";     
       break;
            
    //Exit
    
    case 6: cout << "\033[2J\033[1;1H";  
            cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
            cout<<"\n\t\t\t\t\t   ||................Thanks for Using...............||";
            cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
            exit(0);
              
    default : cout<<"Invalid choice";
              cout << "\033[2J\033[1;1H";  
 }
 
}while(choice!=6);


    return 0;
}
