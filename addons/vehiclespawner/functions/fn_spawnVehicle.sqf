/*
    fn_spawnVehicle.sqf
    Called by the Eden Editor module
    Params:
    0: OBJECT - The module logic object
    1: ARRAY  - Array of synced objects (e.g., spawn pad and console)
    2: BOOL   - Activation state (unused)
*/

params ["_logic", "_syncedObjects", "_activated"];

// Retrieve and parse module attributes
private _vehicleClassStr = _logic getVariable ["vehicleClassNames", "RHS_M2A2_BUSKI"];
private _vehicleNameStr  = _logic getVariable ["vehicleDisplayNames", "M2A2ODS (BUSK I)"];

private _vehicleClasses = _vehicleClassStr splitString ",";
private _vehicleNames   = _vehicleNameStr splitString ",";

// Parse synced objects: find the console and spawn pad
private _console  = objNull;
private _spawnPad = objNull;

{
    private _type = typeOf _x;
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

// Add spawn actions for each vehicle
if (hasInterface) then {
    {
        private _index = _forEachIndex;
        private _class = _x;
        private _name  = _vehicleNames param [_index, _class]; // fallback to class name

        _console addAction [
            format ["Spawn %1", _name],
            {
                params ["_target", "_caller", "_actionId", "_arguments"];
                private _spawnPad     = _arguments select 0;
                private _vehicleClass = _arguments select 1;
                private _vehicleName  = _arguments select 2;

                [[_spawnPad, _vehicleClass, _vehicleName], {
                    params ["_spawnPad", "_vehicleClass", "_vehicleName"];

                    private _pos = getPosASL _spawnPad;
                    private _dir = getDir _spawnPad;

                    private _veh = createVehicle [_vehicleClass, [0, 0, 0], [], 0, "NONE"];
                    _veh setPosASL _pos;
                    _veh setDir _dir;
                    _veh setVariable ["vehicleName", _vehicleName, true];
                }] remoteExec ["call", 2]; // Server side
            },
            [_spawnPad, _class, _name]
        ];
    } forEach _vehicleClasses;
};
