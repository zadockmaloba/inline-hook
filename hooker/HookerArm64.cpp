#ifdef __ARM_ARCH_ISA_A64
#include "HookerArm64.h"
#include <sys/cachectl.h>

void hooker::HookerArm64::doHook(void *func, void *newAddr, void **origFunc) const {
    // Cast the function pointer to the appropriate type
    uintptr_t *targetFunc = reinterpret_cast<uintptr_t*>(func);

    // Store the original function address if requested
    if (origFunc != nullptr) {
        *origFunc = reinterpret_cast<void*>(*targetFunc);
    }

    // Calculate the new instruction to jump to the newAddr
    uintptr_t jumpInstruction = 0x58000051; // LDR X17, [PC, #8]; BR X17
    uintptr_t jumpAddress = reinterpret_cast<uintptr_t>(newAddr);

    // Write the jump instruction and the jump address
    targetFunc[0] = jumpInstruction;
    targetFunc[1] = jumpAddress;

#ifdef cacheflush
    cacheflush((long)func,(long)func + 8, 0);
#endif
}
#endif
