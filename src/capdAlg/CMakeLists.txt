if ( ${CAPD_BUILD_EXAMPLES} )

    add_subdirectory(examples/alglibdemo)
    add_subdirectory(examples/intervals)
    add_subdirectory(examples/matrixAlgorithms)
    add_subdirectory(examples/TexWriter)
    add_subdirectory(examples/vectalg)

    if ( ${CAPD_ENABLE_MULTIPRECISION} )
    
        # add_subdirectory(examples/BigIntegers)              # disabled due to build failures

    endif()

endif()
