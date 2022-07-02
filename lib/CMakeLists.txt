########################################
# put all sources in to {DIR_LIBHIRT_SRCS}
aux_source_directory(. DIR_LIB_SRCS)

########################################
# generate library
add_library(testbench_encode ${DIR_LIB_SRCS})

########################################
# install
install(TARGETS testbench_encode
    ARCHIVE DESTINATION ${LIB_INSTALL_PATH}
)