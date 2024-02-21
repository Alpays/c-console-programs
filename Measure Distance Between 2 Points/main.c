#include <stdio.h>
#include <math.h>

#pragma warning(disable : 4996)

#ifdef _WIN32
	#include <windows.h>
#elif __unix__
	#include<unistd.h>
#endif



float getDistanceBetweenTwoPoints(float x1, float y1, float x2, float y2);
void clearDisplay();

int main(void)
{
	float x1, x2, y1, y2; x1 = x2 = y1 = y2 = 0.0f;

start:
	clearDisplay();
	printf("Enter the value of x coordinate of the first point.\n");

	if (!scanf("%f", &x1)) { scanf("%*[^\n]"); goto start; }
	printf("Enter the value of y coordinate of the first point.\n");
	if (!scanf("%f", &y1)) { scanf("%*[^\n]"); goto start; }
	printf("Enter the value of x coordinate of the second point.\n");
	if (!scanf("%f", &x2)) { scanf("%*[^\n]"); goto start; }
	printf("Enter the value of y coordinate of the second point.\n");
	if (!scanf("%f", &y2)) { scanf("%*[^\n]"); goto start; }

	printf("Distance between (%f, %f) and (%f, %f) is: %f", x1, y1, x2, y2, getDistanceBetweenTwoPoints(x1, y1, x2, y2));
#ifdef _WIN32
	Sleep(10 * 1000);
#elif __unix__
	Sleep(10);
#endif
	return 0;
}

void clearDisplay()
{
#ifdef __unix__
	system("clear");
#elif _WIN32
	system("cls");
#endif
}

float getDistanceBetweenTwoPoints(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
