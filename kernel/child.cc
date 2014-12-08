#include "child.h"
#include "machine.h"
#include "err.h"
#include "resource.h"

Child::Child(Process *parent) : Process("child",parent->resources->forkMe()) {
	Process::disable();
	AddressSpace *addressSpace = (AddressSpace*)resources->get(addressSpaceId, ResourceType::ADDRESS_SPACE);
	resources->close(parent->addressSpaceId);
	AddressSpace *parentAddressSpace = (AddressSpace*)parent->resources->get(parent->addressSpaceId, ResourceType::ADDRESS_SPACE);
    parentAddressSpace->fork(addressSpace);
	//addressSpace->pd = parentAddressSpace->pd;
	
}

long Child::run() {
	//Debug::printf("%x %x \n", pc, esp);
    switchToUser(pc,esp,0);
    return ERR_NOT_POSSIBLE;
}
