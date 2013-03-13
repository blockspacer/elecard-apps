
/*
 StbMainApp.h

Copyright (C) 2012  Elecard Devices

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Elecard Devices nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ELECARD DEVICES BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/***********************************************
* INCLUDE FILES                                *
************************************************/

#include "interface.h"

#include <time.h>

/***********************************************
* EXPORTED MACROS                              *
************************************************/

#ifdef STB225
	#define DID_KEYBOARD (16)
#else
	#define DID_KEYBOARD (0)
#endif

#define DID_FRONTPANEL (4)

#define DID_STANDBY (5)

#define FREE(x) if(x) { dfree(x); (x) = NULL; }

/***********************************************
* EXPORTED DATA                                *
************************************************/

extern volatile int keepCommandLoopAlive;
extern volatile int keyThreadActive;

/******************************************************************
* EXPORTED FUNCTIONS PROTOTYPES               <Module>_<Word>+    *
*******************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

int  helperFileExists(const char* filename);

int  helperStartApp(const char* filename);

int  helperReadLine(int file, char* buffer);

int  helperParseLine(const char *path, const char *cmd, const char *pattern, char *out, char stopChar);

int  helperParseMmio(int addr);

/** strcpy without characters unsupported by FAT filesystem
 * @param[out] dst Destination pointer
 * @param[in]  src Source stream
 * @return     dst
 */
char *helperStrCpyTrimSystem(char *dst, char *src);

void helperFlushEvents(void);

interfaceCommand_t helperGetEvent(int flush);

int  helperCheckDirectoryExsists(const char *path);

char *helperEthDevice(int i);

void signal_handler(int signal);

void tprintf(const char *str, ...);

int  helperCheckUpdates(void);

/** Copy src string to new dest buffer.
 * @param[out] dest If already allocated and have enough space, will be used without changing pointer. If buffer will not be big enough, realloc would be used on *dest.
 * @param[in]  stc  If null, *dest will be freed and nulled.
 * @return 0 if src was copied successfully
 */
int  helperSafeStrCpy( char** dest, const char* src );

/** UTC equivalent for mktime() */
time_t gmktime(struct tm *t);

/** Thread function that handles directfb events  */
void *keyThread(void *pArg);

#ifdef __cplusplus
}
#endif
