#ifndef DN_GLOBALS_H
#define DN_GLOBALS_H

#include <stdio.h>
#include <malloc.h>

//--------------------------------------------------------------------------------------------------------------------------------//
//MEMORY FUNCTIONS USED BY LIBRARY:

//represents different message types
typedef enum DNmessageType
{
	DN_MESSAGE_CPU_MEMORY, //the message is about CPU memory usage
	DN_MESSAGE_GPU_MEMORY, //the message is about GPU memory usage
	DN_MESSAGE_SHADER,     //the message is about shader compilation
	DN_MESSAGE_FILE_IO     //the message is about file I/O (just used for if opening a file fails)
} DNmessageType;

//represents different message severities
typedef enum DNmessageSeverity
{
	DN_MESSAGE_NOTE,  //the message is purely informative, no error has occured
	DN_MESSAGE_ERROR, //an error has occured, but the engine is still able to run without crashing
	DN_MESSAGE_FATAL  //a fatal error has occured, and the engine will likely not be able to continue running without crashing
} DNmessageSeverity;

//the message callback function, the last parameter is the actual message in string format
void (*m_DN_message_callback)(DNmessageType, DNmessageSeverity, const char*); //TODO: figure out a better way to use this than a global variable

//for allocating heap memory:
#ifndef DN_MALLOC
#define DN_MALLOC(s) malloc((s))
#endif

//for freeing heap memory:
#ifndef DN_FREE
#define DN_FREE(p) free((p))
#endif

//for reallocating heap memory:
#ifndef DN_REALLOC
#define DN_REALLOC(p, s) realloc((p), (s))
#endif

#endif