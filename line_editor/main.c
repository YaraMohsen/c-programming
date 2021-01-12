#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef  unsigned char u_int_8;
typedef unsigned int u_int_32;

u_int_8 array[100];

u_int_8 *ptr=&array[0];
u_int_8 position=0;

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

u_int_8 scan_array(void){
printf("plz enter a sentence : \n \n");
   scanf("%c",ptr);
  static u_int_8 i;

for(i=1;array[i-1]!='\n';i++){
    scanf("%c",(ptr+i));
    }
ptr[i-1]='\0';
//printf("%s",&array);
return i;
}
void insert_char(u_int_8 place,u_int_8 *size){
u_int_8 replaced_char = getch();
int i= *size -1;

if(replaced_char!=13){

for(;i>position+1;i--){

    ptr[i]=ptr[i-1];
}
ptr[i]=replaced_char;
(*size)++;
ptr[(*size)]='\0';
}
 system("cls");
printf("%s",ptr);
gotoxy(position,0);
}

void backspace_char(u_int_8 place,u_int_8 *size){
int i= place-1;

if(place==0);
else{
for(;i<(*size);i++){

    ptr[i]=ptr[i+1];
}
position--;
(*size)--;
ptr[(*size)]='\0';
}
 system("cls");
printf("%s",ptr);
gotoxy(position,0);
}

void delete_after(u_int_8 place,u_int_8 *size){
int i= place+1;

if(place==(*size)-1);
else{
for(;i<(*size);i++){

    ptr[i]=ptr[i+1];
}

(*size)--;
ptr[(*size)]='\0';
}
 system("cls");
printf("%s",ptr);
gotoxy(position,0);

}

void replace_char(u_int_8 ch,u_int_8 position){

ptr[position]=ch;

system("cls");
printf("%s",ptr);
gotoxy(position,0);

}


int main(){

u_int_8 ch='+',x=0,index=0;

u_int_8 size =scan_array();
 system("cls");
printf("%s",ptr);
gotoxy(0,0);


 while(ch!=13)
 {

ch=getch();


if(ch==224){
    ch=getch();



     switch(ch)
     {
     case 75:  //left
         if(x>0)
          {--x;
           --position;
         gotoxy(position,0);}
         break;

     case 77: //right
         if(x<size)
           {
           ++position;
           ++x;
    gotoxy(position,0);
    }
         break;
    case 82:  //insert
         {insert_char(position,&size);}
         break;
     case 83:  //insert
         {delete_after(position,&size);}
         break;
     }

}
else if(ch==8){
   backspace_char(position,&size);

}
else if((ch>='A'&& ch<='Z')||(ch>='a'&& ch<='z')){
    replace_char(ch,position);

}



 }


 return 0;
}
