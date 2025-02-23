#include "display.h"


/// Private variables ///
uint8_t buf1[RESOLUTION_HORIZONTAL * RESOLUTION_VERTICAL / 10 * BYTES_PER_PIXEL];
uint16_t *framebuffer;

////////////////////// Right side buttons local objects/////////////////
static lv_obj_t *label_stopRun;
static lv_obj_t *label_Cursor;
static lv_obj_t *label_DC_ACCoupling;
static lv_obj_t *label_mathFun;
static lv_obj_t *label_options;
////////////////////////////////////////////////////////////////////////

////////////////////// Bottom bar local objects ////////////////////////
static lv_obj_t *voltsDiv;
static lv_obj_t *timeDiv;
static lv_obj_t *time;
////////////////////////////////////////////////////////////////////////

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
	lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x43444d), LV_STATE_DEFAULT);
	//ui_init();


	//Display tool bars and chart template initialization
	display_bottomBarWindow();
	display_buttonsWindow();
	display_chartWindow();

}

void display_buttonsWindow(void)
{

	//////////////////////////// Stop/Run /////////////////////////////////////
	lv_obj_t *btn_stopRun = lv_button_create(lv_screen_active());
	lv_obj_set_size(btn_stopRun, 100, 48);
	lv_obj_align(btn_stopRun, LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_set_style_bg_color(btn_stopRun, lv_color_hex(0x1b39c6), LV_PART_MAIN);
	lv_obj_set_style_radius(btn_stopRun, 2, LV_PART_MAIN);


	label_stopRun = lv_label_create(btn_stopRun);
	lv_label_set_text(label_stopRun, "Stop/Run");
	lv_obj_center(label_stopRun);
	lv_obj_set_style_text_color(label_stopRun, lv_color_hex(0xd6e32b), LV_PART_MAIN);
	///////////////////////////////////////////////////////////////////////////


	//////////////////////////// Place X/Y Cursor 1 | 2 ///////////////////////
	lv_obj_t *btn_Cursor = lv_button_create(lv_screen_active());
	lv_obj_set_size(btn_Cursor, 100, 48);
	lv_obj_align(btn_Cursor, LV_ALIGN_TOP_RIGHT,0 ,50);
	lv_obj_set_style_bg_color(btn_Cursor, lv_color_hex(0x1b39c6), LV_PART_MAIN);
	lv_obj_set_style_radius(btn_Cursor, 2, LV_PART_MAIN);

	label_Cursor = lv_label_create(btn_Cursor);
	lv_label_set_text(label_Cursor, "Cursor");
	lv_obj_center(label_Cursor);
	lv_obj_set_style_text_color(label_Cursor, lv_color_hex(0xd6e32b), LV_PART_MAIN);
	///////////////////////////////////////////////////////////////////////////

	//////////////////////////// DC/AC Coupling ///////////////////////////////
	lv_obj_t *btn_DC_ACCoupling = lv_button_create(lv_screen_active());
	lv_obj_set_size(btn_DC_ACCoupling, 100, 48);
	lv_obj_align(btn_DC_ACCoupling, LV_ALIGN_TOP_RIGHT, 0, 100);
	lv_obj_set_style_bg_color(btn_DC_ACCoupling, lv_color_hex(0x1b39c6), LV_PART_MAIN);
	lv_obj_set_style_radius(btn_DC_ACCoupling, 2, LV_PART_MAIN);

	label_DC_ACCoupling = lv_label_create(btn_DC_ACCoupling);
	lv_label_set_text(label_DC_ACCoupling, "DC/AC");
	lv_obj_center(label_DC_ACCoupling);
	lv_obj_set_style_text_color(label_DC_ACCoupling, lv_color_hex(0xd6e32b), LV_PART_MAIN);
	///////////////////////////////////////////////////////////////////////////

	//////////////////////////// Math functions ///////////////////////////////
	lv_obj_t *btn_mathFun = lv_button_create(lv_screen_active());
	lv_obj_set_size(btn_mathFun, 100, 48);
	lv_obj_align(btn_mathFun, LV_ALIGN_TOP_RIGHT, 0, 150);
	lv_obj_set_style_bg_color(btn_mathFun, lv_color_hex(0x1b39c6), LV_PART_MAIN);
	lv_obj_set_style_radius(btn_mathFun, 2, LV_PART_MAIN);

	label_mathFun = lv_label_create(btn_mathFun);
	lv_label_set_text(label_mathFun, "Math");
	lv_obj_center(label_mathFun);
	lv_obj_set_style_text_color(label_mathFun, lv_color_hex(0xd6e32b), LV_PART_MAIN);
	///////////////////////////////////////////////////////////////////////////

	//////////////////////////// More options /////////////////////////////////
	lv_obj_t *btn_options = lv_button_create(lv_screen_active());
	lv_obj_set_size(btn_options, 100, 48);
	lv_obj_align(btn_options, LV_ALIGN_TOP_RIGHT, 0, 200);
	lv_obj_set_style_bg_color(btn_options, lv_color_hex(0x1b39c6), LV_PART_MAIN);
	lv_obj_set_style_radius(btn_options, 2, LV_PART_MAIN);

	label_options = lv_label_create(btn_options);
	lv_label_set_text(label_options, "Options");
	lv_obj_center(label_options);
	lv_obj_set_style_text_color(label_options, lv_color_hex(0xd6e32b), LV_PART_MAIN);
	///////////////////////////////////////////////////////////////////////////
}

void display_bottomBarWindow(void)
{
	lv_obj_t *bottom_bar = lv_obj_create(lv_scr_act());
	lv_obj_set_size(bottom_bar, 480, 22);
	lv_obj_align(bottom_bar, LV_ALIGN_BOTTOM_MID, 0, 0);
	lv_obj_set_style_bg_color(bottom_bar, lv_color_hex(0x1b39c6), LV_PART_MAIN);
	lv_obj_clear_flag(bottom_bar, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_style_border_width(bottom_bar, 0, LV_PART_MAIN);
	lv_obj_set_style_radius(bottom_bar, 0, LV_PART_MAIN);



	voltsDiv = lv_label_create(bottom_bar);
	lv_label_set_text(voltsDiv, "V/Div:");
	lv_obj_align(voltsDiv, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_text_color(voltsDiv, lv_color_hex(0xd6e32b), LV_PART_MAIN);

	timeDiv = lv_label_create(bottom_bar);
	lv_label_set_text(timeDiv, "s/Div:");
	lv_obj_align(timeDiv, LV_ALIGN_LEFT_MID, 80, 0);
	lv_obj_set_style_text_color(timeDiv, lv_color_hex(0xd6e32b), LV_PART_MAIN);

	time = lv_label_create(bottom_bar);
	lv_label_set_text(time, "Time: 12:00");
	lv_obj_align(time, LV_ALIGN_LEFT_MID, 370, 0);
	lv_obj_set_style_text_color(time, lv_color_hex(0xd6e32b), LV_PART_MAIN);
}

void display_chartWindow(void)
{
	lv_obj_t * chart;
	chart = lv_chart_create(lv_screen_active());
	lv_obj_set_size(chart, 380, 250);
	lv_obj_align(chart, LV_ALIGN_TOP_LEFT, 0, 0);
	lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
	lv_obj_set_style_radius(chart, 2, LV_PART_MAIN);
	lv_obj_set_style_bg_color(chart, lv_color_hex(0x0d0d0c), LV_PART_MAIN);
	//lv_obj_set_style_border_color(chart, lv_color_hex(0x1b39c6), LV_PART_MAIN);
	//lv_obj_set_style_border_width(chart, 2, LV_PART_MAIN);

	lv_chart_series_t * ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);

	for(uint32_t i = 0; i < 10; i++)
		lv_chart_set_next_value(chart, ser1, lv_rand(10, 50));

	lv_chart_refresh(chart); /*Required after direct set*/
}
