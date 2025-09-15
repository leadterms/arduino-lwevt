/**
 * \file            lwevt.h
 * \brief           Lightweight event manager for C
 */
#ifndef LWEVT_HDR_H
#define LWEVT_HDR_H

#include <stddef.h>
#include <stdint.h>
#include "lwevt_opt.h"
#include "lwevt_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lwevt_evt_tag {
    uint32_t type;
    void*    data;
} lwevt_evt_t;

typedef void (*lwevt_fn_evt_cb)(lwevt_evt_t* evt);

void lwevt_init(void);
void lwevt_register(lwevt_fn_evt_cb fn);
void lwevt_dispatch(uint32_t type, void* data);

#ifdef __cplusplus
}
#endif

#endif /* LWEVT_HDR_H */