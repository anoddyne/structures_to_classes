#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

class Student
{
public:
    string fio;
    int yearob;
    int course;
    int group;
};

ostream& operator<<(ostream& out, const Student obj)
{
    out << obj.fio << " " << obj.yearob << " " << obj.group << " " << obj.course;
    return out;
}

int main()
{
    SetConsoleCP(1251); //����� ��� ����, ����� getline ��������� �������� ���������
    setlocale(LC_ALL, "");
    int search = 0;
    string fio_s;
    int yearob_s;
    int course_s, group_s;
    char command = '�'; //����
    while (command != '�')
    {
        int leng = 0;
        string s;
        ifstream myfile("input.txt");
        while (getline(myfile, s))
        {
            leng++;
        }
        Student* stud_list = new Student[leng];
        int a = 0;

        myfile.close();
        ifstream file("input.txt");

        string ss, buff;
        while (getline(file, s))
        {
            buff.assign(s);
            stud_list[a].course = buff[0] - '0';
            buff.erase(0, 2);

            ss += buff[0];
            ss += buff[1];
            stud_list[a].group = stoi(ss);
            ss.clear();
            buff.erase(0, 3);

            ss += buff[0];
            ss += buff[1];
            ss += buff[2];
            ss += buff[3];
            stud_list[a].yearob = stoi(ss);
            ss.clear();
            buff.erase(0, 5);

            stud_list[a].fio.assign(buff);
            a += 1;
            buff.clear();
        }
        cout << "�� ������ ��������� ����� ����� ���������: 1 - �� ���, 2 - �� ���� ��������, 3 - �� �����, 4 - �� ������ ������: ";

        cin >> search;
        cin.ignore();
        switch (search) {
        case(1):
        {
            cout << "������� ��� ���������: ";
            getline(cin, fio_s);
            for (int i = 0; i < leng; i++) {
                if (fio_s == stud_list[i].fio) {
                    cout << stud_list[i].fio << ", " << stud_list[i].course << " ����, " << stud_list[i].group << " ������, " << stud_list[i].yearob << " ��� ��������; " << endl;
                }
            }
            break;
        }
        case(2): {
            cout << "������� ���� ��������: ";
            cin >> yearob_s;
            for (int i = 0; i < leng; i++) {
                if (yearob_s == stud_list[i].yearob) {
                    cout << stud_list[i].fio << ", " << stud_list[i].course << " ����, " << stud_list[i].group << " ������, " << stud_list[i].yearob << " ��� ��������; " << endl;
                }
            }
            break;
        }
        case(3): {
            cout << "������� ����, �� ������� ��������� �������: ";
            cin >> course_s;
            for (int i = 0; i < leng; i++) {
                if (course_s == stud_list[i].course) {
                    cout << stud_list[i].fio << ", " << stud_list[i].course << " ����, " << stud_list[i].group << " ������, " << stud_list[i].yearob << " ��� ��������; " << endl;
                }
            }
            break;
        }
        case(4):
            cout << "������� ������, � ������� ������ �������: ";
            cin >> group_s;
            for (int i = 0; i < leng; i++) {
                if (group_s == stud_list[i].group) {
                    cout << stud_list[i].fio << ", " << stud_list[i].course << " ����, " << stud_list[i].group << " ������, " << stud_list[i].yearob << " ��� ��������; " << endl;
                }
            }
            break;
        }
        file.close();
        cout << "\n����������? (�/�) "; //� - ��, � - ���
        cin >> command;
    }
}