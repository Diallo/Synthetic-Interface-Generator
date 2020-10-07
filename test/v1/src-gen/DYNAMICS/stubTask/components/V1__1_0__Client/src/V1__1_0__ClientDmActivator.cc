#include "V1__1_0__ClientDmActivator.h"
#include "V1__1_0__Client.h"

celix::dm::DmActivator* DmActivator::create(celix::dm::DependencyManager& mng) {
    return new V1__1_0__ClientDmActivator(mng);
}

void V1__1_0__ClientDmActivator::init() {
    V1__1_0__ClientDmActivatorBase::init();
}

void V1__1_0__ClientDmActivator::deinit() {
    V1__1_0__ClientDmActivatorBase::deinit();
}
