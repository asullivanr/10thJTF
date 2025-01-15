private["_object", "_vehicleName", "_spawnPoint", _pad1];
_object = _this select 0; // The object to add actions to (usually "this")
_vehicleName = _this select 1; // Name of the teleport location
_className = _this select 1; // Name of the teleport location
_spawnPoint = _this select 3; // Lift marker for teleport destination

// Construct the action label dynamically using the location name
_actionLabel = format["Spawn %1", _vehicleName];

// Add the action to teleport to the specified location
_object addAction [_actionLabel, {

    if (surfaceIsWater position _spawnPoint) then {
        _pad1 = getPosASL _spawnPoint;
    } else {
        _pad1 = getPosATL _spawnPoint;
    };
    _dir = getDir _spawnPoint;

    // Spawn the selected vehicle at the calculated position and direction
    _veh = createVehicle [_className, _pad1, [], 0, "NONE"];
    _veh setDir _dir;


}];