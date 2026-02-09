#define MOVE_LAYER(layer, x, y, w, h) layer_set_frame(layer, GRect(x, (y)-obstruction_shift, w, h))
#define MOVE_TEXT_LAYER(layer, x, y, w, h) MOVE_LAYER(text_layer_get_layer(layer), x, y, w, h)

static void move_layers(void) {
	MOVE_LAYER(background_paint_layer, 0, 0, 200, 228);
	MOVE_LAYER(s_image_layer_hour_1, 4, 127, 40, 56);
	MOVE_LAYER(s_image_layer_hour_2, 51, 127, 40, 56);
	MOVE_LAYER(s_image_layer_minute_1, 113, 127, 40, 56);
	MOVE_LAYER(s_image_layer_minute_2, 162, 127, 40, 56);
#ifdef COMPILE_WITH_SECONDS
	MOVE_LAYER(s_image_layer_second_1, 168, 186, 30, 35);
	MOVE_LAYER(s_image_layer_second_2, 184, 186, 30, 35);
#endif
	MOVE_TEXT_LAYER(text_sunrise_layer, 12, 206, 69, 38);
	MOVE_TEXT_LAYER(text_sunset_layer, 167, 206, 69, 38);
	MOVE_TEXT_LAYER(connection_layer, 65, 206, 69, 46);
	MOVE_TEXT_LAYER(battery_runtime_layer, 2, 24+2, 63, 20+20);

	Layer *battery_layer;
#ifdef PBL_PLATFORM_APLITE
	battery_layer = inverter_layer_get_layer(s_battery_layer_fill);
#else
	battery_layer = effect_layer_get_layer(s_battery_layer_fill);
#endif
	BatteryChargeState battery = battery_state_service_peek();
	MOVE_LAYER(battery_layer, 3, 46, (int)53*battery.charge_percent/100, 15);

	MOVE_TEXT_LAYER(Date_Layer, 5, 89, 186, 30);
	MOVE_TEXT_LAYER(cwLayer, 125, 184, 73, 20);
	MOVE_TEXT_LAYER(moonLayer_IMG, 71, NightMode ? 129 : 5, 46, 45);

	MOVE_TEXT_LAYER(weather_layer_1_temp, 69, 19, 130, 41);
	MOVE_TEXT_LAYER(weather_layer_3_location, 0, -1, 152, 23);
	MOVE_TEXT_LAYER(weather_layer_4_last_update, 153, -1, 47, 23);
	MOVE_TEXT_LAYER(weather_layer_7_string_1, 120, 73-20, 200-119-2, 40);
	MOVE_TEXT_LAYER(weather_layer_7_string_2, 0, 69, 117, 23); //TODO
	MOVE_TEXT_LAYER(text_TimeZone_layer, 5, 184, 100, 20); //TODO
#ifndef PBL_PLATFORM_APLITE
	MOVE_LAYER(bitmap_layer_get_layer(s_health_bmp_layer), 0,185,23,23);
	MOVE_LAYER(s_layer_health_up_down, 25, 187, 23, 23);
	MOVE_TEXT_LAYER(text_layer_health, 25+23, 180, 90, 30); //TODO
#endif
}

