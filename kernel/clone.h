#ifndef _CLONE_H_
#define _CLONE_H_

#include "process.h"

class Clone : public Process{
public:
	Clone(Process *parent, uint32_t eax, uint32_t esp, uint32_t pc);
	virtual long run();
	uint32_t eax;
	uint32_t esp;
	uint32_t pc;
};

#endif
