add_library(MathFunctions my_sqrt.cxx)

# Anybody linking to this library needs to include the current source directry,
# but this is applicable only for the other consumers, not for the producers (us)
target_include_directories(MathFunctions
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                        )