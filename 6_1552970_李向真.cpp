/*
 * ���ݽṹ�γ����
 * ��Ŀ��  ���׹���ϵͳ
 * ������������
 * ѧ�ţ�1552970
 * */

#include <iostream>
#include <string>

using namespace std;

/*��Ա�ṹ�� member*/
struct member{
    member(){}    // Ĭ�Ϲ��캯��
    member(string n):name(n){}   // �ó�Ա���ֳ�ʼ��
    ~member(){         //  ��������
        offspring = NULL;
        brother = NULL;
    }
    string name;     // ��Ա����
    member* offspring = NULL;   // ����
    member* brother = NULL;     // �ֵ�
};

typedef member* familyTree;   // ����������

member* findMember(familyTree tree,string m){  // �������ֲ��ҳ�Ա
    if(tree == NULL)   //����ʧ��
        return NULL;
    if(tree->name == m)  //���ҳɹ�
        return tree;

    member* temp = findMember(tree->brother,m);
    if(temp != NULL)     //�Ȳ��ҳ���
        return temp;
    else
        return findMember(tree->offspring,m);   //�ݹ����ͬ����Ա
}

member* addOffspring(familyTree tree,string n){  // Ϊָ����Ա��Ӻ��
    if(tree->offspring == NULL)   //����������
        tree->offspring = new member(n);
    else{
        member* temp = tree->offspring;
        while(temp->brother != NULL)   //�ҵ�ͬ�����һ����Ů
            temp = temp->brother;
        temp->brother = new member(n);
    }
    return tree;
}

member* modify(familyTree tree,string past,string now){ // �޸�ָ����Ա������
    member* temp = findMember(tree,past);
    if(temp == NULL)    //�жϲ����Ϸ���
        cout<<"���޴��ˣ�\n";
    else
        temp->name = now;

    return temp;
}

void deleteFamily(familyTree tree){  // ɾ��ָ����Ա
    if(tree != NULL){
        deleteFamily(tree->brother);   //�ݹ��ɾ���ýڵ������ֵܼ���Ů�ڵ�
        deleteFamily(tree->offspring);
        delete tree;
    }
}

void displayOffspring(familyTree p){  //���������Ů��Ϣ
    cout<<p->name<<"�ĵ�һ�������ǣ�";
    p = p->offspring;        //���������
    while(p != NULL){       //ѭ������ֵܽڵ�
        cout<<p->name<<" ";
        p = p->brother;
    }
    cout<<endl;
}

void menu(){    //��ӡ�˵�
    cout<<"**          ���׹���ϵͳ         **\n"
        <<"=================================\n"
        <<"**    ��ѡ��Ҫִ�еĲ�����        **\n"
        <<"**     A --- ���Ƽ�ͥ            **\n"
        <<"**     B --- ��Ӽ�ͥ��Ա        **\n"
        <<"**     C --- ��ɢ�ֲ���ͥ        **\n"
        <<"**     D --- ���ļ�ͥ��Ա����    **\n"
        <<"**     E --- �˳�����           **\n"
        <<"=================================\n"
        <<"���Ƚ���һ�����ף�\n"
        <<"���������ȵ�������";
}

int main() {

    string n;
    familyTree myTree;
    menu();  //��ʼ������˵�
    cin>>n;
    cout<<"�˼��׵������ǣ�"<<n<<endl;
    myTree = new member(n);   //�½�һ�ż�����
    char op;
    int num;
    member* p;
    cout<<"\n��ѡ��Ҫִ�еĲ�����";
    /*
     * ���ݲ�ͬ��ѡ��ִ�в���
     */
    while(cin>>op && op != 'E'){
        switch (op){
            case 'A':
                cout<<"������Ҫ������ͥ���˵�������";
                cin>>n;
                p = findMember(myTree,n);
                if(p == NULL){         //����Ƿ�����
                    cout<<"���޴��ˣ�\n";
                    break;
                }
                cout<<"������" <<n<<"�Ķ�Ů����";
                cin>>num;
                cout<<"����������"<<n<<"�Ķ�Ů��������";
                for(int i = 0;i < num;++i){    //ѭ�������Ů
                    cin>>n;
                    addOffspring(p,n);
                }
                displayOffspring(p);
                break;
            case 'B':
                cout<<"������Ҫ��Ӷ���(��Ů��)���˵�������";
                cin>>n;
                p = findMember(myTree,n);
                if(p == NULL){          //����Ƿ�����
                    cout<<"���޴��ˣ�\n";
                    break;
                }
                cout<<"������"<<n<<"����ӵĶ���(��Ů��)��������";
                cin>>n;
                addOffspring(p,n);
                displayOffspring(p);
                break;
            case 'C':
                cout<<"������Ҫ��ɢ���˵�������";
                cin>>n;
                cout<<"Ҫ��ɢ��ͥ�����ǣ�"<<n<<endl;
                p = findMember(myTree,n);
                if(p == NULL){        //����Ƿ�����
                    cout<<"���޴��ˣ�\n";
                    break;
                }
                displayOffspring(p);
                deleteFamily(p->offspring);  //ɾ���ýڵ�������Ů
                p->offspring = NULL;         //����Ӧָ���ÿգ�����Ƿ�����
                break;
            case'D':
                cout<<"������Ҫ���ĵ��˵�Ŀǰ������";
                cin>>n;
                string now;
                cout<<"��������ĺ��������";
                cin>>now;
                modify(myTree,n,now);   //�޸ĸýڵ�
                cout<<n<<"�Ѹ���Ϊ"<<now<<endl;
                break;
        }
        cout<<"\n��ѡ��Ҫִ�еĲ�����";
    }
    
    system("pause");
    return 0;
}



















