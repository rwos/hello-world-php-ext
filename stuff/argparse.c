if (zend_parse_parameters(
        ZEND_NUM_ARGS() TSRMLS_CC,
        "l",  /* format (b, l, d, s, r, a, o, z) */
        &a    /* variables */
    ) == FAILURE
) {
    RETURN_NULL();
}
