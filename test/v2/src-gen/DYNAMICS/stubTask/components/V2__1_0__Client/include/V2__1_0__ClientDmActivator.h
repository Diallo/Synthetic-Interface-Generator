#ifndef V2__1_0__CLIENTDMACTIVATOR_H
#define V2__1_0__CLIENTDMACTIVATOR_H

#include "V2__1_0__ClientDmActivatorBase.h"

class V2__1_0__ClientDmActivator : public V2__1_0__ClientDmActivatorBase {
public:
    V2__1_0__ClientDmActivator(DependencyManager& m) : V2__1_0__ClientDmActivatorBase(m) {}
    
    void init() override;
    
    void deinit() override;
};

#endif //V2__1_0__CLIENTDMACTIVATOR_H
