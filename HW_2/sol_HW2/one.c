#include <stdio.h>
#include <string.h>

int main()
{
	char cardNumber[105];
	scanf("%s", cardNumber);
	int len = strlen(cardNumber);
	int i, st = 0, en = len-2;
	while(st<en){
		char tmp = cardNumber[st];
		cardNumber[st] = cardNumber[en];
		cardNumber[en] = tmp;
		st++;
		en--;
	}
	int sum = 0, checkDigit = cardNumber[len-1]-48;
	for(i=0; i<len-1; i++){
		int digit = cardNumber[i]-48;
		if(i%2 == 0){
			digit = digit*2;
			if(digit > 9){
				digit = digit/10 + digit%10;
			}
		}
		cardNumber[i] = digit+48;
		sum += digit;
	}
	sum += checkDigit;
	if(sum%10 == 0){
		printf("Valid Card Number\n");
	}
	else{
		printf("Invalid Card Number\n");
	}
	return 0;
}
