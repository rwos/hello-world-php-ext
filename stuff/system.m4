dnl install check
dnl ==================================
dnl AC_MSG_CHECKING([for FOO library])
dnl ...
dnl if not installed
dnl then
dnl     AC_MSG_RESULT([not found])
dnl     AC_MSG_ERROR([Please install FOO-lib])
dnl fi

dnl if needed: add include paths
dnl ==================================
PHP_ADD_INCLUDE(/usr/include/espeak)

dnl add libs
dnl ==================================
PHP_SUBST(HW_SHARED_LIBADD)
PHP_ADD_LIBRARY(espeak, 1, HW_SHARED_LIBADD)

PHP_NEW_EXTENSION(hw, hello-world.c, $ext_shared)
