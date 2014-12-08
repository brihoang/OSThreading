#include "clone.h"
#include "machine.h"
#include "err.h"

Clone::Clone(Process *parent, uint32_t eax, uint32_t esp, uint32_t pc) : Process ("clone", parent->resources->forkMe()), eax(eax), esp(esp),pc(pc){
    //parent->addressSpace->fork(&addressSpace);
} 

long Clone::run() {
	Debug::printf("%d %d %d \n", eax, esp, pc);
	switchToUser(pc, esp, 0);
	return ERR_NOT_POSSIBLE;
}
