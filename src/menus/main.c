//
// Created by Lorenzo on 21/02/2026.
//

#include <stdio.h>
#include <stdlib.h>

#include "../../includes/menus.h"
#include "../../includes/supremeio.h"

void launch_main_menu() {
    // Pulisci lo schermo
    clear_screen_cp();

    // Intestazione
    print_program_head();

    get_pressed_key_cp();
}