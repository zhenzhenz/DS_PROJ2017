/*
 * ���ݽṹ�γ����
 * ��Ŀ��  �´��Թ���Ϸ
 * ������������
 * ѧ�ţ�1552970
 * */

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MAXSIZE 100     // �����ͼ����ģ

/*
 * ����·���ڵ���
 * �洢�ڵ�������Ϣ
 * �����׵Ĺ��캯��
 * �Զ����˱ȽϺ���
 * �Զ����������
 * */
struct PathPoint{
    PathPoint():x(0),y(0){}     // Ĭ�Ϲ��캯��
    PathPoint(int a = 0,int b = 0):x(a),y(b){}  // ��������ֵ�Ĺ��캯��
    friend ostream& operator <<(ostream&, const PathPoint&);    // �Զ��������
    bool operator == (const PathPoint& target){     // �Զ���ȽϺ���
        return (x==target.x&&y==target.y);
    }

    int x;      // �ڵ������
    int y;      // �ڵ�������
};

/*
 * �Զ���������
 * ��ʽ������ýڵ������
 * */
ostream& operator <<(ostream& out, const PathPoint& p){
    out<<'<'<<p.x<<','<<p.y<<'>';
    return out;
}

int map[MAXSIZE][MAXSIZE];      // ��ͼ���飬��¼��ͼ��Ϣ
int mark[MAXSIZE][MAXSIZE];     // ��Ƿ��ʹ���λ��
vector<PathPoint> PathStack;  // ջ�洢·��

void initMap(int M,int N);      // ��ͼ��ʼ������
void readMap(int M,int N);      // ��ͼ��Ϣ���뺯��
void createPath(PathPoint e);   // ·����Ѱ����
void print(int M,int N,PathPoint e);        // ·����ӡ����

int main(){

    int m,n;
    cout<<"�������Թ�����������(��������ǽ):\n";       // �����Թ���ģ
    cin>>m>>n;
    const int M = m;        // �����Թ���ģ����
    const int N = n;

    initMap(M,N);           // ��ʼ���Թ���ͼ

    readMap(M,N);           // �����Թ���ͼ

    cout<<"������������꣺\n";
    cin>>m>>n;                  // �����Թ�����
    PathPoint exit(m,n);        // �������ڽڵ�

    //���ںϷ��Լ��
    if(map[exit.x][exit.y] == 1||exit.y != N){      // ������ڴ���ǽ����ڲ����Թ���Ե��Ƿ�
        cout<<"�Ƿ��ĳ��ڣ�\n";
        return 0;
    }

    if(map[1][1] == 1)
        cout<<"��1��1����ʼλ����ǽ��·���Ƿ�\n";
    else{
        createPath(exit);       // ���Թ�������·��

        print(M,N,exit);            // ��ӡ·��
    }

	system("pause");
    return 0;
}

/*
 * �Ե�ͼ���г�ʼ������
 * ������ͼ��Ե����������
 * */
void initMap(int M,int N){
    //��ʼ��map,mark
    memset(map,0,(M + 2)*(N + 2)*sizeof(int));      // �Ե�ͼ����
    memset(mark,0,(M + 2)*(N + 2)*sizeof(int));     // �Ա����������
    for(int i = 0;i < N + 2;++i)                    // ����ͼ�߽���ǽ��1
        map[M + 1][i] = map[0][i] = 1;
    for(int i = 0;i < M + 2;++i)
        map[i][0] = map[i][N + 1] = 1;
}

/*
 * �����ͼ��Ϣ
 * 0 ����ͨ·��1 ����·��
 * ������Թ���ͼ��������ǽ
 * */
void readMap(int M,int N){
    //�����ͼ
    cout<<"�������ͼ���и��У�0 ����ͨ·��1 ����·�ϣ�\n";

    for(int i = 1;i <= M;++i)
        for(int j = 1;j <= N;++j){
            cin>>map[i][j];
        }

}

/*
 * ���Թ�������·��
 * ͨ��ջ���洢��;�ڵ�
 * ����DFS����̽Ѱ·��
 * */
void createPath(PathPoint e){

    mark[1][1] = 1;     // �ӣ�1��1��λ�ÿ�ʼ̽Ѱ
    PathStack.push_back(PathPoint(1,1));    // ����ʼ��1��1��λ��ѹ��ջ��

    while(!PathStack.empty()){      // ջ�ǿ�ʱһֱ̽Ѱ·��
        PathPoint current = PathStack.back();   // ȡ��ջ��Ԫ�أ�����Ϊ���̽Ѱ·��
        if(current == e)        // ջ��Ԫ��Ϊ���ڣ����ҵ�·����̽Ѱ����
            break;
        if(mark[current.x][current.y - 1] == 0&&map[current.x][current.y - 1] == 0){        //��̽Ѱ�Ϸ�·��
            PathStack.push_back(PathPoint(current.x,current.y - 1));
            mark[current.x][current.y - 1] = 1;
        }
        else if(mark[current.x + 1][current.y] == 0&&map[current.x + 1][current.y] == 0){   //̽Ѱ�Ҳ�·��
            PathStack.push_back(PathPoint(current.x + 1,current.y));
            mark[current.x + 1][current.y] = 1;
        }
        else if(mark[current.x][current.y + 1] == 0&&map[current.x][current.y + 1] == 0){   //̽Ѱ�·�·��
            PathStack.push_back(PathPoint(current.x,current.y + 1));
            mark[current.x][current.y + 1] = 1;
        }
        else if(mark[current.x - 1][current.y] == 0&&map[current.x - 1][current.y] == 0){   //̽Ѱ���·��
            PathStack.push_back(PathPoint(current.x + 1,current.y));
            mark[current.x - 1][current.y] = 1;
        }
        else
            PathStack.pop_back();       //�ĸ�������߲�ͨ�����˻�ǰһ��
    }

}

/*
 * ��ʽ�����·��ͼ�Լ�·��
 * �ڲ������˸�������printmap
 * */
void print(int M,int N,PathPoint e){
    //������

    char printmap[M + 2][N + 2];        // ���������������

    if(PathStack.back() == e){          // ����ҵ��˳��ڣ����ӡ·�ߵ�ͼ

        for(int i = 0;i < M + 2;++i)        // �Ƚ�ǽ��·д��
            for(int j = 0;j < N + 2;++j){
                if(map[i][j] == 1)
                    printmap[i][j] = '#';
                else
                    printmap[i][j] = '0';
            }
        for(int i = 0;i < PathStack.size();++i){        // д����������·��
            printmap[PathStack[i].x][PathStack[i].y] = 'x';
        }
        cout<<"�Թ���ͼ��\n\n";      //��ʽ�������ͼ
        cout<<"   	";
        for(int i = 0;i < N + 2;++i)
            cout<<i<<"��	";
        cout<<endl;
        for(int i = 0;i < M + 2;++i){
            cout<<i<<"��	";
            for(int j = 0;j < N + 2;++j)
                cout<<printmap[i][j]<<"  	";
            cout<<"\n\n";
        }

        cout<<"�Թ�·����\n\n";      // ��ʽ�����·��
        for(int i = 0;i < PathStack.size() - 1;++i){
            cout<<PathStack[i]<<" ---> ";
        }
        cout<<e<<endl;
    }
    else
        cout<<"�Թ�û�кϷ�·����\n";    // ���û���ҵ���������ʾ����

}
