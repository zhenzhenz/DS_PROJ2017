/*
 * ���ݽṹ�γ����
 * ��Ŀʮ  8�������㷨�ıȽϰ���
 * ������������
 * ѧ�ţ�1552970
 * */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>

#define MAXNUM 10000    // ��������������ֵ
using namespace std;

clock_t start,stop;     // ��¼������ʼ����ֹʱ��
double time_consuming;  // ����ʱ��
int swap_num = 0;       // ��������

int bubble_sort(int array[],int n);     // ð������
int select_sort(int array[],int n);     // ѡ������
int insert_sort(int array[],int n);     // ��������
int shell_sort(int array[],int n);      // ϣ������
int quick_sort(int array[],int n);      // ��������
int heap_sort(int array[],int n);       // ������
int merge_sort(int array[],int n);      // �鲢����
int radix_sort(int array[],int n);      // ��������

void menu();    // ��ӡ���˵�

int main() {

    menu();     // ��ʼ���˵�����

    srand((unsigned)time(NULL));    // �����������
    int n;
    cout<<"������Ҫ������������ĸ�����";
    cin>>n;                         // �������������

    int* array = new int[n];        // �������ݵ�����
// 	for(int i = 0;i < n;++i)
  //  	array[i] = rand()%MAXNUM; 
    int choice;
    cout<<"��ѡ�������㷨�� ";
    cin>>choice;
    while(choice != 9){             // ѭ�������û�ѡ��
        int s;
        switch (choice){
            case 1:
                for(int i = 0;i < n;++i)
        		array[i] = rand()%MAXNUM;   // �����������

                start = clock();
                s = bubble_sort(array,n);
                stop = clock();
                time_consuming = (double)(stop - start)/CLOCKS_PER_SEC;     // ��ʽ����������㷨������
                cout<<"ð����������ʱ�䣺 ";
                cout<<time_consuming<<endl;
                cout<<"ð�����򽻻������� "<<s<<endl<<endl;
                break;
            case 2:
            	for(int i = 0;i < n;++i)
        			array[i] = rand()%MAXNUM;   // �����������

                start = clock();
                s = select_sort(array,n);
                stop = clock();
                time_consuming = (double)(stop - start)/CLOCKS_PER_SEC;
                cout<<"ѡ����������ʱ�䣺 ";
                cout<<time_consuming<<endl;
                cout<<"ѡ�����򽻻������� "<<s<<endl<<endl;
                break;
            case 3:
            	for(int i = 0;i < n;++i)
        			array[i] = rand()%MAXNUM;   // �����������

                start = clock();
                s = insert_sort(array,n);
                stop = clock();
                time_consuming = (double)(stop - start)/CLOCKS_PER_SEC;
                cout<<"ֱ�Ӳ�����������ʱ�䣺 ";
                cout<<time_consuming<<endl;
                cout<<"ֱ�Ӳ������򽻻������� "<<s<<endl<<endl;
                break;
            case 4:
            	for(int i = 0;i < n;++i)
        		   array[i] = rand()%MAXNUM;   // �����������

                start = clock();
                s = select_sort(array,n);
                stop = clock();
                time_consuming = (double)(stop - start)/CLOCKS_PER_SEC;
                cout<<"ϣ����������ʱ�䣺 ";
                cout<<time_consuming<<endl;
                cout<<"ϣ�����򽻻������� "<<s<<endl<<endl;
                break;
            case 5:
            	for(int i = 0;i < n;++i)
        		array[i] = rand()%MAXNUM;   // �����������

                start = clock();
                s = quick_sort(array,n);
                stop = clock();
                time_consuming = (double)(stop - start)/CLOCKS_PER_SEC;
                cout<<"������������ʱ�䣺 ";
                cout<<time_consuming<<endl;
                cout<<"�������򽻻������� "<<s<<endl<<endl;
                break;
            case 6:
            	for(int i = 0;i < n;++i)
        		array[i] = rand()%MAXNUM;   // �����������

                start = clock();
                s = heap_sort(array,n);
                stop = clock();
                time_consuming = (double)(stop - start)/CLOCKS_PER_SEC;
                cout<<"����������ʱ�䣺 ";
                cout<<time_consuming<<endl;
                cout<<"�����򽻻������� "<<s<<endl<<endl;
                break;
            case 7:
            	for(int i = 0;i < n;++i)
        		array[i] = rand()%MAXNUM;   // �����������

                start = clock();
                s = heap_sort(array,n);
                stop = clock();
                time_consuming = (double)(stop - start)/CLOCKS_PER_SEC;
                cout<<"�鲢��������ʱ�䣺 ";
                cout<<time_consuming<<endl;
                cout<<"�鲢����Ƚϴ����� "<<s<<endl<<endl;
                break;
            case 8:
            	for(int i = 0;i < n;++i)
        		array[i] = rand()%MAXNUM;   // �����������

                start = clock();
                s = radix_sort(array,n);
                stop = clock();
                time_consuming = (double)(stop - start)/CLOCKS_PER_SEC;
                cout<<"������������ʱ�䣺 ";
                cout<<time_consuming<<endl;
                cout<<"�������򽻻������� "<<s<<endl<<endl;
                break;
        }
        cout<<"��ѡ�������㷨�� ";
        cin>>choice;
    }

//    delete[] array;
	
	system("pause");
    return 0;
}


