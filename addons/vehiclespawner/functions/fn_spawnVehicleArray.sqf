params ["_logic", "_syncedObjects", "_activated"];

// Parse input from module
private _vehicleRaw = _logic getVariable ["vehicleEntries", ""];
private _vehicleList = [];

{
    private _parts = _x splitString "|";
    if (count _parts == 2) then {
        _vehicleList pushBack [_parts select 0, _parts select 1];
    };
} forEach (_vehicleRaw splitString ";");

// Identify synced objects
private _console = objNull;
private _spawnPad = objNull;

{
    private _type = typeOf _x;
    if (_type isKindOf "VR_Area_01_square_1x1_yellow_F") then {
        _spawnPad = _x;
    } else {
        _console = _x;
    };
} forEach _syncedObjects;

if (isNull _console || isNull _spawnPad) exitWith {
    diag_log "SpawnVehicle Module ERROR: Console or Spawn Pad not properly synced!";
};

if (hasInterface) then {
    {
        private _displayName = _x select 0;
        private _className = _x select 1;

        _console addAction [
            format ["Spawn %1", _displayName],
            {
                params ["_target", "_caller", "_actionId", "_arguments"];
                private _spawnPad = _arguments select 0;
                private _vehicleClass = _arguments select 1;
                private _vehicleName = _arguments select 2;

                [[_spawnPad, _vehicleClass, _vehicleName], {
                    params ["_spawnPad", "_vehicleClass", "_vehicleName"];

                    private _pos = getPosASL _spawnPad;
                    private _dir = getDir _spawnPad;

                    private _veh = createVehicle [_vehicleClass, [0, 0, 0], [], 0, "NONE"];
                    _veh setPosASL _pos;
                    _veh setDir _dir;
                    _veh setVariable ["vehicleName", _vehicleName, true];
                }] remoteExec ["call", 2];
            },
            [_spawnPad, _className, _displayName]
        ];
    } forEach _vehicleList;
};
