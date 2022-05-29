//purpose: Реализовать функцию, которая  переписывает все символы строки в обратном порядке.


#include <iostream>
using namespace std;

void cin_rescue()
//функция, очищающая cin в случае ошибочного ввода
{
    cin.clear(); // то возвращаем cin в 'обычный' режим работы
    cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
}

string func_reverse_string(const string main_string, const short int reverse_method)
//функция реверсирования текстовой строки различными методами
{
    string reversed_string; //перевернутая строка
    short int len = main_string.length(); //переменная длины строки
    short int n = len - 1; //длина исходной строки минус 1, данная переменная используется в качестве счетчика последнего символа в циклах
    short int i = 0; // счтёчик цикла
    char temp_char; // переменная временного символа
    reversed_string.reserve(main_string.length()); //выделение памяти для переменной reversed_string длиною строки main_string

    //использая метод pushback
    if (reverse_method == 1)
    {                
        //перебираем строку с её конца до начала 
        for (len = len - 1; len >= 0; len--)
            reversed_string.push_back(main_string[len]); //с помощью метода push_back копируем символы в новую переменную из исходной
        return reversed_string; //возвратить инвертированную строку
    }
    //использование метода swap через цикл for
    if (reverse_method == 2)
    {
        reversed_string = main_string; //копируем исходную строку в строку для реверса
        for (i = 0; i < (len / 2); ++i)
        {
            swap(reversed_string[i], reversed_string[n]); //свапаем элементы i и элемент n (длина строки - 1)
            n--; //при каждой итерации i++, n--
        }
        return reversed_string; //возвратить инвертированную строку
    }
    //использование метода swap через цикл while
    if (reverse_method == 3)
    {
        reversed_string = main_string; //копируем исходную строку в строку для реверса
        while (i<=n) //цикл выполняется пока i (изначально 0) меньше или равен n (изначально длина строки -1)
        {
            swap(reversed_string[i], reversed_string[n]); //функция перестановки местами символов
            n--; i++; //n уменьшается на 1, i инкрементируется
        }
        return reversed_string;
    }
    //используя перемещение символов через временную переменную char
    //данный метод крайне похож на метод swap, но тут мы не используем команду swap, а пермещаем символы, используя временную переменную
    if (reverse_method == 4)
    {
        reversed_string = main_string; //копируем исходную строку в строку для реверса
        for (i = 0; i < (len / 2); ++i)
        {
            temp_char = reversed_string[i]; //присваеваем временной переменной значение i-ного символа из строки [i-символ уже скопирован]
            reversed_string[i] = reversed_string[n]; //присваем i-символу значение последнего n-символа из текущей строки [i-символ уже скопирован]
            reversed_string[n] = temp_char; //присваиваем n-символу значение из временой переменной (который i символ был ранее)
            n--;
        }
        return reversed_string;
    }
}

string func_string_randomise(const short int len)
//функция заполнения текстовой строки случайными значениями
{
    short int i; //переменная для счётчика цикла
    srand(time(0)); //определение стартовой точки для рандомизатора, требуется чтобы каждый раз были разные значения

    const char data_set[] = //объявление переменной data_set с содержимым из символов, которые нам надо генерить
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string generated_string;
    generated_string.reserve(len); //выделение памяти для переменной temp длинною len

    //цикл, который иттерируется количество раз равным длине строки и каждый раз случайным образом выбирает символ из датасета
    for (i = 0; i < len; ++i)
        generated_string += data_set[rand() % (sizeof(data_set) - 1)];

    return generated_string;

}


int main()
{
    //объявление переменных:
    const short int LIMIT_len_min = 2;              //минимальный размер строки
    const short int LIMIT_len_max = 256;            //максимальный размер строки
    short int string_fill_type;                     //выбор типа заполнения строки
    short int string_len_ifrandom;                  //длина строки, если строка заполняется рандомно
    short int reverse_method;                       //выбор типа метода пеерстановки символов
    string main_string;                             //строковая переменная, содержащая главную строку
    string reversed_string;                         //переменная для инвертированный строки
    

    //приветственное сообщение
    cout << "Hello and welcome to laboratory workshop #7!\nMain topic of workshop is making software to reverse string\n\n";
    while(true)
    { 
        //запрос ввода входящих данных: 
        //тип заполнения строки: рандом или вручную или выйти из программы, 
        while (true)
        {
            cout << "[OUT]\tPlease enter type of string filling (please enter only digit):\n\t[1] Randomising string\n\t[2] Manually\n\t[3] Exit\n[INPUT]\tPlease make your choise: ";
            cin >> string_fill_type;
            //если введено 1 или 2, то прервать цикл
            if (string_fill_type == 1 or 
                string_fill_type == 2 or 
                string_fill_type == 3)
                break;
            if (!cin) cin_rescue();
            cerr << "[ERROR]\tPlease enter correct data\n";
        }
        
        //если тип заполнения случайный, то запросить размер строки
        if (string_fill_type == 1)
        {   
            //запросить длину строки
            while (true)
            {
                cout << "[INPUT]\tPlease enter random string length (limits: from "<< LIMIT_len_min <<" to "<< LIMIT_len_max <<"): ";
                cin >> string_len_ifrandom;
                //если строка болье или равна минимальному литиу и меньше или равно максимальному лимиту
                if (string_len_ifrandom >= LIMIT_len_min and
                    string_len_ifrandom <= LIMIT_len_max)
                    break;
                if (!cin) cin_rescue();
                cerr << "[ERROR]\tPlease enter correct data\n";
            }
            //сгенерировать строку и вывести её на экран
            main_string = func_string_randomise(string_len_ifrandom);
            cout << "[OUT]\tGenerated string: " << main_string << endl;
        }

        //если тип заполнения вручную
        if (string_fill_type == 2)        
            while (true)
            {
                cout << "[INPUT]\tPlease enter string to processing: (limits to length: from " << LIMIT_len_min << " to " << LIMIT_len_max << "):"; cin >> main_string;
                if (main_string.length() >= LIMIT_len_min and
                    main_string.length() <= LIMIT_len_max)
                    break;
                if (!cin) cin_rescue();
                cerr << "[ERROR]\tPlease enter correct string\n";
            }
        //выйти из программы
        if (string_fill_type == 3)
            break;

        //ввод типа метода перестановки
        while (true)
        {
            //рендер выбора
            cout << "[OUT]\tAvailable methods:" << endl; 
            cout << "\t[1] pushback" << endl; 
            cout << "\t[2] swap (over FOR cirlce)" << endl;
            cout << "\t[3] swap (over WHILE cirlce)" << endl;
            cout << "\t[4] using temporary char" << endl;
            cout << "[INPUT]\tPlease choose reverse method (only digit) : "; 
            cin >> reverse_method;
            //проверка выбора
            if (reverse_method == 1 or 
                reverse_method == 2 or 
                reverse_method == 3 or 
                reverse_method == 4)
                break;
            //обработка ошибочного ввода
            if (!cin) cin_rescue();
            cerr << "[ERROR]\tPlease enter correct data\n";
        }
        
        //вызов функции реверсирования (передаются: строка и метод реверсирования)
        reversed_string = func_reverse_string(main_string, reverse_method);
        cout << "[OUT]\tReversed string:" << reversed_string << endl;

        //вывод результатов в удобном виде для сравнения
        cout << "[OUT]\tComparing" << endl;
        cout << "[OUT]\tOriginal string:\t" << main_string << endl;
        cout << "[OUT]\tReversed string:\t" << reversed_string << endl; 
        //пауза (не очень хороший метод приостановить работу ПО, тк не кроссплатформенный)
        system("pause");
    }
}