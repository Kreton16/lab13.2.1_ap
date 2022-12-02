#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

#define z 2 // директива препроцесора – макровизначення
#define SQR(x) (x)*(x) // макрос з параметром – визначення квадрата числа
// макрос визначення найбільшого з двох чисел
#define MIN(x,y) ((x)>(y))?(y):(x) // макрос як умовний вираз
#define MAX(x,y) ((x)>(y))?(x):(y) // макрос як умовний вираз
// виведення повідомлення та значення цілого числа
#define PRINTI(w) puts("control output"); \
printf(#w"=%d\n",w)
// використовується символ продовження макроса '\'
// символ '#' використовується для об’єднання рядків
// виведення повідомлення та значення дійсного числа
#define PRINTR(w) puts ("rezult :"); \
printf (#w"=%f\n",(float)w)
void main()
{
	puts("Lab 13.2. Using macros and preprocessing directive");
	int x, y, // змінні для розрахунків
		fsqrx_y,
		fsqrx_z,// допоміжна змінна // квадрат числа
		fzx_plus_yz_sqr,
		fxy_plus_yz,
		fzx_plus_yz,
		maxim,
		minim;
	char ch; // відповідь чи продовжувати виконання програми

	/*scanf_s("%d", z);
	PRINTI(z);*/
	do
	{
#if z > 3  // якщо умова істинна,
		puts("define maximum of two numbers");
		puts("Input 2 integer numbers");
		scanf_s("%d", &x);// введення числа
		PRINTI(x); // макрос виведення числа
		scanf_s("%d", &y);
		PRINTI(y);

		fsqrx_y = SQR(x + y);// макрос визначення квадрату числа
		PRINTI(fsqrx_y);

		fsqrx_z = SQR(x - z);
		PRINTI(fsqrx_z);

		maxim = MAX(fsqrx_y, fsqrx_z);
		PRINTR(maxim);
#else // компілювати іншу частину програми, якщо z <= 3
		
			puts("define maximum of two numbers");
			puts("Input 2 integer numbers");
			scanf_s("%d", &x);// введення числа
			PRINTI(x); // макрос виведення числа
			scanf_s("%d", &y);
			PRINTI(y);

			fzx_plus_yz = z * y + y * z;

			fxy_plus_yz = x * y + y * z;
			PRINTR(fxy_plus_yz);

			fzx_plus_yz_sqr = SQR(fzx_plus_yz);
			PRINTR(fzx_plus_yz_sqr);

			minim = MIN(fxy_plus_yz, fzx_plus_yz_sqr);
			PRINTR(minim);
		
#endif // завершення блоку умовної компіляції
		puts("Repeat? y /n "); ch = _getch();
	} while (ch == 'y');
}