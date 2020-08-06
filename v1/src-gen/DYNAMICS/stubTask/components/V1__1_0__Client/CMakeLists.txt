set(SOURCES
	src/V1__1_0__Client.cc
	src/EventRepository.cc
	src/EventViewer.cc
	src/NotificationCallbackThread.cc
	src/V1_StateMachineController.cc
	src/V1StubAdapterImpl.cc
)
 
set(DM_SOURCES
	src/V1__1_0__ClientDmActivator.cc
)

#The V1__1_0__Client.cmake creates the library target V1__1_0__Client_component, 
#which is linked against Celix::utils, rt, pthread and m, but not against 
#Celix::framework. This library constains the component implementation, but is as much as 
#possible decoupled from the Celix framework. Celix::utils is used for the properties implementation
#
#The V1__1_0__Client.cmake also create the V1__1_0__Client bundle target. This target
#contains the bundle activator and declaritive setup of the service provided/dependencies for the component.
#This bundle target is linked against the Celix::framework and as is result is coupled to Celix.
include(${INAETICS_GEN_DIR}/lang_cxx/component/V1__1_0__Client/V1__1_0__Client.cmake) 

celix_bundle_files(V1__1_0__Client V1__1_0__Client.owfn)


if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/test) #If test dir exist setup and include CmpTest.cmake
    set(TEST_SOURCES
        test/V1__1_0__ClientTest.cc
    ) 
    include(${INAETICS_GEN_DIR}/lang_cxx/component-test/V1__1_0__Client/V1__1_0__ClientTest.cmake)
endif ()

if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/gtest) #If gtest dir exist setup and include CmpTest.cmake
    set(TEST_SOURCES
        gtest/V1__1_0__ClientTest.cc
    )
    include(${INAETICS_GEN_DIR}/lang_cxx/component-gtest/V1__1_0__Client/V1__1_0__ClientTest.cmake)
endif ()
