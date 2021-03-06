ENABLE_TESTING()
INCLUDE(AddCxxtest)

IF (WIN32)
	ADD_DEFINITIONS(-D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
	                -D_CRT_SECURE_NO_WARNINGS)
ENDIF (WIN32)

ADD_DEFINITIONS(-DPROJECT_SOURCE_DIR=\\"${CMAKE_SOURCE_DIR}\\"
                -DPROJECT_BINARY_DIR=\\"${CMAKE_BINARY_DIR}\\")

# The atom_types.h file is written to the build directory
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

# Perform tests in component-dependency order, as much as possible.
# For example, since most things depends on the atomspace,
# its is tested first.
IF (CXXTEST_FOUND)

	IF (HAVE_ATOMSPACE)
		ADD_SUBDIRECTORY (atomspace)
		ADD_SUBDIRECTORY (atomutils)

		# Persistence is for saving/restoring atomspace to disk.
		ADD_SUBDIRECTORY (persist)

		# guile provides scheme bindings for the atomspace.
		IF (HAVE_GUILE)
			ADD_SUBDIRECTORY (scm)
		ENDIF (HAVE_GUILE)

		# Many of the query tests require a working guile, so run
		# these only after guile has been tested.
		ADD_SUBDIRECTORY (query)

		# Currently, reasoning depends on query, above.
		ADD_SUBDIRECTORY (rule-engine)

		ADD_SUBDIRECTORY (pln)

	ENDIF (HAVE_ATOMSPACE)

	IF (HAVE_CYTHON AND PYTHONINTERP_FOUND)
		ADD_SUBDIRECTORY (cython)
		ADD_SUBDIRECTORY (python)
	ENDIF (HAVE_CYTHON AND PYTHONINTERP_FOUND)

ENDIF (CXXTEST_FOUND)
