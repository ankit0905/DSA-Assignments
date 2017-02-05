#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int isLeapYear(int year)
{
	if(year%4 !=0 || (year%100 == 0 && year%400 != 0))
		return 0;
	else 
		return 1;
}

void calc(int year, int numDays)
{
	int st = 0, days = 0;
	while(1){
		if(st == 1 && isLeapYear(year) == 1){
			if(days+monthDays[st]+1 < numDays){
				days += monthDays[st];
				days++;
				st++;
			}
			else{
				break;
			}	
		}
		if(days+monthDays[st] < numDays){
			days += monthDays[st];
			st++;
		}
		else{
			break;
		}
	}
	int diff = numDays-days;
	printf("%s %d,",months[st],diff);
}

int main(int argc, char *argv[])
{
	const char *inp1 = argv[1], *inp2 = argv[2];
	int year = atoi(inp1), numDays = atoi(inp2);
	//printf("%d %d\n",year,numDays);
	calc(year, numDays);
	int st = 1900;
	int diff = year-st;
	int tmp = diff/400;
	st += 400*tmp;
	int y,oddDays = 1;
	for(y = st; y < year; y++){
		if(isLeapYear(y))
			oddDays += 2;
		else
			oddDays += 1;
	}
	oddDays = oddDays%7;
	oddDays = (oddDays+numDays-1)%7;
	printf(" %s\n",days[oddDays]);
	return 0;
}
