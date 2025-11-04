#include<stdio.h>

int main(){
    int KidNumber = 0;                  //the number of kids
    int KidGroup[1000001] = {0};       //position of kids
    int FirstKid = 0;                  //the position of first kid
    int counter = 0;
    scanf("%d",&KidNumber);            //get the first input
    for(int i = 1;i<=KidNumber;i++){   //from 1 to KidNumber
        scanf("%d",&KidGroup[i]);
    }
    scanf("%d",&FirstKid);
    counter = FirstKid;
    while(1){
        printf("%d ",counter);
	if (!KidGroup[counter]){
		break;
	}
	if(KidGroup[counter] == counter){
		break;
	}
        counter = KidGroup[counter];
       	//printf("##################") ;
    }
    

    return 0;
}
