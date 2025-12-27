#ifndef UI_H
#define UI_H

#include "process_list.h"

#define ACTION_NONE 0
#define ACTION_REDRAW 1
#define ACTION_REFRESH 2

void init_ui();
void cleanup_ui();
void draw_ui(ProcessList *list, int selected_index, int scroll_offset, SystemInfo *sys_info);
int handle_input(int ch, ProcessList *list, int *selected_index, int *scroll_offset);
void toggle_theme();
void reset_search_mode();

#endif
