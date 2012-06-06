/*
 * RobotTime.c
 *
 *  Created on: 04/06/2012
 *      Author: Mikkel
 */
#include "RobotTime.h"

static long g_nTime;

void init_RobotTime()
{
	g_nTime = 0;
}
void SetTime(long nNewTime)
{
	g_nTime = nNewTime;
}
long GetTime()
{
	return g_nTime;
}

