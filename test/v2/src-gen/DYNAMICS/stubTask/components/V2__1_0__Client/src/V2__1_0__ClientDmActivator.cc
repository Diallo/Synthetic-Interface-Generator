#include "V2__1_0__ClientDmActivator.h"
#include "V2__1_0__Client.h"

celix::dm::DmActivator* DmActivator::create(celix::dm::DependencyManager& mng) {
    return new V2__1_0__ClientDmActivator(mng);
}

void V2__1_0__ClientDmActivator::init() {
    V2__1_0__ClientDmActivatorBase::init();
}

void V2__1_0__ClientDmActivator::deinit() {
    V2__1_0__ClientDmActivatorBase::deinit();
}
