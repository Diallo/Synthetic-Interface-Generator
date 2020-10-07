#include "V1__1_0__ServerDmActivator.h"
#include "V1__1_0__Server.h"

celix::dm::DmActivator* DmActivator::create(celix::dm::DependencyManager& mng) {
    return new V1__1_0__ServerDmActivator(mng);
}

void V1__1_0__ServerDmActivator::init() {
    V1__1_0__ServerDmActivatorBase::init();
}

void V1__1_0__ServerDmActivator::deinit() {
    V1__1_0__ServerDmActivatorBase::deinit();
}
