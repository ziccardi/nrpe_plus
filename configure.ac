AC_INIT([nrpe++], [0.1], [massimiliano.ziccardi@gmail.com])
AC_CONFIG_SRCDIR([src/main.cpp])

AC_PROG_CXXCPP
AC_PROG_CXX
AC_PROG_CC

AM_INIT_AUTOMAKE([1.9 foreign])
AC_LANG([C++])

AC_HEADER_STDC
AC_CHECK_HEADERS([string])
AC_CHECK_HEADERS([iostream])
AC_CHECK_HEADERS([boost/asio.hpp], [],
    [AC_MSG_ERROR(You need the Boost asio libraries.)])

AC_TYPE_SIZE_T

AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

