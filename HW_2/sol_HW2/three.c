#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char itemName[20];
	int itemCode;
	float price;
	int QtyInStock;
	int IsHighDemand;
	int SoldToday;
}Item;

Item list[20];
int count = 0;

void addItem(char* item, int code, float price, int qty)
{
	strcpy(list[count].itemName,item);
	list[count].itemCode = code;
	list[count].price = price;
	list[count].QtyInStock = qty;
	count++;
}

void updatePrice(char* item, float newPrice)
{
	int i;
	for(i=0; i<count; i++){
		if(strcmp(list[i].itemName,item)==0){
			list[i].price = newPrice;
			break;
		}
	}
}

void updateStock(char* item, int qty)
{
	int i;
	for(i=0; i<count; i++){
		if(strcmp(list[i].itemName,item)==0){
			list[i].QtyInStock = qty;
			break;
		}
	}
}

void showPriceList()
{
	int i;
	for(i=0; i<count; i++){
		printf("%s: %f\n",list[i].itemName, list[i].price);
	}
}

void sellItem(char* item)
{
	int i;
	for(i=0; i<count; i++){
		if(strcmp(list[i].itemName,item)==0){
			list[i].SoldToday++;
			break;
		}
	}
}

void Exit()
{
	exit(0);
}

int main()
{
	addItem("apple",1,2.0,10);
	addItem("orange",2,5.0,5);
	addItem("mango",3,4.0,16);
	showPriceList();
	updateStock("apple",4);
	updatePrice("orange",6.0);
	showPriceList();
	Exit();
	return 0;
}
