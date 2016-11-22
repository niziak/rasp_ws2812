set(RPI_WS281X_SOURCES
    rpi_ws281x/mailbox.c
    rpi_ws281x/ws2811.c
    rpi_ws281x/pwm.c
    rpi_ws281x/dma.c
    rpi_ws281x/rpihw.c
)

add_library(rpi_ws281x STATIC ${RPI_WS281X_SOURCES})
