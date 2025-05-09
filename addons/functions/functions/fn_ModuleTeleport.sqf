params ["_logic", "_syncedObjects", "_args"];

// Debugging: Log the arguments passed to the module
//diag_log format ["[Functions] Debug: Teleport module arguments: %1", _args];

// Default fallback name
private _locationName = "Forward Base";

// Try to fetch the custom location name directly from the module
private _customName = _logic getVariable ["locationName", ""];
if (_customName isEqualType "" && {_customName != ""}) then {
    _locationName = _customName;
} else {
    diag_log "[Functions] Warning: Module 'locationName' variable not found.";
	exitWith {};
};

//diag_log format ["[Functions] Teleport module location name: %1", _locationName];

// Initialize global registries if not already
if (isNil "Tenthed_Teleport_Locations") then { Tenthed_Teleport_Locations = []; };
if (isNil "Tenthed_Teleport_Terminals") then { Tenthed_Teleport_Terminals = []; };

// Identify destination and terminal
private _destination = objNull;
private _console = objNull;

{
    private _type = typeOf _x;
    if (_type isKindOf "VR_Area_01_square_1x1_yellow_F") then {
        _destination = _x;
    } else {
        _console = _x;
    };
} forEach _syncedObjects;

// Validation
if (isNull _destination || isNull _console) exitWith {
    diag_log "[Functions] ERROR: Could not identify both destination and terminal.";
	exitWith {};
};

// Prevent duplicate entry
private _alreadyExists = Tenthed_Teleport_Locations findIf {
    (_x select 0) isEqualTo _locationName && (_x select 2) isEqualTo _console
} != -1;

if (!_alreadyExists) then {
    Tenthed_Teleport_Locations pushBack [_locationName, getPos _destination, _console];
};

// Add to terminal list
if (!(_console in Tenthed_Teleport_Terminals)) then {
    Tenthed_Teleport_Terminals pushBack _console;
};

// Broadcast updates
publicVariable "Tenthed_Teleport_Locations";
publicVariable "Tenthed_Teleport_Terminals";

//diag_log format ["[Functions] Registered teleport: %1 | Terminal: %2", _locationName, _console];
//diag_log format ["[Functions] Updated location list: %1", Tenthed_Teleport_Locations];

// Rebuild all terminals after short delay
[] spawn {
    sleep 2;
    {
        [_x] remoteExecCall ["Tenthed_fnc_AddTeleportMenu", _x];
    } forEach Tenthed_Teleport_Terminals;
};