/*
 * ��ӡ���˵�
 * */
void menu(){

    cout<<"**        �����㷨�Ƚ�           **\n";
    cout<<"=================================\n";
    cout<<"**       1 --- ð������         **\n";
    cout<<"**       2 --- ѡ������         **\n";
    cout<<"**       3 --- ֱ�Ӳ�������      **\n";
    cout<<"**       4 --- ϣ������         **\n";
    cout<<"**       5 --- ��������         **\n";
    cout<<"**       6 --- ������           **\n";
    cout<<"**       7 --- �鲢����         **\n";
    cout<<"**       8 --- ��������         **\n";
    cout<<"**       9 --- �˳�����         **\n";
    cout<<"=================================\n\n";

}


/*
 * ð�������㷨
 * �������������������ݹ�ģ
 * �������򽻻�����
 * �����˽������ flag
 * ��ʱ�ж��㷨�Ľ���
 * */
int bubble_sort(int array[],int n){

    int swap_count = 0;     // ��ʼ����������
    int flag = 0;           // �������
    for(int i = 0; i < n-1; ++i){   // ���� n - 1 ��
        for(int j = 0;j < n - i - 1; ++j){  // ÿ�ι�ģ��С
            if(array[j] > array[j + 1]){
                int t = array[j];
                array[j] = array[j + 1];    // ����������˳���Ԫ��
                array[j + 1] = t;
                ++swap_count;       // ��¼��������
                flag  = 1;
            }
        }
        if(flag == 0)       // δ������������ǰ��ֹ�㷨
            break;
    }
    return swap_count;
}


/*
 * ѡ�������㷨
 * �������������������ݹ�ģ
 * �������򽻻�����
 * */
int select_sort(int array[],int n){

    int swap_count = 0;     // ��ʼ����������
    for(int i = 0;i < n-1;++i){
        int mintag = i;         // ��СԪ���±�
        int min = 100001;       // ��ʼ����Сֵ
        for(int j = i;j < n;++j){   // �����ҳ���СԪ��
            if(array[j] < min){
                min = array[j];
                mintag = j;
            }
        }
        int t = array[i];           // ��СԪ�ؽ�������ȷλ��
        array[i] = array[mintag];
        array[mintag] = t;
        ++swap_count;           // ��¼��������
    }

    return swap_count;
}

/*
 * ���������㷨
 * �������������������ݹ�ģ
 * �������򽻻�����
 * */
int insert_sort(int array[],int n){

    int swap_count = 0;
    for(int i = 1;i < n;++i){
        int current = array[i];
        int j;
        for(j = i;j > 0&&current < array[j - 1];--j){
            array[j] = array[j - 1];
            ++swap_count;
        }
        array[j] = current;
    }

    return swap_count;
}


