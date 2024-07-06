if ( ${CAPD_BUILD_EXAMPLES} )

    add_subdirectory(examples/cndemo)
    add_subdirectory(examples/coveringRelation)
    add_subdirectory(examples/diffIncldemo)
    add_subdirectory(examples/encloseTrajectory)
    # add_subdirectory(examples/graphicalSet)          # disabled due to krak dependency
    add_subdirectory(examples/integrate)
    # add_subdirectory(examples/invariantSet)          # disabled due to krak dependency
    add_subdirectory(examples/LorenzPeriodicOrbit)
    add_subdirectory(examples/maps)
    add_subdirectory(examples/newton)
    add_subdirectory(examples/odes)
    add_subdirectory(examples/odesrig)
    add_subdirectory(examples/poincare)
    # add_subdirectory(examples/pointst)               # disabled due to krak dependency
    add_subdirectory(examples/RosslerChaoticDynamics)
    add_subdirectory(examples/RosslerPeriodicOrbit)
    # add_subdirectory(examples/taylor)                # disabled due to krak dependency

    if ( ${CAPD_ENABLE_MULTIPRECISION} )

        add_subdirectory(examples/multiPrecision)
    
    endif()

endif()
