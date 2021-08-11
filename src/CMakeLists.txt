# [pdCalc]
# Practical design Calculator

set(pdcalc_lib_sources
  Stack.h
  Stack.cpp
)

#-------------------------------------------------------------------------------
# pdCalcLib (static)
add_library(pdCalcLib)
target_sources(pdCalcLib
  PRIVATE
  ${pdcalc_lib_sources}
)
target_include_directories(pdCalcLib
  PUBLIC 
  "${PROJECT_SOURCE_DIR}/hdr"
  "${PROJECT_SOURCE_DIR}/ext/include"
)

# main code
add_executable(main main.cpp)
set(additional_libs ${PROJECT_SOURCE_DIR}/ext/lib$<$<CONFIG:Debug>:.dbg>${PA_x64_postfix}/*.lib)

target_link_libraries(main
  PRIVATE pdCalcLib 
  ${additional_libs}
)


