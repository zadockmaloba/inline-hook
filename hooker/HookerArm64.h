#ifndef C_11_HOOKERARM_64_H
#define C_11_HOOKERARM_64_H


#include "Hooker.h"

namespace hooker {
    class HookerArm64 : public Hooker {
    public:
        void doHook(void *func, void *newAddr, void **origFunc) const ;
        size_t getHookHeadSize() const {
            return 8;
        }
		size_t getOrigFunctionSize() const {
			return 2 * getHookHeadSize();
		}
    };
}


#endif //C_11_HOOKERARM_64_H