static void create_layers(void) {
  background_paint_layer = layer_create(GRectZero);
  layer_set_update_proc(background_paint_layer, layer_update_callback_background);
  layer_add_child(main_window_layer, background_paint_layer);
  
  s_image_layer_hour_1 = layer_create(GRectZero);
  layer_set_update_proc(s_image_layer_hour_1, layer_update_callback_hour_1);
  layer_add_child(main_window_layer, s_image_layer_hour_1);
  s_image_layer_hour_2 = layer_create(GRectZero);
  layer_set_update_proc(s_image_layer_hour_2, layer_update_callback_hour_2);
  layer_add_child(main_window_layer, s_image_layer_hour_2);
  
  s_image_layer_minute_1 = layer_create(GRectZero);
  layer_set_update_proc(s_image_layer_minute_1, layer_update_callback_minute_1);
  layer_add_child(main_window_layer, s_image_layer_minute_1);
  s_image_layer_minute_2 = layer_create(GRectZero);
  layer_set_update_proc(s_image_layer_minute_2, layer_update_callback_minute_2);
  layer_add_child(main_window_layer, s_image_layer_minute_2);
  
#ifdef COMPILE_WITH_SECONDS
  s_image_layer_second_1 = layer_create(GRectZero);
  layer_set_update_proc(s_image_layer_second_1, layer_update_callback_second_1);

  layer_add_child(main_window_layer, s_image_layer_second_1);
  s_image_layer_second_2 = layer_create(GRectZero);
  layer_set_update_proc(s_image_layer_second_2, layer_update_callback_second_2);
  layer_add_child(main_window_layer, s_image_layer_second_2);
#endif
  
  
  GColor textcolor = GColorWhite;
    
  // Sunrise Text
  text_sunrise_layer = text_layer_create(GRectZero); 
  text_layer_set_text_color(text_sunrise_layer, textcolor);
  text_layer_set_background_color(text_sunrise_layer, GColorClear );
  text_layer_set_font(text_sunrise_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  layer_add_child(main_window_layer, text_layer_get_layer(text_sunrise_layer));
  
  // Sunset Text
  text_sunset_layer = text_layer_create(GRectZero); 
  text_layer_set_text_color(text_sunset_layer, textcolor);
  text_layer_set_background_color(text_sunset_layer, GColorClear );
  text_layer_set_font(text_sunset_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  layer_add_child(main_window_layer, text_layer_get_layer(text_sunset_layer));      
  
  // Connection
  connection_layer = text_layer_create(GRectZero);
  text_layer_set_text_color(connection_layer, textcolor);
  text_layer_set_background_color(connection_layer, GColorClear);
  text_layer_set_font(connection_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(connection_layer, GTextAlignmentCenter);
  text_layer_set_text(connection_layer, "----");
  layer_add_child(main_window_layer, text_layer_get_layer(connection_layer));
  
  // Battery state / runtime:
  battery_runtime_layer = text_layer_create(GRectZero);
  text_layer_set_text_color(battery_runtime_layer, textcolor);
  text_layer_set_background_color(battery_runtime_layer, GColorClear);
  text_layer_set_font(battery_runtime_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  text_layer_set_text_alignment(battery_runtime_layer, GTextAlignmentCenter);
  text_layer_set_text(battery_runtime_layer, "100%\n0:00 d");
  layer_add_child(main_window_layer, text_layer_get_layer(battery_runtime_layer));
  
  #ifdef PBL_PLATFORM_APLITE
    //fill battery with an InverterLayer
    s_battery_layer_fill = inverter_layer_create(GRectZero);
    layer_set_hidden(inverter_layer_get_layer(s_battery_layer_fill), true);
    layer_add_child(main_window_layer, inverter_layer_get_layer(s_battery_layer_fill));
  #else //else use effect layer on basalt
    s_battery_layer_fill = effect_layer_create(GRectZero);
    effect_layer_add_effect(s_battery_layer_fill, effect_invert_color, (void *)0b00000000); //use global inverter color
    layer_set_hidden(effect_layer_get_layer(s_battery_layer_fill), true);
    layer_add_child(main_window_layer, effect_layer_get_layer(s_battery_layer_fill));
  #endif
  
  
  
  // Date text
  Date_Layer = text_layer_create(GRectZero);
  text_layer_set_text_color(Date_Layer, textcolor);
  text_layer_set_background_color(Date_Layer, GColorClear );
  text_layer_set_font(Date_Layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  text_layer_set_text_alignment(Date_Layer, GTextAlignmentCenter);
  layer_add_child(main_window_layer, text_layer_get_layer(Date_Layer));
  
  // Calendar Week
  cwLayer = text_layer_create(GRectZero); //64 = label_width = 144-72-2*4 = display_width - display_width/2 - 2*Space
  text_layer_set_text_color(cwLayer, textcolor);
  text_layer_set_background_color(cwLayer, GColorClear );
  text_layer_set_font(cwLayer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  text_layer_set_text_alignment(cwLayer, GTextAlignmentLeft);
  layer_add_child(main_window_layer, text_layer_get_layer(cwLayer));
  set_cwLayer_size();
  
  // Moon phase
  moonLayer_IMG = text_layer_create(GRectZero);
  text_layer_set_text_color(moonLayer_IMG, textcolor);
  text_layer_set_background_color(moonLayer_IMG, GColorClear);
  text_layer_set_font(moonLayer_IMG, pFontMoon);
  text_layer_set_text_alignment(moonLayer_IMG, GTextAlignmentCenter);
  layer_add_child(main_window_layer, text_layer_get_layer(moonLayer_IMG));
  
  // --- Weather Layers: ---
  
  // Create temperature Layer
  weather_layer_1_temp = text_layer_create(GRectZero);
  text_layer_set_background_color(weather_layer_1_temp, GColorClear);
  text_layer_set_text_color(weather_layer_1_temp, textcolor);
  text_layer_set_text_alignment(weather_layer_1_temp, GTextAlignmentRight);
  text_layer_set_text(weather_layer_1_temp, "---");
  text_layer_set_font(weather_layer_1_temp, fonts_get_system_font(FONT_KEY_LECO_32_BOLD_NUMBERS)); //FONT_KEY_BITHAM_30_BLACK
	layer_add_child(main_window_layer, text_layer_get_layer(weather_layer_1_temp));
  
  // Create location name Layer
  weather_layer_3_location = text_layer_create(GRectZero);
  text_layer_set_background_color(weather_layer_3_location, GColorClear);
  text_layer_set_text_color(weather_layer_3_location, textcolor);
  text_layer_set_text_alignment(weather_layer_3_location, GTextAlignmentCenter);
  text_layer_set_text(weather_layer_3_location, "---" /*"Loading Weather ..."*/);
  text_layer_set_font(weather_layer_3_location, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
	layer_add_child(main_window_layer, text_layer_get_layer(weather_layer_3_location));
  
  // Create last updated Layer
  weather_layer_4_last_update = text_layer_create(GRectZero);
  text_layer_set_background_color(weather_layer_4_last_update, GColorClear);
  text_layer_set_text_color(weather_layer_4_last_update, textcolor);
  text_layer_set_text_alignment(weather_layer_4_last_update, GTextAlignmentCenter);
  text_layer_set_text(weather_layer_4_last_update, "---");
  text_layer_set_font(weather_layer_4_last_update, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	layer_add_child(main_window_layer, text_layer_get_layer(weather_layer_4_last_update));
  
  // Create String_1 Layer
  weather_layer_7_string_1 = text_layer_create(GRectZero); //TODO
  text_layer_set_background_color(weather_layer_7_string_1, GColorClear);
  text_layer_set_text_color(weather_layer_7_string_1, textcolor);
  text_layer_set_text_alignment(weather_layer_7_string_1, GTextAlignmentCenter);
  text_layer_set_text(weather_layer_7_string_1, "---\n---");
  text_layer_set_font(weather_layer_7_string_1, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
	layer_add_child(main_window_layer, text_layer_get_layer(weather_layer_7_string_1));
  
  // Create String_2 Layer
  weather_layer_7_string_2 = text_layer_create(GRectZero); //TODO
  text_layer_set_background_color(weather_layer_7_string_2, GColorClear);
  text_layer_set_text_color(weather_layer_7_string_2, textcolor);
  text_layer_set_text_alignment(weather_layer_7_string_2, GTextAlignmentCenter);
  text_layer_set_text(weather_layer_7_string_2, "--- / ---");
  text_layer_set_font(weather_layer_7_string_2, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
	layer_add_child(main_window_layer, text_layer_get_layer(weather_layer_7_string_2));
  
  // Create TimeZone Layer
  text_TimeZone_layer = text_layer_create(GRectZero); //TODO
  text_layer_set_background_color(text_TimeZone_layer, GColorClear);
  text_layer_set_text_color(text_TimeZone_layer, textcolor);
  text_layer_set_text_alignment(text_TimeZone_layer, GTextAlignmentLeft);
  text_layer_set_text(text_TimeZone_layer, " ");
  text_layer_set_font(text_TimeZone_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
	layer_add_child(main_window_layer, text_layer_get_layer(text_TimeZone_layer));

  // Create Health_BMP Layer:
  #ifndef PBL_PLATFORM_APLITE
    s_health_bmp_layer = bitmap_layer_create(GRectZero);
    bitmap_layer_set_alignment(s_health_bmp_layer, GAlignBottomLeft);
    layer_add_child(main_window_layer, bitmap_layer_get_layer(s_health_bmp_layer));

    text_layer_health = text_layer_create(GRectZero); //TODO
    text_layer_set_background_color(text_layer_health, GColorClear);
    text_layer_set_text_color(text_layer_health, textcolor);
    text_layer_set_text_alignment(text_layer_health, GTextAlignmentLeft);
    text_layer_set_text(text_layer_health, " ");
    text_layer_set_font(text_layer_health, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  	layer_add_child(main_window_layer, text_layer_get_layer(text_layer_health));

    s_layer_health_up_down = layer_create(GRectZero);
    layer_set_update_proc(s_layer_health_up_down, layer_update_callback_health_up_down);
    layer_add_child(main_window_layer, s_layer_health_up_down);
  #endif

	move_layers();
    
  // --- END ---
}
