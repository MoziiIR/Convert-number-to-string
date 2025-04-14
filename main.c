#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>



void main()
{
    FILE *file;
    file = fopen("Data.txt","w");

    char temp[10];
    char data[100] ="";
    char *show = (void*)malloc(100*sizeof(char));
    char *str = "1 36 55 3 7 8";
    char *pEnd;
    uint32_t *num = (void*)malloc(10*sizeof(uint32_t));

    pEnd = (char*)str;

    for(uint8_t k=0;k<6;k++)
    {
        num[k] = strtoul(pEnd,&pEnd,10) *2;
    }


    // for(uint8_t k=0;k<6;k++)
    // {
    //     printf("%3u\n",num[k]);
    // }

    for(uint8_t k=0;k<6;k++) {
        sprintf(temp,"%u",num[k]);
        strcat(data,temp);

        if(k<5) strcat(data,",");
    }
    sprintf(show,"Data recieved from Client: %s",data);
    

    fputs(show,file);

    fclose(file);
    free(num);
    free(show);
}