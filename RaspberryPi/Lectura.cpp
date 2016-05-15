#include <iostream>
#include <fstream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

using namespace std;

int main() {

ifstream fin;
fin.open("leer.txt", ios::in);

char valor[256];
char i = 0;
char my_character ;
int number_of_lines = 0;

	while (!fin.eof() ) {
	fin.get(my_character);
	//cout << my_character;
		if (my_character == '\n'){
			++number_of_lines;
		}
	valor[i]=my_character;
	i++;
	//printf("%d",valor);
	}
int result;
result = atoi(valor);
printf("%d \n",result);
cout << "NUMBER OF LINES: " << number_of_lines << endl;

}
