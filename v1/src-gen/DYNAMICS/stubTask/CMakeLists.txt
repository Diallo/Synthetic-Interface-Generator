cmake_minimum_required(VERSION 3.2)
project(V1_CGP LANGUAGES C CXX)

set(PUBSUB_USE_UDPMC false)
set(PUBSUB_USE_ZMQ true)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")

set(O2N_ADD_CMAKE_WARNING_FLAGS false)
set(PUBSUB_USE_JSON_SERIALIZER true)
include(target/dependencies/export/o2n-resources/shared/o2n-setup.cmake)

## list components
add_subdirectory(components/V1__1_0__Server)
add_subdirectory(components/V1__1_0__Client)
add_subdirectory(components/ComponentInfoClient)

add_celix_container(V1
		CXX
		BUNDLES
		${INFRA_BUNDLES}
		V1__1_0__Server
		V1__1_0__Client
		ComponentInfoClient
		PROPERTIES
		PSA_ZMQ_VERBOSE=false
		PUBSUB_ETCD_DISCOVERY_VERBOSE=false
		O2N_CONTAINER_ADMIN_ACTIVE=false
		O2N_CAPABILITY_ADMIN_ACTIVE=false
		)

target_link_libraries(V1 PRIVATE "${INFRA_LINK_LIBRARIES}")


#if (EXISTS ${CMAKE_SOURCE_DIR}/Use.cmake) 
#    include(${CMAKE_SOURCE_DIR}/Use.cmake)
#endif ()


deploy_o2()
#o2_add_web_resources(${CMAKE_SOURCE_DIR}/example.html DESTINATION .)
deploy_clone()
deploy_ps()
ps_add_parameters(${CMAKE_SOURCE_DIR}/resources/ DESTINATION .)
deploy_etcd()


######################## Install Configuration ##################################
#install Config and ConfigVersion file. \
#These files are used for the FindPackage resolving
install(FILES
    "${CMAKE_SOURCE_DIR}/cmake/ConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
	RENAME ${CMAKE_PROJECT_NAME}ConfigVersion.cmake
)
install(FILES
	"${CMAKE_SOURCE_DIR}/cmake/Config.cmake"
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
	RENAME ${CMAKE_PROJECT_NAME}Config.cmake
)

#install exported library & executable targets. Only needed & possible if libs/exe are install with the ${CMAKE_PROJECT_NAME} export
#install(EXPORT ${CMAKE_PROJECT_NAME} NAMESPACE ${CMAKE_PROJECT_NAME}:: DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}/cmake FILE Targets.cmake)

#export celix targets. Only needed & possible if bundles are install with the ${CMAKE_PROJECT_NAME} export
#install_celix_targets(${CMAKE_PROJECT_NAME} NAMESPACE ${CMAKE_PROJECT_NAME}:: DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}/cmake FILE CelixTargets.cmake)


if (EXISTS "${CMAKE_SOURCE_DIR}/Use.cmake")
    #if exists install the project use cmake file. This can be used to create containers for integration 
    #or export project specific functions, etc
    install(FILES
        "${CMAKE_SOURCE_DIR}/Use.cmake"
        DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}/cmake"
    )
endif ()
