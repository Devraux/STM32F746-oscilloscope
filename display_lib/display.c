#include "display.h"


/// Private variables ///
uint8_t buf1[RESOLUTION_HORIZONTAL * RESOLUTION_VERTICAL / 10 * BYTES_PER_PIXEL];
uint16_t *framebuffer;
// uint32_t my_ltdc_layer_index = 0; /* typically 0 or 1 */


void my_flush_cb(lv_display_t *display, const lv_area_t *area, uint8_t *px_map) {
    uint16_t *buf16 = (uint16_t *)px_map;
    int32_t x, y;

    for (y = area->y1; y <= area->y2; y++) {
        for (x = area->x1; x <= area->x2; x++) {
            BSP_SDRAM_WriteData(SDRAM_BANK_ADDR + (y * 480 + x) * sizeof(uint16_t), buf16, sizeof(uint16_t));
            buf16++;
        }
    }

    display_Simple_Update(SDRAM_BANK_ADDR);
    lv_display_flush_ready(display);
}

void display_init(void)
{
	lv_init();
	lv_tick_set_cb(HAL_GetTick);
	lv_display_t *display1 = lv_display_create(RESOLUTION_HORIZONTAL, RESOLUTION_VERTICAL);
	lv_display_set_buffers(display1, buf1, NULL, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);
	lv_display_set_flush_cb(display1, my_flush_cb);
	//ui_init();
}

void display_chartWindow(void);
void display_buttonsWindow(void);
void display_bottomWindow(void);
void display_topWindow(void);
