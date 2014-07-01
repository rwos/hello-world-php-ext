PHP_ARG_ENABLE(
    hw,
    whether to enable hello world support,
    [ --enable-hw Enable hello world support]
)
if test "$PHP_HW" != "no"
then
    PHP_SUBST(HW_SHARED_LIBADD)
    dnl               module name, source files,  libraries
    PHP_NEW_EXTENSION(hw,          hello-world.c, $ext_shared)
fi
