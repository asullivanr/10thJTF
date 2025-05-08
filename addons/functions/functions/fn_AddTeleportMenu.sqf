/*
 * Tenthed_fnc_AddTeleportMenu
 * Adds teleport destination actions to an object, based on Tenthed_Teleport_Locations
 * Clears any previous actions it added
 * Params: [object]
 */

params ["_object"];

// Track added actions to remove them before adding new ones
if (isNil {_object getVariable "Tenthed_Teleport_Actions"}) then {
    _object setVariable ["Tenthed_Teleport_Actions", []];
} else {
    // Remove previous actions
    {
        _object removeAction _x;
    } forEach (_object getVariable "Tenthed_Teleport_Actions");

    // Clear the action list
    _object setVariable ["Tenthed_Teleport_Actions", []];
};

// Store action IDs as we add them
private _addedActions = [];

// Add a new action for each teleport location
{
    private _locName = _x select 0;
    private _pos = _x select 1;

    private _id = _object addAction [format["Teleport to %1", _locName], {
        params ["_target", "_caller", "_actionId", "_args"];
        _caller setPos (_args select 0);
    }, [_pos], 1.5, true, true, "", "true", 5];

    _addedActions pushBack _id;
} forEach Tenthed_Teleport_Locations;

// Save new action IDs for future cleanup
_object setVariable ["Tenthed_Teleport_Actions", _addedActions];
