/*
 * ���ݽṹ�γ����
 * ��Ŀ��  �����������ģ��ϵͳ
 * ������������
 * ѧ�ţ�1552970
 * */


#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

#define MAXSIZE 1000    // ����ͼ������ģ
#define MAXWEIGHT 100000    // ����ߵ����Ȩֵ

struct edge{   // ����߽ṹ��
    edge(string a,string b,int c):x(a),y(b),weight(c){}
    string x,y;
    int weight;
};

int graph[MAXSIZE][MAXSIZE];    // ����ͼ�ṹ
map<string,int> node;       // ����ͼ�нڵ����Ƶ��ڵ�洢λ�õ�ӳ��
map<int,string> denode;     // ����ͼ�нڵ�洢λ�õ����Ƶ�ӳ��
vector<edge> MST;           // ������С������

void printMenu();   // ��ӡ���˵�
void getNodes();    // ��ͼ�в��붥��
void addEdge();     // ��ͼ�в����
void prim(int start);        // prim �㷨����С������
void printTree();   // ��ӡ��С������

int main() {
    printMenu();    // ������˵�
    char c;
    cout<<"��ѡ�������"; // �û��������
    cin>>c;
    string t;
    while(c != 'E'){
        switch (c){     // ���ݲ���ִ����غ���
            case 'A':
                getNodes();
                break;
            case 'B':
                addEdge();
                break;
            case 'C':
                cout<<"��������ʼ���㣺";
                cin>>t;
                if(node.find(t) == node.end())
                    cout<<"���㲻���ڣ�\n";
                else
                    prim(node[t]);
                break;
            case 'D':
                printTree();
                break;
        }

        cout<<"��ѡ�������";
        cin>>c;
    }
	
	system("pause");
    return 0;
}

/*
 * ��ͼ�в���ڵ�
 * �����ڵ�洢λ�úͽڵ����Ƶ�����ӳ��
 * ͬʱ�Խڵ��еı߽��г�ʼ��
 * */
void getNodes(){
    cout<<"�����붥������� ";
    int n;
    cin>>n;
    cout<<"������������������ƣ�\n";
    string name;
    for(int i = 0;i < n;++i){
        cin>>name;
        node.insert(make_pair(name,i));    // �����ڵ����Ƶ��ڵ�洢λ�õ�ӳ��
        denode.insert(make_pair(i,name));      // �����ڵ�洢λ�õ����Ƶ�ӳ��
    }
    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j){
            graph[i][j] = MAXWEIGHT;        //��ʼ�����б�
        }
    cout<<endl;
}

/*
 * ��ͼ������
 * �ޱ����ӵĽڵ���ΪMAXWEIGHT
 * */
void addEdge(){
    int w;
    string n1,n2;
    cout<<"�������������㼰�ߣ�";
    cin>>n1>>n2>>w;
    while(n1 != "?"&&n2 != "?"&&w != 0){        //ѭ���������б�
        if(node.find(n1) == node.end()||node.find(n2) == node.end()){       //����ڵ㲻���ڵ����
            cout<<"���㲻���ڣ�\n";
        }
        else{
            graph[node[n1]][node[n2]] = graph[node[n2]][node[n1]] = w;
        }
        cout<<"�������������㼰�ߣ�";
        cin>>n1>>n2>>w;
    }
    cout<<endl;
}


/*
 * prim�㷨
 * ������С������
 * */
void prim(int start){
    const int N = node.size();  //�ڵ�����
    int distan[N];      //δѡ��ڵ㵽��ѡ�뼰�ڵ㼯����̾���
    int parent[N];      //�ڵ�����ѡ��ڵ�ĸ��ڵ�
    int count = 1;
    for(int i = 0;i < N;++i){   //��ʼ����������
        distan[i] = graph[start][i];
        parent[i] = start;
    }
    parent[start] = -1;     //��ʼ�� 0 �ڵ�
    distan[start] = 0;

    while(1){
        int v = -1;     //��¼��������ڵ�
        int mindis = MAXWEIGHT; //��¼�������

        for(int i = 0;i < N;++i){   //ѭ���������ҳ�����ڵ�
            if(distan[i] != 0&&distan[i] < mindis){
                v = i;
                mindis = distan[i];
            }
        }
        if(v == -1)     //����������ڵ㣬���㷨����
            break;
        ++count;        //��¼��ѡ��ڵ�����
        distan[v] = 0;
        MST.push_back(edge(denode[parent[v]],denode[v],graph[parent[v]][v]));    //�������ɵı߲�����С������

        for(int i = 0;i < N;++i){       //����δѡ��ڵ㵽��ѡ�뼰�ڵ㼯����̾���
            if(distan[i] != 0&&distan[i] > graph[i][v]){
                distan[i] = graph[i][v];
                parent[i] = v;
            }
        }

    }
    if(count < N - 1)       //����ͼ����ͨ�����
        cout<<"��������С��������";
    else
        cout<<"����Prim��С��������\n";

}

/*
 * �����С������
 * */
void printTree(){
    cout<<"��С�������Ķ��׼���Ϊ��\n\n";
    for(int i = 0;i < MST.size();++i){
        cout<<MST[i].x<<"-<"<<MST[i].weight<<">->"<<MST[i].y<<"    ";   //
    }
    cout<<"\n\n";
}

/*
 * ��ӡ���˵�
 * */
void printMenu(){
    cout<<"**       �������ģ��ϵͳ        **\n";
    cout<<"=================================\n";
    cout<<"**       A --- ������������      **\n";
    cout<<"**       B --- ��ӵ����ı�      **\n";
    cout<<"**       C --- ������С������    **\n";
    cout<<"**       D --- ��ʾ��С������    **\n";
    cout<<"**       E --- �˳�����         **\n";
    cout<<"=================================\n";
}













