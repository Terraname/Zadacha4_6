// Zadacha6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "This program replaces elements of the matrix with the highest of \n the elements with lower index, if it's value is higher than elements value\n";
    int n, m;
    std::cout << "Enter N\n";
    std::cin >> n;
    while (std::cin.fail() || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong N!\n";
        std::cout << "Enter N another time\n";
        std::cin >> n;
    }
    std::cout << "Enter M\n";
    std::cin >> m;
    while (std::cin.fail() || m <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong M!\n";
        std::cout << "Enter M another time\n";
        std::cin >> m;
    }
    double** array = new double* [n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new double[m];
    }

    std::cout << "Enter elements of the matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> array[i][j];
            while (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Wrong element's value!\n";
                std::cout << "Enter element № " << (i + 1) << ", " << (j + 1) << "  of the array another time\n";
                std::cin >> array[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0)
            {
                if (array[i][j] < array[i - 1][j])
                {
                    array[i][j] = array[i - 1][j];
                }
            }
            if (j > 0)
            {
                if (array[i][j] < array[i][j - 1])
                {
                    array[i][j] = array[i][j - 1];
                }
            }
        }
    }

    std::cout << "\n";
    std::cout << "New matrix is: \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
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
