add_library(recursive INTERFACE)

# target_sources(recursive
# INTERFACE 
#     ${CMAKE_CURRENT_SOURCE_DIR}/detail/arity.hpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/detail/parallel_evaluation.hpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/aliases.hpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/general.hpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/primitive.hpp
# )

target_include_directories(recursive
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)