/*
 * ϣ�������㷨
 * �������������������ݹ�ģ
 * �������򽻻�����
 * �Զ����� 0��1��5��19 Ϊϣ������������
 * */
int shell_sort(int array[],int n){

    int swap_count = 0;             // ��ʼ����������
    int shell[4] = {19,5,1,0};      // �Զ���ϣ����
    int beg = 0;
    while(beg < 4&&shell[beg] > n)      // ȷ����ʼϣ����
        ++beg;
    for(;beg < 4;++beg)     // ѭ������ϣ������
        for(int i = 1;i < n;++i){
            int current = array[i];
            int j;
            for(j = i;j > 0&&current < array[j - shell[beg]];j -= shell[beg]){      // ��¼��������
                array[j] = array[j - shell[beg]];
                ++swap_count;
            }
            array[j] = current;
        }

    return swap_count;
}

/*
 * ��ֵ����
 * ���������㷨�ĸ�������
 * ��ָ�������ף�β���м����������򣬲������м�ֵ
 * �м�ֵ�𽻻������Ҳ�Ԫ�ص����
 * ���ں������а���ֵ��С���ֵ�ִ��
 * */
int Median( int A[], int Left, int Right ) {
    int Center = (Left+Right) / 2;      // ������ֵ
    if ( A[Left] > A[Center] ){         // ��αȽϣ�������ʹ����������
        ++swap_num;
        swap( A[Left], A[Center] );
    }
    if ( A[Left] > A[Right] ){
        ++swap_num;
        swap( A[Left], A[Right] );
    }
    if ( A[Center] > A[Right] ){
        ++swap_num;
        swap( A[Center], A[Right] );
    }
    swap( A[Center], A[Right-1] );      // ��ֵ�ص�����ֵ�����
    ++swap_num;
    return  A[Right-1];
}

/*
 * ���������㷨���ĺ���
 * �ڴ���Ԫ������100ʱֱ��ִ�в�������
 * ����100 ʱ����Ԫ�ذ���ֵ���֣����п���
 * */
void Qsort( int A[], int Left, int Right ) {
    int tag, Low, High;

    if ( 100 <= Right-Left ) {      // �������ݹ�ģ�ж��Ƿ���Ҫ����
        tag = Median( A, Left, Right ); // �ҳ�������ֵ
        Low = Left; High = Right-1;
        while (1) {                     // �����ݶ���ֵ����Ԫ��
            while ( A[++Low] < tag ) ;
            while ( A[--High] > tag ) ;
            if ( Low < High ){
                ++swap_num;
                swap( A[Low], A[High] );
            }
            else break;
        }
        swap( A[Low], A[Right-1] );
        ++swap_num;
        Qsort( A, Left, Low-1 );        // ����ֵ�������ݶεݹ�ִ�п���
        Qsort( A, Low+1, Right );
    }
    else insert_sort( A+Left, Right-Left+1 );   // ��������Сֱ��ִ�п���
}

/*
 * ���������㷨�ӿ�
 * ���������㷨�ӿ�
 * �������������������ݹ�ģ
 * �������򽻻�����
 * */
int quick_sort( int array[], int n ) {
    Qsort( array, 0, n-1 );     // ���ÿ��ŵݹ��㷨
    return swap_num;
}


/*
 * ���¹����㷨
 * ���������㷨
 * �������������Ѿ����ֵĶ���������
 * ���ڸ��ڵ�λ��ʹ���������ֶ���
 * */
void percdown(int array[], int position, int n){
    int parent,child;

    int current = array[position];      // ��¼��Ԫ��
    for(parent = position; parent*2 + 1 <n; parent = child){        // ���¹���Ѱ�Ҳ���λ��
        child = parent*2 + 1;
        if(child < n-1&&array[child] < array[child + 1])        // �ҵ�������Ů�еĽϴ���
            ++child;
        if(array[child] > current){         // ���¹���
            array[parent] = array[child];
            ++swap_num;
        }

        else
            break;
    }
    array[parent] = current;    // �嵽����λ��
}

