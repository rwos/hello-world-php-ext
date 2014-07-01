    char *s;
    int s_sz;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &s, &s_sz) == FAILURE) {
        RETURN_NULL();
    }

    espeak_Initialize(AUDIO_OUTPUT_SYNCH_PLAYBACK, 0, NULL, 0);
    espeak_Synth(s, s_sz, 0, POS_CHARACTER, 0, 0, NULL, NULL);
