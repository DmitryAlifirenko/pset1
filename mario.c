#include <stdio.h>
#include <cs50.h>

int getHeight(){
    int height = 0;
    do {
        printf("Enter height of mario pyramid < 24:");
        height = get_int();
    }
    while (0>height || height>23);
    return height;
}
int setPyramid(getHeight){
    for(int i = 1; i <= getHeight; i++) 
	{
        for(int j = 0; j < getHeight-i; j++) //печать пробелов слева
        {
            printf("%s", " ");
        }
		for(int k = 0; k < i; k++) //печать левой пирамиды
		{
			printf("#");
		}
		printf("%s", "  "); //печать пробелов между пирамидами
		for(int m = 0; m < i; m++) //печать правой пирамиды
		{
			printf("#");
		}
		printf("\n");
	}	
	return 0;
}

int main () {
    setPyramid(getHeight());
}