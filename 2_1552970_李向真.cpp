/*
 * ���ݽṹ�γ����
 * ��Ŀ��  Լɪ������������Ϸ
 * ������������
 * ѧ�ţ�1552970
 * */

#include<iostream>
using namespace std;

/*
 * �˿ͽṹ��
 * �����Լɪ�򻷵Ľڵ�����
 * */
struct Member{
    Member():next(NULL){}       // Ĭ�Ϲ��캯��
    Member(int s){              // ���캯��������˿�λ�ñ��
        id = s;
        next = NULL;
    }

    int id;                 // λ�ñ��
    Member* next;           // ���ڵ���һ���ڵ�
};

/*
 * Լɪ������������
 * ʵ������һ��ѭ������
 * �ṩ�ڻ����Ʋ���ɾ���Ȳ���
 * */
struct DyingList{
    DyingList(){}           // Ĭ�Ϲ��캯��
    DyingList(int sz);      // ���캯�������뻷�ĳ���

    Member* step(int n,Member* beg);    // �Ʋ��������ƶ�ָ������
    Member* kill(Member* target);       // ɱ�˺�����ɾ���ڵ�

    int size;                       // �������ĳ���
    Member* head;                   // ������ͷ�ڵ�ָ��
};


/*
 * ���������캯��
 * ��������������
 * ������Ӧ���ȵ�������
 * */
DyingList::DyingList(int sz){
    size = sz;          // ���������ȸ�ֵ
    head = new Member(1);         // ����ͷ�ڵ�
    Member* p = head;

    for(int i = 2;i <= sz;++i){     // ѭ���Ľ�������ڵ�
        p->next = new Member(i);
        p = p->next;
    }
    p->next = head;
}

/*
 * �Ʋ�����
 * ����Ҫ�ƶ��Ĳ����Լ��ƶ���ʼ�ڵ�
 * �����ƶ����λ��ָ��
 * */
Member* DyingList::step(int n,Member* beg){
    for(int i = 0;i < n;++i){       // ѭ���Ʋ���ÿ���ƶ��Ʋ�
        beg = beg->next;
    }
    return beg;         // �����ƶ���λ��
}

/*
 * ɱ�˺���
 * ��ɾ������
 * ����Ҫɾ���Ľڵ�ָ��
 * ���ر�ɾ�ڵ����һ���ڵ�
 * */
Member* DyingList::kill(Member* target){
    if(target == head)          // ����ɾ��ͷ�ڵ�����
        head = target->next;

    Member* p = head;
    while(p->next != target){       // Ѱ�ұ�ɾ���ڵ��ǰ���ڵ�
        p = p->next;
    }
    p->next = target->next;         // ������ȥ���ڵ�
    p = target->next;               // ������ɾ�ڵ����һ���ڵ�
    delete target;                  // �ͷű�ɾ�ռ�
    return p;                       // ���ر�ɾ�ڵ����һ��
}

int main(){

    /*
     * ��ʼ����Ϸ��Ϣ
     * */
    cout<<"����N��Χ��һȦ���ӵ�S���˿�ʼ���α�������M���˳��֣�������һ���˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ\n\n";
    int n,m,s,k;
    cout<<"������������Ϸ��������N:";
    cin>>n;
    cout<<"��������Ϸ��ʼ��λ��S:  ";
    cin>>s;
    cout<<"��������������M:        ";
    cin>>m;
    cout<<"������ʣ�����������K:  ";
    cin>>k;
    cout<<endl;


    /*
     * ����Ƿ���������
     * */
    if(n == 0){
        cout<<"��Ϸ����Ϊ0���Ƿ����룡\n";
        return 0;
    }
    else if(n < k){
        cout<<"��Ϸ�������٣��Ƿ����룡\n";
        return 0;
    }
    else if(n < s){
        cout<<"�Ƿ��Ŀ�ʼλ�ã�\n";
        return 0;
    }


    DyingList list(n);          // ��������ĳ˿���������Լɪ��
    Member* current = list.head;        // ָ�����ָ��������ͷ�ڵ�
    current = list.step(s - 1,current);         // ���ݿ�ʼλ�õ�Ҫ����ת����Ӧλ��

    /*
     * ѭ��ִ�� n - k �Σ�ÿ��ɱ��һ����
     * �����ʣ�� k ����
     * */
    for(int i = 1;i <= n - k;++i){
        Member* killed = list.step(m - 1,current);      // ÿ����ת m - 1 ��λ��
        cout<<"��"<<i<<"�����ߵ�λ���ǣ�	"<<killed->id<<endl;        // ɱ����Ӧλ�õ���
        current = list.kill(killed);
    }

    /*
     * �����Ϸ���
     * */
    cout<<"\n���ʣ�£�	"<<k<<"��\n";

    cout<<"ʣ�����ߵ�λ��Ϊ��	";
    Member* p = list.head;
    for(int i = 0;i < k;++i){       // ѭ�������������ʣ����˵�λ��
        cout<<p->id<<"	";
        p = p->next;
    }
	system("pause");
    return 0;
}
