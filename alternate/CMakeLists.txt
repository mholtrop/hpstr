
# Declare processors module
module(
        NAME alternate
        EXTRA_SOURCES AlternateDict.cxx
        DEPENDENCIES event
        EXTERNAL_DEPENDENCIES ROOT
)

message("The alternate: include: ${alternate_INCLUDE_DIR}")
root_generate_dictionary(AlternateDict ${alternate_INCLUDE_DIR}/AlternateDef.h LINKDEF ${alternate_INCLUDE_DIR}/AlternateLinkDef.h)

# install ROOT pcm file
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libAlternateDict_rdict.pcm DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
