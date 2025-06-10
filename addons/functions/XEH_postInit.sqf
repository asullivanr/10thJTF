Tenthed_var_showServerFPS = false;

[] spawn {
    waitUntil { !isNil { CBA_fnc_addKeybind } };

    [
        "10th JTF Mod", // Category ID (internal)
        "ToggleServerFPSDisplay",   // Action ID (internal)
        [
            "Toggle Server FPS Display",                   // Display Name in Controls Menu
            "Show/hide server FPS counter (admin only)"   // Tooltip
        ],
        { [] call Tenthed_fnc_toggleServerFPS },           // On key down
        {},                                                // On key up (optional)
        "DIK_SEMICOLON"                                             // Default key (OEM_1 = ;)
    ] call CBA_fnc_addKeybind;
};
