AC_INIT(jglut, 0.99.2, daniel.p.pflager@boeing.com)
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_FILES([Makefile])
AC_CONFIG_SRCDIR(Java_com_pflager_glut_glutInitDisplayMode.c)

AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AM_PROG_AR

AC_PROG_CC([gcc icc])
AC_PROG_CC_STDC

LT_INIT([$WIN32])

AC_PROG_LIBTOOL

CPPFLAGS="$CPPFLAGS"
LDFLAGS="$LDFLAGS"
CFLAGS="-std=gnu99"

AC_STDC_HEADERS

AC_CHECK_LIB([m],[main],,
    AC_MSG_ERROR(["Cannot find standard math library: m"]),
    )

AM_CONDITIONAL([WIN32], [! test -z ${WIN32+x}])

AC_OUTPUT
