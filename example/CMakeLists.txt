########################################
add_executable(example_conv2d example_conv2d.cpp)
target_link_libraries(example_conv2d oplib)

########################################
# install
install(TARGETS example_conv2d
    RUNTIME DESTINATION ${BIN_INSTALL_PATH}
)
