/*
    fn_spawnVehicle.sqf
    Called by the Eden Editor module
    Params:
    0: OBJECT - The module logic object
    1: ARRAY  - Array of synced objects (e.g., spawn pad and console)
    2: BOOL   - Activation state (unused)
*/

params ["_logic", "_syncedObjects", "_activated"];

// Retrieve module attributes
private _vehicleClass = _logic getVariable ["vehicleClassName", "RHS_M2A2_BUSKI"];
private _vehicleName  = _logic getVariable ["vehicleDisplayName", "M2A2ODS (BUSK I)"];

// Parse synced objects: find the console and spawn pad
private _console  = objNull;
private _spawnPad = objNull;

{
    private _type = typeOf _x;

    // Adjust these type checks as needed based on your setup
    if (_type isKindOf "VR_Area_01_square_1x1_yellow_F") then {
        _spawnPad = _x;
    } else {
        _console = _x;
    };
} forEach _syncedObjects;

// Safety check
if (isNull _console || isNull _spawnPad) exitWith {
    diag_log "SpawnVehicle Module ERROR: Console or Spawn Pad not properly synced!";
};

// Add the action to the console on all clients
if (hasInterface) then {
    _console addAction [
        format ["Spawn %1", _vehicleName],
        {
            hint "tried to spawn";
            params ["_target", "_caller", "_actionId", "_arguments"];
            private _spawnPad     = _arguments select 0;
            private _vehicleClass = _arguments select 1;
            private _vehicleName  = _arguments select 2;

            // Create the vehicle on the server
            [[_spawnPad, _vehicleClass, _vehicleName], {
                params ["_spawnPad", "_vehicleClass", "_vehicleName"];

                private _pos = getPosASL _spawnPad;
                private _dir = getDir _spawnPad;

                private _veh = createVehicle [
                    _vehicleClass,
                    [0, 0, 0],
                    [],
                    0,
                    "NONE"
                ];
                _veh setPosASL _pos;
                _veh setDir _dir;
                _veh setVariable ["vehicleName", _vehicleName, true];
            }] remoteExec ["call", 2]; // Run on server
        },
        [_spawnPad, _vehicleClass, _vehicleName]
    ];
};
