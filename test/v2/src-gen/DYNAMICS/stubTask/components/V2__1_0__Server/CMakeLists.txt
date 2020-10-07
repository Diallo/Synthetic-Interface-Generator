set(SOURCES
	src/V2__1_0__Server.cc
    src/EventRepository.cc
    src/EventViewer.cc
    src/NotificationCallbackThread.cc
    src/V2_StateMachineController.cc
    src/V2StubAdapter.cc
) 
 
set(DM_SOURCES
	src/V2__1_0__ServerDmActivator.cc
)

#The ServerComponent.cmake creates the library target ServerComponent_component, 
#which is linked against Celix::utils, rt, pthread and m, but not against 
#Celix::framework. This library constains the component implementation, but is as much as 
#possible decoupled from the Celix framework. Celix::utils is used for the properties implementation
#
#The ServerComponent.cmake also create the ServerComponent bundle target. This target
#contains the bundle activator and declaritive setup of the service provided/dependencies for the component.
#This bundle target is linked against the Celix::framework and as is result is coupled to Celix.
include(${INAETICS_GEN_DIR}/lang_cxx/component/V2__1_0__Server/V2__1_0__Server.cmake) 

celix_bundle_files(V2__1_0__Server V2__1_0__Server.owfn)

if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/test) #If test dir exist setup and include CmpTest.cmake
    set(TEST_SOURCES
        test/V2__1_0__ServerTest.cc
    ) 
    include(${INAETICS_GEN_DIR}/lang_cxx/component-test/ServerComponent/V2__1_0__ServerTest.cmake)
endif ()

if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/gtest) #If gtest dir exist setup and include CmpTest.cmake
    set(TEST_SOURCES
        gtest/V2__1_0__ServerTest.cc
    )
    include(${INAETICS_GEN_DIR}/lang_cxx/component-gtest/V2__1_0__Server/V2__1_0__ServerTest.cmake)
endif ()

