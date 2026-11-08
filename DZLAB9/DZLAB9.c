#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // не работает #include <locale.h>

int get_last_digit(int number) {
    if (number < 0) number = -number;
    return number % 10;
}

int get_digit_sum(int number) {
    if (number < 0) number = -number;
    int sum = 0;
    while (number > 0) {
        sum += number % 10; 
        number /= 10;       
    }
    return sum;
}


char get_symbol_by_digit(int digit) {
    const char symbols[] = "!@#$%^&*(";
    if (digit >= 0 && digit <= 9) {
        return symbols[digit];
    }
    return '*'; 
}

void print_full_pythagorean_table() {
    printf("\n--- Полная таблица Пифагора ---\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%3d ", i * j); 
        }
        printf("\n");
    }
}


void print_lower_pythagorean_triangle() {
    printf("\n--- Нижний треугольник Пифагора ---\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) { 
            printf("%3d ", i * j);
        }
        printf("\n");
    }
}


void draw_isosceles_triangle(int h, char symbol) {
    for (int row = 1; row <= h; row = row + 1) {
        for (int space = 1; space <= h - row; space = space + 1) {
            printf(" ");
        }
        for (int col = 1; col <= (2 * row - 1); col = col + 1) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}


int main(void) {
    SetConsoleOutputCP(65001);
    print_full_pythagorean_table();
    print_lower_pythagorean_triangle();

    char choice;
    do {
        int h = 0;
        int number = 0;
        char symbol;

        printf("\n--- Рисование фигуры на основе анализа цифр ---\n");
        printf("Введите ваше число (например, номер зачетки или вариант): ");
        if (scanf("%d", &number) != 1) {
            printf("Ошибка! Введите целое число.\n");
            while (getchar() != '\n'); 
            continue;
        }

        h = get_last_digit(number);    
        int sym_digit = get_digit_sum(number); 
        symbol = get_symbol_by_digit(sym_digit);

        printf("\nАнализ числа %d:\n", number);
        printf("Высота треугольника (последняя цифра): %d\n", h);
        printf("Сумма цифр (для выбора символа): %d\n", sym_digit);
        printf("Выбранный символ: '%c'\n\n", symbol);

        if (h > 0) {
            draw_isosceles_triangle(h, symbol);
        } else {
            printf("Высота равна 0, рисовать нечего.\n");
        }

        printf("\nПродолжить? (Да - y, нет - n): ");
        while (getchar() != '\n'); 
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nПрограмма завершена.\n");
    return 0;
}
