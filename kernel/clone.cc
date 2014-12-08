#include "clone.h"
#include "machine.h"
#include "err.h"

Clone::Clone(Process *parent) : Process("child",parent->resources->forkMe()) {
	Process::disable();
	//AddressSpace *addressSpace = (AddressSpace*)resources->get(addressSpaceId, ResourceType::ADDRESS_SPACE);
	resources->close(addressSpaceId);
	//AddressSpace *parentAddressSpace = (AddressSpace*)parent->resources->get(parent->addressSpaceId, ResourceType::ADDRESS_SPACE);
	addressSpaceId = parent->addressSpaceId;
	//addressSpace->pd = parentAddressSpace->pd;
} 

long Clone::run() {
	//Debug::printf("%d %d %d \n", eax, esp, pc);
	switchToUser(pc, esp, 0);
	return ERR_NOT_POSSIBLE;
}
