#include "V2__1_0__ServerDmActivator.h"
#include "V2__1_0__Server.h"

celix::dm::DmActivator* DmActivator::create(celix::dm::DependencyManager& mng) {
    return new V2__1_0__ServerDmActivator(mng);
}

void V2__1_0__ServerDmActivator::init() {
    V2__1_0__ServerDmActivatorBase::init();
}

void V2__1_0__ServerDmActivator::deinit() {
    V2__1_0__ServerDmActivatorBase::deinit();
}
