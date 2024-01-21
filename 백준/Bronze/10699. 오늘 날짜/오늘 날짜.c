#include <stdio.h>
#include <time.h>

// 현 서버의 날짜를 출력한다.

int main(void){
	time_t now = time(NULL);
	struct tm tm = *localtime(&now);
    if (tm.tm_hour >= 15){
        tm.tm_mday++;
    }
	printf("%d-%02d-%02d\n", 1900 + tm.tm_year, 1 + tm.tm_mon, tm.tm_mday);
	return 0;
}