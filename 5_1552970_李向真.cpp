/*
 * ���ݽṹ�γ����
 * ��Ŀ��  ���ʼ���ͳ��ϵͳ
 * ������������
 * ѧ�ţ�1552970
 * */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

void split_line( const string & str, vector<string> & words );   //���ʲ��
void menu1();   //��ӡ�˵�1
void menu2();   //��ӡ�˵�2
void create_TXT(); //�½��ı�
void word_list(string name);  //�������ʻ�����Ϣ�б�
int word_count(vector<vector<int> >& list); //���ʼ���
void word_locate(vector<vector<int> >& list);  //���ʶ�λ
void word_analyse(string f,string word,vector<vector<int> >& ans);  //���ʷ���

int main() {

    menu1();     //�˵���ʼ��
    int choice;
    cout<<"��ѡ��<1~4>:";
    cin>>choice;      //�������
    string fname;

    while(choice != 4){    //���ݲ�����ѡ�����
        switch (choice){
            case 1:
                create_TXT();    //�½��ļ�
                break;
            case 2:
                cout<<"�������ļ�����";
                cin>>fname;
                word_list(fname);   //�������ʻ��ܱ�
                break;
            case 3:
                menu2();
                string word;

                cout<<"������a��b��";
                char c;
                cin>>c;
                if(c == 'a'){
                    cout<<"�������ļ�����";
                    cin>>fname;
                    cout<<"������Ҫͳ�Ƽ����ĵ��ʣ�";
                    cin>>word;
                    vector<vector<int> > ans;    //��¼�Ըõ��ʵķ������
                    word_analyse(fname,word,ans);
                    cout<<"����"<<word<<"���ı��ļ�"<<fname<<"�й�����"
                        <<word_count(ans)<<"��\n";
                }
                else if(c == 'b'){
                    cout<<"�����ļ�����";
                    cin>>fname;
                    cout<<"������Ҫ�����ĵ��ʣ�";
                    cin>>word;
                    vector<vector<int> > ans;   //��¼���ʷ������
                    word_analyse(fname,word,ans);
                    word_locate(ans);
                }
                else{
                    cout<<"�Ƿ����룡\n";
                }
                break;
        }
        menu1();
        cout<<"��ѡ��<1~4>:";
        cin>>choice;
    }
    
    system("pause");
    return 0;
}

/*
 * ��һ��string�������з�Ϊ��������
 * */
void split_line( const string & str, vector<string> & words )
{
    int i = 0;

    while( i != str.size() )
    {
        while( i != str.size() && !isalpha( str[i] ) )   //��������ĸ����
            ++i;

        int j = i;
        while( j != str.size() && isalpha(str[j]))    //��¼���ʿ��
            ++j;
        if( i != j )
        {
            words.push_back(str.substr( i, j - i ));  //�����ʼ�¼������
            i = j;
        }
    }
}

/*
 * �½�txt�ļ�
 * �ļ������ļ��������û�����
 * */
void create_TXT(){
    string name;
    cout<<"����Ҫ�������ļ�����";
    cin>>name;
    getchar();
    ofstream txt(name.c_str());  //�½��ļ�
    while(1){              //ѭ�������ļ�����
        cout<<"������һ���ı���";
        string line;
        getline(cin,line);
        for(int i = 0;i < line.size();++i)  //ȫ��ת��ΪСд��ĸ�������Сд����
            if(isalpha(line[i]))
                line[i] = tolower(line[i]);
        txt<<line<<endl;
        cout<<"���������y or n :";
        char choice;
        cin>>choice;
        if(choice == 'y')
            break;
        getchar();
    }
    txt.close();        //�ļ�������ϣ��ر��ļ���
    cout<<"�����ļ�����!\n";
}

/*
 * ͳ���ļ��е��ʵ������Լ��������ʳ��ֵĴ���
 * */
