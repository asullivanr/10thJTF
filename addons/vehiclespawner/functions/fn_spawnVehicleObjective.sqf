// fn_spawnVehicleObjective.sqf
private ["_object", "_vehicleCategories", "_category", "_vehicles", "_vehicleClass", "_vehicleName", "_actionID", "_spawnPosition"];

// Get the synchronized object and the list of vehicle categories
_object = _this select 0;
_vehicleCategories = _this select 1;

// Get the spawn position from the synchronized spawn position module
_spawnPosition = (_object getVariable ["VehicleSpawner_SpawnPosition", nil]);

// Check if spawn position exists
if (isNull _spawnPosition) exitWith {
    hint "No spawn position defined. Please synchronize with a Spawn Position module.";
};

// Loop through each category and add actions for vehicles
{
    _category = _x select 0;  // Get the category name (MRAP, Tank, etc.)
    _vehicles = _x select 1;  // Get the list of vehicles for this category
    
    // Loop through each vehicle in the category
    {
        _vehicleClass = _x select 0;  // Get the vehicle class name
        _vehicleName = _x select 1;   // Get the display name for the vehicle
        
        // Add the action to the object, calling spawnVehicle with the vehicle class
        _actionID = _object addAction [
            format ["Spawn %1 (%2)", _category, _vehicleName], 
            "fn_spawnVehicle.sqf", 
            [_object, _vehicleClass, _spawnPosition],  // Pass the object, vehicle class, and spawn position
            1, 
            false, 
            true, 
            "", 
            "true"
        ];
    } forEach _vehicles;

} forEach _vehicleCategories;