/**
 * \file            lwevt.c
 * \brief           Lightweight event manager for C
 */
#include "lwevt.h"

#ifndef LWEVT_MAX_HANDLERS
#define LWEVT_MAX_HANDLERS 8
#endif

static lwevt_fn_evt_cb handlers[LWEVT_MAX_HANDLERS];
static size_t handler_count = 0;

void lwevt_init(void) {
    handler_count = 0;
}

void lwevt_register(lwevt_fn_evt_cb fn) {
    if (handler_count < LWEVT_MAX_HANDLERS) {
        handlers[handler_count++] = fn;
    }
}

void lwevt_dispatch(uint32_t type, void* data) {
    lwevt_evt_t evt;
    evt.type = type;
    evt.data = data;
    for (size_t i = 0; i < handler_count; ++i) {
        if (handlers[i]) {
            handlers[i](&evt);
        }
    }
}