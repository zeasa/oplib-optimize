########################################
#add_executable(benchmark_net_conv2d_relu_pooling_fuse benchmark_net_conv2d_relu_pooling_fuse.c)
#target_link_libraries(benchmark_net_conv2d_relu_pooling_fuse oplib libmkl_intel_ilp64.a libmkl_sequential.a libmkl_core.a argtable3 m)
#target_link_libraries(benchmark_net_conv2d_relu_pooling_fuse oplib argtable3 m)

#add_executable(benchmark_net_conv2d_relu_pooling_nofuse benchmark_net_conv2d_relu_pooling_nofuse.c)
#target_link_libraries(benchmark_net_conv2d_relu_pooling_nofuse oplib libmkl_intel_ilp64.a libmkl_sequential.a libmkl_core.a argtable3 m)
#target_link_libraries(benchmark_net_conv2d_relu_pooling_nofuse oplib argtable3 m)

add_executable(benchmark_gemm1 benchmark_gemm1.c)
target_link_libraries(benchmark_gemm1 oplib m)

########################################
# install
install(TARGETS benchmark_net_conv2d_relu_pooling_fuse
    RUNTIME DESTINATION ${BIN_INSTALL_PATH}
)

install(TARGETS benchmark_net_conv2d_relu_pooling_nofuse
    RUNTIME DESTINATION ${BIN_INSTALL_PATH}
)
