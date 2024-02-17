#include "SICA.h"

//this functions display the widget which will show the value of salt and temperature
lv_obj_t * obj1;
lv_obj_t * obj2;
lv_obj_t * label1;
lv_obj_t * label2;

void lv_example_style_1(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    /*Make a gradient*/
    //a way to add height and width
    lv_style_set_width(&style,315);
    lv_style_set_height(&style, LV_SIZE_CONTENT);

    lv_style_set_pad_ver(&style, 20);
    lv_style_set_pad_left(&style, 5);

    lv_style_set_x(&style, lv_pct(15));
    lv_style_set_y(&style, 170);

    /*Add border to the bottom+left*/
    //to set colour of the border
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    //to set width of the border
    lv_style_set_border_width(&style, 5);
    //to set opacity
    lv_style_set_border_opa(&style, LV_OPA_50);
    //side on which border should appear
    lv_style_set_border_side(&style, LV_BORDER_SIDE_FULL);

    /*Create an object with the new style*/
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_style_set_text_font(&style,  &lv_font_montserrat_28);
    lv_obj_add_style(obj, &style, 0);

    lv_obj_t * label = lv_label_create(obj);
    lv_label_set_text(label, " Salt Concentration");
}


void lv_example_style_2(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    /*Make a gradient*/
    lv_style_set_width(&style, 315);
    lv_style_set_height(&style, LV_SIZE_CONTENT);

    lv_style_set_pad_ver(&style, 20);
    lv_style_set_pad_left(&style, 5);

    lv_style_set_x(&style, lv_pct(15));
    lv_style_set_y(&style, 244);

    /*Add border to the bottom+left*/
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_border_width(&style, 5);
    lv_style_set_border_opa(&style, LV_OPA_50);
    lv_style_set_border_side(&style, LV_BORDER_SIDE_FULL);

    /*Add a shadow*/
    // lv_style_set_shadow_width(&style, 60);
    // lv_style_set_shadow_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    // lv_style_set_shadow_ofs_x(&style, -10);
    // lv_style_set_shadow_ofs_y(&style, 12);

    /*Create an object with the new style*/
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);

    lv_obj_t * label = lv_label_create(obj);
    lv_label_set_text(label, "      Temperature");
}


void lv_example_style_3(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    /*Make a gradient*/
    lv_style_set_width(&style, 280);
    lv_style_set_height(&style, LV_SIZE_CONTENT);

    lv_style_set_pad_ver(&style, 20);
    lv_style_set_pad_left(&style, 5);

    lv_style_set_x(&style, lv_pct(53.99));
    lv_style_set_y(&style, 170);

    /*Add border to the top+right*/
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_border_width(&style, 5);
    lv_style_set_border_opa(&style, LV_OPA_50);
    lv_style_set_border_side(&style, LV_BORDER_SIDE_FULL);


    /*Create an object with the new style*/
    obj1 = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj1, &style, 0);

    label1 = lv_label_create(obj1);

    lv_label_set_text(label1, "PROCESSING...");

}

void update_current(void)
{
  if(update_display_flag !=0 && processingFLAG==1)
  {
    lv_label_set_text_fmt(label1,"%f",display_current);
  }
  else if(processingFLAG==0)
  {
    lv_label_set_text(label1, "PROCESSING...");
  }
}


void lv_example_style_4(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    /*Make a gradient*/
    lv_style_set_width(&style, 280);
    lv_style_set_height(&style, LV_SIZE_CONTENT);

    lv_style_set_pad_ver(&style, 20);
    lv_style_set_pad_left(&style, 5);

    lv_style_set_x(&style, lv_pct(53.99));
    lv_style_set_y(&style, 244);

    /*Add border to the bottom+right*/
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_border_width(&style, 5);
    lv_style_set_border_opa(&style, LV_OPA_50);
    lv_style_set_border_side(&style, LV_BORDER_SIDE_FULL);

    /*Add a shadow*/
    // lv_style_set_shadow_width(&style, 55);
    // lv_style_set_shadow_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    // lv_style_set_shadow_ofs_x(&style, 15);
    // lv_style_set_shadow_ofs_y(&style, 12);

    /*Create an object with the new style*/
    obj2 = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj2, &style, 0);

    label2 = lv_label_create(obj2);
    // lv_label_set_text_fmt(label2,"%f",temperature);
    lv_label_set_text(label2, "PROCESSING...");

}

void update_temp(void)
{
  if(update_display_flag !=0 && processingFLAG==1)
    {
      lv_label_set_text_fmt(label2,"%f",display_temp);
    }
    else if(processingFLAG==0)
    {
      lv_label_set_text(label2, "PROCESSING...");
    }
  
}
