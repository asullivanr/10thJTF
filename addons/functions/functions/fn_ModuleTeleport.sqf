/*
 * Tenthed_fnc_ModuleTeleport
 * Called by the teleport module placed in Eden.
 * Sets up a teleport destination and interactable terminal.
 *
 * Params:
 *   0: OBJECT - module logic
 *   1: ARRAY - units synced to module (not used)
 *   2: ARRAY - arguments from module (e.g., locationName)
 */

params ["_logic", "_syncedObjects", "_args"];

//private _syncedObjects = synchronizedObjects _logic;

// Ensure there are at least two synced objects (destination + terminal)
if (count _syncedObjects < 2) exitWith {
    diag_log "[Tenthed] ERROR: Teleport module requires two synced objects (destination and terminal)";
};

// Get objects by order (DESTINATION first, TERMINAL second)
//private _destination = _syncedObjects select 0;
//private _console = _syncedObjects select 1;

{
    private _type = typeOf _x;
    if (_type isKindOf "VR_Area_01_square_1x1_yellow_F") then {
        _destination = _x;
    } else {
        _console = _x;
    };
} forEach _syncedObjects;

// Get the location name from module arguments
private _locationName = _args select 0;

// Initialize the teleport location registry if not present
if (isNil "Tenthed_Teleport_Locations") then {
    Tenthed_Teleport_Locations = [];
};

// Add new teleport destination to the global list
Tenthed_Teleport_Locations pushBack [_locationName, getPos _destination];

// Broadcast to clients for multiplayer/JIP compatibility
publicVariable "Tenthed_Teleport_Locations";

// Add the menu to the terminal object on all clients
[_console] remoteExecCall ["Tenthed_fnc_AddTeleportMenu", 0, true];
