#include "app.h"

void main(void)
{
    static AppData app_data;
    static CREATE_APP_RESOURCES(app_resources);

    app_auto_execute(&app_data, &app_resources);
}
