/*
 * ���ݽṹ�γ����
 * ��Ŀ��  N�ʺ�����
 * ������������
 * ѧ�ţ�1552970
 * */

#include<iostream>
#include<cmath>

using namespace std;

bool qualified(int* map,int m,int n);   // �Ϸ��Լ��麯��
void printmap(int* map,int n);      // ��ӡ�����N�ʺ󲼾�

int main(){

    int n;
    cout<<"����N X N �����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�С��к�ͬһб���ϣ�\n\n";    // ���������ʾ
    cout<<"������ʺ������";
    cin>>n;                 // ������̹�ģ
    cout<<"\n�ʺ�ڷ���\n\n";
    const int N = n;        // ���峣��N��Ϊ���̴�С�����ڽ�����������
    int map[N];             // �������飬�洢ÿ���аڷŻʺ���к�
    int count = 0;
    int i = 0,j = 0;
    while(1){               // ѭ�����Իʺ���ܵİڷ�λ��
        while(j < N){          // �Ե�i�е�����j��������г���
            if(qualified(map,i,j)){     // �ж��Ƿ�Ϊ�Ϸ�λ��
                map[i] = j;         // ����ǺϷ�λ�þͷ��ýڵ�
                j = 0;              // �кŹ�0
                break;
            }
            else                // ������ǺϷ�λ�ã�����̽����һ��
                ++j;
        }
        if(j == N){             // �����ǰ��û�кϷ�λ��
            if(i == 0)          // ����к�Ϊ0��˵���Ѿ��ҵ����������ѭ������
                break;
            else{               // ����кŷ�0�����˻�ǰһ��
                --i;
                j = map[i] + 1;     // ̽��ǰһ��֮ǰ�Ϸ�λ�õ���һ��
            }
        }
        else if(i == N - 1){            // ����Ѿ�̽�������һ�У�˵���Ѿ�����һ�ַ���
            printmap(map,N);           // ����÷���
            ++count;                    // ��¼��������
            j = map[i] + 1;             // ̽��������һ��λ��
        }
        else                            // ������м��У������̽����һ��
            ++i;
    }
    cout<<"\n����"<<count<<"�ֽⷨ��"<<endl;
    system("pause");
    return 0;
}

/*
 * λ�úϷ��Լ��麯��
 * ����ڷ�λ���Ƿ�Ϸ�
 * �������б�򶼲����������ʺ�
 * */
bool qualified(int* map,int m,int n){
    for(int i = 0;i < m;++i){       // �����Ѿ��ںõ�ÿ���ʺ�λ�ã�����Ƿ��г�ͻ
        if(map[i] == n||abs(m - i) == abs(n - map[i]))
            return false;
    }
    return true;
}

/*
 * �ʺ�λ�ô�ӡ����
 * ���ݸ����Ļʺ�λ����Ϣ
 * ��ʽ�������ͼ�лʺ�ڷ�
 * */
void printmap(int* map,int n){
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){       // ��ʽ��������̸���
            if(map[i] == j)
                cout<<"X ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<endl;
}
