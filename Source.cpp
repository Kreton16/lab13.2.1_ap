#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

#define z 2 // ��������� ������������ � ���������������
#define SQR(x) (x)*(x) // ������ � ���������� � ���������� �������� �����
// ������ ���������� ���������� � ���� �����
#define MIN(x,y) ((x)>(y))?(y):(x) // ������ �� ������� �����
#define MAX(x,y) ((x)>(y))?(x):(y) // ������ �� ������� �����
// ��������� ����������� �� �������� ������ �����
#define PRINTI(w) puts("control output"); \
printf(#w"=%d\n",w)
// ��������������� ������ ����������� ������� '\'
// ������ '#' ��������������� ��� �ᒺ������ �����
// ��������� ����������� �� �������� ������� �����
#define PRINTR(w) puts ("rezult :"); \
printf (#w"=%f\n",(float)w)
void main()
{
	puts("Lab 13.2. Using macros and preprocessing directive");
	int x, y, // ���� ��� ����������
		fsqrx_y,
		fsqrx_z,// �������� ����� // ������� �����
		fzx_plus_yz_sqr,
		fxy_plus_yz,
		fzx_plus_yz,
		maxim,
		minim;
	char ch; // ������� �� ������������ ��������� ��������

	/*scanf_s("%d", z);
	PRINTI(z);*/
	do
	{
#if z > 3  // ���� ����� �������,
		puts("define maximum of two numbers");
		puts("Input 2 integer numbers");
		scanf_s("%d", &x);// �������� �����
		PRINTI(x); // ������ ��������� �����
		scanf_s("%d", &y);
		PRINTI(y);

		fsqrx_y = SQR(x + y);// ������ ���������� �������� �����
		PRINTI(fsqrx_y);

		fsqrx_z = SQR(x - z);
		PRINTI(fsqrx_z);

		maxim = MAX(fsqrx_y, fsqrx_z);
		PRINTR(maxim);
#else // ���������� ���� ������� ��������, ���� z <= 3
		
			puts("define maximum of two numbers");
			puts("Input 2 integer numbers");
			scanf_s("%d", &x);// �������� �����
			PRINTI(x); // ������ ��������� �����
			scanf_s("%d", &y);
			PRINTI(y);

			fzx_plus_yz = z * y + y * z;

			fxy_plus_yz = x * y + y * z;
			PRINTR(fxy_plus_yz);

			fzx_plus_yz_sqr = SQR(fzx_plus_yz);
			PRINTR(fzx_plus_yz_sqr);

			minim = MIN(fxy_plus_yz, fzx_plus_yz_sqr);
			PRINTR(minim);
		
#endif // ���������� ����� ������ ���������
		puts("Repeat? y /n "); ch = _getch();
	} while (ch == 'y');
}