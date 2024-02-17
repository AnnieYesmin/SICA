#include "SICA.h"

int flag=0;

static void set_angle(void * obj, int32_t v)
{
  //this function will be called when the peogress bar rechaes 100%
  lv_arc_set_value((lv_obj_t *)obj, v);
  if(v>=100)
  {
    lv_obj_clean(lv_scr_act());
    flag++;
  }
}
void execute(void)
{
  //as soon as progres bar ends this function will call every widgets to execute
  if (flag==1)
  {
    LOGODisplay();
    lv_example_style_1();
    lv_example_style_2();
    lv_example_style_3();
    lv_example_style_4();
    lv_example_dropdown_1();
    lv_example_btn_2();
    update_display_flag=1;
    flag=0;
  }
}
//the following function is to create a circular progress bar
static void btn1_event_cb(lv_event_t * e)
{
    lv_obj_t * btn1 = lv_event_get_target(e);
    // lv_obj_t * arc = (lv_obj_t *)lv_event_get_user_data(e);

    if(lv_obj_has_state(btn1, LV_EVENT_CLICKED)) 
    {
        lv_obj_clean(lv_scr_act());
        lv_obj_t * arc = lv_arc_create(lv_scr_act());
        lv_arc_set_rotation(arc, 270);
        lv_arc_set_bg_angles(arc, 0, 360);
        lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
        lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/
        lv_obj_set_size(arc,200,200);
        lv_obj_align(arc, LV_ALIGN_CENTER, 0, 0);
        START_flag=1;

        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, arc);
        lv_anim_set_values(&a, lv_obj_get_x(arc), 100);
        //this below function call determins the time taken in ms to complete the bar(can be adjusted as we need)
        lv_anim_set_time(&a, 1000);
        lv_anim_set_exec_cb(&a, set_angle);
        lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
        lv_anim_start(&a);
    }

}

void lv_example_anim_1(void)
{
  
  lv_obj_t * label;
  lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
  lv_obj_center(btn1);
  lv_obj_add_state(btn1, LV_STATE_DEFAULT);
  lv_obj_set_size(btn1, 200, 100);
  lv_obj_align(btn1, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_event_cb(btn1, btn1_event_cb, LV_EVENT_CLICKED, NULL);
  
  lv_style_t style;
  lv_style_init(&style);

  label = lv_label_create(btn1);
  //this is to give label name
  lv_label_set_text(label, "START");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
  
  lv_style_set_text_font(&style, &lv_font_montserrat_28);
  lv_obj_add_style(label, &style, LV_PART_MAIN);

}


void setup() 
{
  Display.begin();
  TouchDetector.begin();
  Serial.begin(115200);
  RPC.begin();

  lv_obj_t *screen =lv_obj_create(lv_scr_act());
  lv_obj_set_size(screen, Display.width(), Display.height());

  static lv_coord_t col_dsc[]={500, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t row_dsc[] = {400, LV_GRID_TEMPLATE_LAST};

  lv_obj_t *grid = lv_obj_create(lv_scr_act());
  lv_obj_set_grid_dsc_array(grid, col_dsc, row_dsc);
  lv_obj_set_size(grid, Display.width(), Display.height());
  lv_obj_center(grid);
  task1.start(read_data);

  
  //-------------------------------------SICA ----------------------------------------------------
  max31865.begin(MAX31865_2WIRE);
  digitalWrite(RelayPIN, HIGH);     //Because the Relay setup is designed to switch at LOW Triggering 
  pinMode(RelayPIN, OUTPUT);
  Vref = 1.1;//readVref(); //read the reference votage(default:VCC)
  analogReadResolution(12);
  /* ------------------------------------------------------------ ---------------------------------*/

  LOGODisplay();
  lv_example_anim_1();
  
  

}

void loop()
{
  lv_timer_handler();
  execute();

}
