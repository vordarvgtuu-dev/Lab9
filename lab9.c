#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // не работает #include <locale.h>


void task1();
void analyze_number(long long original_num);


int main(void)
{
    SetConsoleOutputCP(65001);

    printf("ЗАДАНИЕ 1:\n");
    task1();


    printf("\nЗАДАНИЕ 2:\n");

    char choice; // выхода из do-while

    do {
        long long original_num = 0;
        printf("\nВведите произвольное длинное число (до 18 знаков): ");

        if (scanf("%lld", &original_num) != 1) {
            printf("Ошибка ввода! Ожидалось число.\n");
            while (getchar() != '\n'); // Очистка буфера
            goto ask_continue;
        }

        // Вызов функции для анализа
        analyze_number(original_num);

    ask_continue:
        while (getchar() != '\n'); // Очистка буфера перед считыванием символа

        printf("\nПродолжить? (Да - y, нет - n): ");
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nПрограмма завершена. Нажмите любую клавишу...");
    system("pause");
    return 0;
}



void task1()
{
    int row, col;


    for (row = 1; row <= 5; row = row + 1)
    {

        for (col = 1; col <= row; col = col + 1)
        {
            printf("%5d", row);
        }
        printf("\n");
    }
}



void analyze_number(long long original_num)
{
    // из - в +
    if (original_num < 0) {
        original_num = -original_num;
    }

    long long temp = original_num;
    int digit_count = 0;
    int last_digit = -1;
    int prev_last = -1;
    int digit_2 = -1;
    int digit_1 = -1;

    // структура числа 
    if (temp == 0) {
        digit_count = 1;
        last_digit = 0;
        digit_1 = 0;
    }
    else {
        last_digit = temp % 10;

        int digits[20];
        while (temp > 0) {
            digits[digit_count] = temp % 10;
            digit_count = digit_count + 1;
            temp = temp / 10;
        }

        digit_1 = digits[digit_count - 1];
        if (digit_count >= 2) {
            digit_2 = digits[digit_count - 2];
            prev_last = digits[1];
        }
    }

    // Сбор
    int count_3 = 0;
    int last_repeat = 0;
    int count_even = 0;
    int punkt_4 = 0;
    int sum_odd = 0;
    int punkt_6 = 0;
    long long no_zero = 1;
    int sum_punkt7 = 0;
    int sum_punkt9 = 0;
    int odinakv_cifri = 0;
    int sum_1_half = 0;
    int sum_2_half = 0;
    int sum_even_pos = 0;
    int sum_odd_pos = 0;

    temp = original_num;
    int current_pos = 1;
    int next_digit = -1;

    if (temp == 0) {
        if (last_digit == 0) last_repeat = 1;
        count_even = 1;
        sum_odd_pos = 0;
    }

    while (temp > 0) {
        int current_digit = temp % 10;
        temp = temp / 10; // Вместо temp /= 10
        next_digit = (temp > 0) ? (temp % 10) : -1;

        // 1) Количество цифр 3
        if (current_digit == 3) count_3 = count_3 + 1;

        // 2) Число повторений последней цифры
        if (current_digit == last_digit) last_repeat = last_repeat + 1;

        // 3) Количество четных цифр
        if (current_digit % 2 == 0) count_even = count_even + 1;

        // 4) Количество цифр больших 5
        if (current_digit > 5) punkt_4 = punkt_4 + 1;

        // 5) Сумма нечетных цифр
        if (current_digit % 2 != 0) sum_odd = sum_odd + current_digit;

        // 6) Сумма цифр больше или равно 7
        if (current_digit >= 7) punkt_6 = punkt_6 + current_digit;

        // 7) Произведение всех цифр, исключая 0
        if (current_digit != 0) {
            no_zero = no_zero * current_digit;
            sum_punkt7 = 1;
        }

        // 9) Сумма четных цифр, исключая последнюю
        if (current_digit % 2 == 0 && current_pos != 1) {
            sum_punkt9 = sum_punkt9 + current_digit;
        }

        // 10) Рядом расположенные одинаковые цифры
        if (next_digit != -1 && current_digit == next_digit) {
            odinakv_cifri = odinakv_cifri + 1;
        }

        // 11) Распределение по половинам числа
        int index_from_left = digit_count - current_pos;
        if (index_from_left < digit_count / 2) {
            sum_1_half = sum_1_half + current_digit;
        }
        else if (digit_count % 2 == 0 || index_from_left > digit_count / 2) {
            sum_2_half = sum_2_half + current_digit;
        }

        // 12) Разряды (младший разряд = 1)
        if (current_pos % 2 == 0) {
            sum_even_pos = sum_even_pos + current_digit;
        }
        else {
            sum_odd_pos = sum_odd_pos + current_digit;
        }

        current_pos = current_pos + 1; 
    }

    if (sum_punkt7 == 0) no_zero = 0;

    // Вывод результатов 
    printf("\nРЕЗУЛЬТАТЫ АНАЛИЗА ЧИСЛА\n");
    printf("1) Количество цифр 3: %d\n", count_3);
    printf("2) Число повторений последней цифры (%d): %d\n", last_digit, last_repeat);
    printf("3) Количество четных цифр: %d\n", count_even);
    printf("4) Количество цифр больших 5: %d\n", punkt_4);
    printf("5) Сумма нечетных цифр: %d\n", sum_odd);
    printf("6) Сумма цифр больше или равно 7: %d\n", punkt_6);
    printf("7) Произведение цифр без нуля: %lld\n", no_zero);

    if (digit_count >= 2) {
        printf("8) Произведение предпоследней (%d) и второй (%d) цифры: %d\n", prev_last, digit_2, prev_last * digit_2);
    }
    else {
        printf("8) Произведение недоступно (в числе меньше 2 цифр)\n");
    }

    printf("9) Сумма четных цифр, исключая последнюю: %d\n", sum_punkt9);
    printf("10) Найдено рядом расположенных одинаковых цифр: %d\n", odinakv_cifri);

    if (digit_count < 2) {
        printf("11) Равенство половин: невозможно определить (слишком короткое число)\n");
    }
    else {
        printf("11) Сумма 1-й половины (%d), сумма 2-й половины (%d). ", sum_1_half, sum_2_half);
        if (sum_1_half == sum_2_half) printf("Равны!\n");
        else printf("Не равны.\n");
    }

    long long proizvod = (long long)sum_even_pos * sum_odd_pos;
    printf("12) Произведение сумм четных (%d) и нечетных (%d) разрядов: %lld\n", sum_even_pos, sum_odd_pos, proizvod);
}