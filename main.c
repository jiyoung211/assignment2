#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);


int main(void)
{
   filestat1();
   filestat2();
   filetime1();
   filetime2();
   sizecmp();
   blockcmp();
   datecmp();
   timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
   stat("text1", &stat1);//text1 size,blocks 크기 저장
   printf("text1 size: %d\n", (int)stat1.st_size);
   printf("text1 blocks : %d\n", (int)stat1.st_blocks);
   return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
   stat("text2", &stat2);// text1 size,blocks 크기 저장
   printf("text2 size: %d\n", (int)stat2.st_size);
   printf("text2 blocks : %d\n", (int)stat2.st_blocks);
   return;
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
   stat("text1", &stat1);
   time1 = localtime(&stat1.st_mtime);//시간정보가져오기
   printf("Time information of text1\n");
   printf("month : %d\n", time1->tm_mon+1);
   printf("date : %d\n", time1->tm_mday);
   printf("hour : %d\n", time1->tm_hour);
   printf("min : %d\n", time1->tm_min);
   return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
   stat("text2", &stat2);
   time2 = localtime(&stat2.st_mtime);//시간정보가져오기
   printf("Time information of text2\n");
   printf("month : %d\n", time2->tm_mon + 1);
   printf("date : %d\n", time2->tm_mday);
   printf("hour : %d\n", time2->tm_hour);
   printf("min : %d\n", time2->tm_min);
   return;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
   printf("size compare\n");

   if((int)stat1.st_size > (int)stat2.st_size)
   printf("text1 is bigger\n");
         else{
        if((int)stat1.st_size == (int)stat2.st_size)
{
                 printf("The two file sizes are the same\n");
}
   printf("text2 is bigger\n");

        }

   return;
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
   printf("block compare\n");

   if((int)stat1.st_blocks > (int)stat2.st_blocks)
        printf("text1 is bigger\n");
        else if((int)stat1.st_blocks == (int)stat2.st_blocks)
                 printf("The two file block sizes are the same\n");
		 else 
			printf("text2 is bigger\n");

        return;
}


//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	printf("Date Compare\n");

	if(time1->tm_mon == time2->tm_mon){
		if(time1->tm_mday > time2->tm_mday){
			printf("Text1 is latest\n");
		}else if(time2->tm_mday > time1->tm_mday) printf("Text2 is latest\n");
			else printf("Text1 & Text2 same date.\n");
	}
	else if(time1->tm_mon > time2->tm_mon){
		printf("Text 1 is lastest\n");
		}else if(time2->tm_mon > time1->tm_mon) printf("Text2 is lastest\n");
			else printf("Text1 & Text2 same date.\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	printf("time Compare\n");

	if(time1->tm_hour == time2->tm_hour){
		if(time1->tm_min > time2->tm_min){
			printf("Text1 is latest\n");
		}else if(time2->tm_min > time1->tm_min) printf("Text2 is latest\n");
		else printf("Text1 & Text2 same time.\n");
	}
	else if(time1->tm_hour > time2->tm_hour){
		printf("Text 1 is lastest\n");
	}else if(time2->tm_hour > time1->tm_hour) printf("Text2 is lastest\n");
		else printf("Text1 & Text2 same time. \n");
}
