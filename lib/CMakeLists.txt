########################################
# put all sources in to {DIR_LIB_SRCS}
aux_source_directory(. DIR_LIB_SRCS)

########################################
# generate library
add_library(oplib ${DIR_LIB_SRCS})
#set_target_properties(liboplib PROPERTIES OUTPUT_NAME "oplib")

########################################
# install
install(TARGETS oplib
    ARCHIVE DESTINATION ${LIB_INSTALL_PATH}
)
