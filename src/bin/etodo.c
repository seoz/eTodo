#include <Elementary.h>
#include "etodo.h"

static Evas_Object *
create_menu(Evas_Object *parent)
{
   Evas_Object *list;

   list = elm_list_add(parent);
   elm_list_item_append(list, "Task", NULL, NULL, task_cb, NULL);
   elm_list_item_append(list, "Calendar", NULL, NULL, NULL, NULL);
   elm_list_item_append(list, "Settings", NULL, NULL, NULL, NULL);
   elm_list_go(list);

   return list;
}

static void
my_win_main(void)
{
   Evas_Object *win, *nf, *list;

   win = elm_win_util_standard_add("etodo", "eTodo");
   elm_win_autodel_set(win, EINA_TRUE);
   evas_object_resize(win, 300, 400);
   evas_object_show(win);

   nf = elm_naviframe_add(win);
   evas_object_size_hint_weight_set(nf, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_win_resize_object_add(win, nf);
   evas_object_show(nf);

   list = create_menu(win);
   elm_naviframe_item_push(nf, "eTodo", NULL, NULL, list, NULL);
}

EAPI_MAIN int
elm_main(int argc, char **argv)
{
   elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);
   my_win_main();
   elm_run();
   elm_shutdown();
}
ELM_MAIN();
