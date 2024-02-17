#include "SICA.h"

//stop button is also describe in lvgl library
static void event_handler_stop(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_CLICKED)
  {
    //only if button is clicked the cpu will enter the function 
    LV_LOG_USER("Clicked");
    //reset every flag
    START_flag=0;
    dd_flag=3;
    display_temp=0;
    display_current=0;
    update_display_flag=0;
    CurrentValue=0;
    temperature=0;
    processingFLAG=0;
    //for debugging (when building actual product the below line can be removed)
    Serial.println("STOP CLICKED");
    lv_obj_clean(lv_scr_act());
    LOGODisplay();
    lv_example_anim_1();
  }
    
}

void lv_example_btn_2(void)
{
  lv_obj_t * label;

  lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
  //this is the event handler function
  lv_obj_add_event_cb(btn1, event_handler_stop, LV_EVENT_ALL, NULL);
  //set size of button
  //this is for height and width
  lv_obj_set_size(btn1, 130, 80);
  //this is for positioning the button (x and y coordinates)
  lv_obj_align(btn1, LV_ALIGN_BOTTOM_MID, 0, -25);

  label = lv_label_create(btn1);
  lv_label_set_text(label, "REPEAT");

  // Create a style for the label and set its font size
  lv_style_t style;
  lv_style_init(&style);
  lv_style_set_text_font(&style, &lv_font_montserrat_28); // Replace with your desired font and size

  // Apply the style to the label
  lv_obj_add_style(label, &style, LV_PART_MAIN);

  lv_obj_center(label);

}
