#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

 

/* 이 플래그는 메인 루프의 종료를 제어한다. */

volatile sig_atomic_t keep_going = 1;

/* 시그널 핸들러는 단지 그 플래그를 소거하고 그 자체를 다시 가능하게 한다. */

void catch_alarm (int sig)
{
	keep_going = 0;
	signal (sig, catch_alarm);
}

 

void do_stuff (void)
{
	puts ("Doing stuff while waiting for alarm. . . . ");
}

int main (void)
{
/* SIGALRM 시그널을 위한 핸들러를 만든다. */
	signal (SIGALRM, catch_alarm);
/* 잠시동안 알람이 멈추도록 설정한다. */
	alarm (2);

/* 종료할 때를 알기 위해서 while에서 플래그를 체크한다. */
while (keep_going)
	do_stuff ();
	return EXIT_SUCCESS;
}


