#include "module.h"

#include "pad.h"

int (*scePadInit)(void);
int (*scePadOpen)(int userID, int, int, void *);
int (*scePadClose)(int handle);
int (*scePadRead)(int handle, void *data, int count);
int (*scePadReadState)(int handle, void *data);

void initPad(void) {
	int libPad;
	loadModule("libScePad.sprx", &libPad);
	
	RESOLVE(libPad, scePadInit);
	RESOLVE(libPad, scePadOpen);
	RESOLVE(libPad, scePadClose);
	RESOLVE(libPad, scePadRead);
	RESOLVE(libPad, scePadReadState);
	
	scePadInit();
}
