#include "clone.h"
#include "machine.h"
#include "err.h"

Clone::Clone(Process *parent) : Process("child",parent->resources->forkMe()) {
	resources->close(addressSpaceId);
	addressSpaceId = parent->addressSpaceId;
	//AddressSpace *addressSpace = (AddressSpace*)resources->get(addressSpaceId, ResourceType::ADDRESS_SPACE);
	//AddressSpace *parentAddressSpace = (AddressSpace*)parent->resources->get(parent->addressSpaceId, ResourceType::ADDRESS_SPACE);
	//Debug::printf("%p %p\n", addressSpace, parentAddressSpace);
	//addressSpace->pd = parentAddressSpace->pd;
} 

long Clone::run() {
	//Debug::printf("%d %d %d \n", eax, esp, pc);
	switchToUser(pc, esp, 0);
	return ERR_NOT_POSSIBLE;
}