/*
 * �������㷨
 * �������������������ݹ�ģ
 * �������򽻻�����
 * �ڲ��������¹����㷨ʵ�ֽ����Լ�ɾ������
 * */
int heap_sort(int array[], int n){

    swap_num = 0;       // ��ʼ����������
    for(int i = n/2-1;i >= 0;--i){
        percdown(array,i,n);        // �����ݵ���Ϊ����
    }
    for(int i = n-1;i > 0;--i){     // ÿ��ɾ���Ѷ�Ԫ�أ������������β��
        swap(array[0],array[i]);
        ++swap_num;
        percdown(array,0,i);        // ���¹��˱��ֶ���
    }
    return swap_num;
}


/*
 * �鲢����
 * �鲢�����㷨��������
 * �������������й鲢Ϊһ��
 * */
void merge(int array[],int temp_array[],int left,int right,int right_end){
    int left_end = right - 1;   // ��¼���������ֹλ��
    int current = left;     // ��¼����������Ԫ��λ��
    int size = right_end - left + 1;    // ���ݹ�ģ
    while(left <= left_end&&right <= right_end){        // ������������ͷ��ʼ�Ƚϱ���
        ++swap_num;
        if(array[left] <= array[right])
            temp_array[current++] = array[left++];
        else
            temp_array[current++] = array[right++];



    }

    while (left <= left_end){       // �����������鳤�Ȳ�ͬ�����
        temp_array[current++] = array[left++];
    }
    while (right <= right_end){
        temp_array[current++] = array[right++];
    }

    for(int i = 0;i < size;++i,--right_end){           // ���źõ�����д��ԭ����
        array[right_end] = temp_array[right_end];
    }
}
/*
 * �鲢�����㷨
 * �ݹ齫������������
 * Ȼ����ϲ�
 * ���� merge ����
 * */
void msort(int array[],int temp_array[],int left, int right_end){

    if(left < right_end){   // �ж����кϷ���
        int center = (left + right_end)/2;
        msort(array,temp_array,left,center);        // �ݹ鴦����������
        msort(array,temp_array,center + 1,right_end);
        merge(array,temp_array,left,center + 1,right_end);  // �ϲ���������
    }
}

/*
 * �鲢�����㷨�ӿ�
 * �������������㷨�ӿ�
 * �������������������ݹ�ģ
 * �������򽻻�����
 * */
int merge_sort(int array[],int n){
    swap_num = 0;   // ��ʼ����������
    int* temp_array = new int[n + 1];   // ��һ���������飬���ںϲ�
    msort(array,temp_array,0,n-1);  // ���ù鲢�㷨
    delete[] temp_array;
    return swap_num;
}

/*
 * ���������㷨
 * �������������������ݹ�ģ
 * �������򽻻�����
 * ����λ����λ��˳����
 * */
int radix_sort(int array[], int n)
{
    int *temp = new int[n];     // �������飬�洢�����е����ݼ�
    int bucket[10];         // 0-9 ʮ��Ͱ
    int i, j, k;
    int radix = 1;          // ����λ��
    for(i = 1; i <= 5; i++)
    {
        for(j = 0; j < 10; j++)     // ��ʼ��Ͱ
            bucket[j] = 0;
        for(j = 0; j < n; j++)      // Ͱ����
        {
            k = (array[j] / radix) % 10;
            bucket[k]++;
        }
        for(j = 1; j < 10; j++)     // �����ͰԪ���ڸ��������е�λ��
            bucket[j] = bucket[j - 1] + bucket[j];
        for(j = n - 1; j >= 0; j--)     // Ͱ�����ݵ��븨������
        {
            k = (array[j] / radix) % 10;
            temp[bucket[k] - 1] = array[j];
            bucket[k]--;
        }
        for(j = 0; j < n; j++)      // ������������д��ԭ���ݼ�
            array[j] = temp[j];
        radix = radix * 10;     // ��������λ��
    }
    delete[]temp;

    return 0;
}






