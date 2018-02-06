/*
 * ���ݽṹ�γ����
 * ��Ŀ��  ��������
 * ������������
 * ѧ�ţ�1552970
 * */

#include <iostream>

using namespace std;


struct Node{    //�ѽ��
    int* data;      //��Ԫ������
    int size;       //�ѵĴ�С
    int capacity;      //�ѿ��Կռ��С
};

typedef Node* Heap;     //������

/*
 * �½���һ���յĶ�
 * �ѵ�Ԥ�ƴ�С�ɲ��� ``` int size ``` ����
 * */
Heap creat(int size){
    Heap h = new Node;
    h->data = new int[size + 1];
    h->size = 0;
    h->capacity = size;
    h->data[0] = -10006;

    return h;
}

/*
 * ���뺯��
 * ����в���һ����Ԫ��
 * Ԫ��Ȩֵ�ɲ�������
 * */
Heap insert(Heap h,int x){

    if(h->size == h->capacity){
        cout<<"Heap is FULL\n";
        return h;
    }

    int i = ++h->size;

    for( ; h->data[i/2] > x; i /= 2){
        h->data[i] = h->data[i/2];
    }
    h->data[i] = x;
    return h;
}

/*
 *ɾ������
 *ɾ���Ѷ��ڵ�
 *���ظýڵ�Ȩֵ
 * */
int delet(Heap h){
    if(h->size == 0){
        cout<<"��Ϊ�գ�\n";
        return -1;
    }
    int result = h->data[1];
    int tag = h->data[h->size];
    --h->size;
    int p,c;
    for(p = 1;p*2 <= h->size;p = c){
        c = p*2;
        if(c + 1 <= h->size && h->data[c] > h->data[c + 1])
            ++c;
        if(h->data[c] >= tag)
            break;
        else
            h->data[p] = h->data[c];
    }
    h->data[p] = tag;
    return result;
}


void test();

/*
 * ����������
 * */
int main() {

//    test();

    int n,x;
    cin>>n;     //����ѵ�����ģ
    Heap hp = creat(2*n);     //�����µĶ�
    for(int i = 0;i < n;++i){       //ѭ������в���Ԫ��
        cin>>x;
        insert(hp,x);
    }

    int answer = 0;     //��¼��ľͷ����
    while(hp->size > 1){
        int p = delet(hp);  //��������ȡ���Ѷ�Ԫ��
        p += delet(hp);
        answer += p;    //��¼�ۼƺ�
        insert(hp,p);   //�����β�����Ԫ�ز����
    }

    cout<<answer<<endl;     //�����
	
	system("pause");
    return 0;
}

/*
 * ���Ը�������
 * ���ڽ��ѣ��ѵ�ɾ�����ѵĲ���Ȳ������в���
 * */
void test(){
    cout<<"�������Ԫ�ظ�����\n";
    int n,x;
    cin>>n;
    cout<<"�������Ԫ��ֵ��\n";
    Heap hp = creat(n);     //�����µĶ�
    for(int i = 0;i < n;++i){       //ѭ������в���Ԫ��
        cin>>x;
        insert(hp,x);
    }

    cout<<"����Ԫ������Ϊ��\n";
    for(int i = 1;i <= n;++i)
        cout<<hp->data[i]<<" ";
    cout<<endl;

    cout<<"��ɾ���ĶѶ�Ԫ��Ϊ��"<<delet(hp)<<endl;
    cout<<"ɾ�������Ԫ��Ϊ��"<<endl;
    for(int i = 1;i < n;++i)
        cout<<hp->data[i]<<" ";
    cout<<endl;
    cout<<"������Ҫ�²����Ԫ��\n";
    cin>>x;
    insert(hp,x);
    cout<<"��������Ԫ��Ϊ��\n";
    for(int i = 1;i <= n;++i)
        cout<<hp->data[i]<<" ";
    cout<<endl;
}





