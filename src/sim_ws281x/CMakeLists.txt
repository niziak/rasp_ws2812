set(SIM_WS281X_SOURCES
    mailbox.c
    ws2811.c
    pwm.c
    dma.c
    rpihw.c
)

add_library(sim_ws281x STATIC ${SIM_WS281X_SOURCES})
