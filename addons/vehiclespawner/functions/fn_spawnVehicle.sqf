// fn_spawnVehicle.sqf
private ["_object", "_vehicleClass", "_spawnPosition", "_vehicle"];

_object = _this select 0;  // Get the synchronized object
_vehicleClass = _this select 1;  // Get the vehicle class
_spawnPosition = _this select 2;  // Get the spawn position

// Create the vehicle at the spawn position
_vehicle = createVehicle [_vehicleClass, _spawnPosition, [], 0, "NONE"];

// Optionally, set the vehicle's direction to match the object
_vehicle setDir (direction _object);

// Optional: If you want the vehicle to be crewed, you can add logic here.
