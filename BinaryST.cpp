# include <iostream>
# include <cstdlib>
#include <graphics.h>
#include<string>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* root=NULL;
int positionx=240,positiony=100,level=0,levelx=0,levely=0;
void draw_circle(int n)
{
    circle(positionx, positiony, 30);
    char intStr[36] = {0};
    itoa(n,intStr,10);
    outtextxy(positionx,positiony,intStr);
    positiony=100;
    positionx=240;
    levelx=0;
    levely=0;
    level=0;
    // getch();
    // closegraph();
    // return 0;
}
void draw_line(string str)
{
    if(str=="left")
    {
        if(level==1)
        {
            int parentx=positionx+70;
            int parenty=positiony-70;
            line(parentx,parenty+30,positionx,positiony-30);
        }
        else
        {
            int parentx=positionx+70;
            int parenty=positiony-70;
            line(parentx-30,parenty+30,positionx,positiony-30);
        }
    }
    else if(str=="right")
    {
        if(level==1)
        {
            int parentx=positionx-70;
            int parenty=positiony-70;
            line(parentx,parenty+30,positionx,positiony-30);
        }
        else
        {
            int parentx=positionx-70;
            int parenty=positiony-70;
            line(parentx+30,parenty+30,positionx,positiony-30);
        }
    }
}
void insert_node(int new_data)
{
    if(root==NULL)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->left = NULL;
        new_node->right= NULL;
        root=new_node;
        draw_circle(new_data);
        level++;
    }
    else
    {
        struct Node* X=root;
        struct Node* Y=NULL;
        int i=70,j=70;
        while(X!=NULL)
        {
            Y=X;
            if(X->data > new_data)
            {
                X=X->left;
                positionx-=i;
                levelx++;

            }
            else
            {
                X=X->right;
                positionx+=j;
                levely++;
            }
            i=i-30;
            j=j-30;
        }
        if(Y->data > new_data)
        {
            level=levelx+levely;
            struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
            new_node->data = new_data;
            new_node->left = NULL;
            new_node->right= NULL;
            Y->left=new_node;
            positiony+=70*level;
            draw_line("left");
            draw_circle(new_data);
        }
        else
        {
            level=levelx+levely;
            struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
            new_node->data = new_data;
            new_node->left = NULL;
            new_node->right= NULL;
            Y->right=new_node;
            positiony+=70*level;
            draw_line("right");
            draw_circle(new_data);
        }
    }

}

void inorder(struct Node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<"  ";
        inorder(ptr->right);
    }
}
void preorder(struct Node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->data<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void postorder(struct Node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<"  ";
    }
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    bool flag=true;
    int b;
    while(flag)
    {
        cout<<"0 For Insert"<<"\n";
        cout<<"1 For In-Order"<<"\n";
        cout<<"2 For Pre-Order"<<"\n";
        cout<<"3 For Post-Order"<<"\n";
        cout<<"4 For Exit"<<"\n";
        cout<<"Enter Choice:";
        int c;
        cin>>c;
        switch(c)
        {
        case 0:
            cout<<"Enter Element:";
            cin>>b;
            insert_node(b);
            break;
        case 1:
            cout<<"In Order:";
            inorder(root);
            cout<<"\n";
            break;
        case 2:
            cout<<"Pre Order:";
            preorder(root);
            cout<<"\n";
            break;
        case 3:
            cout<<"Post Order:";
            postorder(root);
            cout<<"\n";
            break;
        case 4:
            flag=false;
            exit(0);
            break;
        default:
            cout<<"Enter Again"<<endl;
            break;
        }
    }
}
