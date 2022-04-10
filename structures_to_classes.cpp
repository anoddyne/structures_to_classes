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
    SetConsoleCP(1251); //нужно для того, чтобы getline нормально считывал кириллицу
    setlocale(LC_ALL, "");
    int search = 0;
    string fio_s;
    int yearob_s;
    int course_s, group_s;
    char command = 'д'; //меню
    while (command != 'н')
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
        cout << "По какому параметру нужно найти студентов: 1 - по ФИО, 2 - по году рождения, 3 - по курсу, 4 - по номеру группы: ";

        cin >> search;
        cin.ignore();
        switch (search) {
        case(1):
        {
            cout << "Введите ФИО полностью: ";
            getline(cin, fio_s);
            for (int i = 0; i < leng; i++) {
                if (fio_s == stud_list[i].fio) {
                    cout << stud_list[i].fio << ", " << stud_list[i].course << " курс, " << stud_list[i].group << " группа, " << stud_list[i].yearob << " год рождения; " << endl;
                }
            }
            break;
        }
        case(2): {
            cout << "Введите дату рождения: ";
            cin >> yearob_s;
            for (int i = 0; i < leng; i++) {
                if (yearob_s == stud_list[i].yearob) {
                    cout << stud_list[i].fio << ", " << stud_list[i].course << " курс, " << stud_list[i].group << " группа, " << stud_list[i].yearob << " год рождения; " << endl;
                }
            }
            break;
        }
        case(3): {
            cout << "Введите курс, на котором обучается студент: ";
            cin >> course_s;
            for (int i = 0; i < leng; i++) {
                if (course_s == stud_list[i].course) {
                    cout << stud_list[i].fio << ", " << stud_list[i].course << " курс, " << stud_list[i].group << " группа, " << stud_list[i].yearob << " год рождения; " << endl;
                }
            }
            break;
        }
        case(4):
            cout << "Введите группу, в которой учится студент: ";
            cin >> group_s;
            for (int i = 0; i < leng; i++) {
                if (group_s == stud_list[i].group) {
                    cout << stud_list[i].fio << ", " << stud_list[i].course << " курс, " << stud_list[i].group << " группа, " << stud_list[i].yearob << " год рождения; " << endl;
                }
            }
            break;
        }
        file.close();
        cout << "\nПродолжить? (д/н) "; //д - да, н - нет
        cin >> command;
    }
}