/*
 * ���ݽṹ�γ����
 * ��Ŀһ  ���Ա���ϵͳ
 * ������������
 * ѧ�ţ�1552970
 * */

#include<iostream>
#include<string>
using namespace std;


/*
 * ѧ������
 * �������нڵ�����
 * ���������ѧ����Ϣ�Լ���һ���ڵ�ָ��
 * �ڲ�����һϵ�и������ܺ���
 * */
class Student{
    friend class StudentDatabase;       // ������Ԫ�෽��Խڵ�Ĳ���

public:


    Student():_Age(0),_Next(NULL){}         // Ĭ�Ϲ��캯�����½���ѧ����Ϣ

    /*
     * ���캯��
     * ��ʼ��ѧ����Ϣ
     * */
    Student(string id, string name, string gender, int age,string major):_TestID(id),_Name(name),_Gender(gender),_Age(age),_Major(major){}


    void InputInfo(string id, string name, string gender, int age,string major);    // ����ѧ����Ϣ


    void PrintInfo();       //  ��ӡѧ����Ϣ

    string _TestID;         // ����
    string _Name;            // ����
    string _Gender;         // �Ա�
    int _Age;               // ����
    string _Major;           // �������

    Student* _Next;         // ��һ��ѧ���ڵ�
};


/*
 * ����ѧ�����ݿ�����
 * ����������
 * ���������ͷ�ڵ�
 * �ڲ�����һϵ�и�������
 * ������Ԫ�Ķ��壬���Ե��ýڵ����͵��ڲ�����
 * */
class StudentDatabase{

public:
    StudentDatabase():_Data(NULL){}         // Ĭ�Ϲ��캯��

    void BuildDatabase(string id, string name, string gender, int age,string major);        // ���ݿ⽨������

    void Insert(string id, string name, string gender, int age,string major, int pos);      // ��Ա���뺯��

    void Delete(Student* target);           // ��Աɾ������

    Student* Find(string id);               // ��Ա���Һ���

    void Modify(Student* target, Student info);     // ��Ա��Ϣ�޸ĺ���

    void Print(Student* target);            // ��Ա��Ϣ�������

    void Display();                         // ���ݿ������������

    int count();                        // ��������

    Student* _Data;             //  ���ݿ�����ͷ�ڵ�

};

int main(){

    /*
     * �½�һ��ѧ�����ݿ�
     * */
    cout << "�����Ƚ���������Ϣϵͳ!" << endl;
    cout << "�����뿼��������";
    int StudentsNum;
    cin >> StudentsNum;         // ѧ����������

    /*
     * �����������Ƿ�����
     * */
    while(StudentsNum <= 0){            // �ų�������0

        cout<<"ѧ��������Ҫ��������!"<<endl;
        cout << "�����뿼������";
        cin >> StudentsNum;
    }

    cout << "���������뿼���Ŀ��ţ��������Ա����估�������!" <<endl;

    /*
     * ����������Ϣ
     * �������ݿ�
     * */
    StudentDatabase studentInfo;            // �½�һ�����ݿ�����

    for(int i = 0; i < StudentsNum; ++i){           //  ѭ�������ݿ��в����Ա
        string id;
        string name;
        string gender;
        int age;
        string major;
        cin>>id>>name>>gender>>age>>major;
        studentInfo.BuildDatabase(id, name, gender, age, major);        // �������ݿ������ڲ��������ݿ⺯��
    }

    if(studentInfo._Data == NULL){          // ����Ϊ�Ϸ��������ݵ����
        cout<<"�յ����ݿ⣡\n";
        return 0;
    }

    cout<<endl;
    studentInfo.Display();          // չʾ���ݿ��е�����

    cout<<"��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ������)\n\n";
    cout<<"��ѡ����Ҫ���еĲ�����";
    /*
     * ����һϵ����ʱ�������������û�����
     * */
    int tag;            // �������
    string id;          // ѧ��
    string name;         // ����
    string gender;         // �Ա�
    int age;            // ����
    string major;       // רҵ
    int pos;            // ����λ��
    Student* temp;      // �������ڵ�ָ��

    while(cin>>tag&&tag != 0){      // ѭ�������û�����
        switch (tag)
        {
            case 1:
                cout<<"��������Ҫ����Ŀ���λ�ã�";
                cin>>pos;                           // �������λ��
                cout << "������������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������!" <<endl;
                cin>>id>>name>>gender>>age>>major;
                if(studentInfo.Find(id) != NULL){       // �ų�ѧ���ظ�
                    cout<<"�����Ѿ����ڣ�\n";
                    break;
                }
                studentInfo.Insert(id, name, gender, age, major, pos);      // �����½ڵ�
                cout<<endl;
                studentInfo.Display();
                break;
            case 2:
                cout<<"������Ҫɾ�������Ŀ��ţ�";
                cin>>id;
                if((temp = studentInfo.Find(id)) == NULL)       // ����ѧ���������
                    cout<<"û�иÿ���"<<endl;
                else{
                    cout<<"��Ҫɾ���Ŀ�������Ϣ�ǣ�";
                    temp->PrintInfo();
                    studentInfo.Delete(temp);                  // ɾ���ýڵ�
                    cout<<endl;

                    studentInfo.Display();
                }
                break;
            case 3:
                cout<<"������Ҫ���ҵĿ����Ŀ��ţ�";
                cin>>id;
                temp = studentInfo.Find(id);        // ����ѧ��
                if(temp != NULL){                   // �����Ϣ
                    cout<<"����    "
                        <<"����    "
                        <<"�Ա�    "
                        <<"����    "
                        <<"��������"<<endl;
                    studentInfo.Print(temp);
                }
                else
                    cout<<"û�иÿ���"<<endl;
                break;
            case 4:
                cout<<"������Ҫ�޸ĵĿ����Ŀ��ţ�";
                cin>>id;
                temp = studentInfo.Find(id);        // ����ѧ���Ƿ����
                if(temp != NULL){
                    cout<<"�����������޸ĺ�Ŀ����Ŀ��ţ��������Ա����估�������:\n";
                    cin>>id>>name>>gender>>age>>major;
                    studentInfo.Modify(temp, Student(id, name, gender, age, major));
                }
                else                // �����������ʾ
                    cout<<"û�иÿ���"<<endl;
                cout<<endl;
                studentInfo.Display();
                break;
            case 5:
                cout<<"���ݿ���һ����"<<studentInfo.count()<<"��ѧ��\n";          // ���ͳ����Ϣ
                studentInfo.Display();
                break;
        }
 //       cout<<"��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ������)\n\n";
        cout<<"��ѡ����Ҫ���еĲ�����";
    }
    cout<< "��Ϣ��ϵͳ�˳���";
    system("pause");
    return 0;
}


