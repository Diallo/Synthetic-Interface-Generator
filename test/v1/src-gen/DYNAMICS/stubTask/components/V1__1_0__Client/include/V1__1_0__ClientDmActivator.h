#ifndef V1__1_0__CLIENTDMACTIVATOR_H
#define V1__1_0__CLIENTDMACTIVATOR_H

#include "V1__1_0__ClientDmActivatorBase.h"

class V1__1_0__ClientDmActivator : public V1__1_0__ClientDmActivatorBase {
public:
    V1__1_0__ClientDmActivator(DependencyManager& m) : V1__1_0__ClientDmActivatorBase(m) {}
    
    void init() override;
    
    void deinit() override;
};

#endif //V1__1_0__CLIENTDMACTIVATOR_H
