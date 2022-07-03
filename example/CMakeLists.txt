########################################
add_executable(example_conv2d example_conv2d.cpp)
#SET_TARGET_PROPERTIES(example_conv2d  PROPERTIES COMPILE_FLAGS "-fasm-blocks -mavx -DHAVEAVX=1")
target_link_libraries(example_conv2d oplib libmkl_intel_ilp64.a libmkl_sequential.a libmkl_core.a)


#add_executable(example_mkl_demo example_mkl_demo.cpp)
#target_link_libraries(example_mkl_demo oplib)

########################################
# install
install(TARGETS example_conv2d
    RUNTIME DESTINATION ${BIN_INSTALL_PATH}
)
#install(TARGETS example_mkl_demo
#    RUNTIME DESTINATION ${BIN_INSTALL_PATH}
#)