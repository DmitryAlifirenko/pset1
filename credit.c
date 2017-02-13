#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#define LLD "%lld"        //макрос для спецификатора чтения long long 
#define MAX 16            //максимальная длина номера карты


long long getCardNumber(){      //ввод номера карты
    long long cardnumber;
    do {
        printf("Enter the credit card number: ");
        cardnumber = get_long_long();
    }
    while (cardnumber < 0);
    return cardnumber;
}

int length;          //переменная для хранения длины номера
char str[MAX];       //массив для хранения номера
int sum;

void checkLength(long long getCardNumber) { //проверка длины номера
    sprintf(str, LLD, getCardNumber);       //присвоение массиву номера 
    length = strlen(str);                   //определение длины номера
    if (length < 13 || length > 16 || length == 14) { 
        //printf("Incorrect number!\n");
    }
}

int sumDigits(){ //проверка валидности номера карты
    int digits[length];                  
    for (int i = 0; i < length; i++)
        digits[i] = str[i] - '0';
    int j=1;
    for (int i=length-1; i >=0; i--)
    {
        if (j % 2 == 0)               //проверка, которая отбирает каждую вторую цифру номера
        {
            sum += digits[i] * 2 % 10; //присвоение сумме остачи от деления цифры умноженной на 2, на 10
            if (digits[i]*2 >= 10)   //прибавляем к сумме 1, если умноженная цифра больше 10
                sum += 1; 
        } 
        else
        {
            sum += digits[i];
        } 
        j++;
    }
    return sum;
}

/*Проверка принадлежности карты к компании по первым цифрам*/
void checkAMEX(){
    int digits[length];                  
    for (int i = 0; i < length; i++)
        digits[i] = str[i] - '0';
    if (digits[0] == 3 && digits[1] == 7 && sum % 10 == 0)       
    printf("AMEX\n");
}

void checkMASTERCARD(){
    int digits[length];                  
    for (int i = 0; i < length; i++)
        digits[i] = str[i] - '0';
    if (digits[0] == 5 && digits[1] > 0 && digits[1] < 6 && sum % 10 == 0)
    printf("MASTERCARD\n");
}

void checkVISA(){
    int digits[length];                  
    for (int i = 0; i < length; i++)
        digits[i] = str[i] - '0';
    if (digits[0] == 4 && sum % 10 == 0)
    printf("VISA\n");
}

void INVALID(/*int sum4*/) {
    if (sum % 10 != 0)
    printf("INVALID\n");
}

int main () {
    checkLength(getCardNumber());
    sumDigits();
    checkMASTERCARD();
    checkVISA();
    checkAMEX();
    INVALID();
}
