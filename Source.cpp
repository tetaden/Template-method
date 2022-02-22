#include <iostream> //подключение заголовочного файла iostream
#include <string> //подключение библиотеки для рабботы со строками
#include <fstream> //подключение библиотеки для работы с файлами
#include "IT.h"  // подключение заголовочного файла для работы с классом IT
using namespace std; // объявление пространства имен std
void Read(string path, IT*); // прототип функции Read
const bool operator>(const IT&, const IT&); // прототип перезагрузки оператора >
const bool operator<(const IT&, const IT&); // прототип перезагрузки оператора <
const bool operator>=(const IT&, const IT&);
const bool operator<=(const IT&, const IT&);
void bubble(IT* a, const int n); //Прототип функции сортировки пузырьком
void insert_sort(IT* a, const int n); //Прототип функции сортировки вставками 
IT* take(const IT a[], int&amount); // Прототип функции создания подмоножества всего датасета 
int main() {
    IT A[6000],*b; //Объявляем массив данных класса IT и указатель на объект данного класса
    int n; // n - количество данных массива подмножества b всего датасета A
    double s, e; //  объекты для замерения скорости работы сортировок (s - начало сортировки, e - конец)
    Read("Dataset.txt", A); //Заполняем массив A датассетом из файла 'Dataset.txt'
   
    b = take(A, n); // создаем массив подмножества b с помощью функции take
    s = clock(); // замеряем начало сортировки 
    bubble(b, n); // сортируем массив b с помощью сортировки Пузырьком
    e = clock(); // конец сортировки 
    cout << "Time for buble sort:" << (e - s) / (double)CLOCKS_PER_SEC << endl; // так как clock() возвращает количество 'тактов'
    //то необходимо преобразовать это в временную единицу - секунду c помощью функции CLOCKS_PER_SEC, которая  сообщает сколько тиков 
    //произошло за секнуду
    delete[]b;// освобождение памяти занятой массивом b 
    b = take(A, n); // создаем массив подмножества b с помощью функции take 
    s = clock();
    insert_sort(b, n); //сортируем массив b с помощью сортировки вставками 
    e = clock();
    cout << "Time for insert sort:" << (e - s) / (double)CLOCKS_PER_SEC << endl;
    delete[]b;// освобождение памяти занятой массивом b 
    


}
IT* take(const IT a[], int&amount) { // функция создания подмножества из множества всего датасета
    //param:  
    // const IT a[] - массив множества всего датасета
    // int& amount  - количество данных в подмножестве
    int first; // целое  число, необходимое для отступа из датассета a и  для обеспечения различия 
    // подмножеств b с одинаковым количеством данных
    cout << "Enter the amount of data in the new dataset: ";
    cin >> amount;
    while (amount > 6000) { // если введеное количество данных больше чем количество данных всего датасета, то просим пользователя ввести число еще раз 
        cout << "Your number is exceed total number of data(6000), Please, enter the number again: ";
        cin >> amount;
    }
    while (amount < 0) { //Если введенное количество данных меньше чем 0 - просим ввести заново
        cout << "Please, enter the number that more than 0: ";
        cin >> amount;
    }
    cout << "Enter the index of first data from IT: ";
    cin >> first;
    while (first < 0) {
        cout << "Please, enter the number that more than 0: ";
        cin >> first;
    }
    IT* b = new IT[amount]; // выделяем память на создание массива b
    for (int i = 0; i < amount; i++)  b[i] = a[first + i]; // заполняем его
    return b;
    //return b  - возвращаем подмножество
}
void bubble(IT* a, const int n) { //Сортировка пузырькам
    //Params:
    //IT* a - Указатель на 1 элемент массива a 
    //const int n  - количество элементов массива a
    for (int i = n - 1; i >= 0; i--) { // делаем обход по всему массиву 
        for (int j = 0; j < i; j++) { // за каждый такой обход меняем местами элементы и помещаем наибольший элемент в конец массива и рассмратриваем подмасив на единицу меньше
            if (a[j] > a[j + 1]) {
                IT tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void insert_sort(IT* a, const int n)//Сортировка вставками 
{
    int i, j;
    IT value;
    for (i = 1; i < n; i++) // проходимся по всему массиву кроме 1 элемента
    {
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; j--) //находим нужный элемент и вставляем его в уже отсартированную часть массива
            // в первой итерации это 1 элемент
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = value;
    }
}
void Read(string path, IT* A) { //Заполнение датасета
    ifstream fout(path); //Потоковый вывод из файла с путем path
    string serv, date, cost, pr_cost; // элементы для заполнения объектов класса IT
    int i = 0; // для индексации массива 
    if (!fout.is_open()) { // если файл не открывается - вызываем ошибку, завершаем программу
        cout << "ERROR: file can't be opened" << endl;
        exit(1);
    }
    else {
        while (!fout.eof()&&i!=6000) {
            getline(fout, cost, '\t');
            getline(fout, date, '\t');
            getline(fout, pr_cost, '\t');
            getline(fout, serv);
            A[i].Set(serv, cost, date, pr_cost);
            i++;
        }
        fout.close(); // закрываем поток
    }
}
const bool operator>(const IT& a1, const IT& a2) { //Перегружаем оператор >
    if (a1.serv > a2.serv) {
        return true;
    }
    else if ((a1.serv == a2.serv) and (a1.cost > a2.cost)) { // если названия услуг равны, то сравниваем по стоимости 
        return true;
    }
    return false;
} 
const bool operator<(const IT& a1, const IT& a2) { // Перегружаем оператор <
    if (a1.serv < a2.serv) {
        return true;
    }
    else if ((a1.serv == a2.serv) and (a1.cost < a2.cost)) {
        return true;
    }
    return false;
}
const bool operator>=(const IT& a1, const IT& a2) {
    if (a1.serv >= a2.serv) {
        return true;
    }
    else if ((a1.serv == a2.serv) and (a1.cost >= a2.cost)) {
        return true;
    }
    return false;
}
const bool operator<=(const IT& a1, const IT& a2) {
    if (a1.serv <= a2.serv) {
        return true;
    }
    else if ((a1.serv == a2.serv) and (a1.cost <= a2.cost)) {
        return true;
    }
    return false;
}
