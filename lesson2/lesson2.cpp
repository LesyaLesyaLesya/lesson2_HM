// Lesson2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <locale>
#include <vector>

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
void SortPointers(vector)
void Zadanie2()
{
    /*--------------------------------------------------
    Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей 
    и сортирует указатели по значениям, на которые они указывают.
    ----------------------------------------------------*/
   


};

void Zadanie3()
{
    /*--------------------------------------------------
   
    ----------------------------------------------------*/
    

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
