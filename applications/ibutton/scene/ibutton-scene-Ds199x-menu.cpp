#include "ibutton-scene-Ds199x-menu.h"
#include "../ibutton-app.h"
#include "../ibutton-view-manager.h"
#include "../ibutton-event.h"
#include <callback-connector.h>

typedef enum {
    SubmenuIndexNVRAM,
    SubmenuIndexDs1994Timer,
    SubmenuIndexDs1991,
    SubmenuIndexInfo,
} SubmenuIndex;

void iButtonSceneDS199xMenu::on_enter(iButtonApp* app) {
    iButtonKey* key = app->get_key();
    iButtonAppViewManager* view_manager = app->get_view_manager();
    Submenu* submenu = view_manager->get_submenu();
    auto callback = cbc::obtain_connector(this, &iButtonSceneDS199xMenu::submenu_callback);
    switch(key->get_ds_type()) {
      case DallasKeyType::Ds1990:
      break;

      case DallasKeyType::Ds1992:
        submenu_add_item(submenu, "Read NVRAM", SubmenuIndexNVRAM, callback, app);
      break;

      case DallasKeyType::Ds1995:
        submenu_add_item(submenu, "Read NVRAM", SubmenuIndexNVRAM, callback, app);
      break;
      /* case DallasKeyType::Ds1994:
        submenu_add_item(submenu, "Read NVRAM", SubmenuIndexNVRAM, callback, app);
        submenu_add_item(submenu, "Read timer", SubmenuIndexDs1994Timer, callback, app);
      break;*/

    }
    submenu_set_selected_item(submenu, submenu_item_selected);

    view_manager->switch_to(iButtonAppViewManager::Type::iButtonAppViewSubmenu);
}

bool iButtonSceneDS199xMenu::on_event(iButtonApp* app, iButtonEvent* event) {
    bool consumed = false;

    if(event->type == iButtonEvent::Type::EventTypeMenuSelected) {
        submenu_item_selected = event->payload.menu_index;
        switch(event->payload.menu_index) {
        case SubmenuIndexNVRAM:
            //app->switch_to_next_scene(iButtonApp::Scene::SubmenuIndexNVRAM);
            break;
        case SubmenuIndexDs1994Timer:
            app->switch_to_next_scene(iButtonApp::Scene::SceneEmulate);
            break;
        case SubmenuIndexDs1991:
            app->switch_to_next_scene(iButtonApp::Scene::SceneAddValue);
            break;
        case SubmenuIndexInfo:
            app->switch_to_next_scene(iButtonApp::Scene::SceneDeleteConfirm);
            break;
        }
        consumed = true;
    }

    return consumed;
}

void iButtonSceneDS199xMenu::on_exit(iButtonApp* app) {
    iButtonAppViewManager* view = app->get_view_manager();
    Submenu* submenu = view->get_submenu();

    submenu_clean(submenu);
}

void iButtonSceneDS199xMenu::submenu_callback(void* context, uint32_t index) {
    iButtonApp* app = static_cast<iButtonApp*>(context);
    iButtonEvent event;

    event.type = iButtonEvent::Type::EventTypeMenuSelected;
    event.payload.menu_index = index;

    app->get_view_manager()->send_event(&event);
}
