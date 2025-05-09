params ["_object"];

// Clean up any old actions
private _oldActions = _object getVariable ["Tenthed_Teleport_Actions", []];
{
    _object removeAction _x;
} forEach _oldActions;

_object setVariable ["Tenthed_Teleport_Actions", []];
private _addedActions = [];

//diag_log format ["[Functions] Building teleport menu for: %1", _object];
//diag_log format ["[Functions] Current destinations: %1", Tenthed_Teleport_Locations];

// Add a new action for each destination that is not this terminal
{
    private _locName = _x select 0;
    private _pos = _x select 1;
    private _terminal = _x select 2;

    if (_terminal isEqualTo _object) then { continue; };

    private _id = _object addAction [format ["Teleport to %1", _locName], {
        params ["_target", "_caller", "_actionId", "_args"];
        _caller setPos (_args select 0);
    }, [_pos], 1.5, true, true, "", "true", 5];

    _addedActions pushBack _id;
} forEach Tenthed_Teleport_Locations;

_object setVariable ["Tenthed_Teleport_Actions", _addedActions];
