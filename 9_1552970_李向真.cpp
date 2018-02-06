/*
 * ���ݽṹ�γ����
 * ��Ŀ��  ����������
 * ������������
 * ѧ�ţ�1552970
 * */

#include <iostream>
#include <sstream>

using namespace std;

typedef int ElementType;    // Ԫ�ؼ�ֵ����
typedef struct TNode *BinTree;  // ��������������

struct TNode{           //�����������ڵ�����
    ElementType Data;   //�ڵ�ؼ�������
    BinTree Left;       //������
    BinTree Right;      //������
};

BinTree Insert( BinTree BST, ElementType X );   // ���뺯��

BinTree Find( BinTree BST, ElementType X );     //���Һ���

void printTree(BinTree BT);                 //�������
void InorderTraversal( BinTree BT );        //�������
void menu();        //���˵�����

int main()
{
    menu();     //��ӡ���˵�

    BinTree BST = NULL;     //�����µĿ���
    ElementType X;

    stringstream ss;   // �ַ�������
    string nodes;       // ���ַ�����ʽ����һ�ж������ڵ�
    int temp;
    int choice;         // ����ѡ��
    cout<<"Please select:   ";
    cin>>choice;

    while(choice != 4){     //ѭ��������ѡ����
        switch (choice){
            case 1:
                cout<<"Please input key to create Bsort_Tree:\n";       // �����ַ������нڵ�
                getchar();
                getline(cin,nodes);
                ss<<nodes;

                while(ss>>X&&X != 0){       // ������Ԫ��Ϊ0ʱ������ֹͣ
                    BST = Insert(BST,X);
                }
                printTree(BST);
                break;
            case 2:
                cout<<"Please input key which is inserted:  ";   //���뵥���ڵ�
                cin>>temp;
                Insert(BST,temp);
                printTree(BST);
                break;
            case 3:
                cout<<"Please input key which is searched:  ";
                cin>>temp;
                BinTree found = Find(BST,temp);
                if(found == NULL)           // ����Ԫ�ز��������
                    cout<<temp<<" not exist\n\n";
                else
                    cout<<"search success!\n\n";
                break;
        }
        cout<<"Please select:   ";
        cin>>choice;
    }
	
	system("pause");
    return 0;
}

/*
 * ��ӡ���˵�
 * */
void menu(){
    cout<<"**        ����������            **\n";
    cout<<"=================================\n";
    cout<<"**       1 --- ��������������    **\n";
    cout<<"**       2 --- ����Ԫ��         **\n";
    cout<<"**       3 --- ��ѯԪ��         **\n";
    cout<<"**       4 --- �˳�����         **\n";
    cout<<"=================================\n";
}

/*
 * ������������в���ڵ�
 * �����������ĸ��ڵ��Լ��������Ԫ�ؼ�ֵ
 * ���ر������ڵ��ָ������
 * ���ڵݹ����
 * */
BinTree Insert( BinTree BST, ElementType X ){
    if(!BST){           // ����������
        BST = new TNode;
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else{       // �ݹ����
        if(X > BST->Data)    // ���ݽڵ��ֵѡ�����λ��
            BST->Right = Insert(BST->Right,X);
        else if(X < BST->Data)
            BST->Left = Insert(BST->Left,X);
        else
            cout<<"The input key<"<<X<<">"<<"iS have in!\n";      // ����Ԫ���Ѿ����ڵ����
    }

    return BST;
}

/*
 * �ڶ����������в���Ԫ��
 * �ݹ����
 * ���ر�����Ԫ�ص�ָ��
 * */
BinTree Find( BinTree BST, ElementType X ){
    if(BST == NULL){
        return NULL;
    }
    if(BST->Data == X){

        return BST;
    }
    else if(BST->Data < X)
        return Find(BST->Right,X);
    else
        return Find(BST->Left,X);
}

/*
 * �����������������
 * ���������˳����ǽڵ��ֵ��С����
 * */
void InorderTraversal( BinTree BT ){
    if(!BT){
        return;
    }

    else{
        InorderTraversal(BT->Left);
        cout<<BT->Data<<"->";
        InorderTraversal(BT->Right);
    }
}

/*
 * ��ӡ����������
 * ��ӡ��˳���սڵ��ֵ��С����
 * �ڲ������������
 * */
void printTree(BinTree BT){
    if(BT == NULL) {
        cout<<"Empty Tree\n";
        return;
    }
    else{
        cout<<"Bsort_Tree is:\n";
        InorderTraversal(BT);
        cout<<"\n\n";
    }
}
