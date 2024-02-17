//Image SICA display also found in lvgl
void LOGODisplay(void)
{
  static lv_coord_t col_dsc[] = { 755, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t row_dsc[] = { 433, LV_GRID_TEMPLATE_LAST};

  lv_obj_t * grid = lv_obj_create(lv_scr_act());
  lv_obj_set_grid_dsc_array(grid, col_dsc, row_dsc);
  lv_obj_set_size(grid, Display.width(), Display.height());
  lv_obj_center(grid);

  lv_obj_t * obj;
  lv_obj_t * img1;

  obj = lv_obj_create(grid);
  lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 0, 1,LV_GRID_ALIGN_STRETCH, 0, 1);
  lv_obj_align(obj, LV_ALIGN_TOP_RIGHT, 100, 0);

  LV_IMG_DECLARE(img_arduinologo);

  img1 = lv_img_create(obj);
  lv_img_set_src(img1, &img_arduinologo);

  lv_obj_align(img1, LV_ALIGN_TOP_RIGHT, 0, 0);
  lv_obj_set_size(img1, 154, 60);

}
