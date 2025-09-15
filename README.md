# Arduino LWEVT

Lightweight event manager for C/Arduino projects.

## Features

- Simple event registration and dispatch
- Configurable maximum handlers
- Suitable for embedded and resource-constrained environments

## Usage

Include the header:

```c
#include "lwevt.h"
```

Register handlers and dispatch events:

```c
void my_handler(lwevt_evt_t* evt) {
    // Handle event
}

lwevt_init();
lwevt_register(my_handler);
lwevt_dispatch(MY_EVENT_TYPE, my_data);
```

See `example/main.c` for more usage.