void word_list(string name){
    ifstream file(name.c_str());
    string line;
    map<string,int> list;
    set<char> st;       //������������ͳ�Ʒ��ı������࣬��֤���ظ�
    while (getline(file,line)){     //ÿ�δ��ļ��ж���һ��
        vector<string> words;
        split_line(line,words);     //���÷ִʺ����������
        for(int i = 0;i < line.size();++i){     //��¼���ı�����
            if(!isalpha(line[i])&&!isspace(line[i]))
                st.insert(line[i]);
        }
        for(int i = 0;i < words.size();++i){
            if(list.find(words[i]) == list.end())   //��¼�³��ֵĵ���
                list.insert(make_pair(words[i],1));
            else
                ++list[words[i]];   //ͳ�����е��ʵ�����
        }

    }
    int count = 0;

    /*
     * ��ͳ��������б�׼�����
     * */
    cout<<">>>>>>>>>>>"<<"����"<<"<<<>>>>"<<"����"<<"<<<<<<<<"<<endl;
    for(map<string,int>::iterator i = list.begin(); i != list.end(); ++i){
        for(int j = 0;j < 13-(i->first).size();++j)
            cout<<" ";
        cout<<i->first <<"         "<<i->second<<endl;
        count += i->second;
    }
    cout<<"\n>>>>>>>>>>>>>>"<<name<<"�ĵ��ʸ���Ϊ"<<count<<"��\n\n";
    cout<<">>>>>>>>>>>>>>"<<name<<"�ķǵ��ʸ���Ϊ"<<st.size()<<"��\n";

}

/*
 * �����õ������ļ��г��ֵ����
 * ��¼�õ����ڸ��г��ֵĴ���
 * */
void word_analyse(string f,string word,vector<vector<int> >& ans){
    ifstream file(f.c_str());
    string line;
    vector<int> positions; //��¼ÿ�����ʳ��ֵ�����λ��

    while (getline(file,line)){
        int beg = 0;
        int pos = 0;
        positions.clear();
        while(beg != string::npos){ //ѭ�����Ҹ����иõ��ʵ����г������
            beg = line.substr(pos).find(word);
            if(beg != string::npos){
                pos += beg;
                positions.push_back(pos); //��¼��ÿ������λ��
                pos += word.size();
            }
        }
        ans.push_back(positions);    //�����еĳ���λ�ü�¼
    }
}

/*
 * ͳ�Ƹõ������ļ��г��ִ���
 * */
int word_count(vector<vector<int> >& list){
    int count = 0;
    for(int i = 0;i < list.size();++i){     //ͳ�Ƶ����ڸ������Դ��������ۼ�
        count += list[i].size();
    }

    return count;
}

/*
 * ��ʽ����������ڸ��г��ֵ����
 * */
void word_locate(vector<vector<int> >& list){
    if(word_count(list) == 0){       //�����ʲ����ڵ����
        cout<<"���ʲ����ڣ�\n";
        return;
    }
    for(int i = 0;i < list.size();++i){     //��ʽ��������ʳ������
        if(list[i].size() != 0){
            cout<<"�кţ�"<<i+1<<"��������"<<list[i].size()<<"����ʼλ�÷ֱ�Ϊ��";
            for(int j = 0;j < list[i].size();++j){
                cout<<"�� "<<list[i][j] + 1<<"���ַ� ";
            }
            cout<<endl;
        }
    }
}

/*
 * ��ӡ���˵�
 * */
void menu1(){
    cout<<"*****************************\n";
    cout<<"****�ı��ļ����ʵļ��������****\n"
        <<"=============================\n"
        <<"*    ��1�������ı��ĵ�        *\n"
        <<"*    ��2���ı����ʻ���        *\n"
        <<"*    ��3�����ʶ�λ            *\n"
        <<"*    ��4���˳�               *\n"
        <<"=============================\n";
}

/*
 * ��ӡ����3�Ĳ˵�
 * */
void menu2(){
    cout<<"==================================\n"
        <<"||�ı��ļ������ַ�����ͳ�ƶ�λ����λ||\n"
        <<"||================================||\n"
        <<"||    a.   ���ʳ��ֵĴ���           ||\n"
        <<"||                                ||\n"
        <<"||                                ||\n"
        <<"||    b.   ���ʳ��ֵ�λ��           ||\n"
        <<"||                                ||\n"
        <<"====================================\n";
}
