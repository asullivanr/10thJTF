// fn_setSpawnPosition.sqf
private ["_object", "_spawnPosition"];

// Get the synchronized spawn position object
_object = _this select 0;
_spawnPosition = position _object;

// Store the spawn position in the object variable for later use
_object setVariable ["VehicleSpawner_SpawnPosition", _spawnPosition];
