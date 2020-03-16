AC_INIT([nrpe++], [0.1], [massimiliano.ziccardi@gmail.com])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_PROG_CXXCPP
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LIBTOOL
AX_PTHREAD

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
BOOST_REQUIRE
BOOST_ASIO
BOOST_SYSTEM
AC_OUTPUT

