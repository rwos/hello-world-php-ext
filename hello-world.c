/* boilerplate */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"

#include "hello-world.h"

#include <speak_lib.h>

/* function registration */
static zend_function_entry hw_php_functions[] = {
    PHP_FE(hello_world, NULL) /* name from below */
    {NULL, NULL, NULL}        /* end of vector   */
};

/* extension boilerplate */
zend_module_entry hw_module_entry = {
    STANDARD_MODULE_HEADER,
    "hw", /* extension name */
    hw_php_functions, /* functions */
    NULL, /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    "1.0", /* version */
    STANDARD_MODULE_PROPERTIES
};
/* shared lib extension boilerplate */
#ifdef COMPILE_DL_HW
ZEND_GET_MODULE(hw)
#endif

/* actual code starts here */

PHP_FUNCTION(hello_world)
{
    char *s;
    int s_sz;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &s, &s_sz) == FAILURE) {
        RETURN_NULL();
    }

    espeak_Initialize(AUDIO_OUTPUT_SYNCH_PLAYBACK, 0, NULL, 0);
    espeak_Synth(s, s_sz, 0, POS_CHARACTER, 0, 0, NULL, NULL);
}
