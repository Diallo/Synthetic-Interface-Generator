#ifndef V1__1_0__SERVERDMACTIVATOR_H
#define V1__1_0__SERVERDMACTIVATOR_H

#include "V1__1_0__ServerDmActivatorBase.h"

class V1__1_0__ServerDmActivator : public V1__1_0__ServerDmActivatorBase {
public:
    V1__1_0__ServerDmActivator(DependencyManager& m) : V1__1_0__ServerDmActivatorBase(m) {}
    
    void init() override;
    
    void deinit() override;
};

#endif //V1__1_0__SERVERDMACTIVATOR_H
