#ifndef V2__1_0__SERVERDMACTIVATOR_H
#define V2__1_0__SERVERDMACTIVATOR_H

#include "V2__1_0__ServerDmActivatorBase.h"

class V2__1_0__ServerDmActivator : public V2__1_0__ServerDmActivatorBase {
public:
    V2__1_0__ServerDmActivator(DependencyManager& m) : V2__1_0__ServerDmActivatorBase(m) {}
    
    void init() override;
    
    void deinit() override;
};

#endif //V2__1_0__SERVERDMACTIVATOR_H
