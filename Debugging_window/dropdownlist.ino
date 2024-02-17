//the function is copy pasted from lvgl library
//Every widget we may require is already defined in lvgl library
static void event_handler(lv_event_t * e)
{
  char buf[32];
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    lv_dropdown_get_selected_str(obj, buf, sizeof(buf));
    LV_LOG_USER("Option: %s", buf);
    if(strcmp(buf,"   PTB")==0)
    {
      //flag value change to display value in PTB
      dd_flag=1;
    }
    if(strcmp(buf,"  mg/kg")==0)
    {
      //flag value chnage to display value in mg/kg
      dd_flag=3;
    }
  }
}

void lv_example_dropdown_1(void)
{

  /*Create a normal drop down list*/
  lv_obj_t * dd = lv_dropdown_create(lv_scr_act());
  lv_dropdown_set_options(dd, "  mg/kg\n"
                          "   PTB");

  lv_obj_align(dd, LV_ALIGN_TOP_LEFT, 20, 20);
  lv_obj_add_event_cb(dd, event_handler, LV_EVENT_ALL, NULL);
  lv_obj_set_size(dd, 220, 70);
  lv_style_t style;
  lv_style_init(&style);
  lv_style_set_text_font(&style, &lv_font_montserrat_28);
}
