// This file is only for the following platforms:
// EMERY (Pebble Time 2)


  //clear all with background_color_clock:
  graphics_context_set_fill_color(ctx, background_color_clock);
  graphics_context_set_stroke_color(ctx, background_color_clock);
  graphics_fill_rect(ctx, GRect(0, 0, 200, 228), 0, 0);
  
  //draw outlines:
  graphics_context_set_fill_color(ctx, GColorClear);
  graphics_context_set_stroke_color(ctx, background_color_lines);
  graphics_draw_line(ctx, GPoint(152,   0), GPoint(152,  21)); // vert line right of location
  graphics_draw_line(ctx, GPoint(  0,  22), GPoint(220,  22)); // hori line below location + last update time 
  graphics_draw_line(ctx, GPoint( 65,  23), GPoint( 65,  67)); // vert line right of battery
  graphics_draw_line(ctx, GPoint(118,  23), GPoint(118,  93)); // vert line left of temps / wind
  graphics_draw_line(ctx, GPoint(  0,  68), GPoint(118,  68)); // hori line below battery / weather icon
  graphics_draw_line(ctx, GPoint(  0,  94), GPoint(220,  94)); // hori line above date
  graphics_draw_line(ctx, GPoint(  0, 122), GPoint(220, 122)); // hori line below date
  graphics_draw_line(ctx, GPoint(  0, 209), GPoint(220, 209)); // hori line below time
  
  #ifndef PBL_PLATFORM_APLITE // GColorFromHEX(0xFF0000)
    //draw background areas:
    graphics_context_set_fill_color(ctx, background_color_clock); // time part
    graphics_context_set_stroke_color(ctx, background_color_clock);
    graphics_fill_rect(ctx, GRect(0, 124, 200, 207-124+1), 0, 0);
    
    graphics_context_set_fill_color(ctx, background_color_date); // date part
    graphics_context_set_stroke_color(ctx, background_color_date);
    graphics_fill_rect(ctx, GRect(0, 95, 200, 121-95+1), 0, 0);
    
    graphics_context_set_fill_color(ctx, background_color_status); // bottom bar
    graphics_context_set_stroke_color(ctx, background_color_status);
    graphics_fill_rect(ctx, GRect(0, 210, 200, 227-210+1), 0, 0);
    
    graphics_context_set_fill_color(ctx, background_color_weather);
    graphics_context_set_stroke_color(ctx, background_color_weather);
    graphics_fill_rect(ctx, GRect( 0, 69, 118, 24), 0, 0);
    graphics_fill_rect(ctx, GRect(119, 23, 81, 71), 0, 0);
    
    graphics_context_set_fill_color(ctx, background_color_moon);
    graphics_context_set_stroke_color(ctx, background_color_moon);
    graphics_fill_rect(ctx, GRect(48, 17, 37, 33), 0, 0);
  
  
    if (warning_color_location == 1){
      graphics_context_set_fill_color(ctx, GColorRed);
      graphics_context_set_stroke_color(ctx, GColorRed);
    } else if (warning_color_location == 2){
      graphics_context_set_fill_color(ctx, GColorBlack);
      graphics_context_set_stroke_color(ctx, GColorBlack);
    } else {
      graphics_context_set_fill_color(ctx, background_color_location);
      graphics_context_set_stroke_color(ctx, background_color_location);
    }
    graphics_fill_rect(ctx, GRect(0, 0, 152, 22), 0, 0);
    
    if (warning_color_last_update){
      graphics_context_set_fill_color(ctx, GColorRed);
      graphics_context_set_stroke_color(ctx, GColorRed);
    } else {
      graphics_context_set_fill_color(ctx, background_color_last_update);
      graphics_context_set_stroke_color(ctx, background_color_last_update);
    }
    graphics_fill_rect(ctx, GRect(153, 0, 33, 22), 0, 0);
  
  #endif
  
  //draw dots of time:
  graphics_context_set_fill_color(ctx, textcolor_clock);
  graphics_context_set_stroke_color(ctx, textcolor_clock);
  graphics_fill_rect(ctx, GRect(69, 102, 7, 7), 0, 0);
  graphics_fill_rect(ctx, GRect(69, 124, 7, 7), 0, 0);
  
  //draw arrows of sun rise/set:
  /*
  	MOVE_TEXT_LAYER(text_sunrise_layer, 12, 206, 69, 38);
	MOVE_TEXT_LAYER(text_sunset_layer, 167, 206, 69, 38);*/
  graphics_context_set_fill_color(ctx, GColorClear);
  graphics_context_set_stroke_color(ctx, textcolor_sun);
  graphics_draw_line(ctx, GPoint(  6, 213), GPoint(  6, 223));
  graphics_draw_line(ctx, GPoint(  5, 214), GPoint(  7, 214));
  graphics_draw_line(ctx, GPoint(  4, 215), GPoint(  8, 215));
  graphics_draw_line(ctx, GPoint(  3, 216), GPoint(  9, 216));

  graphics_draw_line(ctx, GPoint(160, 213), GPoint(160, 223)); //sunset
  graphics_draw_line(ctx, GPoint(159, 222), GPoint(161, 222)); //sunset  
  graphics_draw_line(ctx, GPoint(158, 221), GPoint(162, 221)); //sunset  
  graphics_draw_line(ctx, GPoint(157, 220), GPoint(163, 220)); //sunset  
  
  //draw battery:
  graphics_context_set_fill_color(ctx, bkgrcolor_bat);
  graphics_context_set_stroke_color(ctx, bkgrcolor_bat);
  GRect layer_bounds = GRect(0, 23, 117-53+1, 68-24+1);
  graphics_fill_rect(ctx, layer_bounds, 0, 0);
  
  graphics_context_set_fill_color(ctx, GColorClear);
  graphics_context_set_stroke_color(ctx, textcolor_bat);
  graphics_draw_line(ctx, GPoint( 0+1, 0+3+25), GPoint(56+1, 0+3+25));  // battery top
  graphics_draw_line(ctx, GPoint( 0+1,19+3+25), GPoint(56+1,19+3+25));  // battery bottom
  graphics_draw_line(ctx, GPoint( 0+1, 0+3+25+Y_OFFSET), GPoint( 0+1,19+3+25));
  
  graphics_draw_line(ctx, GPoint(57+1, 0+3+25), GPoint(57+1, 5+3+25));
  graphics_draw_line(ctx, GPoint(57+1,14+3+25), GPoint(57+1,19+3+25));
  graphics_draw_line(ctx, GPoint(60+1, 5+3+25), GPoint(60+1,14+3+25));
  graphics_draw_line(ctx, GPoint(57+1, 5+3+25), GPoint(60+1, 5+3+25));
  graphics_draw_line(ctx, GPoint(57+1,14+3+25), GPoint(60+1,14+3+25));