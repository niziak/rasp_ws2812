#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <version.h>

//#inclue <sys/types.h>

#include "ws2811.h"

// defaults for cmdline options
#define TARGET_FREQ                              WS2811_TARGET_FREQ
#define GPIO_PIN                                 18
#define DMA                                      5
#define STRIP_TYPE                                               WS2811_STRIP_RGB               // WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE                                         WS2811_STRIP_GBR           // WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE                                         SK6812_STRIP_RGBW          // SK6812RGBW (NOT SK6812RGB)

#define WIDTH                                    8
#define HEIGHT                                   8
#define LED_COUNT                                (WIDTH * HEIGHT)

int width = WIDTH;
int height = HEIGHT;
int led_count = LED_COUNT;



ws2811_t ledstring =
{
    .freq = TARGET_FREQ,
    .dmanum = DMA,
    .channel =
    {
        [0] =
        {
            .gpionum = GPIO_PIN,
            .count = LED_COUNT,
            .invert = 0,
            .brightness = 255,
            .strip_type = STRIP_TYPE,
        },
        [1] =
        {
            .gpionum = 0,
            .count = 0,
            .invert = 0,
            .brightness = 0,
        },
    },
};


ws2811_led_t *matrix;
ws2811_return_t ret;


char digit1[8*8] = {
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
};

char digit2[8*8] = {
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0
};

char digitTest[8*8] = {
    0, 0, 0, 1, 0, 1, 1, 1,
    0, 0, 0, 1, 0, 0, 0, 1,
    0, 0, 0, 1, 0, 1, 1, 1,
    0, 0, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 1, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

void writeled (char *what, ws2811_t *ledstring)
{
    int i;
    for (i=0; i<sizeof(digit1); i++) { //TODO use typedef
	int val;
	if (what[i]) {
	    val = 0x0F0F0F;
	} else {
	    val = 0;
	}
	(*ledstring).channel[0].leds[i] = val;
    }
    
}

void writeColor (int val, ws2811_t *ledstring)
{
    int i;
  for (i=0; i<sizeof(digit1); i++) {
    (*ledstring).channel[0].leds[i] = val;
  }
}

void render () 
{
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS)
    {
        fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
        //break;
    }

}

int main(int argc, char *argv[])
{
    fprintf(stdout, "Version " VERSION_STR);
    //matrix = malloc(sizeof(ws2811_led_t) * width * height);

    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS)
    {
        fprintf(stderr, "ws2811_init failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }
    
    writeled (digit1, &ledstring); render(); sleep(1);
    writeled (digit2, &ledstring); render(); sleep(1);
    writeled (digitTest, &ledstring); render();   sleep (1);

    writeColor (0xFF0000, &ledstring); render(); sleep (1);

    writeColor (0x00FF00, &ledstring); render(); sleep (1);
    writeColor (0x0000FF, &ledstring); render(); sleep (1);

    writeColor (0x00FF00, &ledstring); render(); sleep (1);
    writeColor (0x0000FF, &ledstring); render(); sleep (1);

    writeColor (0x00FF00, &ledstring); render(); sleep (1);
    writeColor (0x0000FF, &ledstring); render(); sleep (1);

    writeColor (0x000000, &ledstring); render();


    ws2811_fini(&ledstring);
    printf ("\n");

    return 0;
}