/*
 * ����ѧ����Ϣ
 * */
void Student::InputInfo(string id, string name, string gender, int age,string major){
    _TestID= id;
    _Name = name;
    _Gender = gender;
    _Age = age;
    _Major = major;
}

/*
 * ��ӡѧ����Ϣ
 * */
void Student::PrintInfo(){
    cout<<_TestID<<"      "
        <<_Name<<"   "
        <<_Gender<<"      "
        <<_Age<<"      "
        <<_Major<<endl;
}

/*
 * �������ݿκ���
 * �����ݲ�������β��
 * */
void StudentDatabase::BuildDatabase(string id, string name, string gender, int age,string major){

    if(_Data == NULL){    // �������ݿ�Ϊ�յ����
        _Data = new Student(id, name, gender, age, major);
        _Data->_Next = NULL;
    }
    else{
        Student* tail = _Data;
        while(tail->_Next != NULL)          // �ҵ�β�ڵ�
            tail = tail->_Next;

        tail->_Next = new Student(id, name, gender, age, major);        // ����β��
        tail->_Next->_Next = NULL;
    }

}

/*
 * �ڵ���뺯��
 * ���ݲ���������λ�ò�������
 * */
void StudentDatabase::Insert(string id, string name, string gender, int age,string major, int pos){

    if(pos == 1){           // ����ͷ������
        Student* temp = new Student(id, name, gender, age, major);
        temp->_Next = _Data;
        _Data = temp;
        return;
    }

    Student* pre = _Data;
    pos -= 2;
    while(pos != 0&&pre != NULL){       // �ҵ�����λ��ǰһ���ڵ�ָ��
        pre = pre->_Next;
        --pos;
    }


    if(pos != 0){               // ����Ƿ�����λ��
        cout<<"�Ƿ�����λ�ã�\n";
        return;
    }
    else{
        Student* temp = new Student(id, name, gender, age, major);      // �����Ӧλ��
        temp->_Next = pre->_Next;
        pre->_Next = temp;
    }

}


/*
 * ɾ������
 * ������ָ���Ӧ�ڵ�ɾ��
 * */
void StudentDatabase::Delete(Student* target){

    if(target == NULL)      // ����ɾ������Ϊ�յ����
        return;

    if(target == _Data){
        _Data = _Data->_Next;          // ����ͷ�ڵ�ɾ��

    }
    else{
        Student* pre = _Data;
        while(pre->_Next != target)     // �ҵ���ɾ�ڵ�ǰһ��λ��
            pre = pre->_Next;

        pre->_Next = target->_Next;     // ��ɾ�ڵ����
    }

    delete target;      // �ͷſռ�

}

/*
 * ���Һ���
 * ���ݲ�����ѧ�Ų���
 * ���ض���ڵ�ָ��
 * */
Student* StudentDatabase::Find(string id){
    Student* temp = _Data;

    while(temp != NULL&&temp->_TestID != id)        // ��������
        temp = temp->_Next;

    return temp;

}

/*
 * �޸ĺ���
 * ������ָ���Ӧ�ڵ���Ϣ�޸�Ϊ��������
 * */
void StudentDatabase::Modify(Student* target, Student info){

    target->_TestID = info._TestID;     // �����޸Ķ�Ӧ��Ϣ
    target->_Age = info._Age;
    target->_Gender = info._Gender;
    target->_Major = info._Major;
    target->_Name = info._Name;

}

/*
 * ��ӡ����
 * �������ָ��ڵ����Ϣ
 * */
void StudentDatabase::Print(Student* target){
    target->PrintInfo();        // ���ýڵ������������
}

/*
 * չʾ����
 * �����ݿ���������Ϣ���
 * */
void StudentDatabase::Display(){

    if(_Data == NULL){      // �������ݿ�Ϊ�����
        cout << "�ձ�";
        return;
    }

    cout<<"����   "
        <<"����   "
        <<"�Ա�   "
        <<"����   "
        <<"��������"<<endl;

    Student* temp = _Data;          // ѭ������������нڵ���Ϣ
    while(temp != NULL){
        temp->PrintInfo();
        temp = temp->_Next;
    }

}

/*
 * ��������
 * ͳ�����ݿ���ѧ������
 * */
int StudentDatabase::count() {
    int ans = 0;        //  ��¼ѧ������
    Student* temp = _Data;
    while(temp != NULL){        // ����ͳ��
        ++ans;
        temp = temp->_Next;
    }

    return ans;
}
