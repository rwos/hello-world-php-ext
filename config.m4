PHP_ARG_ENABLE(
    hw, dnl module name
    whether to enable hello world support,
    [ --enable-hw Enable hello world support]
)
if test "$PHP_HW" != "no"
then
    dnl if needed: add include paths
    dnl ==================================
    PHP_ADD_INCLUDE(/usr/include/espeak)

    dnl add libs
    dnl ==================================
    PHP_SUBST(HW_SHARED_LIBADD)
    PHP_ADD_LIBRARY(espeak, 1, HW_SHARED_LIBADD)

    PHP_NEW_EXTENSION(hw, hello-world.c, $ext_shared)
fi
