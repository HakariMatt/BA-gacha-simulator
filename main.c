#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "students.h"

Student chooseStudent(int star){
	int n, randNum;
	
	if (star == 1) {
		n = sizeof(students_one) / sizeof(students_one[0]);
		randNum = rand() % n;
		return students_one[randNum];
	}
	if (star == 2) {
		n = sizeof(students_two) / sizeof(students_two[0]);
		randNum = rand() % n;
		return students_two[randNum];
	}
	if (star == 3) {
		n = sizeof(students_three) / sizeof(students_three[0]);
		randNum = rand() % n;
		return students_three[randNum];
	}
}

int chooseStar()
{
	int totalRate = 0;
	for (int i = 0; i < 3; i++)
	{
		totalRate += rates[stars[i] - 1];
	}

	int randNum = rand() % totalRate + 1;
	int cumulativeRate = 0;
	for (int i = 0; i < 3; i++)
	{
		cumulativeRate += rates[stars[i] - 1];
		if (randNum < cumulativeRate)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		Student student = chooseStudent(chooseStar()+1);
		if (student.rate == 1) {
			printf("\x1b[94m");
		}

		if (student.rate == 2) {
			printf("\x1b[33m");
		}

		if (student.rate == 3) {
			printf("\x1b[35m");
		}	
		printf("%d* %s\n", student.rate, student.name);

		printf("\x1b[0m");
	}
	return 0;
}
