#include <iostream>
#include <cmath>
#include <string>

std::string TransferDecimalToAnyIntegers(long long int number, const unsigned int& base); //Перевод целого числа из любой системы счисления в десятичную
std::string TransferDecimalToAny(long double number, const unsigned int& base, const int& accuracy); //Переводит любое число из десятичной системы счисления в другую на выбор
std::string BackToDecIntegers(long long int number, const unsigned int& base); //Переводит целые числа из любой системы счисления в десятчиную ( не учитывает дробную часть )
std::string BackToDec(long double number, const unsigned int& base, const int& accuracy); //Переводит любые числа из любой системы счисления в десятичную
char IntToChar(int c); //Переводит число в символ
int CharToInt(char c, const unsigned int base); //Переводит символ в число

int main() {
    setlocale(LC_ALL, "Ru");
    int a = 10;
    long long int number1 = 15;
    long double number2 = 22.533243;
    long double number3 = 17;
    long double number4 = 17.425;
    const unsigned int base1 = 8;

    std::cout << IntToChar(11) << std::endl;
    std::cout << CharToInt('B', 16) << std::endl;

    std::cout << TransferDecimalToAnyIntegers(number1, base1).c_str() << " в " << base1 << "-ой системе счисления" << std::endl;
    std::cout << TransferDecimalToAny(number2, base1, 15) << " в " << base1 << "-ой системе счисления" << std::endl;
    std::cout << BackToDecIntegers(number3, base1) << " в 10-ой системе счисления" << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "Нынешняя херня " << BackToDec(number4, base1, 10) << " в 10-ой системе счисления" << std::endl;

    system("pause");
    return 0;
}

char IntToChar(int c)
{
    if (c >= 0 && c <= 9)
    {
        return c + '0';
    }
    else
    {
        return c + 'A' - 10;
    }
}

int CharToInt(char c, const unsigned int base)
{
    if (c >= '0' && c <= '9' && (c - '0') < base)
    {
        return c - '0';
    }
    else {
        if (c >= 'A' && c <= 'Z' && (c - 'A') < base)
        {
            return c - 'A' + 10;
        }
        else
        {
            return -1;
        }
    }
}

std::string BackToDec(long double number, const unsigned int& base, const int& accuracy) {

    const char* MASS = "0123456789abcdefghijklmnopqrstuvwxyz";
    int iter = 0, tmp = 0;
    bool Flag = false;

    long long int integer; // Будет хранить целую часть приведённую к типу (long long int)
    long double integer_tmp, fractional; // fractional будет хранить дробную часть, integer_tmp целую часть

    std::string stringInBase;

    if (number < 0)
    {
        Flag = true;
        number *= -1;
    }
    if (base < 2 || base > 36)
    {
        std::cout << "Error: основание должно быть от 2 до 36." << std::endl;
        return "-1";
    }

    fractional = modf(number, &integer_tmp);
    integer = static_cast<long long int>(integer_tmp);

    iter += integer % 10 * pow(base, tmp--);
    integer /= 10;
    while (integer)
    {
        iter += integer % 10 * pow(base, tmp--);
        integer /= 10;
    }

    stringInBase = std::to_string(iter);

    return stringInBase;
}

std::string TransferDecimalToAny(long double number, const unsigned int& base, const int& accuracy) {
    const char* MASS = "0123456789abcdefghijklmnopqrstuvwxyz";
    int iter = 0, tmp = 0;
    bool FlagInverse = false;

    long long int integer; // Будет хранить целую часть приведённую к типу (long long int)
    long double integer_tmp, fractional; // fractional будет хранить дробную часть, integer_tmp целую часть

    std::string reversString, stringInBase;

    if (number < 0)
    {
        FlagInverse = true;
        number *= -1;
    }

    if (base < 2 || base > 36)
    {
        std::cout << "Ошибка: основание должно быть от 2 до 36." << std::endl;
        return "-1";
    }

    fractional = modf(number, &integer_tmp);
    integer = static_cast<long long int>(integer_tmp);

    stringInBase += MASS[integer % base];
    integer = integer / base;

    while (integer)
    {
        stringInBase += MASS[integer % base];
        integer = integer / base;
    }

    if (FlagInverse == true)
        reversString = "-";

    for (int i = stringInBase.length() - 1; i >= 0; i--)
        reversString += stringInBase[i];
    reversString += '.';

    while (iter < accuracy)
    {
        fractional *= base;
        fractional = modf(fractional, &integer_tmp);
        tmp = static_cast<int>(integer_tmp);
        reversString += MASS[tmp];
        iter++;
    }

    return reversString;
}

std::string BackToDecIntegers(long long int number, const unsigned int& base) {

    bool Flag = false;
    int tmp = 0, iter = 0;
    std::string stringInBase;

    if (number < 0)
    {
        Flag = true;
        number *= -1;
    }

    if (base < 2 || base > 36)
    {
        std::cout << "Error: основание должно быть от 2 до 36." << std::endl;
        return "-1";
    }

    iter += number % 10 * pow(base, tmp++);
    number /= 10;
    while (number)
    {
        iter += number % 10 * pow(base, tmp++);
        number /= 10;
    }

    stringInBase = std::to_string(iter);

    return stringInBase;
}

std::string TransferDecimalToAnyIntegers(long long int number, const unsigned int& base) {
    const char* MASS = "0123456789abcdefghijklmnopqrstuvwxyz";
    bool FlagInverse = false;

    std::string reversString, stringInBase;

    if (base < 2 || base > 36)
    {
        std::cout << "Error: основание должно быть от 2 до 36." << std::endl;
        return "-1";
    }
    if (number < 0)
    {
        FlagInverse = true;
        number *= -1;
    }

    stringInBase += MASS[number % base];
    number = number / base;
    while (number)
    {
        stringInBase += MASS[number % base];
        number = number / base;
    }

    if (FlagInverse == true)
        reversString = "-";

    for (int i = stringInBase.length() - 1; i >= 0; i--)
        reversString += stringInBase[i];

    return reversString;
}
