#include <stdio.h>
#include "raylib.h"
#include "../check-and-set.h"

#include "../../config.h"
void check_and_set(void) {
	printf("=============================================");
	printf("\nOpenPPS 'check_and_set' program     [ DEBUG ]\n");

//20+4+1+3+4
	printf("Setting trace log level [%i]       ", DEFAULT_TRACE_LOG_LEVEL);
	SetTraceLogLevel(DEFAULT_TRACE_LOG_LEVEL);
	printf("   [  OK  ]");
	
	printf("\nSetting resolution (%ix%i)...", DEFAULT_RESOLUTION_HORIZONTAL, DEFAULT_RESOLUTION_VERTICAL);
	InitWindow(DEFAULT_RESOLUTION_HORIZONTAL, DEFAULT_RESOLUTION_VERTICAL, "OpenPPS");
	printf("     [  OK  ]\n"); //   11
	
	printf("Setting target framerate [%i]...", DEFAULT_FRAMERATE);
	SetTargetFPS(DEFAULT_FRAMERATE);
	printf("     [  OK  ]\n");

	printf("Hiding cursor...");
	if (HIDE_CURSOR == true) {
		HideCursor();
		printf("                     [  OK  ]\n");
	} else { printf("                     [ FAIL ] Check 'HIDE_CURSOR' in config.h\n");}
	printf("=============================================\n");
}