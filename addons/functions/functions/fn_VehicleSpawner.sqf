//if (!isServer) exitWith {};

private ["_spawnPoint", "_vehicleIndex", "_selectedVehicle", "_pad1", "_dir"];

_spawnPoint = _this select 0;    // Spawn point position
_categoryIndex = _this select 1;  // Index of the category to spawn in _category array
_vehicleIndex = _this select 2;  // Index of the vehicle to spawn in _vehicles array

// List of vehicles to choose from
_utility = [ // Vehicle class
    "B_Truck_01_Repair_F", // 0
    "B_Truck_01_fuel_F", // 1
    "B_Truck_01_ammo_F", // 2
    "OPTRE_cart" // 3
    // Add more vehicles as needed
];
_utility_name = [ // Vehicle Name, index # must match above
    "Repair_F", // 0
    "fuel_F", // 1
    "ammo_F", // 2
    "cart" // 3
    // Add more vehicles as needed
];
// List of vehicles to choose from
_airPelican = [ // 1
    "Tenthed_Pelican_SOCOM_Jungle", // 0
    "Tenthed_Pelican_Jungle" // 1
    // Add more vehicles as needed
];
// List of vehicles to choose from
_airAdditional = [ // 1
    "OPTRE_UNSC_hornet", // 0
    "Tenthed_Falcon", // 1
    "OPTRE_AV22_Sparrowhawk", // 2
    "TCF_UNSC_Nightingale"
    // Add more vehicles as needed
];
// List of vehicles to choose from
_airFastMovers = [ // 1
    "FIR_F23A_Wizard", // 0
    "FIR_F35B_VMFA531", // 1
    "B_Plane_CAS_01_dynamicLoadOut_F" // 2
    // Add more vehicles as needed
];
// List of vehicles to choose from
_tank = [ // 2
    "I_APC_Wheeled_03_cannon_F", // 0
    "LM_OPCAN_AFV102_AR_WDL", // 1
    "I_APC_tracked_03_cannon_F", // 2
    "OPTRE_M494",
    "O_T_APC_Tracked_02_cannon_ghex_F",
    "B_T_AFV_Wheeled_01_up_cannon_F",
    "B_T_MBT_01_TUSK_F",
    "O_T_MBT_04_command_F",
    "O_T_02_MBT_railgun_ghex_F",
    "OPTRE_tarantula_01",
    "B_T_MBT_01_arty_F",
    "B_T_APC_Tracked_01_CRV_F"
    // Add more vehicles as needed
];
// List of vehicles to choose from
_car = [ // 3
    "OPTRE_M12_FAV_APC", // 0
    "OPTRE_M12_LRV" // 1
    // Add more vehicles as needed
];
// List of vehicles to choose from
_fun = [ // 4
    "C_Kart_01_Blu_F", // 0
    "C_Kart_01_Fuel_F", // 1
    "C_Kart_01_Red_F", // 2
    "C_Kart_01_Vrana_F" // 3
    // Add more vehicles as needed
];

// Ensure the index is within bounds
if (_vehicleIndex >= 0) then {
    // Switch statement to check different cases
    switch (_categoryIndex) do {
        case "Utility": { // Utility
            _selectedVehicle = _utility select _vehicleIndex;
        };
        case "AirPelican": { // Air
            _selectedVehicle = _airPelican select _vehicleIndex;
        };
        case "AirAdditional": { // Air
            _selectedVehicle = _airAdditional select _vehicleIndex;
        };
        case "AirFastMovers": { // Air
            _selectedVehicle = _airFastMovers select _vehicleIndex;
        };
        case "Tank": { // Tank
            _selectedVehicle = _tank select _vehicleIndex;
        };
        case "Car": { // Car
            _selectedVehicle = _car select _vehicleIndex;
        };
        case "Fun": { // Fun
            _selectedVehicle = _fun select _vehicleIndex;
        };
        default {
            hint "Invalid category index!";
            // Default code if no cases match
        };
    };

    if (surfaceIsWater position _spawnPoint) then {
        _pad1 = getPosASL _spawnPoint;
    } else {
        _pad1 = getPosATL _spawnPoint;
    };
    _dir = getDir _spawnPoint;

    // Spawn the selected vehicle at the calculated position and direction
    _veh = createVehicle [_selectedVehicle, _pad1, [], 0, "NONE"];
    _veh setDir _dir;
} else {
    hint "Invalid vehicle index!";
};

// TODO: Move the vehicle name from the ingame code into the script code here.