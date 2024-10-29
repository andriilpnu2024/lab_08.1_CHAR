#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>


using namespace std;
int Count(char* s,char* s1);
char* Change(char* str);
int main()
{
    char str[101];
    char str1[] = { "BASIC" };
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str, str1) << " elements of 'BASIC'" << endl;
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
int Count(char* s,char* s1) // s = вказівник на початок рядка
{
    int i = 0;
    int k = 0,
        pos= 0;
    char* t;
    while (t = strpbrk(s + pos, s1))
    {
        pos = t - s + 1; 
        k++;
    }
    return k;
}
char* Change(char* s) // s = вказівник на початок рядка
{
    char* t = new char[strlen(s)];
    char* p;
    int pos1 = 0, // pos1 = позиція початку пошуку
        pos2 = 0;
    *t = 0;
    while (p = strchr(s + pos1, 'B')) // p = вказівник на '+'
    {
        if (s[p - s + 1] == 'A' && s[p - s + 2] == 'S' && s[p - s + 3] == 'I' && s[p - s + 4] == 'C')
        {
            pos2 = p - s + 5; // pos2 = позиція наступного символа після '-'
            strncat(t, s + pos1, pos2 - pos1 - 5);
            strcat(t, "Delphi");
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1; // pos2 = позиція наступного символа після '+'
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}
