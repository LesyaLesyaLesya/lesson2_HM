// Lesson2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <algorithm>
#include "Timer.hpp"
#include <string_view>

using namespace std;

template<class Type>
void Swap(Type ptr1, Type ptr2)
{
    auto tempValue = move(*ptr1);
    *ptr1 = move(*ptr2);
    *ptr2 = move(tempValue);

}
void Zadanie1()
{
    /*--------------------------------------------------
    Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения, 
    на которые указывают эти указатели (нужно обменивать именно сами указатели, переменные должны оставаться в тех же адресах памяти)
    ----------------------------------------------------*/
    int a{ 2 };
    int b{ 5 };

    cout << "First value " << a << ", first pointer " << &a << endl;
    cout << "Second value " << b << ", second pointer " << &b << endl;

    Swap(&a, &b);

    cout << "After swap " << endl;

    cout << "First value " << *&a << ", first pointer " << &a << endl;
    cout << "Second value " << *&b << ", second pointer " << &b << endl;

    cout << "---------------------------" << endl;


    double a1{ 10.85 };
    double b1{ 1.13 };

    cout << "First value " << a1 << ", first pointer " << &a1 << endl;
    cout << "Second value " << b1 << ", second pointer " << &b1 << endl;

    Swap(&a1, &b1);

    cout << "After swap " << endl;

    cout << "First value " << *&a1 << ", first pointer " << &a1 << endl;
    cout << "Second value " << *&b1 << ", second pointer " << &b1 << endl;
};

template<class Type>
void SortPointers(vector<Type*> &vectroForSort)
{
    sort(vectroForSort.begin(), vectroForSort.end(), [](const Type* left, const Type* right) {return *left < *right; });
}

template<class Type>
void printVector(const vector<Type*>& vectorForPrint)
{
    for (const auto elem : vectorForPrint)
    {
        cout << *elem << " ";
    }
}
void Zadanie2()
{
    /*--------------------------------------------------
    Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей 
    и сортирует указатели по значениям, на которые они указывают.
    ----------------------------------------------------*/
   
    vector<int*> myVector = { new int{5}, new int{2}, new int{-10}, new int{100}, new int{55} };
    printVector(myVector);
    cout << endl;
    SortPointers(myVector);
    cout << "After sort" << endl;
    printVector(myVector);

};

string readFile(const string& fileName) {
    std::ifstream f(fileName);
    f.seekg(0, ios::end);
    size_t size = f.tellg();
    string s(size, ' ');
    f.seekg(0);
    f.read(&s[0], size); // по стандарту можно в C++11, по факту работает и на старых компиляторах
    return s;
}

void Variant1(const string_view& s, const string_view& vowels)
{   
    cout << endl;
    Timer  timer1;
    timer1.start("1");
    int count1 = count_if(s.begin(), s.end(), [&](const auto& symbol)
        {
            return vowels.find(symbol) != string::npos;
        });
    cout << "1 variant - " << count1 << "vowels" << endl;
    timer1.print();
}

void Variant2(const string_view& s, const string_view& vowels)
{
    //○      count_if и цикл for
    cout << endl;
    Timer  timer2;
    timer2.start("2");
    int count2 = count_if(s.begin(), s.end(), [&](const auto& symbol)
        {
            for (size_t i = 0; i < vowels.size(); i++)
            {
                if (vowels[i] == symbol)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        });
    cout << "2 variant - " << count2 << "vowels" << endl;
    timer2.print();
}

void Variant3(const string_view& s, const string_view& vowels)
{
    cout << endl;
    Timer  timer3;
    timer3.start("3");
    int k3{ 0 };
    for (size_t i = 0; i < s.size(); i++)
    {
        if (vowels.find(s[i]) != string::npos) k3++;
    }
    cout << "3 variant - " << k3 << "vowels" << endl;
    timer3.print();
}
void Variant4(const string_view& s, const string_view& vowels)
{
    cout << endl;
    Timer  timer4;
    timer4.start("4");

    int k4{ 0 };
    for (size_t i = 0; i < s.length(); i++)
        for (size_t j = 0; j < vowels.length(); j++)
        {
            if (s[i] == vowels[j])
            {
                k4++;
                break;
            }
        }
    cout << "4 variant - " << k4 << "vowels" << endl;
    timer4.print();
}
void Zadanie3()
{
    /*--------------------------------------------------
    Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4 способа:
        ○      count_if и find
        ○      count_if и цикл for
        ○      цикл for и find
        ○      2 цикла for
        Замерьте время каждого способа подсчета и сделайте выводы.
        Справка:
        count_if - это алгоритмическая функция из STL, которая принимает 3 параметра:
        итератор на начало, итератор на конец и унарный предикат (функцию, принимающую один параметр и возвращающую тип bool).

        find - это метод класса string, который возвращает позицию символа (строки),
        переданного в качестве параметра, в исходной строке. Если символ не найден, то метод возвращает string::npos.

    ----------------------------------------------------*/
    string s = readFile("WarAndPeace.txt");
    //vector<char> vowels = {'а','А','Е', 'е','Ё', 'ё','И','и','О','о','У', 'у','Э', 'э','Ю','ю','Я','я','Ы','ы'};
    const string_view vowels{ "аАЕеЁёИиОоУуЭэЮюЯяЫы" };
    //1 
    Variant1(s, vowels);
    
    //2
    Variant2(s, vowels);
    //3
    Variant3(s,vowels);
    //4

    Variant4(s, vowels);
};


int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер задания цифрой" << std::endl;
    unsigned short nomerZadania;

    std::cin >> nomerZadania;

    switch (nomerZadania)
    {
    case 1:Zadanie1(); break;

    case 2:Zadanie2(); break;

    case 3:Zadanie3(); break;

    default: break;
    }


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
