// Define a function to add teleport actions to an object (usually "this")
fnc_addTeleportAction = {
    private["_object", "_locationName", "_liftMarker"];
    _object = _this select 0; // The object to add actions to (usually "this")
    _locationName = _this select 1; // Name of the teleport location
    _liftMarker = _this select 2; // Lift marker for teleport destination

    // Construct the action label dynamically using the location name
    _actionLabel = format["To %1", _locationName];

    // Add the action to teleport to the specified location
    _object addAction [_actionLabel, {
        //_this select 1 setPosASL (getPosASLVisual _liftMarker);
        _this select 1 setPos (getPos _liftMarker);
        _this select 1 setDir (getDir _liftMarker);
        sleep 0.5;
        _this select 1 switchMove "";
    }];
};

// Example usage:
// Call the function on a specific object (this can be a player, a vehicle, etc.)
// Syntax: object call fnc_addTeleportAction [locationName, liftMarker];
//player call fnc_addTeleportAction ["Killhouse A", "Lift_KHA"];