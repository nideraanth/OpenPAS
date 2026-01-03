/*******************************************************************************
 * OpenPAS (Open Portable Atomic-Chemistry Simulator)                          *
 * Copyright (C) 2026 Ronald Nidera                                            *
 * *
 * This program is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation, either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 * *
 * Any redistribution of this code MUST retain this copyright notice and       *
 * give credit to the original author: Ronald Nidera.                          *
 *******************************************************************************/

#include <stdlib.h>
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
	if (!IsWindowReady()) {
		printf("     [ FAIL ]\n");
		printf("Error: OpenGL / WGL driver failed to initialize! \n");
		printf("Tip: If on a VM, enable 3D acceleration or enable KVM.\n");
		printf("Press [ENTER] twice to exit.");
		while (getchar() != '\n');

        getchar();
		exit(1);
	}
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